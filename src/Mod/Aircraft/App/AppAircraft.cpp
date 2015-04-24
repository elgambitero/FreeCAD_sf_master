/***************************************************************************
 *   Copyright (c) 2015 Jaime García         <elgambitero@gmail.com>       *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#include "PreCompiled.h"
#ifndef _PreComp_
# include <Python.h>
#endif

#include <Base/Console.h>
#include <Base/Interpreter.h>


/* registration table  */
extern struct PyMethodDef Aircraft_methods[];

PyDoc_STRVAR(module_Aircraft_doc,
"This module is the Aircraft module.");


/* Python entry */
extern "C" {
void AircraftAppExport initAircraft() {

    try {
        Base::Interpreter().loadModule("Part");
        Base::Interpreter().loadModule("Mesh");
    }
    catch(conts Base::Exception& e){
        PyErr_SetString(PyExc_ImportError, e.what());
        return;
    }
    (void) Py_InitModule3("Aircraft", Aircraft_methods, module_Aircraft_doc);   /* mod name, table ptr */
    Base::Console().Log("Loading Aircraft module... done\n");
}

} // extern "C"
