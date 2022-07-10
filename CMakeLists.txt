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

set( FC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendors/hive/libraries/fc" )
add_subdirectory(vendors/hive/libraries/fc)
add_custom_target(build_fc ALL COMMAND make -C ${FC_DIR})

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_library(ven_fc STATIC IMPORTED)
add_dependencies(ven_fc build_fc)
set_property(TARGET ven_fc PROPERTY IMPORTED_LOCATION ${FC_DIR}/libfc${CMAKE_STATIC_LIBRARY_SUFFIX})
set_property(TARGET ven_fc PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${FC_DIR}/include)
target_link_libraries(ven_fc INTERFACE ${Boost_LIBRARIES})

add_executable(visitor main.cpp)
add_dependencies(visitor ven_fc)
target_link_libraries(visitor ven_fc)

