// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__array_1.pypp.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "cxtypes_h_wrapper.hpp"
#include "boost/python/object.hpp"
#include "boost/python/str.hpp"
#include "boost/python/list.hpp"
#include "boost/python/tuple.hpp"
#include "cxtypes_h_ext_classes_2.pypp.hpp"

namespace bp = boost::python;

struct CvAttrList_wrapper : CvAttrList, bp::wrapper< CvAttrList > {

    CvAttrList_wrapper(CvAttrList const & arg )
    : CvAttrList( arg )
      , bp::wrapper< CvAttrList >(){
        // copy constructor
        
    }

    CvAttrList_wrapper()
    : CvAttrList()
      , bp::wrapper< CvAttrList >(){
        // null constructor
        
    }

    static CvAttrList * get_next(CvAttrList const & inst ){
        return inst.next;
    }
    
    static void set_next( CvAttrList & inst, CvAttrList * new_value ){ 
        inst.next = new_value;
    }

    static bp::object get_attr( CvString const & inst ){
    if(!inst.ptr) return bp::object();
    bp::list l;
    for(int i = 0; inst.ptr[i]; ++i) l.append(inst.ptr[i]);
    return bp::tuple(l);
}

};

static CvSeq * get_CvChain_h_prev( CvChain const & inst ) { return inst.h_prev; }

static CvSeq * get_CvChain_h_next( CvChain const & inst ) { return inst.h_next; }

static CvSeq * get_CvChain_v_prev( CvChain const & inst ) { return inst.v_prev; }

static CvSeq * get_CvChain_v_next( CvChain const & inst ) { return inst.v_next; }

static ::CvSeqBlock * get_CvChain_free_blocks( CvChain const & inst ) { return inst.free_blocks; }

static ::CvSeqBlock * get_CvChain_first( CvChain const & inst ) { return inst.first; }

static bp::object get_CvChain_block_max( CvChain const & inst ){        
    return inst.block_max? bp::str(inst.block_max): bp::object();
}

static bp::object get_CvChain_ptr( CvChain const & inst ){        
    return inst.ptr? bp::str(inst.ptr): bp::object();
}

static cv::MemStorage get_CvChain_storage(CvChain const &inst) { return cv::MemStorage(inst.storage); }

static cv::Point_<int> *get_CvChain_origin(CvChain const &inst) { return (cv::Point_<int> *)(&inst.origin); }

struct CvContour_wrapper : CvContour, bp::wrapper< CvContour > {

    CvContour_wrapper(CvContour const & arg )
    : CvContour( arg )
      , bp::wrapper< CvContour >(){
        // copy constructor
        
    }

    CvContour_wrapper()
    : CvContour()
      , bp::wrapper< CvContour >(){
        // null constructor
        
    }

    static pyplusplus::containers::static_sized::array_1_t< int, 3>
    pyplusplus_reserved_wrapper( CvContour & inst ){
        return pyplusplus::containers::static_sized::array_1_t< int, 3>( inst.reserved );
    }

};

static CvSeq * get_CvContour_h_prev( CvContour const & inst ) { return inst.h_prev; }

static CvSeq * get_CvContour_h_next( CvContour const & inst ) { return inst.h_next; }

static CvSeq * get_CvContour_v_prev( CvContour const & inst ) { return inst.v_prev; }

static CvSeq * get_CvContour_v_next( CvContour const & inst ) { return inst.v_next; }

static ::CvSeqBlock * get_CvContour_free_blocks( CvContour const & inst ) { return inst.free_blocks; }

static ::CvSeqBlock * get_CvContour_first( CvContour const & inst ) { return inst.first; }

static bp::object get_CvContour_block_max( CvContour const & inst ){        
    return inst.block_max? bp::str(inst.block_max): bp::object();
}

static bp::object get_CvContour_ptr( CvContour const & inst ){        
    return inst.ptr? bp::str(inst.ptr): bp::object();
}

static cv::MemStorage get_CvContour_storage(CvContour const &inst) { return cv::MemStorage(inst.storage); }

static cv::Rect_<int> *get_CvContour_rect(CvContour const &inst) { return (cv::Rect_<int> *)(&inst.rect); }

static CvSeq * get_CvGraph_h_prev( CvGraph const & inst ) { return inst.h_prev; }

static CvSeq * get_CvGraph_h_next( CvGraph const & inst ) { return inst.h_next; }

static CvSeq * get_CvGraph_v_prev( CvGraph const & inst ) { return inst.v_prev; }

static CvSeq * get_CvGraph_v_next( CvGraph const & inst ) { return inst.v_next; }

static ::CvSeqBlock * get_CvGraph_free_blocks( CvGraph const & inst ) { return inst.free_blocks; }

static ::CvSeqBlock * get_CvGraph_first( CvGraph const & inst ) { return inst.first; }

static bp::object get_CvGraph_block_max( CvGraph const & inst ){        
    return inst.block_max? bp::str(inst.block_max): bp::object();
}

static bp::object get_CvGraph_ptr( CvGraph const & inst ){        
    return inst.ptr? bp::str(inst.ptr): bp::object();
}

static ::CvSetElem * get_CvGraph_free_elems( CvGraph const & inst ) { return inst.free_elems; }

static ::CvSet * get_CvGraph_edges( CvGraph const & inst ) { return inst.edges; }

static cv::MemStorage get_CvGraph_storage(CvGraph const &inst) { return cv::MemStorage(inst.storage); }

static bp::object get_CvGraphEdge_next( CvGraphEdge const & inst ){
    bp::list l;
    for(int i = 0; i < 2; ++i)
        l.append(inst.next[i]);
    return bp::tuple(l);
}

static bp::object get_CvGraphEdge_vtx( CvGraphEdge const & inst ){
    bp::list l;
    for(int i = 0; i < 2; ++i)
        l.append(inst.vtx[i]);
    return bp::tuple(l);
}

static CvGraphEdge * get_CvGraphVtx_first( CvGraphVtx const & inst ) { return inst.first; }

static CvGraphEdge * get_CvGraphVtx2D_first( CvGraphVtx2D const & inst ) { return inst.first; }

static ::CvPoint2D32f * get_CvGraphVtx2D_ptr( CvGraphVtx2D const & inst ) { return inst.ptr; }

static bp::object get_data(CvMat const &inst)
{
    return bp::object(bp::handle<>(PyBuffer_FromReadWriteMemory(
        (void*)inst.data.ptr, inst.rows*inst.step)));
}

static CvMemBlock * get_CvMemBlock_prev( CvMemBlock const & inst ) { return inst.prev; }

static CvMemBlock * get_CvMemBlock_next( CvMemBlock const & inst ) { return inst.next; }

static ::CvMemBlock * get_CvMemStorage_bottom( CvMemStorage const & inst ) { return inst.bottom; }

static ::CvMemBlock * get_CvMemStorage_top( CvMemStorage const & inst ) { return inst.top; }

static cv::MemStorage get_CvMemStorage_parent(CvMemStorage const &inst) { return cv::MemStorage(inst.parent); }

static ::CvMemBlock * get_CvMemStoragePos_top( CvMemStoragePos const & inst ) { return inst.top; }

static CvModuleInfo * get_CvModuleInfo_next( CvModuleInfo const & inst ) { return inst.next; }

static ::CvPluginFuncInfo * get_CvModuleInfo_func_tab( CvModuleInfo const & inst ) { return inst.func_tab; }

static bp::object get_CvModuleInfo_name( CvModuleInfo const & inst ){        
    return inst.name? bp::str(inst.name): bp::object();
}

static bp::object get_CvModuleInfo_version( CvModuleInfo const & inst ){        
    return inst.version? bp::str(inst.version): bp::object();
}

struct CvPluginFuncInfo_wrapper : CvPluginFuncInfo, bp::wrapper< CvPluginFuncInfo > {

    CvPluginFuncInfo_wrapper(CvPluginFuncInfo const & arg )
    : CvPluginFuncInfo( arg )
      , bp::wrapper< CvPluginFuncInfo >(){
        // copy constructor
        
    }

    CvPluginFuncInfo_wrapper()
    : CvPluginFuncInfo()
      , bp::wrapper< CvPluginFuncInfo >(){
        // null constructor
        
    }

};

static bp::object get_CvPluginFuncInfo_func_names( CvPluginFuncInfo const & inst ){        
    return inst.func_names? bp::str(inst.func_names): bp::object();
}

void register_classes_2(){

    bp::class_< CvAttrList_wrapper >( "CvAttrList" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvAttrList >() )    
        .add_property( "next"
                    , bp::make_function( (::CvAttrList * (*)( ::CvAttrList const & ))(&CvAttrList_wrapper::get_next), bp::return_internal_reference< >() )
                    , bp::make_function( (void (*)( ::CvAttrList &,::CvAttrList * ))(&CvAttrList_wrapper::set_next), bp::with_custodian_and_ward_postcall< 1, 2 >() ) )    
        .add_property( "attr", bp::make_function(&CvAttrList_wrapper::get_attr) );

    bp::class_< CvChain >( "CvChain" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvChain >() )    
        .def_readwrite( "delta_elems", &CvChain::delta_elems )    
        .def_readwrite( "elem_size", &CvChain::elem_size )    
        .def_readwrite( "flags", &CvChain::flags )    
        .def_readwrite( "header_size", &CvChain::header_size )    
        .def_readwrite( "total", &CvChain::total )    
        .add_property( "h_prev", bp::make_function(&::get_CvChain_h_prev, bp::return_internal_reference<>()) )    
        .add_property( "h_next", bp::make_function(&::get_CvChain_h_next, bp::return_internal_reference<>()) )    
        .add_property( "v_prev", bp::make_function(&::get_CvChain_v_prev, bp::return_internal_reference<>()) )    
        .add_property( "v_next", bp::make_function(&::get_CvChain_v_next, bp::return_internal_reference<>()) )    
        .add_property( "free_blocks", bp::make_function(&::get_CvChain_free_blocks, bp::return_internal_reference<>()) )    
        .add_property( "first", bp::make_function(&::get_CvChain_first, bp::return_internal_reference<>()) )    
        .add_property( "block_max", &::get_CvChain_block_max )    
        .add_property( "ptr", &::get_CvChain_ptr )    
        .add_property( "storage", bp::make_function(&::get_CvChain_storage, bp::with_custodian_and_ward_postcall<0, 1>()) )    
        .add_property( "origin", bp::make_function(&::get_CvChain_origin, bp::return_internal_reference<>()) );

    { //::CvContour
        typedef bp::class_< CvContour_wrapper > CvContour_exposer_t;
        CvContour_exposer_t CvContour_exposer = CvContour_exposer_t( "CvContour" );
        bp::scope CvContour_scope( CvContour_exposer );
        CvContour_exposer.add_property( "this", pyplus_conv::make_addressof_inst_getter< CvContour >() );
        CvContour_exposer.def_readwrite( "color", &CvContour::color );
        CvContour_exposer.def_readwrite( "delta_elems", &CvContour::delta_elems );
        CvContour_exposer.def_readwrite( "elem_size", &CvContour::elem_size );
        CvContour_exposer.def_readwrite( "flags", &CvContour::flags );
        CvContour_exposer.def_readwrite( "header_size", &CvContour::header_size );
        pyplusplus::containers::static_sized::register_array_1< int, 3 >( "__array_1_int_3" );
        { //CvContour::reserved [variable], type=int[3]
        
            typedef pyplusplus::containers::static_sized::array_1_t< int, 3> ( *array_wrapper_creator )( CvContour & );
            
            CvContour_exposer.add_property( "reserved"
                , bp::make_function( array_wrapper_creator(&CvContour_wrapper::pyplusplus_reserved_wrapper)
                                    , bp::with_custodian_and_ward_postcall< 0, 1 >() ) );
        }
        CvContour_exposer.def_readwrite( "total", &CvContour::total );
        CvContour_exposer.add_property( "h_prev", bp::make_function(&::get_CvContour_h_prev, bp::return_internal_reference<>()) );
        CvContour_exposer.add_property( "h_next", bp::make_function(&::get_CvContour_h_next, bp::return_internal_reference<>()) );
        CvContour_exposer.add_property( "v_prev", bp::make_function(&::get_CvContour_v_prev, bp::return_internal_reference<>()) );
        CvContour_exposer.add_property( "v_next", bp::make_function(&::get_CvContour_v_next, bp::return_internal_reference<>()) );
        CvContour_exposer.add_property( "free_blocks", bp::make_function(&::get_CvContour_free_blocks, bp::return_internal_reference<>()) );
        CvContour_exposer.add_property( "first", bp::make_function(&::get_CvContour_first, bp::return_internal_reference<>()) );
        CvContour_exposer.add_property( "block_max", &::get_CvContour_block_max );
        CvContour_exposer.add_property( "ptr", &::get_CvContour_ptr );
        CvContour_exposer.add_property( "storage", bp::make_function(&::get_CvContour_storage, bp::with_custodian_and_ward_postcall<0, 1>()) );
        CvContour_exposer.add_property( "rect", bp::make_function(&::get_CvContour_rect, bp::return_internal_reference<>()) );
    }

    bp::class_< CvGenericHash >( "CvGenericHash" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvGenericHash >() );

    bp::class_< CvGraph >( "CvGraph" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvGraph >() )    
        .def_readwrite( "active_count", &CvGraph::active_count )    
        .def_readwrite( "delta_elems", &CvGraph::delta_elems )    
        .def_readwrite( "elem_size", &CvGraph::elem_size )    
        .def_readwrite( "flags", &CvGraph::flags )    
        .def_readwrite( "header_size", &CvGraph::header_size )    
        .def_readwrite( "total", &CvGraph::total )    
        .add_property( "h_prev", bp::make_function(&::get_CvGraph_h_prev, bp::return_internal_reference<>()) )    
        .add_property( "h_next", bp::make_function(&::get_CvGraph_h_next, bp::return_internal_reference<>()) )    
        .add_property( "v_prev", bp::make_function(&::get_CvGraph_v_prev, bp::return_internal_reference<>()) )    
        .add_property( "v_next", bp::make_function(&::get_CvGraph_v_next, bp::return_internal_reference<>()) )    
        .add_property( "free_blocks", bp::make_function(&::get_CvGraph_free_blocks, bp::return_internal_reference<>()) )    
        .add_property( "first", bp::make_function(&::get_CvGraph_first, bp::return_internal_reference<>()) )    
        .add_property( "block_max", &::get_CvGraph_block_max )    
        .add_property( "ptr", &::get_CvGraph_ptr )    
        .add_property( "free_elems", bp::make_function(&::get_CvGraph_free_elems, bp::return_internal_reference<>()) )    
        .add_property( "edges", bp::make_function(&::get_CvGraph_edges, bp::return_internal_reference<>()) )    
        .add_property( "storage", bp::make_function(&::get_CvGraph_storage, bp::with_custodian_and_ward_postcall<0, 1>()) );

    bp::class_< CvGraphEdge >( "CvGraphEdge" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvGraphEdge >() )    
        .def_readwrite( "flags", &CvGraphEdge::flags )    
        .def_readwrite( "weight", &CvGraphEdge::weight )    
        .add_property( "next", &::get_CvGraphEdge_next )    
        .add_property( "vtx", &::get_CvGraphEdge_vtx );

    bp::class_< CvGraphVtx >( "CvGraphVtx" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvGraphVtx >() )    
        .def_readwrite( "flags", &CvGraphVtx::flags )    
        .add_property( "first", bp::make_function(&::get_CvGraphVtx_first, bp::return_internal_reference<>()) );

    bp::class_< CvGraphVtx2D >( "CvGraphVtx2D" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvGraphVtx2D >() )    
        .def_readwrite( "flags", &CvGraphVtx2D::flags )    
        .add_property( "first", bp::make_function(&::get_CvGraphVtx2D_first, bp::return_internal_reference<>()) )    
        .add_property( "ptr", bp::make_function(&::get_CvGraphVtx2D_ptr, bp::return_internal_reference<>()) );

    bp::class_< CvMat >( "CvMat", "\nA multi-channel matrix."
    "\n"
    "\nWarning: This structure is obsolete. It exists only to support "
    "\nbackward compatibility. Please use class Mat instead."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/basic_structures.html#cvmat" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvMat >(), "\nA multi-channel matrix."
    "\n"
    "\nWarning: This structure is obsolete. It exists only to support "
    "\nbackward compatibility. Please use class Mat instead."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/basic_structures.html#cvmat" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvMat >() )    
        .def_readwrite( "cols", &CvMat::cols )    
        .def_readwrite( "width", &CvMat::width )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvMat >() )    
        .def_readwrite( "height", &CvMat::height )    
        .def_readwrite( "rows", &CvMat::rows )    
        .def_readwrite( "step", &CvMat::step )    
        .def_readwrite( "type", &CvMat::type )    
        .add_property("data", &::get_data);

    bp::class_< CvMemBlock >( "CvMemBlock" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvMemBlock >() )    
        .add_property( "prev", bp::make_function(&::get_CvMemBlock_prev, bp::return_internal_reference<>()) )    
        .add_property( "next", bp::make_function(&::get_CvMemBlock_next, bp::return_internal_reference<>()) );

    bp::class_< CvMemStorage >( "CvMemStorage" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvMemStorage >() )    
        .def_readwrite( "block_size", &CvMemStorage::block_size )    
        .def_readwrite( "free_space", &CvMemStorage::free_space )    
        .def_readwrite( "signature", &CvMemStorage::signature )    
        .add_property( "bottom", bp::make_function(&::get_CvMemStorage_bottom, bp::return_internal_reference<>()) )    
        .add_property( "top", bp::make_function(&::get_CvMemStorage_top, bp::return_internal_reference<>()) )    
        .add_property( "parent", bp::make_function(&::get_CvMemStorage_parent, bp::with_custodian_and_ward_postcall<0, 1>()) );

    bp::class_< CvMemStoragePos >( "CvMemStoragePos" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvMemStoragePos >() )    
        .def_readwrite( "free_space", &CvMemStoragePos::free_space )    
        .add_property( "top", bp::make_function(&::get_CvMemStoragePos_top, bp::return_internal_reference<>()) );

    bp::class_< CvModuleInfo >( "CvModuleInfo" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvModuleInfo >() )    
        .add_property( "next", bp::make_function(&::get_CvModuleInfo_next, bp::return_internal_reference<>()) )    
        .add_property( "func_tab", bp::make_function(&::get_CvModuleInfo_func_tab, bp::return_internal_reference<>()) )    
        .add_property( "name", &::get_CvModuleInfo_name )    
        .add_property( "version", &::get_CvModuleInfo_version );

    bp::class_< CvPluginFuncInfo_wrapper >( "CvPluginFuncInfo" )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< CvPluginFuncInfo >() )    
        .add_property( "default_func_addr"
                    , pyplus_conv::make_addressof_getter(&CvPluginFuncInfo::default_func_addr)
                    , pyplus_conv::make_address_setter(&CvPluginFuncInfo::default_func_addr) )    
        .add_property( "func_addr"
                    , pyplus_conv::make_addressof_getter(&CvPluginFuncInfo::func_addr)
                    , pyplus_conv::make_address_setter(&CvPluginFuncInfo::func_addr) )    
        .def_readwrite( "loaded_from", &CvPluginFuncInfo::loaded_from )    
        .def_readwrite( "search_modules", &CvPluginFuncInfo::search_modules )    
        .add_property( "func_names", &::get_CvPluginFuncInfo_func_names );

}
