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


import os
from pygccxml import declarations as D
from pyplusplus import module_builder, messages
import function_transformers as FT
from pyplusplus.module_builder import call_policies as CP

import cxerror_h
import cxtypes_h
import cxcore_h
import cvtypes_h
import cv_h
import cvcompat_h
import ml_h
import highgui_h

#Creating an instance of class that will help you to expose your declarations
mb = module_builder.module_builder_t(
    ["opencv.hpp",],
    gccxml_path=r"M:/utils/gccxml/bin/gccxml.exe",
    working_directory=r"M:/programming/mypackages/pyopencv/svn_workplace/trunk/codegen",
    include_paths=[
        r"M:/programming/mypackages/pyopencv/svn_workplace/trunk/codegen/opencv2_include",
        r"M:\programming\builders\MinGW\gcc\gcc-4.4.0-mingw\lib\gcc\mingw32\4.4.0\include\c++",
        r"M:\programming\builders\MinGW\gcc\gcc-4.4.0-mingw\lib\gcc\mingw32\4.4.0\include\c++\mingw32",
        r"M:\programming\builders\MinGW\gcc\gcc-4.4.0-mingw\lib\gcc\mingw32\4.4.0\include",
    ],
    define_symbols=[] )

cc = open('pyopencv/__init__.py', 'w')
cc.write('''#!/usr/bin/env python
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

from pyopencvext import *
import pyopencvext as _PE
import math as _Math
import ctypes as _CT


#=============================================================================
# cvver.h
#=============================================================================

CV_MAJOR_VERSION    = 2
CV_MINOR_VERSION    = 0
CV_SUBMINOR_VERSION = 0
CV_VERSION          = "2.0.0"




''')
mb.cc = cc

# -----------------------------------------------------------------------------------------------
# Modules related to writing to the __init__.py file
# -----------------------------------------------------------------------------------------------

def add_doc(self, decl, s):
    """Adds a string s to the docstring of declaration f"""
    self.cc.write('''
str = "    [pyopencv] STR"
if DECL.__doc__ is None:
    DECL.__doc__ = str
else:
    DECL.__doc__ += str
'''.replace("DECL", decl.alias).replace("STR", str(s)))
module_builder.module_builder_t.add_doc = add_doc

def insert_del_interface(self, class_name, del_func_name):
    """Insert an interface to delete the self instance"""
    self.cc.write('''
CLASS_NAME._ownershiplevel = 0

def _CLASS_NAME__del__(self):
    if self._ownershiplevel==1:
        DEL_FUNC_NAME(self)
CLASS_NAME.__del__ = _CLASS_NAME__del__
'''.replace("CLASS_NAME", class_name).replace("DEL_FUNC_NAME", del_func_name))
module_builder.module_builder_t.insert_del_interface = insert_del_interface

def init_class(self, z):
    """Initializes a class z"""
    z.include()
    funs = []
    try:
        funs.extend(z.mem_funs())
    except RuntimeError:
        pass
    try:
        funs.extend(z.operators())
    except RuntimeError:
        pass
    for fun in funs:
        fun._transformer_creators = []
    z._funs = funs
module_builder.module_builder_t.init_class = init_class


def is_arg_touched(f, arg_name):
    for tr in f._transformer_creators:
        if arg_name in tr.func_closure[1].cell_contents:
            return True
    return False


def beautify_func_list(self, func_list):
    # function argument int *sizes and int dims
    for f in func_list:
        for arg in f.arguments:
            if is_arg_touched(f, arg.name):
                continue
            if arg.name == 'sizes' and D.is_pointer(arg.type):
                for arg2 in f.arguments:
                    if arg2.name == 'dims' and D.is_integral(arg2.type):
                        f._transformer_creators.append(FT.input_dynamic_array('sizes', 'dims'))
                        break

    # function argument const CvPoint2D32f * src and const CvPoint2D32f * dst
    for f in func_list:
        for arg in f.arguments:
            if is_arg_touched(f, arg.name):
                continue
            if arg.name == 'src' and D.is_pointer(arg.type) and 'CvPoint2D32f' in arg.type.decl_string:
                for arg2 in f.arguments:
                    if arg2.name == 'dst' and D.is_pointer(arg2.type) and 'CvPoint2D32f' in arg2.type.decl_string:
                        f._transformer_creators.append(FT.input_dynamic_array('src'))
                        f._transformer_creators.append(FT.input_dynamic_array('dst'))
                        break

    #  argument 'void *data'
    for f in func_list:
        for arg in f.arguments:
            if is_arg_touched(f, arg.name):
                continue
            if arg.name == 'data' and D.is_void_pointer(arg.type):
                f._transformer_creators.append(FT.input_string(arg.name))
                if not f.ignore:
                    mb.add_doc(f, "'data' is represented by a string")

module_builder.module_builder_t.beautify_func_list = beautify_func_list

def finalize_class(self, z):
    """Finalizes a class z"""
    mb.beautify_func_list(z._funs)
module_builder.module_builder_t.finalize_class = finalize_class



#=============================================================================
# Initialization
#=============================================================================


#Well, don't you want to see what is going on?
# mb.print_declarations() -- too many declarations

# Disable every declarations first
mb.decls().exclude()

# disable some warnings
mb.decls().disable_warnings(messages.W1027, messages.W1025)

# expose 'this'
mb.classes().expose_this = True

# expose all enumerations
mb.enums().include()

# get the list of OpenCV functions
opencv_funs = mb.free_funs(lambda decl: decl.name.startswith('cv'))

# initialize list of transformer creators for each function
for z in opencv_funs:
    z._transformer_creators = []



#=============================================================================
# Wrappers for different headers
#=============================================================================

# cxerror.h
cxerror_h.generate_code(mb, cc, D, FT, CP)

# cxtypes.h
cxtypes_h.generate_code(mb, cc, D, FT, CP)

# cxcore.h
cxcore_h.generate_code(mb, cc, D, FT, CP)

# cvtypes.h
cvtypes_h.generate_code(mb, cc, D, FT, CP)

# cv.h
cv_h.generate_code(mb, cc, D, FT, CP)

# cvcompat.h
cvcompat_h.generate_code(mb, cc, D, FT, CP)

# ml.h
ml_h.generate_code(mb, cc, D, FT, CP)

# highgui.h
highgui_h.generate_code(mb, cc, D, FT, CP)




#=============================================================================
# Rules for free functions and member functions
#=============================================================================


mb.beautify_func_list(opencv_funs)


#=============================================================================
# Final tasks
#=============================================================================

for z in ('hdr_refcount', 'refcount'): # too low-level
    mb.decls(z).exclude()

# apply all the function transformations
for z in opencv_funs:
    if len(z._transformer_creators) > 0:
        z.add_transformation(*z._transformer_creators)


for z in ('IPL_', 'CV_'):
    try:
        mb.decls(lambda decl: decl.name.startswith(z)).include()
    except RuntimeError:
        pass













# exlude every class first
# mb.classes().exclude()

# expose every OpenCV's C structure and class but none of its members
# for z in mb.classes(lambda z: z.decl_string.startswith('::Cv') or z.decl_string.startswith('::_Ipl')):
    # z.include()
    # z.decls().exclude()

# exclude stupid CvMat... aliases
# mb.classes(lambda z: z.decl_string.startswith('::CvMat') and not z.name.startswith('CvMat')).exclude()

# cannot expose unions
# mb.class_('Cv32suf').exclude()
# mb.class_('Cv64suf').exclude()

# expose every OpenCV's C++ class but none of its members
# for z in mb.classes(lambda z: z.decl_string.startswith('::cv')):
    # z.include()
    # z.decls().exclude()

# exclude every Ptr class
# mb.classes(lambda z: z.decl_string.startswith('::cv::Ptr')).exclude()

# exclude every MatExpr class
# mb.classes(lambda z: z.decl_string.startswith('::cv::MatExpr')).exclude()

# expose every OpenCV's C++ free function
# mb.free_functions(lambda z: z.decl_string.startswith('::cv')).include()


# -----------------------------------------------------------------------------------------------

# cv = mb.namespace('cv')
# cv.decls().exclude()

# cv.decls(lambda decl: 'Optimized' in decl.name).include()

# for z in ('CvScalar', 'CvPoint', 'CvSize', 'CvRect', 'CvBox', 'CvSlice'):
    # mb.decls(lambda decl: decl.name.startswith(z)).include()


# -----------------------------------------------------------------------------------------------
# cxcore.hpp
# -----------------------------------------------------------------------------------------------
# cv = mb.namespace('cv') # namespace cv

# cv.class_('Exception').include()

# for z in ('Optimized', 'NumThreads', 'ThreadNum', 'getTick'):
    # cv.decls(lambda decl: z in decl.name).include()

# for z in ('DataDepth', 'Vec', 'Complex', 'Point', 'Size', 'Rect', 'RotatedRect',
    # 'Scalar', 'Range', 'DataType'):
    # cv.decls(lambda decl: decl.name.startswith(z)).include()

# class Mat
# mat = cv.class_('Mat')
# mat.include()
# for z in ('refcount', 'datastart', 'dataend'):
    # mat.var(z).exclude()
# TODO: expose the 'data' member as read-write buffer
# mat.var('data').exclude()
# expose_addressof_member(mat, 'data')
# mat.decls('ptr').exclude()

#Creating code creator. After this step you should not modify/customize declarations.
mb.build_code_creator( module_name='pyopencvext' )

#Writing code to file.
mb.split_module( 'code' )
