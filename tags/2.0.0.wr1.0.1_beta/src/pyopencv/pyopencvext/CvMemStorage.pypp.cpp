// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "opencv_headers.hpp"
#include "boost/python/object.hpp"
#include "CvMemStorage.pypp.hpp"

namespace bp = boost::python;

struct CvMemStorage_wrapper : CvMemStorage, bp::wrapper< CvMemStorage > {

    CvMemStorage_wrapper(CvMemStorage const & arg )
    : CvMemStorage( arg )
      , bp::wrapper< CvMemStorage >(){
        // copy constructor
        
    }

    CvMemStorage_wrapper()
    : CvMemStorage()
      , bp::wrapper< CvMemStorage >(){
        // null constructor
        
    }

    static bp::object get_bottom( ::CvMemStorage const & inst ){        
        return inst.bottom? bp::object(inst.bottom): bp::object();
    }

    static bp::object get_top( ::CvMemStorage const & inst ){        
        return inst.top? bp::object(inst.top): bp::object();
    }

    static bp::object get_parent( ::CvMemStorage const & inst ){        
        return inst.parent? bp::object(inst.parent): bp::object();
    }

};

void register_CvMemStorage_class(){

    bp::class_< CvMemStorage_wrapper >( "CvMemStorage" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvMemStorage >() )    
        .def_readwrite( "block_size", &CvMemStorage::block_size )    
        .def_readwrite( "free_space", &CvMemStorage::free_space )    
        .def_readwrite( "signature", &CvMemStorage::signature )    
        .add_property( "bottom", bp::make_function(&::CvMemStorage_wrapper::get_bottom) )    
        .add_property( "top", bp::make_function(&::CvMemStorage_wrapper::get_top) )    
        .add_property( "parent", bp::make_function(&::CvMemStorage_wrapper::get_parent) );

}