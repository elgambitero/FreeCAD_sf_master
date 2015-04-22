PYSIDE_WRAP_RC(Aircraft_QRC_SRCS Resources/Aircraft.qrc)

SET(AircraftMain_SRCS
    InitGui.py
    AircraftGui.py
)
SOURCE_GROUP(“” FILES ${AircraftMain_SRCS})

SET(NACAairfoil_SRCS)
	NACAairfoil/__Init__.py
	NACAairfoil/TaskPanel.py
	NACAairfoil/TaskPanel.ui
)

SET(all_files ${AircraftMain_SRCS} ${NACAairfoil_SRCS})

ADD_CUSTOM_TARGET(Aircraft ALL SOURCES ${all_files} ${Ship_QRC_SRCS})

fc_copy_sources(Aircraft “${CMAKE_BINARY_DIR}/Mod/Aircraft” ${all_files})

INSTALL(
    FILES
        ${AircraftMain_SRCS}
        ${Aircraft_QRC_SRCS}
    DESTINATION
        Mod/Aircraft
)

