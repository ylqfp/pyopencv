// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "cxtypes_h_wrapper.hpp"
#include "boost/python/object.hpp"
#include "CvMemStorage.pypp.hpp"

namespace bp = boost::python;

static ::CvMemBlock * get_bottom( CvMemStorage const & inst ) { return inst.bottom; }

static ::CvMemBlock * get_top( CvMemStorage const & inst ) { return inst.top; }

static cv::MemStorage get_parent(CvMemStorage const &inst) { return cv::MemStorage(inst.parent); }

void register_CvMemStorage_class(){

    bp::class_< CvMemStorage >( "CvMemStorage" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvMemStorage >() )    
        .def_readwrite( "block_size", &CvMemStorage::block_size )    
        .def_readwrite( "free_space", &CvMemStorage::free_space )    
        .def_readwrite( "signature", &CvMemStorage::signature )    
        .add_property( "bottom", bp::make_function(&::get_bottom, bp::return_internal_reference<>()) )    
        .add_property( "top", bp::make_function(&::get_top, bp::return_internal_reference<>()) )    
        .add_property( "parent", bp::make_function(&::get_parent, bp::with_custodian_and_ward_postcall<0, 1>()) );

}