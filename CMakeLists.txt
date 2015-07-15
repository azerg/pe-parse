cmake_minimum_required (VERSION 2.8)

project (pe-parse)

if (CMAKE_COMPILER_IS_GNUCXX)
  SET (CMAKE_CXX_FLAGS_DEBUG_INIT 		   "-g")
  SET (CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
  SET (CMAKE_CXX_FLAGS_RELEASE_INIT        "-O3 -DNDEBUG")
  SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")
  SET (CMAKE_CXX_FLAGS                     "-Wall -std=c++0x ${CMAKE_CXX_FLAGS}")  
endif()

#lets use boost for smart pointers
set(BOOST_USE_MULTITHREADED ON)
if(WIN32)
    set(Boost_USE_STATIC_LIBS ON)
endif(WIN32)
find_package(Boost COMPONENTS thread system filesystem program_options date_time regex REQUIRED)
find_package(Threads REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(parser-library)
add_subdirectory(dump-prog)
