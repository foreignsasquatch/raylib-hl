cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME raylib)
set(TARGET_EXT .hdll)

project(${TARGET_NAME})

set(SOURCES source/raylib.c)
set(RAYLIB_SOURCES
 library/raylib/src/rcore.c
 library/raylib/src/utils.c
 library/raylib/src/rshapes.c
 library/raylib/src/rtextures.c
 library/raylib/src/rtext.c
 library/raylib/src/rmodels.c
 library/raylib/src/rglfw.c
 library/raylib/src/raudio.c
)
file(GLOB GLFW_INCLUDES "library/raylib/src/external/glfw/include/**.h")
file(GLOB RAYLIB_INCLUDES "library/raylib/src/*.h")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${TARGET_NAME}${TARGET_EXT} SHARED ${SOURCES} ${RAYLIB_SOURCES})
target_include_directories(${TARGET_NAME}${TARGET_EXT} PRIVATE GLFW_INCLUDES RAYLIB_INCLUDES)

set_target_properties(${TARGET_NAME}${TARGET_EXT}
    PROPERTIES
    PREFIX ""
    OUTPUT_NAME ${TARGET_NAME}
    SUFFIX ${TARGET_EXT}
)

IF (WIN32)
target_include_directories(${TARGET_NAME}${TARGET_EXT} PUBLIC $ENV{HASHLINKPATH}/include)
target_link_libraries(${TARGET_NAME}${TARGET_EXT} $ENV{HASHLINKPATH}/libhl.lib)

ELSEIF (APPLE)
find_library(APPLICATION_SERVICES_FRAMEWORK ApplicationServices REQUIRED)
set(HLPATH /usr/local/opt/hashlink/libexec)
target_include_directories(${TARGET_NAME}${TARGET_EXT} PUBLIC ${HLPATH}/include)
target_link_libraries(${TARGET_NAME}${TARGET_EXT} ${HLPATH}/lib/libhl.dylib ${APPLICATION_SERVICES_FRAMEWORK})

ELSE()
target_link_libraries(${TARGET_NAME}${TARGET_EXT} hl)
add_compile_definitions(PLATFORM_DESKTOP)
add_compile_definitions(_GLFW_X11)
ENDIF()