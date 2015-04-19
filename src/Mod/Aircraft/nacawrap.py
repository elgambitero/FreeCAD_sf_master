from numpy import f2py
f='/Users/jaimitillo/Documents/Desarrollos/FreeCAD/src/Mod/Aircraft/naca.f'
f2py.compile(f,'naca',-1,1)

