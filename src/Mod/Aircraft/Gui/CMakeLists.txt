
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
    ${COIN3D_INCLUDE_DIR}
    ${QT_INCLUDE_DIR}
    ${ZLIB_INCLUDE_DIR}
    ${PYTHON_INCLUDE_PATH}
    ${XERCESC_INCLUDE_DIR}
)

set(AircraftGui_LIBS
    Aircraft
    FreeCADGui
)

qt4_add_resources(Aircraft_QRC_SRCS Resources/Aircraft.qrc)

SET(AircraftGui_SRCS
    ${Aircraft_QRC_SRCS}
    AppAircraftGui.cpp
    AppAircraftGuiPy.cpp
    Command.cpp
    PreCompiled.cpp
    PreCompiled.h
    Workbench.cpp
    Workbench.h
)

add_library(AircraftGui SHARED ${AircraftGui_SRCS})
target_link_libraries(AircraftGui ${AircraftGui_LIBS})

fc_target_copy_resource(AircraftGui 
    ${CMAKE_SOURCE_DIR}/src/Mod/Aircraft
    ${CMAKE_BINARY_DIR}/Mod/Aircraft
    InitGui.py)

SET_BIN_DIR(AircraftGui AircraftGui /Mod/Aircraft)
SET_PYTHON_PREFIX_SUFFIX(AircraftGui)
    
install(TARGETS AircraftGui DESTINATION ${CMAKE_INSTALL_LIBDIR})
