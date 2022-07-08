cmake_minimum_required(VERSION 3.16)
project(visitor)

set(CMAKE_CXX_STANDARD 20)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} \
        -lboost_filesystem\
        -lboost_system\
")

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/external/fc/include)

find_package(CURL REQUIRED)
find_package(EXPAT REQUIRED)


SET(BOOST_COMPONENTS)
LIST(APPEND BOOST_COMPONENTS thread date_time system filesystem program_options serialization chrono unit_test_framework context locale iostreams)
SET( Boost_USE_STATIC_LIBS ON CACHE STRING "ON or OFF" )

FIND_PACKAGE(Boost 1.53 REQUIRED COMPONENTS ${BOOST_COMPONENTS})
IF(NOT "${Boost_VERSION}" MATCHES "1.53(.*)")
    SET(BOOST_LIBRARIES_TEMP ${Boost_LIBRARIES})
    FIND_PACKAGE(Boost 1.54 REQUIRED COMPONENTS coroutine)
    LIST(APPEND BOOST_COMPONENTS coroutine)
    SET(Boost_LIBRARIES ${BOOST_LIBRARIES_TEMP} ${Boost_LIBRARIES})
ENDIF()

include(ExternalProject)
ExternalProject_Add( project_fc
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/external/fc
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/fc
        CONFIGURE_COMMAND cmake .
        BUILD_COMMAND make
        INSTALL_COMMAND true
        BUILD_BYPRODUCTS ${CMAKE_CURRENT_BINARY_DIR}/libfc.a
        )

ExternalProject_Get_Property(project_fc binary_dir)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    add_library(fc STATIC IMPORTED)
    set_property(TARGET fc PROPERTY IMPORTED_LOCATION ${binary_dir}/libfc${CMAKE_STATIC_LIBRARY_SUFFIX})
    set_property(TARGET fc PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/external/fc/include)
    add_dependencies(fc project_fc)
    target_link_libraries(fc INTERFACE ${Boost_LIBRARIES})

    add_executable(visitor main.cpp)
    target_link_libraries(visitor fc )
endif()

