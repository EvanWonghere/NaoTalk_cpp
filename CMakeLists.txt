cmake_minimum_required(VERSION 2.8)
project(tactile)
find_package(qibuild)

option(TACTILE_IS_REMOTE
  "module is compiled as a remote module (ON or OFF)"
  ON)

set(_srcs
  src/*.cpp
  src/*.c
  include/*.h
)

include_directories(./include)
include_directories(/usr/include/jsoncpp/json)
include_directories(/usr/include)
include_directories(../include)

# set(MSC_DIR libs)
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR})

# clean(libmsc)
# flib(msc libmsc)

set(LIB_DIR ${CMAKE_SOURCE_DIR}/../lib)

if(TACTILE_IS_REMOTE)
  add_definitions(" -DTACTILE_IS_REMOTE ")
  qi_create_bin(tactile ${_srcs})
else()
  qi_create_lib(tactile SHARED ${_srcs} SUBFOLDER naoqi)
endif()

link_directories(${CMAKE_SOURCE_DIR}/libs)
# link_directories(${CMAKE_SOURCE_DIR}/../lib)

#qi_stage_lib(msc)
target_link_libraries(tactile PRIVATE msc rt dl pthread asound stdc++ aikit jsoncpp ${LIB_DIR}/libalcommon.so ${LIB_DIR}/libalproxies.so ${LIB_DIR}/libalthread.so ${LIB_DIR}/libalvalue.so ${LIB_DIR}/libalerror.so ${LIB_DIR}/libqi.so ${LIB_DIR}/libboost_system.so.1.59.0)
# qi_use_lib(tactile ALCOMMON ALPROXIES ALTHREAD msc)${LIB_DIR}/libalcommon.so

