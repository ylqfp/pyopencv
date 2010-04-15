// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__array_1.pypp.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "opencv_headers.hpp"
#include "CvScalar.pypp.hpp"

namespace bp = boost::python;

struct CvScalar_wrapper : CvScalar, bp::wrapper< CvScalar > {

    CvScalar_wrapper(CvScalar const & arg )
    : CvScalar( arg )
      , bp::wrapper< CvScalar >(){
        // copy constructor
        
    }

    CvScalar_wrapper()
    : CvScalar()
      , bp::wrapper< CvScalar >(){
        // null constructor
        
    }

    static pyplusplus::containers::static_sized::array_1_t< double, 4>
    pyplusplus_val_wrapper( ::CvScalar & inst ){
        return pyplusplus::containers::static_sized::array_1_t< double, 4>( inst.val );
    }

};

void register_CvScalar_class(){

    { //::CvScalar
        typedef bp::class_< CvScalar_wrapper > CvScalar_exposer_t;
        CvScalar_exposer_t CvScalar_exposer = CvScalar_exposer_t( "CvScalar", "\nA container for 1-,2-,3- or 4-tuples of doubles.CvScalar is always "
    "\nrepresented as a 4-tuple.."
    "\nWarning: This structure is obsolete. It exists only to support "
    "\nbackward compatibility. Please use class Scalar instead."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/basic_structures.html#cvscalar" );
        bp::scope CvScalar_scope( CvScalar_exposer );
        CvScalar_exposer.add_property( "this", pyplus_conv::make_addressof_inst_getter< CvScalar >(), "\nA container for 1-,2-,3- or 4-tuples of doubles.CvScalar is always "
    "\nrepresented as a 4-tuple.."
    "\nWarning: This structure is obsolete. It exists only to support "
    "\nbackward compatibility. Please use class Scalar instead."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/basic_structures.html#cvscalar" );
        pyplusplus::containers::static_sized::register_array_1< double, 4 >( "__array_1_double_4" );
        { //CvScalar::val [variable], type=double[4]
        
            typedef pyplusplus::containers::static_sized::array_1_t< double, 4> ( *array_wrapper_creator )( ::CvScalar & );
            
            CvScalar_exposer.add_property( "val"
                , bp::make_function( array_wrapper_creator(&CvScalar_wrapper::pyplusplus_val_wrapper)
                                    , bp::with_custodian_and_ward_postcall< 0, 1 >() ) );
        }
    }

}
