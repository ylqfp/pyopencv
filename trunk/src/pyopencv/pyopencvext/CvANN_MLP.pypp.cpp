// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "opencv_headers.hpp"
#include "CvANN_MLP.pypp.hpp"

namespace bp = boost::python;

struct CvANN_MLP_wrapper : CvANN_MLP, bp::wrapper< CvANN_MLP > {

    CvANN_MLP_wrapper(CvANN_MLP const & arg )
    : CvANN_MLP( arg )
      , bp::wrapper< CvANN_MLP >(){
        // copy constructor
        
    }

    CvANN_MLP_wrapper( )
    : CvANN_MLP( )
      , bp::wrapper< CvANN_MLP >(){
        // null constructor
    
    }

    virtual void clear(  ) {
        if( bp::override func_clear = this->get_override( "clear" ) )
            func_clear(  );
        else{
            this->CvANN_MLP::clear(  );
        }
    }
    
    void default_clear(  ) {
        CvANN_MLP::clear( );
    }

    virtual void create( ::cv::Mat const & _layer_sizes, int _activ_func=int(::CvANN_MLP::SIGMOID_SYM), double _f_param1=0, double _f_param2=0 ) {
        if( bp::override func_create = this->get_override( "create" ) )
            func_create( boost::ref(_layer_sizes), _activ_func, _f_param1, _f_param2 );
        else{
            this->CvANN_MLP::create( boost::ref(_layer_sizes), _activ_func, _f_param1, _f_param2 );
        }
    }
    
    void default_create( ::cv::Mat const & _layer_sizes, int _activ_func=int(::CvANN_MLP::SIGMOID_SYM), double _f_param1=0, double _f_param2=0 ) {
        CvANN_MLP::create( boost::ref(_layer_sizes), _activ_func, _f_param1, _f_param2 );
    }

    virtual float predict( ::cv::Mat const & _inputs, ::cv::Mat & _outputs ) const  {
        if( bp::override func_predict = this->get_override( "predict" ) )
            return func_predict( boost::ref(_inputs), boost::ref(_outputs) );
        else{
            return this->CvANN_MLP::predict( boost::ref(_inputs), boost::ref(_outputs) );
        }
    }
    
    float default_predict( ::cv::Mat const & _inputs, ::cv::Mat & _outputs ) const  {
        return CvANN_MLP::predict( boost::ref(_inputs), boost::ref(_outputs) );
    }

    virtual void read( ::CvFileStorage * fs, ::CvFileNode * node ) {
        namespace bpl = boost::python;
        if( bpl::override func_read = this->get_override( "read" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_read.ptr(), fs, node );
        }
        else{
            CvANN_MLP::read( boost::python::ptr(fs), boost::python::ptr(node) );
        }
    }
    
    static void default_read( ::CvANN_MLP & inst, ::cv::FileStorage & fs, ::cv::FileNode & node ){
        if( dynamic_cast< CvANN_MLP_wrapper * >( boost::addressof( inst ) ) ){
            inst.::CvANN_MLP::read(fs.fs, *(node));
        }
        else{
            inst.read(fs.fs, *(node));
        }
    }

    virtual int train( ::cv::Mat const & _inputs, ::cv::Mat const & _outputs, ::cv::Mat const & _sample_weights, ::cv::Mat const & _sample_idx=cv::Mat(), ::CvANN_MLP_TrainParams _params=::CvANN_MLP_TrainParams( ), int flags=0 ) {
        if( bp::override func_train = this->get_override( "train" ) )
            return func_train( boost::ref(_inputs), boost::ref(_outputs), boost::ref(_sample_weights), boost::ref(_sample_idx), _params, flags );
        else{
            return this->CvANN_MLP::train( boost::ref(_inputs), boost::ref(_outputs), boost::ref(_sample_weights), boost::ref(_sample_idx), _params, flags );
        }
    }
    
    int default_train( ::cv::Mat const & _inputs, ::cv::Mat const & _outputs, ::cv::Mat const & _sample_weights, ::cv::Mat const & _sample_idx=cv::Mat(), ::CvANN_MLP_TrainParams _params=::CvANN_MLP_TrainParams( ), int flags=0 ) {
        return CvANN_MLP::train( boost::ref(_inputs), boost::ref(_outputs), boost::ref(_sample_weights), boost::ref(_sample_idx), _params, flags );
    }

    virtual void write( ::CvFileStorage * storage, char const * name ) const  {
        namespace bpl = boost::python;
        if( bpl::override func_write = this->get_override( "write" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_write.ptr(), storage, name );
        }
        else{
            CvANN_MLP::write( boost::python::ptr(storage), name );
        }
    }
    
    static void default_write( ::CvANN_MLP const & inst, ::cv::FileStorage & storage, char const * name ){
        if( dynamic_cast< CvANN_MLP_wrapper const* >( boost::addressof( inst ) ) ){
            inst.::CvANN_MLP::write(storage.fs, name);
        }
        else{
            inst.write(storage.fs, name);
        }
    }

    virtual void load( char const * filename, char const * name=0 ) {
        if( bp::override func_load = this->get_override( "load" ) )
            func_load( filename, name );
        else{
            this->CvStatModel::load( filename, name );
        }
    }
    
    void default_load( char const * filename, char const * name=0 ) {
        CvStatModel::load( filename, name );
    }

    virtual void save( char const * filename, char const * name=0 ) const  {
        if( bp::override func_save = this->get_override( "save" ) )
            func_save( filename, name );
        else{
            this->CvStatModel::save( filename, name );
        }
    }
    
    void default_save( char const * filename, char const * name=0 ) const  {
        CvStatModel::save( filename, name );
    }

    CvANN_MLP_wrapper(::cv::Mat const & _layer_sizes, int _activ_func=int(::CvANN_MLP::SIGMOID_SYM), double _f_param1=0, double _f_param2=0 )
    : CvANN_MLP()
      , bp::wrapper< CvANN_MLP >(){
        // constructor
        create( _layer_sizes, _activ_func, _f_param1, _f_param2 );
    }

};

void register_CvANN_MLP_class(){

    { //::CvANN_MLP
        typedef bp::class_< CvANN_MLP_wrapper, bp::bases< CvStatModel > > CvANN_MLP_exposer_t;
        CvANN_MLP_exposer_t CvANN_MLP_exposer = CvANN_MLP_exposer_t( "CvANN_MLP", bp::init< >() );
        bp::scope CvANN_MLP_scope( CvANN_MLP_exposer );
        CvANN_MLP_exposer.add_property( "this", pyplus_conv::make_addressof_inst_getter< CvANN_MLP >() );
        bp::scope().attr("IDENTITY") = (int)CvANN_MLP::IDENTITY;
        bp::scope().attr("SIGMOID_SYM") = (int)CvANN_MLP::SIGMOID_SYM;
        bp::scope().attr("GAUSSIAN") = (int)CvANN_MLP::GAUSSIAN;
        bp::scope().attr("UPDATE_WEIGHTS") = (int)CvANN_MLP::UPDATE_WEIGHTS;
        bp::scope().attr("NO_INPUT_SCALE") = (int)CvANN_MLP::NO_INPUT_SCALE;
        bp::scope().attr("NO_OUTPUT_SCALE") = (int)CvANN_MLP::NO_OUTPUT_SCALE;
        { //::CvANN_MLP::clear
        
            typedef void ( ::CvANN_MLP::*clear_function_type )(  ) ;
            typedef void ( CvANN_MLP_wrapper::*default_clear_function_type )(  ) ;
            
            CvANN_MLP_exposer.def( 
                "clear"
                , clear_function_type(&::CvANN_MLP::clear)
                , default_clear_function_type(&CvANN_MLP_wrapper::default_clear) );
        
        }
        { //::CvANN_MLP::create
        
            typedef void ( ::CvANN_MLP::*create_function_type )( ::cv::Mat const &,int,double,double ) ;
            typedef void ( CvANN_MLP_wrapper::*default_create_function_type )( ::cv::Mat const &,int,double,double ) ;
            
            CvANN_MLP_exposer.def( 
                "create"
                , create_function_type(&::CvANN_MLP::create)
                , default_create_function_type(&CvANN_MLP_wrapper::default_create)
                , ( bp::arg("_layer_sizes"), bp::arg("_activ_func")=int(::CvANN_MLP::SIGMOID_SYM), bp::arg("_f_param1")=0, bp::arg("_f_param2")=0 ) );
        
        }
        { //::CvANN_MLP::get_layer_count
        
            typedef int ( ::CvANN_MLP::*get_layer_count_function_type )(  ) ;
            
            CvANN_MLP_exposer.def( 
                "get_layer_count"
                , get_layer_count_function_type( &::CvANN_MLP::get_layer_count ) );
        
        }
        { //::CvANN_MLP::predict
        
            typedef float ( ::CvANN_MLP::*predict_function_type )( ::cv::Mat const &,::cv::Mat & ) const;
            typedef float ( CvANN_MLP_wrapper::*default_predict_function_type )( ::cv::Mat const &,::cv::Mat & ) const;
            
            CvANN_MLP_exposer.def( 
                "predict"
                , predict_function_type(&::CvANN_MLP::predict)
                , default_predict_function_type(&CvANN_MLP_wrapper::default_predict)
                , ( bp::arg("_inputs"), bp::arg("_outputs") ) );
        
        }
        { //::CvANN_MLP::read
        
            typedef void ( *default_read_function_type )( ::CvANN_MLP &,::cv::FileStorage &,::cv::FileNode & );
            
            CvANN_MLP_exposer.def( 
                "read"
                , default_read_function_type( &CvANN_MLP_wrapper::default_read )
                , ( bp::arg("inst"), bp::arg("fs"), bp::arg("node") )
                , "\nArgument 'fs', of C++ type '::CvFileStorage *', is a FileStorage."\
    "\nArgument 'node', of C++ type '::CvFileNode *', is a FileNode." );
        
        }
        { //::CvANN_MLP::train
        
            typedef int ( ::CvANN_MLP::*train_function_type )( ::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::CvANN_MLP_TrainParams,int ) ;
            typedef int ( CvANN_MLP_wrapper::*default_train_function_type )( ::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::CvANN_MLP_TrainParams,int ) ;
            
            CvANN_MLP_exposer.def( 
                "train"
                , train_function_type(&::CvANN_MLP::train)
                , default_train_function_type(&CvANN_MLP_wrapper::default_train)
                , ( bp::arg("_inputs"), bp::arg("_outputs"), bp::arg("_sample_weights"), bp::arg("_sample_idx")=cv::Mat(), bp::arg("_params")=::CvANN_MLP_TrainParams( ), bp::arg("flags")=(int)(0) ) );
        
        }
        { //::CvANN_MLP::write
        
            typedef void ( *default_write_function_type )( ::CvANN_MLP const &,::cv::FileStorage &,char const * );
            
            CvANN_MLP_exposer.def( 
                "write"
                , default_write_function_type( &CvANN_MLP_wrapper::default_write )
                , ( bp::arg("inst"), bp::arg("storage"), bp::arg("name") )
                , "\nArgument 'storage', of C++ type '::CvFileStorage *', is a FileStorage." );
        
        }
        { //::CvStatModel::load
        
            typedef void ( ::CvStatModel::*load_function_type )( char const *,char const * ) ;
            typedef void ( CvANN_MLP_wrapper::*default_load_function_type )( char const *,char const * ) ;
            
            CvANN_MLP_exposer.def( 
                "load"
                , load_function_type(&::CvStatModel::load)
                , default_load_function_type(&CvANN_MLP_wrapper::default_load)
                , ( bp::arg("filename"), bp::arg("name")=bp::object() ) );
        
        }
        { //::CvStatModel::save
        
            typedef void ( ::CvStatModel::*save_function_type )( char const *,char const * ) const;
            typedef void ( CvANN_MLP_wrapper::*default_save_function_type )( char const *,char const * ) const;
            
            CvANN_MLP_exposer.def( 
                "save"
                , save_function_type(&::CvStatModel::save)
                , default_save_function_type(&CvANN_MLP_wrapper::default_save)
                , ( bp::arg("filename"), bp::arg("name")=bp::object() ) );
        
        }
        CvANN_MLP_exposer.def( bp::init< cv::Mat const &, bp::optional< int, double, double > >(( bp::arg("_layer_sizes"), bp::arg("_activ_func")=int(::CvANN_MLP::SIGMOID_SYM), bp::arg("_f_param1")=0, bp::arg("_f_param2")=0 )) );
    }

}