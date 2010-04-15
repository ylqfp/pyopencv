// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "opencv_headers.hpp"
#include "CvSize2D32f.pypp.hpp"

namespace bp = boost::python;

void register_CvSize2D32f_class(){

    bp::class_< CvSize2D32f >( "CvSize2D32f", "\nSub-pixel-accurate size of a rectangle."
    "\nWarning: This structure is obsolete. It exists only to support "
    "\nbackward compatibility. Please use class Size2f instead."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/basic_structures.html#cvsize2d32f" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvSize2D32f >(), "\nSub-pixel-accurate size of a rectangle."
    "\nWarning: This structure is obsolete. It exists only to support "
    "\nbackward compatibility. Please use class Size2f instead."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/basic_structures.html#cvsize2d32f" )    
        .def_readwrite( "height", &CvSize2D32f::height )    
        .def_readwrite( "width", &CvSize2D32f::width );

}
