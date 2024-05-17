cmake_minimum_required(VERSION 3.14)
project(candle)

# Enable CMake's AUTOMOC, AUTOUIC, and AUTORCC features
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Qt libraries
find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL Network SerialPort REQUIRED)

# Add the source files
set(SOURCES
    main.cpp
    frmmain.cpp
    frmsettings.cpp
    frmabout.cpp
    drawers/gcodedrawer.cpp
    drawers/heightmapborderdrawer.cpp
    drawers/heightmapgriddrawer.cpp
    drawers/heightmapinterpolationdrawer.cpp
    drawers/origindrawer.cpp
    drawers/shaderdrawable.cpp
    drawers/tooldrawer.cpp
    parser/arcproperties.cpp
    parser/gcodeparser.cpp
    parser/gcodepreprocessorutils.cpp
    parser/gcodeviewparse.cpp
    parser/linesegment.cpp
    parser/pointsegment.cpp
    tables/gcodetablemodel.cpp
    tables/heightmaptablemodel.cpp
    utils/profiles.cpp
    widgets/colorpicker.cpp
    widgets/combobox.cpp
    widgets/groupbox.cpp
    widgets/scrollarea.cpp
    widgets/styledtoolbutton.cpp
    widgets/widget.cpp
    widgets/glwidget.cpp
    widgets/slider.cpp
    widgets/sliderbox.cpp
    drawers/selectiondrawer.cpp
    widgets/comboboxkey.cpp
    protocol/grbl1_1.cpp
    interface/SerialInterface.cpp
    GrIP/CRC.c
    frmmain_heightmap.cpp
    frmmain_jogcontrol.cpp
    frmmain_processresponse.cpp
    frmmain_settings.cpp
    frmmain_util.cpp
    frmmain_event.cpp
    GrIP/GrIP.cpp
    shaders.qrc
    images.qrc
)

# Add the header files
set(HEADERS
    frmmain.h
    frmsettings.h
    frmabout.h
    drawers/gcodedrawer.h
    drawers/heightmapborderdrawer.h
    drawers/heightmapgriddrawer.h
    drawers/heightmapinterpolationdrawer.h
    drawers/origindrawer.h
    drawers/shaderdrawable.h
    drawers/tooldrawer.h
    parser/arcproperties.h
    parser/gcodeparser.h
    parser/gcodepreprocessorutils.h
    parser/gcodeviewparse.h
    parser/linesegment.h
    parser/pointsegment.h
    tables/gcodetablemodel.h
    tables/heightmaptablemodel.h
    utils/interpolation.h
    utils/profiles.h
    utils/util.h
    widgets/colorpicker.h
    widgets/combobox.h
    widgets/groupbox.h
    widgets/scrollarea.h
    widgets/styledtoolbutton.h
    widgets/widget.h
    widgets/glwidget.h
    widgets/slider.h
    widgets/sliderbox.h
    drawers/selectiondrawer.h
    widgets/comboboxkey.h
    protocol/grbl1_1.h
    interface/SerialInterface.h
    GrIP/CRC.h
    GrIP/GrIP.h
    utils/safequeue.h
)

# Add the UI files
set(UIS
    frmmain.ui
    frmsettings.ui
    frmabout.ui
    widgets/sliderbox.ui
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UIS})

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:/Zi>
        $<$<CONFIG:Release>:/O2>
        /W4
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>: -g3 -pg>
        $<$<CONFIG:Release>:-O2>
        -Wall -Wextra -Wl,-rpath,\'\$$ORIGIN/libs\'
    )
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE
    sNan=65536
    APP_VERSION="2.2.0"
    _USE_MATH_DEFINES
)

# Link the Qt libraries
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::OpenGL Qt5::Network Qt5::SerialPort)

# Include additional directories if necessary
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/drawers
    ${CMAKE_CURRENT_SOURCE_DIR}/GrIP
    ${CMAKE_CURRENT_SOURCE_DIR}/images
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/parser
    ${CMAKE_CURRENT_SOURCE_DIR}/protocol
    ${CMAKE_CURRENT_SOURCE_DIR}/tables
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/widgets
)

add_custom_target(clean-extra
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/cmake_clean.cmake
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_SOURCE_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_SOURCE_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_SOURCE_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_SOURCE_DIR}/cmake_install.cmake
)

