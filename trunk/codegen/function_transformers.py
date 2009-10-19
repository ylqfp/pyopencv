#!/usr/bin/env python
# pyopencv - A Python wrapper for OpenCV 2.0 using Boost.Python and ctypes

# Copyright (c) 2009, Minh-Tri Pham
# All rights reserved.

# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

#    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
#    * Neither the name of pyopencv's copyright holders nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# For further inquiries, please contact Minh-Tri Pham at pmtri80@gmail.com.
# ----------------------------------------------------------------------------


from pygccxml import declarations as _D
from pyplusplus import code_repository
from pyplusplus.function_transformers import *
import pyplusplus.function_transformers.transformers as _T
from pyplusplus.decl_wrappers import call_policies as CP


def expose_func(func, ownershiplevel=None, ward_indices=(), return_arg_index=None, return_pointee=True, transformer_creators=[]):
    
    func.include()    
    func._transformer_creators.extend(transformer_creators)
    
    cp = CP.return_value_policy(CP.reference_existing_object) if return_pointee is True else None
    
    if return_arg_index is None:
        for ward_index in ward_indices:
            cp = CP.with_custodian_and_ward_postcall(0, ward_index, cp)
    else:
        cp = CP.return_arg(return_arg_index) # ignore previous settings
        for ward_index in ward_indices:
            cp = CP.with_custodian_and_ward(return_arg_index, ward_index, cp)
            
    if ownershiplevel is not None:
        cp = with_ownershiplevel_postcall(ownershiplevel, cp)
        
    if cp is not None:
        func.call_policies = cp
        
    

# -----------------------------------------------------------------------------------------------
# Call policies
# -----------------------------------------------------------------------------------------------

class with_ownershiplevel_postcall_t( CP.compound_policy_t ):
    """implements code generation for boost::python::with_ownershiplevel_postcall call policies"""
    def __init__( self, value=0, base=None):
        CP.compound_policy_t.__init__( self, base )
        self._value = value

    def _get_value( self ):
        return self._value
    def _set_value( self, new_value):
        self._value = new_value
    value = property( _get_value, _set_value )

    def _get_name(self, function_creator):
        return '::boost::python::with_ownershiplevel_postcall'

    def _get_args(self, function_creator):
        return [ str( self.value ) ]

    @property
    def header_file(self):
        """return a name of the header file the call policy is defined in"""
        return "with_ownershiplevel_postcall.hpp"

def with_ownershiplevel_postcall( arg_value=0, base=None):
    """create boost::python::with_ownershiplevel_postcall call policies code generator"""
    return with_ownershiplevel_postcall_t( arg_value, base )







def add_underscore(decl):
    decl.rename('_'+decl.name)
    decl.include()

def expose_addressof_member(klass, member_name, exclude_member=True):
    klass.include_files.append( "boost/python/long.hpp" )
    if exclude_member:
        klass.var(member_name).exclude()
    klass.add_declaration_code('''
    boost::python::long_ get_MEMBER_NAME_addr( CLASS_TYPE const & inst ){
        return boost::python::long_((int)&inst.MEMBER_NAME);
    }
    '''.replace("MEMBER_NAME", member_name).replace("CLASS_TYPE", klass.decl_string))
    klass.add_registration_code('def( "get_MEMBER_NAME_addr", &::get_MEMBER_NAME_addr )'.replace("MEMBER_NAME", member_name))
    # TODO: finish the wrapping with ctypes code
    
def expose_member_as_str(klass, member_name):
    klass.include_files.append( "boost/python/object.hpp" )
    klass.include_files.append( "boost/python/str.hpp" )
    klass.var(member_name).exclude()
    klass.add_wrapper_code('''
    static bp::object get_MEMBER_NAME( CLASS_TYPE const & inst ){        
        return inst.MEMBER_NAME? bp::str(inst.MEMBER_NAME): bp::object();
    }
    '''.replace("MEMBER_NAME", member_name).replace("CLASS_TYPE", klass.decl_string))
    klass.add_registration_code('''
    add_property( "MEMBER_NAME", bp::make_function(&CLASS_TYPE_wrapper::get_MEMBER_NAME) )
    '''.replace("MEMBER_NAME", member_name).replace("CLASS_TYPE", klass.decl_string))
    
def expose_member_as_pointee(klass, member_name):
    klass.include_files.append( "boost/python/object.hpp" )
    klass.var(member_name).exclude()
    klass.add_wrapper_code('''
    static bp::object get_MEMBER_NAME( CLASS_TYPE const & inst ){        
        return inst.MEMBER_NAME? bp::object(inst.MEMBER_NAME): bp::object();
    }
    '''.replace("MEMBER_NAME", member_name).replace("CLASS_TYPE", klass.decl_string))
    klass.add_registration_code('''
    add_property( "MEMBER_NAME", bp::make_function(&CLASS_TYPE_wrapper::get_MEMBER_NAME) )
    '''.replace("MEMBER_NAME", member_name).replace("CLASS_TYPE", klass.decl_string))
    
def expose_member_as_array_of_pointees(klass, member_name, array_size):
    klass.include_files.append( "boost/python/object.hpp")
    klass.include_files.append( "boost/python/list.hpp")
    klass.include_files.append( "boost/python/tuple.hpp")
    klass.var(member_name).exclude()
    klass.add_wrapper_code('''
    static bp::object get_MEMBER_NAME( CLASS_TYPE const & inst ){
        bp::list l;
        for(int i = 0; i < ARRAY_SIZE; ++i)
            l.append(inst.MEMBER_NAME[i]);
        return bp::tuple(l);
    }
    '''.replace("MEMBER_NAME", member_name) \
        .replace("CLASS_TYPE", klass.decl_string) \
        .replace("ARRAY_SIZE", str(array_size)))
    klass.add_registration_code('''
    add_property( "MEMBER_NAME", bp::make_function(&CLASS_TYPE_wrapper::get_MEMBER_NAME) )
    '''.replace("MEMBER_NAME", member_name).replace("CLASS_TYPE", klass.decl_string))
    

def remove_ptr( type_ ):
    if _D.is_pointer( type_ ):
        return _D.remove_pointer( type_ )
    else:
        raise TypeError( 'Type should be a pointer, got %s.' % type_ )


# -----------------------------------------------------------------------------------------------
# Function transfomers
# -----------------------------------------------------------------------------------------------

# input_double_pointee_t
class input_double_pointee_t(transformer_t):
    """Handles a double pointee input.
    
    Convert by dereferencing: do_smth(your_type **v) -> do_smth(your_type v)

    Right now compiler should be able to use implicit conversion
    """

    def __init__(self, function, arg_ref):
        transformer.transformer_t.__init__( self, function )
        self.arg = self.get_argument( arg_ref )
        self.arg_index = self.function.arguments.index( self.arg )
        if not _D.is_pointer( self.arg.type ):
            raise ValueError( '%s\nin order to use "input_double_pointee_t" transformation, argument %s type must be a pointer or a array (got %s).' ) \
                  % ( function, self.arg_ref.name, arg.type)

    def __str__(self):
        return "input_double_pointee(%s)" % self.arg.name

    def __configure_sealed( self, controller ):
        w_arg = controller.find_wrapper_arg( self.arg.name )
        tmp_type = remove_ptr( self.arg.type )
        w_arg.type = remove_ptr( tmp_type )
        if not _D.is_convertible( w_arg.type, self.arg.type ):
            controller.add_pre_call_code("%s tmp_%s = reinterpret_cast< %s >(& %s);" % ( tmp_type, w_arg.name, tmp_type, w_arg.name ))
            casting_code = 'reinterpret_cast< %s >( & tmp_%s )' % (self.arg.type, w_arg.name)
            controller.modify_arg_expression(self.arg_index, casting_code)

    def __configure_v_mem_fun_default( self, controller ):
        self.__configure_sealed( controller )

    def configure_mem_fun( self, controller ):
        self.__configure_sealed( controller )

    def configure_free_fun(self, controller ):
        self.__configure_sealed( controller )

    def configure_virtual_mem_fun( self, controller ):
        self.__configure_v_mem_fun_default( controller.default_controller )

    def required_headers( self ):
        """Returns list of header files that transformer generated code depends on."""
        return []

def input_double_pointee( *args, **keywd ):
    def creator( function ):
        return input_double_pointee_t( function, *args, **keywd )
    return creator

# input_smart_pointee_t
class input_smart_pointee_t(transformer_t):
    """Handles a pointee input.
    
    Convert by dereferencing: do_smth(your_type *v) -> do_smth(object v2)
    where v2 is either of type NoneType or type 'your_type'. 
    If v2 is None, v is NULL.  Otherwise, v is the pointer to v2.
    """

    def __init__(self, function, arg_ref):
        transformer_t.__init__( self, function )
        self.arg = self.get_argument( arg_ref )
        self.arg_index = self.function.arguments.index( self.arg )

    def __str__(self):
        return "input_smart_pointee(%s)" % self.arg.name

    def required_headers( self ):
        """Returns list of header files that transformer generated code depends on."""
        return [ "boost/python/object.hpp", "boost/python/extract.hpp" ]

    def __configure_sealed( self, controller ):
        w_arg = controller.find_wrapper_arg( self.arg.name )
        data_type = _D.remove_const(remove_ptr( self.arg.type ))
        w_arg.type = _D.dummy_type_t( "boost::python::object" )
        if self.arg.default_value == '0' or self.arg.default_value == 'NULL':
            w_arg.default_value = 'bp::object()'
        exp_code = "(ARGNAME.ptr() != Py_None)? (ARGTYPE)bp::extract< DATATYPE * >(ARGNAME): 0".replace("ARGNAME", self.arg.name) \
            .replace("ARGTYPE", self.arg.type.decl_string) \
            .replace("DATATYPE", data_type.decl_string)
        controller.modify_arg_expression(self.arg_index, exp_code)

    def __configure_v_mem_fun_default( self, controller ):
        self.__configure_sealed( controller )

    def configure_mem_fun( self, controller ):
        self.__configure_sealed( controller )

    def configure_free_fun(self, controller ):
        self.__configure_sealed( controller )

    def configure_virtual_mem_fun( self, controller ):
        self.__configure_v_mem_fun_default( controller.default_controller )

def input_smart_pointee( *args, **keywd ):
    def creator( function ):
        return input_smart_pointee_t( function, *args, **keywd )
    return creator
    
# input_string_t
class input_string_t(transformer_t):
    """Handles a string.
    
    Convert: do_smth(void *v) -> do_smth(str v2)
    where v2 is a Python string and v is a pointer to its content.
    If vs is None, then v is NULL.
    """

    def __init__(self, function, arg_ref):
        transformer_t.__init__( self, function )
        self.arg = self.get_argument( arg_ref )
        self.arg_index = self.function.arguments.index( self.arg )
        if not _D.is_pointer( self.arg.type ):
            raise ValueError( '%s\nin order to use "input_string_t" transformation, argument %s type must be a pointer (got %s).' ) \
                  % ( function, arg_ref, self.arg.type)

    def __str__(self):
        return "input_string(%s)" % self.arg.name

    def required_headers( self ):
        """Returns list of header files that transformer generated code depends on."""
        return [ "boost/python/str.hpp", "boost/python/object.hpp", "boost/python/extract.hpp" ]

    def __configure_sealed( self, controller ):
        w_arg = controller.find_wrapper_arg( self.arg.name )
        w_arg.type = _D.dummy_type_t( "const char *" )
        controller.modify_arg_expression(self.arg_index, "((%s) %s)" % (self.arg.type, w_arg.name))

    def __configure_v_mem_fun_default( self, controller ):
        self.__configure_sealed( controller )

    def configure_mem_fun( self, controller ):
        self.__configure_sealed( controller )

    def configure_free_fun(self, controller ):
        self.__configure_sealed( controller )

    def configure_virtual_mem_fun( self, controller ):
        self.__configure_v_mem_fun_default( controller.default_controller )

def input_string( *args, **keywd ):
    def creator( function ):
        return input_string_t( function, *args, **keywd )
    return creator

    
class input_dynamic_array_t(transformer.transformer_t):
    """Handles an input array with a dynamic size.

    void do_something([int N, ]double* v) ->  do_something(object v2)

    where v2 is a Python sequence of N items. Each item is of the same type as v's element type.
    """

    def __init__(self, function, arg_ref, arg_size_ref=None, remove_arg_size=True):
        transformer.transformer_t.__init__( self, function )

        self.arg = self.get_argument( arg_ref )
        self.arg_index = self.function.arguments.index( self.arg )

        if not _T.is_ptr_or_array( self.arg.type ):
            raise ValueError( '%s\nin order to use "input_dynamic_array" transformation, argument %s type must be a array or a pointer (got %s).' ) \
                  % ( function, self.arg.name, self.arg.type)

        if arg_size_ref is not None:
            self.arg_size = self.get_argument( arg_size_ref )
            self.arg_size_index = self.function.arguments.index( self.arg_size )
            
            if not _D.is_integral( self.arg_size.type ):
                raise ValueError( '%s\nin order to use "input_dynamic_array" transformation, argument %s type must be an integer (got %s).' ) \
                      % ( function, self.arg_size.name, self.arg_size.type)

        else:
            self.arg_size = None

        self.array_item_type = _D.remove_const( _D.array_item_type( self.arg.type ) )
        self.remove_arg_size = remove_arg_size

    def __str__(self):
        if self.arg_size is not None:
            return "input_dynamic_array(%s,%s)"%( self.arg.name, self.arg_size.name)
        return "input_dynamic_array(%s)"% self.arg.name

    def required_headers( self ):
        """Returns list of header files that transformer generated code depends on."""
        return [ code_repository.convenience.file_name ]

    def __configure_sealed(self, controller):
        w_arg = controller.find_wrapper_arg( self.arg.name )
        w_arg.type = _D.dummy_type_t( "boost::python::object" )

        if self.remove_arg_size and self.arg_size is not None:
            #removing arg_size from the function wrapper definition
            controller.remove_wrapper_arg( self.arg_size.name )
        
        # array size
        array_size = controller.declare_variable( "int", "size_" + self.arg.name, 
            "=bp::len(%s)" % self.arg.name)

        # Declare a variable that will hold the C array...
        native_array = controller.declare_variable( _D.pointer_t(self.array_item_type), 
            "native_" + self.arg.name, 
            "= new %s [%s]" % (self.array_item_type, array_size) )
            
        controller.add_post_call_code("delete[] %s;" % native_array)

        copy_pylist2arr = _T._seq2arr.substitute( type=self.array_item_type
                                                , pylist=w_arg.name
                                                , array_size=array_size
                                                , native_array=native_array )

        controller.add_pre_call_code( copy_pylist2arr )

        controller.modify_arg_expression( self.arg_index, native_array )
        if self.remove_arg_size and self.arg_size is not None:
            controller.modify_arg_expression( self.arg_size_index, array_size )

    def __configure_v_mem_fun_default( self, controller ):
        self.__configure_sealed( controller )

    def configure_mem_fun( self, controller ):
        self.__configure_sealed( controller )

    def configure_free_fun(self, controller ):
        self.__configure_sealed( controller )

    def configure_virtual_mem_fun( self, controller ):
        self.__configure_v_mem_fun_default( controller.default_controller )

def input_dynamic_array( *args, **keywd ):
    def creator( function ):
        return input_dynamic_array_t( function, *args, **keywd )
    return creator


class input_dynamic_array_of_pointers_t(transformer.transformer_t):
    """Handles an input array with a dynamic size.

    void do_something([int N, ]double** v) ->  do_something(object v2)

    where v2 is a Python sequence of N items. Each item is of the same type as v's element pointee type.
    """

    def __init__(self, function, arg_ref, arg_size_ref=None):
        transformer.transformer_t.__init__( self, function )

        self.arg = self.get_argument( arg_ref )
        self.arg_index = self.function.arguments.index( self.arg )

        if not _T.is_ptr_or_array( self.arg.type ) or not _T.is_ptr_or_array(remove_ptr(self.arg.type)):
            raise ValueError( '%s\nin order to use "input_dynamic_array_of_pointers" transformation, argument %s type must be a array of pointers or a double pointer (got %s).' ) \
                  % ( function, self.arg.name, self.arg.type)

        if arg_size_ref is not None:
            self.arg_size = self.get_argument( arg_size_ref )
            self.arg_size_index = self.function.arguments.index( self.arg_size )
            
            if not _D.is_integral( self.arg_size.type ):
                raise ValueError( '%s\nin order to use "input_dynamic_array_of_pointers" transformation, argument %s type must be an integer (got %s).' ) \
                      % ( function, self.arg_size.name, self.arg_size.type)

        else:
            self.arg_size = None

        self.array_item_type = _D.remove_const( _D.array_item_type( self.arg.type ) )
        self.array_item_pointee_type = _D.remove_const( _D.remove_pointer( self.array_item_type ) )

    def __str__(self):
        if self.arg_size is not None:
            return "input_dynamic_array_of_pointers(%s,%s)"%( self.arg.name, self.arg_size.name)
        return "input_dynamic_array_of_pointers(%s)"% self.arg.name

    def required_headers( self ):
        """Returns list of header files that transformer generated code depends on."""
        return [ code_repository.convenience.file_name ]

    def __configure_sealed(self, controller):
        w_arg = controller.find_wrapper_arg( self.arg.name )
        w_arg.type = _D.dummy_type_t( "boost::python::object" )

        if self.arg_size is not None:
            #removing arg_size from the function wrapper definition
            controller.remove_wrapper_arg( self.arg_size.name )
        
        # array size
        array_size = controller.declare_variable( "int", "size_" + self.arg.name, 
            "=bp::len(%s)" % self.arg.name)
            
        array_item_type = "item_of_%s_t" % self.arg.name
        native_array = "native_%s" % self.arg.name
        iter_array = "iter_%s" % self.arg.name
            
        # Declare a variable that will hold the C array...
        precall_code = """typedef S_ITEM_TYPE ARRAY_ITEM_TYPE;
    ARRAY_ITEM_TYPE *NATIVE_ARRAY = new ARRAY_ITEM_TYPE [ARRAY_SIZE];
    for(int ITER_ARRAY = 0; ITER_ARRAY < ARRAY_SIZE; ++ITER_ARRAY)
        NATIVE_ARRAY[ITER_ARRAY] = (ARRAY_ITEM_TYPE)(bp::extract< ARRAY_ITEM_POINTEE_TYPE * >(PARRAY[ITER_ARRAY]));
    """.replace("S_ITEM_TYPE", self.array_item_type.decl_string) \
            .replace("ARRAY_ITEM_TYPE", array_item_type) \
            .replace("ARRAY_ITEM_POINTEE_TYPE", self.array_item_pointee_type.decl_string) \
            .replace("NATIVE_ARRAY", native_array) \
            .replace("ITER_ARRAY", iter_array) \
            .replace("ARRAY_SIZE", array_size) \
            .replace("PARRAY", self.arg.name)
        
        controller.add_pre_call_code(precall_code)
            
        controller.add_post_call_code("delete[] %s;" % native_array)
        
        controller.modify_arg_expression( self.arg_index, native_array )
        if self.arg_size is not None:
            controller.modify_arg_expression( self.arg_size_index, array_size )

    def __configure_v_mem_fun_default( self, controller ):
        self.__configure_sealed( controller )

    def configure_mem_fun( self, controller ):
        self.__configure_sealed( controller )

    def configure_free_fun(self, controller ):
        self.__configure_sealed( controller )

    def configure_virtual_mem_fun( self, controller ):
        self.__configure_v_mem_fun_default( controller.default_controller )

def input_dynamic_array_of_pointers( *args, **keywd ):
    def creator( function ):
        return input_dynamic_array_of_pointers_t( function, *args, **keywd )
    return creator

    
class input_dynamic_double_array_t(transformer.transformer_t):
    """Handles an input array with a dynamic size.

    void do_something([[int N, ]int *ncnts, ]double** v) ->  do_something(object v2)

    where v2 is a Python sequence of sequences of items. Each item is of the same type as v's element type.
    """

    def __init__(self, function, arg_ref, arg_ncnts_ref=None, arg_size_ref=None, remove_arg_ncnts=True, remove_arg_size=True):
        transformer.transformer_t.__init__( self, function )

        self.arg = self.get_argument( arg_ref )
        self.arg_index = self.function.arguments.index( self.arg )

        if not _T.is_ptr_or_array( self.arg.type ) or not _T.is_ptr_or_array(remove_ptr(self.arg.type)):
            raise ValueError( '%s\nin order to use "input_dynamic_double_array" transformation, argument %s type must be a double array or a double pointer (got %s).' ) \
                  % ( function, self.arg.name, self.arg.type)
                  
        if arg_ncnts_ref is not None:
            self.arg_ncnts = self.get_argument( arg_ncnts_ref )
            self.arg_ncnts_index = self.function.arguments.index( self.arg_ncnts )
            
            if not _T.is_ptr_or_array(self.arg_ncnts.type) or not _D.is_integral( remove_ptr(self.arg_ncnts.type) ):
                raise ValueError( '%s\nin order to use "input_dynamic_double_array" transformation, argument %s type must be an integer array (got %s).' ) \
                      % ( function, self.arg_ncnts.name, self.arg_ncnts.type)

        else:
            self.arg_ncnts = None
        self.remove_arg_ncnts = remove_arg_ncnts

        if arg_size_ref is not None:
            self.arg_size = self.get_argument( arg_size_ref )
            self.arg_size_index = self.function.arguments.index( self.arg_size )
            
            if not _D.is_integral( self.arg_size.type ):
                raise ValueError( '%s\nin order to use "input_dynamic_double_array" transformation, argument %s type must be an integer (got %s).' ) \
                      % ( function, self.arg_size.name, self.arg_size.type)

        else:
            self.arg_size = None
        self.remove_arg_size = remove_arg_size

        self.array_item_type = _D.remove_const( _D.array_item_type( _D.array_item_type( self.arg.type ) ) )

    def __str__(self):
        return "input_dynamic_double_array(%s)"% (self.arg.name,
            "None" if self.arg_ncnts is None else self.arg_ncnts.name,
            "None" if self.arg_sizes is None else self.arg_sizes.name,
            )

    def required_headers( self ):
        """Returns list of header files that transformer generated code depends on."""
        return [ code_repository.convenience.file_name ]

    def __configure_sealed(self, controller):
        w_arg = controller.find_wrapper_arg( self.arg.name )
        w_arg.type = _D.dummy_type_t( "boost::python::object" )

        if self.remove_arg_size and self.arg_size is not None:
            #removing arg_size from the function wrapper definition
            controller.remove_wrapper_arg( self.arg_size.name )
            
        if self.remove_arg_ncnts and self.arg_ncnts is not None:
            #removing arg_ncnts from the function wrapper definition
            controller.remove_wrapper_arg( self.arg_ncnts.name )
        
        # precall_code
        precall_code = """typedef ITEM_TYPE *LP_ARRAY;
    int i_ARRAY, j_ARRAY, n0_ARRAY = bp::len(ARRAY);
    int *n1_ARRAY = new int [n0_ARRAY];
    LP_ARRAY *buf_ARRAY = new LP_ARRAY [n0_ARRAY];
    for(i_ARRAY = 0; i_ARRAY < n0_ARRAY; ++i_ARRAY)
    {
        bp::object const &obj_ARRAY = ARRAY[i_ARRAY];
        n1_ARRAY[i_ARRAY] = bp::len(obj_ARRAY);
        buf_ARRAY[i_ARRAY] = new ITEM_TYPE [n1_ARRAY[i_ARRAY]];
        for(j_ARRAY = 0; j_ARRAY < n1_ARRAY[i_ARRAY]; ++j_ARRAY)
            buf_ARRAY[i_ARRAY][j_ARRAY] = bp::extract< ITEM_TYPE const & > ( obj_ARRAY[j_ARRAY] );
    }
        """.replace("ARRAY", self.arg.name) \
            .replace("ITEM_TYPE", self.array_item_type.decl_string)
        controller.add_pre_call_code(precall_code)
        
        # postcall_code
        postcall_code = """for(i_ARRAY = 0; i_ARRAY < n0_ARRAY; ++i_ARRAY) delete[] buf_ARRAY[i_ARRAY];
    delete[] n1_ARRAY;
    delete[] buf_ARRAY;
        """.replace("ARRAY", self.arg.name)
        controller.add_post_call_code(postcall_code)
        

        controller.modify_arg_expression( self.arg_index, "buf_"+self.arg.name )
        
        if self.remove_arg_ncnts and self.arg_ncnts is not None:
            controller.modify_arg_expression( self.arg_ncnts_index, "n1_"+self.arg.name )

        if self.remove_arg_size and self.arg_size is not None:
            controller.modify_arg_expression( self.arg_size_index, "n0_"+self.arg.name )

    def __configure_v_mem_fun_default( self, controller ):
        self.__configure_sealed( controller )

    def configure_mem_fun( self, controller ):
        self.__configure_sealed( controller )

    def configure_free_fun(self, controller ):
        self.__configure_sealed( controller )

    def configure_virtual_mem_fun( self, controller ):
        self.__configure_v_mem_fun_default( controller.default_controller )

def input_dynamic_double_array( *args, **keywd ):
    def creator( function ):
        return input_dynamic_double_array_t( function, *args, **keywd )
    return creator


