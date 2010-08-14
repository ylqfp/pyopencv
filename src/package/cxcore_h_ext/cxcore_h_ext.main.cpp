// This file has been generated by Py++.

#include "boost/python.hpp"

#include "__array_1.pypp.hpp"

#include "__call_policies.pypp.hpp"

#include "opencv_converters.hpp"

#include "boost/python/str.hpp"

#include "boost/python/object.hpp"

#include "boost/python/extract.hpp"

#include "__ctypes_integration.pypp.hpp"

#include "cxcore_h_wrapper.hpp"

#include "cxcore_h_ext/cxcore_h_ext_classes_1.pypp.hpp"

#include "cxcore_h_ext/cxcore_h_ext_classes_2.pypp.hpp"

#include "cxcore_h_ext/cxcore_h_ext_classes_3.pypp.hpp"

#include "cxcore_h_ext/cxcore_h_ext_enumerations.pypp.hpp"

#include "cxcore_h_ext/cxcore_h_ext_free_functions.pypp.hpp"

namespace bp = boost::python;

static void cvClearMemStorage_12bef253d2fbe591c64ea340c887838d( ::cv::MemStorage & storage ){
    ::cvClearMemStorage((CvMemStorage *)storage);
}

static boost::python::object cvCloneSeq_e969b36551290223fbe88a9b08f2f188( ::CvSeq const * seq, ::cv::MemStorage storage=cv::MemStorage(0) ){
    ::CvSeq * result = ::cvCloneSeq(seq, (CvMemStorage *)storage);
    typedef bp::with_custodian_and_ward_postcall< 0, 2, bp::return_value_policy< bp::reference_existing_object > > call_policies_t;
    return bp::object( pyplusplus::call_policies::make_object< call_policies_t, ::CvSeq * >( result ) );
}

static boost::python::object cvCreateSeq_2f3129dfcaf52efd3761ddb7b9d8096d( int seq_flags, int header_size, int elem_size, ::cv::MemStorage & storage ){
    ::CvSeq * result = ::cvCreateSeq(seq_flags, header_size, elem_size, (CvMemStorage *)storage);
    typedef bp::with_custodian_and_ward_postcall< 0, 4, bp::return_value_policy< bp::reference_existing_object > > call_policies_t;
    return bp::object( pyplusplus::call_policies::make_object< call_policies_t, ::CvSeq * >( result ) );
}

static boost::python::object cvCreateSet_450935d8525d718f561edada26de1f0c( int set_flags, int header_size, int elem_size, ::cv::MemStorage & storage ){
    ::CvSet * result = ::cvCreateSet(set_flags, header_size, elem_size, (CvMemStorage *)storage);
    typedef bp::with_custodian_and_ward_postcall< 0, 4, bp::return_value_policy< bp::reference_existing_object > > call_policies_t;
    return bp::object( pyplusplus::call_policies::make_object< call_policies_t, ::CvSet * >( result ) );
}

static void cvEndWriteStruct_49df8f8a99539026dfbd302575d7a485( ::cv::FileStorage & fs ){
    ::cvEndWriteStruct(fs.fs);
}

static boost::python::object cvGetElemType_28303ccd15acadc45a20b8189b3b5941( ::cv::Mat & arr ){
    int result = ::cvGetElemType(get_CvMat_ptr(arr));
    return bp::object( result );
}

static boost::python::object cvGetHashedKey_5bf3bb09f908d63c5767d651120f813f( ::cv::FileStorage & fs, char const * name, int len=-0x000000001, int create_missing=0 ){
    ::CvStringHashNode * result = ::cvGetHashedKey(fs.fs, name, len, create_missing);
    typedef bp::with_custodian_and_ward_postcall< 0, 1, bp::return_value_policy< bp::reference_existing_object > > call_policies_t;
    return bp::object( pyplusplus::call_policies::make_object< call_policies_t, ::CvStringHashNode * >( result ) );
}

static boost::python::object cvInitNArrayIterator_4c1924434c279d42b088754762acc53b( std::vector<cv::Mat> const & arrs, ::cv::Mat & mask, ::CvMatND * stubs, ::CvNArrayIterator * array_iterator, int flags=0 ){
    
    std::vector<void *> buf_arrs(arrs.size());
    for(size_t i_arrs = 0; i_arrs<arrs.size(); ++i_arrs)
        buf_arrs[i_arrs] = (void *)get_CvMat_ptr(arrs[i_arrs]);
        
    int result = ::cvInitNArrayIterator(arrs.size(), (CvArr * *)(&buf_arrs[0]), get_CvMat_ptr(mask), stubs, array_iterator, flags);
    return bp::object( result );
}

static boost::python::object cvMemStorageAllocString_9839ce871d1503bdcc9755acafa55ace( ::cv::MemStorage & storage, char const * ptr, int len=-0x000000001 ){
    ::CvString result = ::cvMemStorageAllocString((CvMemStorage *)storage, ptr, len);
    typedef bp::with_custodian_and_ward_postcall< 0, 1 > call_policies_t;
    return bp::object( pyplusplus::call_policies::make_object< call_policies_t, ::CvString >( result ) );
}

static void cvRandArr_7e6e03c94e3a5f654b62b47647889d1d( ::cv::RNG & rng, ::cv::Mat & arr, int dist_type, cv::Scalar_<double> const & param1, cv::Scalar_<double> const & param2 ){
    ::cvRandArr(&rng.state, get_CvMat_ptr(arr), dist_type, (CvScalar const &)param1, (CvScalar const &)param2);
}

static boost::python::object cvRange_073a997114e2c96bbeff2aaa986e76a1( ::cv::Mat & mat, double start, double end ){
    ::CvArr * result = ::cvRange(get_CvMat_ptr(mat), start, end);
    typedef bp::return_self< > call_policies_t;
    return bp::object( pyplusplus::call_policies::make_object< call_policies_t, ::CvArr * >( result ) );
}

static void cvRestoreMemStoragePos_3e71d651091766556a8f53d4fa0c5b14( ::cv::MemStorage & storage, ::CvMemStoragePos * pos ){
    ::cvRestoreMemStoragePos((CvMemStorage *)storage, pos);
}

static void cvSaveMemStoragePos_7a8c57c29bc3108b8813e96f38fa74ea( ::cv::MemStorage & storage, ::CvMemStoragePos * pos ){
    ::cvSaveMemStoragePos((CvMemStorage *)storage, pos);
}

static boost::python::object cvSliceLength_e14285df18654820c66883f592fc67a6( cv::Range const & slice, ::CvSeq const * seq ){
    int result = ::cvSliceLength((CvSlice const &)slice, seq);
    return bp::object( result );
}

static boost::python::object cvSolveCubic_97d0ac3b0fc6ba46cd5b5f2eaea79583( ::cv::Mat & coeffs, ::cv::Mat & roots ){
    int result = ::cvSolveCubic(get_CvMat_ptr(coeffs), get_CvMat_ptr(roots));
    return bp::object( result );
}

static void cvSolvePoly_a7fe4b7abe368e2e780716aa49dc8f82( ::cv::Mat & coeffs, ::cv::Mat & roots2, int maxiter=20, int fig=100 ){
    ::cvSolvePoly(get_CvMat_ptr(coeffs), get_CvMat_ptr(roots2), maxiter, fig);
}

static void cvStartNextStream_db71e53dfa9475145f4487a80d5d8bf2( ::cv::FileStorage & fs ){
    ::cvStartNextStream(fs.fs);
}

static void cvStartWriteStruct_e7e2128639c3a858bdb332c89468a8e0( ::cv::FileStorage & fs, char const * name, int struct_flags, char const * type_name=0, ::CvAttrList attributes=cvAttrList(0u, 0u) ){
    ::cvStartWriteStruct(fs.fs, name, struct_flags, type_name, attributes);
}

static boost::python::object cvTypeOf_4e7bd20b082b35b68253f04b04f578ce( ::CvArr * struct_ptr ){
    ::CvTypeInfo * result = ::cvTypeOf(reinterpret_cast< void const * >( struct_ptr ));
    typedef bp::return_value_policy< bp::reference_existing_object > call_policies_t;
    return bp::object( pyplusplus::call_policies::make_object< call_policies_t, ::CvTypeInfo * >( result ) );
}

static void cvWrite_00335cc764e72fb9408450c10fffab4a( ::cv::FileStorage & fs, char const * name, const char * ptr, ::CvAttrList attributes=cvAttrList(0u, 0u) ){
    ::cvWrite(fs.fs, name, ((void const *) ptr), attributes);
}

static void cvWriteComment_3e89473031f5fbea0ed6232440721138( ::cv::FileStorage & fs, char const * comment, int eol_comment ){
    ::cvWriteComment(fs.fs, comment, eol_comment);
}

static void cvWriteFileNode_4df1ea107367e738fdd6f88f15146fb9( ::cv::FileStorage & fs, char const * new_node_name, ::cv::FileNode const & node, int embed ){
    ::cvWriteFileNode(fs.fs, new_node_name, *(node), embed);
}

BOOST_PYTHON_MODULE(cxcore_h_ext){
    register_enumerations();

    { //::cvClearMemStorage
    
        typedef void ( *clearMemStorage_function_type )( ::cv::MemStorage & );
        
        bp::def( 
            "clearMemStorage"
            , clearMemStorage_function_type( &cvClearMemStorage_12bef253d2fbe591c64ea340c887838d )
            , ( bp::arg("storage") )
            , "\nWrapped function:"
    "\n    cvClearMemStorage"
    "\nArgument 'storage':"\
    "\n    C++ type: ::CvMemStorage *"\
    "\n    Python type: MemStorage" );
    
    }

    { //::cvCloneSeq
    
        typedef boost::python::object ( *cloneSeq_function_type )( ::CvSeq const *,::cv::MemStorage );
        
        bp::def( 
            "cloneSeq"
            , cloneSeq_function_type( &cvCloneSeq_e969b36551290223fbe88a9b08f2f188 )
            , ( bp::arg("seq"), bp::arg("storage")=cv::MemStorage(0) )
            , "\nWrapped function:"
    "\n    cvCloneSeq"
    "\nArgument 'storage':"\
    "\n    C++ type: ::CvMemStorage *"\
    "\n    Python type: MemStorage" );
    
    }

    { //::cvCreateSeq
    
        typedef boost::python::object ( *createSeq_function_type )( int,int,int,::cv::MemStorage & );
        
        bp::def( 
            "createSeq"
            , createSeq_function_type( &cvCreateSeq_2f3129dfcaf52efd3761ddb7b9d8096d )
            , ( bp::arg("seq_flags"), bp::arg("header_size"), bp::arg("elem_size"), bp::arg("storage") )
            , "\nWrapped function:"
    "\n    cvCreateSeq"
    "\nArgument 'storage':"\
    "\n    C++ type: ::CvMemStorage *"\
    "\n    Python type: MemStorage" );
    
    }

    { //::cvCreateSet
    
        typedef boost::python::object ( *createSet_function_type )( int,int,int,::cv::MemStorage & );
        
        bp::def( 
            "createSet"
            , createSet_function_type( &cvCreateSet_450935d8525d718f561edada26de1f0c )
            , ( bp::arg("set_flags"), bp::arg("header_size"), bp::arg("elem_size"), bp::arg("storage") )
            , "\nWrapped function:"
    "\n    cvCreateSet"
    "\nArgument 'storage':"\
    "\n    C++ type: ::CvMemStorage *"\
    "\n    Python type: MemStorage" );
    
    }

    { //::cvEndWriteStruct
    
        typedef void ( *endWriteStruct_function_type )( ::cv::FileStorage & );
        
        bp::def( 
            "endWriteStruct"
            , endWriteStruct_function_type( &cvEndWriteStruct_49df8f8a99539026dfbd302575d7a485 )
            , ( bp::arg("fs") )
            , "\nWrapped function:"
    "\n    cvEndWriteStruct"
    "\nArgument 'fs':"\
    "\n    C++ type: ::CvFileStorage *"\
    "\n    Python type: FileStorage" );
    
    }

    { //::cvGetElemType
    
        typedef boost::python::object ( *getElemType_function_type )( ::cv::Mat & );
        
        bp::def( 
            "getElemType"
            , getElemType_function_type( &cvGetElemType_28303ccd15acadc45a20b8189b3b5941 )
            , ( bp::arg("arr") )
            , "\nWrapped function:"
    "\n    cvGetElemType"
    "\nArgument 'arr':"\
    "\n    C++ type: ::CvArr const *"\
    "\n    Python type: Mat" );
    
    }

    { //::cvGetHashedKey
    
        typedef boost::python::object ( *getHashedKey_function_type )( ::cv::FileStorage &,char const *,int,int );
        
        bp::def( 
            "getHashedKey"
            , getHashedKey_function_type( &cvGetHashedKey_5bf3bb09f908d63c5767d651120f813f )
            , ( bp::arg("fs"), bp::arg("name"), bp::arg("len")=(int)(-0x000000001), bp::arg("create_missing")=(int)(0) )
            , "\nWrapped function:"
    "\n    cvGetHashedKey"
    "\nArgument 'fs':"\
    "\n    C++ type: ::CvFileStorage *"\
    "\n    Python type: FileStorage" );
    
    }

    { //::cvInitNArrayIterator
    
        typedef boost::python::object ( *initNArrayIterator_function_type )( std::vector<cv::Mat> const &,::cv::Mat &,::CvMatND *,::CvNArrayIterator *,int );
        
        bp::def( 
            "initNArrayIterator"
            , initNArrayIterator_function_type( &cvInitNArrayIterator_4c1924434c279d42b088754762acc53b )
            , ( bp::arg("arrs"), bp::arg("mask"), bp::arg("stubs"), bp::arg("array_iterator"), bp::arg("flags")=(int)(0) )
            , "\nWrapped function:"
    "\n    cvInitNArrayIterator"
    "\nArgument 'count':"\
    "\n    Dependent argument: omitted from input. Its value is derived from "\
    "\n    argument 'arrs'."\
    "\nArgument 'arrs':"\
    "\n    C++ type: ::CvArr * *"\
    "\n    Python type: (C++)std::vector<cv::Mat>"\
    "\nArgument 'mask':"\
    "\n    C++ type: ::CvArr const *"\
    "\n    Python type: Mat" );
    
    }

    { //::cvMemStorageAllocString
    
        typedef boost::python::object ( *memStorageAllocString_function_type )( ::cv::MemStorage &,char const *,int );
        
        bp::def( 
            "memStorageAllocString"
            , memStorageAllocString_function_type( &cvMemStorageAllocString_9839ce871d1503bdcc9755acafa55ace )
            , ( bp::arg("storage"), bp::arg("ptr"), bp::arg("len")=(int)(-0x000000001) )
            , "\nWrapped function:"
    "\n    cvMemStorageAllocString"
    "\nArgument 'storage':"\
    "\n    C++ type: ::CvMemStorage *"\
    "\n    Python type: MemStorage" );
    
    }

    { //::cvRandArr
    
        typedef void ( *randArr_function_type )( ::cv::RNG &,::cv::Mat &,int,cv::Scalar_<double> const &,cv::Scalar_<double> const & );
        
        bp::def( 
            "randArr"
            , randArr_function_type( &cvRandArr_7e6e03c94e3a5f654b62b47647889d1d )
            , ( bp::arg("rng"), bp::arg("arr"), bp::arg("dist_type"), bp::arg("param1"), bp::arg("param2") )
            , "\nWrapped function:"
    "\n    cvRandArr"
    "\nArgument 'rng':"\
    "\n    C++ type: ::CvRNG *"\
    "\n    Python type: RNG"\
    "\nArgument 'arr':"\
    "\n    C++ type: ::CvArr *"\
    "\n    Python type: Mat"\
    "\nArgument 'param1':"\
    "\n    C++ type: ::CvScalar"\
    "\n    Python type: Scalar"\
    "\nArgument 'param2':"\
    "\n    C++ type: ::CvScalar"\
    "\n    Python type: Scalar" );
    
    }

    { //::cvRange
    
        typedef boost::python::object ( *range__function_type )( ::cv::Mat &,double,double );
        
        bp::def( 
            "range_"
            , range__function_type( &cvRange_073a997114e2c96bbeff2aaa986e76a1 )
            , ( bp::arg("mat"), bp::arg("start"), bp::arg("end") )
            , "\nWrapped function:"
    "\n    cvRange"
    "\nArgument 'mat':"\
    "\n    C++ type: ::CvArr *"\
    "\n    Python type: Mat" );
    
    }

    { //::cvRestoreMemStoragePos
    
        typedef void ( *restoreMemStoragePos_function_type )( ::cv::MemStorage &,::CvMemStoragePos * );
        
        bp::def( 
            "restoreMemStoragePos"
            , restoreMemStoragePos_function_type( &cvRestoreMemStoragePos_3e71d651091766556a8f53d4fa0c5b14 )
            , ( bp::arg("storage"), bp::arg("pos") )
            , "\nWrapped function:"
    "\n    cvRestoreMemStoragePos"
    "\nArgument 'storage':"\
    "\n    C++ type: ::CvMemStorage *"\
    "\n    Python type: MemStorage" );
    
    }

    { //::cvSaveMemStoragePos
    
        typedef void ( *saveMemStoragePos_function_type )( ::cv::MemStorage &,::CvMemStoragePos * );
        
        bp::def( 
            "saveMemStoragePos"
            , saveMemStoragePos_function_type( &cvSaveMemStoragePos_7a8c57c29bc3108b8813e96f38fa74ea )
            , ( bp::arg("storage"), bp::arg("pos") )
            , "\nWrapped function:"
    "\n    cvSaveMemStoragePos"
    "\nArgument 'storage':"\
    "\n    C++ type: ::CvMemStorage const *"\
    "\n    Python type: MemStorage" );
    
    }

    { //::cvSliceLength
    
        typedef boost::python::object ( *sliceLength_function_type )( cv::Range const &,::CvSeq const * );
        
        bp::def( 
            "sliceLength"
            , sliceLength_function_type( &cvSliceLength_e14285df18654820c66883f592fc67a6 )
            , ( bp::arg("slice"), bp::arg("seq") )
            , "\nWrapped function:"
    "\n    cvSliceLength"
    "\nArgument 'slice':"\
    "\n    C++ type: ::CvSlice"\
    "\n    Python type: Range" );
    
    }

    { //::cvSolveCubic
    
        typedef boost::python::object ( *solveCubic_function_type )( ::cv::Mat &,::cv::Mat & );
        
        bp::def( 
            "solveCubic"
            , solveCubic_function_type( &cvSolveCubic_97d0ac3b0fc6ba46cd5b5f2eaea79583 )
            , ( bp::arg("coeffs"), bp::arg("roots") )
            , "\nWrapped function:"
    "\n    cvSolveCubic"
    "\nArgument 'coeffs':"\
    "\n    C++ type: ::CvMat const *"\
    "\n    Python type: Mat"\
    "\nArgument 'roots':"\
    "\n    C++ type: ::CvMat *"\
    "\n    Python type: Mat" );
    
    }

    { //::cvSolvePoly
    
        typedef void ( *solvePoly_function_type )( ::cv::Mat &,::cv::Mat &,int,int );
        
        bp::def( 
            "solvePoly"
            , solvePoly_function_type( &cvSolvePoly_a7fe4b7abe368e2e780716aa49dc8f82 )
            , ( bp::arg("coeffs"), bp::arg("roots2"), bp::arg("maxiter")=(int)(20), bp::arg("fig")=(int)(100) )
            , "\nWrapped function:"
    "\n    cvSolvePoly"
    "\nArgument 'coeffs':"\
    "\n    C++ type: ::CvMat const *"\
    "\n    Python type: Mat"\
    "\nArgument 'roots2':"\
    "\n    C++ type: ::CvMat *"\
    "\n    Python type: Mat" );
    
    }

    { //::cvStartNextStream
    
        typedef void ( *startNextStream_function_type )( ::cv::FileStorage & );
        
        bp::def( 
            "startNextStream"
            , startNextStream_function_type( &cvStartNextStream_db71e53dfa9475145f4487a80d5d8bf2 )
            , ( bp::arg("fs") )
            , "\nWrapped function:"
    "\n    cvStartNextStream"
    "\nArgument 'fs':"\
    "\n    C++ type: ::CvFileStorage *"\
    "\n    Python type: FileStorage" );
    
    }

    { //::cvStartWriteStruct
    
        typedef void ( *startWriteStruct_function_type )( ::cv::FileStorage &,char const *,int,char const *,::CvAttrList );
        
        bp::def( 
            "startWriteStruct"
            , startWriteStruct_function_type( &cvStartWriteStruct_e7e2128639c3a858bdb332c89468a8e0 )
            , ( bp::arg("fs"), bp::arg("name"), bp::arg("struct_flags"), bp::arg("type_name")=bp::object(), bp::arg("attributes")=cvAttrList(0u, 0u) )
            , "\nWrapped function:"
    "\n    cvStartWriteStruct"
    "\nArgument 'fs':"\
    "\n    C++ type: ::CvFileStorage *"\
    "\n    Python type: FileStorage" );
    
    }

    { //::cvTypeOf
    
        typedef boost::python::object ( *typeOf_function_type )( ::CvArr * );
        
        bp::def( 
            "typeOf"
            , typeOf_function_type( &cvTypeOf_4e7bd20b082b35b68253f04b04f578ce )
            , ( bp::arg("struct_ptr") )
            , "\nWrapped function:"
    "\n    cvTypeOf" );
    
    }

    { //::cvWrite
    
        typedef void ( *write_function_type )( ::cv::FileStorage &,char const *,const char *,::CvAttrList );
        
        bp::def( 
            "write"
            , write_function_type( &cvWrite_00335cc764e72fb9408450c10fffab4a )
            , ( bp::arg("fs"), bp::arg("name"), bp::arg("ptr"), bp::arg("attributes")=cvAttrList(0u, 0u) )
            , "\nWrapped function:"
    "\n    cvWrite"
    "\nArgument 'fs':"\
    "\n    C++ type: ::CvFileStorage *"\
    "\n    Python type: FileStorage"\
    "\nArgument 'ptr':"\
    "\n    C++ type: void const *"\
    "\n    Python type: string" );
    
    }

    { //::cvWriteComment
    
        typedef void ( *writeComment_function_type )( ::cv::FileStorage &,char const *,int );
        
        bp::def( 
            "writeComment"
            , writeComment_function_type( &cvWriteComment_3e89473031f5fbea0ed6232440721138 )
            , ( bp::arg("fs"), bp::arg("comment"), bp::arg("eol_comment") )
            , "\nWrapped function:"
    "\n    cvWriteComment"
    "\nArgument 'fs':"\
    "\n    C++ type: ::CvFileStorage *"\
    "\n    Python type: FileStorage" );
    
    }

    { //::cvWriteFileNode
    
        typedef void ( *writeFileNode_function_type )( ::cv::FileStorage &,char const *,::cv::FileNode const &,int );
        
        bp::def( 
            "writeFileNode"
            , writeFileNode_function_type( &cvWriteFileNode_4df1ea107367e738fdd6f88f15146fb9 )
            , ( bp::arg("fs"), bp::arg("new_node_name"), bp::arg("node"), bp::arg("embed") )
            , "\nWrapped function:"
    "\n    cvWriteFileNode"
    "\nArgument 'fs':"\
    "\n    C++ type: ::CvFileStorage *"\
    "\n    Python type: FileStorage"\
    "\nArgument 'node':"\
    "\n    C++ type: ::CvFileNode const *"\
    "\n    Python type: FileNode" );
    
    }

    register_classes_1();

    register_classes_2();

    register_classes_3();

    register_free_functions();
}

