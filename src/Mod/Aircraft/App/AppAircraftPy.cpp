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
#endif

#include <Python.h>

#include <Base/Console.h>
#include <Base/PyObjectBase.h>
#include <Base/Exception.h>
#include <Mod/Aircraft/App/Xflr5/Foil.h>

//#include

/* module functions */
static PyObject * GenerateNACA(PyObject *self, PyObject *args)
{
    Foil Airfoil();
    Airfoil.SetNaca009();
}


/* registration table  */
struct PyMethodDef Aircraft_methods[] = {
    {"NACAairfoil", GenerateNACA, 1},
    {NULL,NULL}  /* end of table marker */
};
