// This file has been generated by Py++.

#include "boost/python.hpp"
#include "highgui_wrapper.hpp"
#include "highgui_ext_free_functions.pypp.hpp"

namespace bp = boost::python;

void register_free_functions(){

    { //::cvDestroyAllWindows
    
        typedef void ( *_cvDestroyAllWindows_function_type )(  );
        
        bp::def( 
            "_cvDestroyAllWindows"
            , _cvDestroyAllWindows_function_type( &::cvDestroyAllWindows )
            , "\nDestroys all of the HighGUI windows."
    "\nWrapped function:"
    "\n    cvDestroyAllWindows"
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/c/user_interface.html#convertimage#destroyallwindows" );
    
    }

    { //::cvDestroyWindow
    
        typedef void ( *_cvDestroyWindow_function_type )( char const * );
        
        bp::def( 
            "_cvDestroyWindow"
            , _cvDestroyWindow_function_type( &::cvDestroyWindow )
            , ( bp::arg("name") )
            , "\nDestroys a window."
    "\nWrapped function:"
    "\n    cvDestroyWindow"
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/c/user_interface.html#convertimage#destroywindow" );
    
    }

    { //::cvGetWindowName
    
        typedef char const * ( *getWindowName_function_type )( void * );
        
        bp::def( 
            "getWindowName"
            , getWindowName_function_type( &::cvGetWindowName )
            , ( bp::arg("window_handle") )
            , "\nGets the window's name by its handle."
    "\nWrapped function:"
    "\n    cvGetWindowName"
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/c/user_interface.html#convertimage#getwindowname" );
    
    }

    { //::cvMoveWindow
    
        typedef void ( *moveWindow_function_type )( char const *,int,int );
        
        bp::def( 
            "moveWindow"
            , moveWindow_function_type( &::cvMoveWindow )
            , ( bp::arg("name"), bp::arg("x"), bp::arg("y") )
            , "\nSets the position of the window."
    "\nWrapped function:"
    "\n    cvMoveWindow"
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/c/user_interface.html#convertimage#movewindow" );
    
    }

    { //::cvResizeWindow
    
        typedef void ( *resizeWindow_function_type )( char const *,int,int );
        
        bp::def( 
            "resizeWindow"
            , resizeWindow_function_type( &::cvResizeWindow )
            , ( bp::arg("name"), bp::arg("width"), bp::arg("height") )
            , "\nSets the window size."
    "\nWrapped function:"
    "\n    cvResizeWindow"
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/c/user_interface.html#convertimage#resizewindow" );
    
    }

    { //::cvStartWindowThread
    
        typedef int ( *startWindowThread_function_type )(  );
        
        bp::def( 
            "startWindowThread"
            , startWindowThread_function_type( &::cvStartWindowThread )
            , "\nWrapped function:"
    "\n    cvStartWindowThread" );
    
    }

    { //::cv::getTrackbarPos
    
        typedef int ( *getTrackbarPos_function_type )( ::std::string const &,::std::string const & );
        
        bp::def( 
            "getTrackbarPos"
            , getTrackbarPos_function_type( &::cv::getTrackbarPos )
            , ( bp::arg("trackbarname"), bp::arg("winname") )
            , "\nReturns the trackbar position."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/user_interface.html#cv-gettrackbarpos" );
    
    }

    { //::cv::getWindowProperty
    
        typedef double ( *getWindowProperty_function_type )( ::std::string const &,int );
        
        bp::def( 
            "getWindowProperty"
            , getWindowProperty_function_type( &::cv::getWindowProperty )
            , ( bp::arg("winname"), bp::arg("prop_id") ) );
    
    }

    { //::cv::imdecode
    
        typedef ::cv::Mat ( *imdecode_function_type )( ::cv::Mat const &,int );
        
        bp::def( 
            "imdecode"
            , imdecode_function_type( &::cv::imdecode )
            , ( bp::arg("buf"), bp::arg("flags") )
            , "\nReads an image from a buffer in memory."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/reading_and_writing_images_and_video.html#cv-imdecode" );
    
    }

    { //::cv::imread
    
        typedef ::cv::Mat ( *imread_function_type )( ::std::string const &,int );
        
        bp::def( 
            "imread"
            , imread_function_type( &::cv::imread )
            , ( bp::arg("filename"), bp::arg("flags")=(int)(1) )
            , "\nLoads an image from a file."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/reading_and_writing_images_and_video.html#cv-imread" );
    
    }

    { //::cv::imshow
    
        typedef void ( *imshow_function_type )( ::std::string const &,::cv::Mat const & );
        
        bp::def( 
            "imshow"
            , imshow_function_type( &::cv::imshow )
            , ( bp::arg("winname"), bp::arg("mat") )
            , "\nDisplays the image in the specified window."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/user_interface.html#cv-imshow" );
    
    }

    { //::cv::imwrite
    
        typedef bool ( *imwrite_function_type )( ::std::string const &,::cv::Mat const &,::std::vector< int > const & );
        
        bp::def( 
            "imwrite"
            , imwrite_function_type( &::cv::imwrite )
            , ( bp::arg("filename"), bp::arg("img"), bp::arg("params")=std::vector<int>() )
            , "\nSaves an image to a specified file."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/reading_and_writing_images_and_video.html#cv-imwrite" );
    
    }

    { //::cv::namedWindow
    
        typedef void ( *namedWindow_function_type )( ::std::string const &,int );
        
        bp::def( 
            "namedWindow"
            , namedWindow_function_type( &::cv::namedWindow )
            , ( bp::arg("winname"), bp::arg("flags")=(int)(1) )
            , "\nCreates a window."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/user_interface.html#cv-namedwindow" );
    
    }

    { //::cv::setTrackbarPos
    
        typedef void ( *setTrackbarPos_function_type )( ::std::string const &,::std::string const &,int );
        
        bp::def( 
            "setTrackbarPos"
            , setTrackbarPos_function_type( &::cv::setTrackbarPos )
            , ( bp::arg("trackbarname"), bp::arg("winname"), bp::arg("pos") )
            , "\nSets the trackbar position."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/user_interface.html#cv-settrackbarpos" );
    
    }

    { //::cv::setWindowProperty
    
        typedef void ( *setWindowProperty_function_type )( ::std::string const &,int,double );
        
        bp::def( 
            "setWindowProperty"
            , setWindowProperty_function_type( &::cv::setWindowProperty )
            , ( bp::arg("winname"), bp::arg("prop_id"), bp::arg("prop_value") ) );
    
    }

    { //::cv::waitKey
    
        typedef int ( *waitKey_function_type )( int );
        
        bp::def( 
            "waitKey"
            , waitKey_function_type( &::cv::waitKey )
            , ( bp::arg("delay")=(int)(0) )
            , "\nWaits for a pressed key."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/user_interface.html#cv-waitkey" );
    
    }

}
