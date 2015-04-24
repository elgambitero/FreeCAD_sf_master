
include_directories(
    ${Boost_INCLUDE_DIRS}
    ${OCC_INCLUDE_DIR}
    ${PYTHON_INCLUDE_PATH}
    ${ZLIB_INCLUDE_DIR}
    ${XERCESC_INCLUDE_DIR}
)

set(Aircraft_LIBS
    FreeCADApp
)

SET(Aircraft_SRCS
    AppAircraft.cpp
    AppAircraftPy.cpp
    PreCompiled.cpp
    PreCompiled.h
)

add_library(Aircraft SHARED ${Aircraft_SRCS})
target_link_libraries(Aircraft ${Aircraft_LIBS})


fc_target_copy_resource(Aircraft 
    ${CMAKE_SOURCE_DIR}/src/Mod/Aircraft
    ${CMAKE_BINARY_DIR}/Mod/Aircraft
    Init.py)

SET_BIN_DIR(Aircraft Aircraft /Mod/Aircraft)
SET_PYTHON_PREFIX_SUFFIX(Aircraft)

install(TARGETS Aircraft DESTINATION ${CMAKE_INSTALL_LIBDIR})
