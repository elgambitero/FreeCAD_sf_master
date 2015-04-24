#***************************************************************************
#*                                                                         *
#*   Copyright (c) 2015                                                    *
#*   Jaime Garcia Villena            <elgambitero@gmail.com>               *
#*                                                                         *
#*   This program is free software; you can redistribute it and/or modify  *
#*   it under the terms of the GNU Lesser General Public License (LGPL)    *
#*   as published by the Free Software Foundation; either version 2 of     *
#*   the License, or (at your option) any later version.                   *
#*   for detail see the LICENCE text file.                                 *
#*                                                                         *
#*   This program is distributed in the hope that it will be useful,       *
#*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
#*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
#*   GNU Library General Public License for more details.                  *
#*                                                                         *
#*   You should have received a copy of the GNU Library General Public     *
#*   License along with this program; if not, write to the Free Software   *
#*   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *
#*   USA                                                                   *
#*                                                                         *
#***************************************************************************

class AircraftWorkbench ( Workbench ):
	"Aircraft workbench object"

        Icon = "AircraftLogo.svg"
	MenuText = "Aircraft"
	ToolTip= ("Module for making the hull of an aircraft")
	def Initialize(self):
		# load the module
		import AircraftGui
                aircraftList:["Aircraft_NACAairfoil"]

                self.appendToolbar(
                    str(QtCore.QT_TRANSLATE_NOOP("Aircraft","Create NACA airfoil")),
                    aircraftList)

	def GetClassName(self):
		return "AircraftGui::Workbench"

Gui.addWorkbench(AircraftWorkbench())
