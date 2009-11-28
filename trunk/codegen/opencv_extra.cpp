#include <boost/python/detail/prefix.hpp>
#include <boost/python/extract.hpp>
#include <boost/python/default_call_policies.hpp>
#include <boost/python/object.hpp>

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

#include "opencv_extra.hpp"


// ================================================================================================

void CV_CDECL sdTrackbarCallback2(int pos, void* userdata)
{
    bp::object items(bp::handle<>(bp::borrowed((PyObject *)userdata)));
    (items[0])(pos, bp::object(items[1])); // need a copy of items[1] to make it safe with threading
}


void CV_CDECL sdMouseCallback(int event, int x, int y, int flags, void* param)
{
    bp::object items(bp::handle<>(bp::borrowed((PyObject *)param)));
    (items[0])(event, x, y, flags, bp::object(items[1])); // need a copy of items[1] to make it safe with threading
}

float CV_CDECL sdDistanceFunction( const float* a, const float*b, void* user_param )
{
    bp::object items(bp::handle<>(bp::borrowed((PyObject *)user_param)));
    // pass 'a' and 'b' by address instead of by pointer
    return bp::extract < float >((items[0])((int)a, (int)b, bp::object(items[1]))); // need a copy of items[1] to make it safe with threading
}

// ================================================================================================

int convert_dtype_to_cvdepth(int dtype)
{
    switch(dtype)
    {
    case NPY_BYTE: return CV_8S;
    case NPY_UBYTE: return CV_8U;
    case NPY_SHORT: return CV_16S;
    case NPY_USHORT: return CV_16U;
    case NPY_LONG: return CV_32S;
    case NPY_FLOAT: return CV_32F;
    case NPY_DOUBLE: return CV_64F;
    }
    PyErr_SetString(PyExc_TypeError, "Unconvertable dtype.");
    throw bp::error_already_set();
    return -1;
}

// ================================================================================================

int convert_cvdepth_to_dtype(int depth)
{
    switch(depth)
    {
    case CV_8S: return NPY_BYTE;
    case CV_8U: return NPY_UBYTE;
    case CV_16S: return NPY_SHORT;
    case CV_16U: return NPY_USHORT;
    case CV_32S: return NPY_LONG;
    case CV_32F: return NPY_FLOAT;
    case CV_64F: return NPY_DOUBLE;
    }
    PyErr_SetString(PyExc_TypeError, "Unconvertable cvdepth.");
    throw bp::error_already_set();
    return -1;
}

// ================================================================================================


void npy_init1()
{
    import_array();
}

bool npy_init2()
{
    npy_init1();
    return true;
}

bool npy_inited = npy_init2();

// ================================================================================================


template<> void convert_ndarray_to< cv::Mat >( const bp::object &in_arr, cv::Mat &out_arr )
{
    PyObject *arr = in_arr.ptr();
    char s[100];
    if(PyArray_Check(arr) != 1)
    {
        PyErr_SetString(PyExc_TypeError, "Input argument is not an ndarray.");
        throw bp::error_already_set(); 
    }
    int nd = PyArray_NDIM(arr);
    if(nd < 2)
    {    
        PyErr_SetString(PyExc_TypeError, "Rank must not be less than 2.");
        throw bp::error_already_set(); 
    }
    if(nd > 3)
    {
        PyErr_SetString(PyExc_TypeError, "Rank must not be greater than 3.");
        throw bp::error_already_set(); 
    }
    
    int nchannels;
    int *shape = PyArray_DIMS(arr);
    int itemsize = PyArray_ITEMSIZE(arr);
    int *strides = PyArray_STRIDES(arr);
    
    if(nd == 2)
    {
        if(strides[1] != itemsize) // non-contiguous
        {
            sprintf(s, "The last (2nd) dimension must be contiguous (last stride=%d and itemsize=%d).", strides[1], itemsize);
            PyErr_SetString(PyExc_TypeError, s);
            throw bp::error_already_set(); 
        }
        nchannels = 1;
    }
    else
    {
        if(strides[2] != itemsize) // non-contiguous
        {
            sprintf(s, "The last (3rd) dimension must be contiguous (last stride=%d and itemsize=%d).", strides[2], itemsize);
            PyErr_SetString(PyExc_TypeError, s);
            throw bp::error_already_set(); 
        }
        nchannels = shape[2];
        if(nchannels < 1) // non-contiguous
        {
            sprintf(s, "The number of channels must not be less than 1 (nchannels=%d).", nchannels);
            PyErr_SetString(PyExc_TypeError, s);
            throw bp::error_already_set(); 
        }
        if(nchannels > 4) // non-contiguous
        {
            sprintf(s, "The number of channels must not be greater than 4 (nchannels=%d).", nchannels);
            PyErr_SetString(PyExc_TypeError, s);
            throw bp::error_already_set(); 
        }
        if(strides[1] != itemsize*nchannels) // non-contiguous
        {
            sprintf(s, "The 2nd dimension must be contiguous (2nd stride=%d, itemsize=%d, nchannels=%d).", strides[1], itemsize, nchannels);
            throw bp::error_already_set(); 
        }
    }
    out_arr = cv::Mat(cv::Size(shape[1], shape[0]), 
        CV_MAKETYPE(convert_dtype_to_cvdepth(PyArray_TYPE(arr)), nchannels), PyArray_DATA(arr), strides[0]);
}

// ================================================================================================


template void convert_ndarray_to( const bp::object &in_arr, std::vector<char> &out_arr );
template void convert_ndarray_to( const bp::object &in_arr, std::vector<unsigned char> &out_arr );
template void convert_ndarray_to( const bp::object &in_arr, std::vector<short> &out_arr );
template void convert_ndarray_to( const bp::object &in_arr, std::vector<unsigned short> &out_arr );
template void convert_ndarray_to( const bp::object &in_arr, std::vector<long> &out_arr );
template void convert_ndarray_to( const bp::object &in_arr, std::vector<unsigned long> &out_arr );
template void convert_ndarray_to( const bp::object &in_arr, std::vector<int> &out_arr );
template void convert_ndarray_to( const bp::object &in_arr, std::vector<unsigned int> &out_arr );
template void convert_ndarray_to( const bp::object &in_arr, std::vector<float> &out_arr );
template void convert_ndarray_to( const bp::object &in_arr, std::vector<double> &out_arr );


// ================================================================================================


bool is_Mat_from_ndarray( const cv::Mat &in_arr, bp::object &out_arr )
{
    PyObject *arr = out_arr.ptr();
    if(PyArray_Check(arr) != 1) return false;
    if(PyArray_DATA(arr) != (void *)in_arr.data) return false;
    int nd = PyArray_NDIM(arr);
    if(nd < 2 || nd > 3) return false;
    int nchannels;
    int *shape = PyArray_DIMS(arr);
    int itemsize = PyArray_ITEMSIZE(arr);
    int *strides = PyArray_STRIDES(arr);
    if(nd == 2)
    {
        if(strides[1] != itemsize) return false;
        nchannels = 1;
    }
    else
    {
        if(strides[2] != itemsize) return false;
        nchannels = shape[2];
        if(nchannels < 1 || nchannels > 4 || strides[1] != itemsize*nchannels) return false;
    }
    if(in_arr.cols != shape[1] || in_arr.rows != shape[0] || in_arr.step != strides[0] ||
        in_arr.channels() != nchannels || in_arr.depth() != convert_dtype_to_cvdepth(PyArray_TYPE(arr)))
        return false;
    // finally, made it
    PyErr_SetString(PyExc_TypeError, "Alright, it is working fine.");
    throw bp::error_already_set(); 
    return true;
}


void create_ndarray_from_Mat( const cv::Mat &in_arr, bp::object &out_arr )
{
    PyObject *arr;
    int rows = in_arr.rows, cols = in_arr.cols, nchannels = in_arr.channels();
    int shape[3], i, rowlen = cols*in_arr.elemSize();
    shape[0] = rows; shape[1] = cols;    
    if(nchannels == 1)
        arr = PyArray_SimpleNew(2, shape, convert_cvdepth_to_dtype(in_arr.depth()));
    else
    {
        shape[2] = nchannels;
        arr = PyArray_SimpleNew(3, shape, convert_cvdepth_to_dtype(in_arr.depth()));
    }
    for(i = 0; i < rows; ++i)
        std::memmove(PyArray_GETPTR1(arr, i), (const void *)in_arr.ptr(i), rowlen);
    out_arr = bp::object(bp::handle<>(arr));
}

template<> void convert_ndarray_from< cv::Mat >( const cv::Mat &in_arr, bp::object &out_arr )
{
    if(!is_Mat_from_ndarray(in_arr, out_arr)) // if same array, no need to do anything
        create_ndarray_from_Mat(in_arr, out_arr);
}

// ================================================================================================


template void convert_ndarray_from( const std::vector<char> &in_arr, bp::object &out_arr );
template void convert_ndarray_from( const std::vector<unsigned char> &in_arr, bp::object &out_arr );
template void convert_ndarray_from( const std::vector<short> &in_arr, bp::object &out_arr );
template void convert_ndarray_from( const std::vector<unsigned short> &in_arr, bp::object &out_arr );
template void convert_ndarray_from( const std::vector<long> &in_arr, bp::object &out_arr );
template void convert_ndarray_from( const std::vector<unsigned long> &in_arr, bp::object &out_arr );
template void convert_ndarray_from( const std::vector<int> &in_arr, bp::object &out_arr );
template void convert_ndarray_from( const std::vector<unsigned int> &in_arr, bp::object &out_arr );
template void convert_ndarray_from( const std::vector<float> &in_arr, bp::object &out_arr );
template void convert_ndarray_from( const std::vector<double> &in_arr, bp::object &out_arr );

// ================================================================================================

// get_ndarray_type
PyTypeObject const* get_ndarray_type()
{
    return &PyArray_Type;
}