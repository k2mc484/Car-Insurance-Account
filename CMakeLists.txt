## \author Hans J. Johnson

cmake_minimum_required(VERSION 3.0.2)
## Use CMake settings for ensuring C++11 standard is adheered to
set(CMAKE_CXX_STANDARD 11)

project(Homework5 CXX)

##==============================
## This section sets up default compiler options for different build environments
#http://stackoverflow.com/questions/10046114/in-cmake-how-can-i-test-if-the-compiler-is-clang
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang") #Both AppleClang and Linux Clang
  # using Clang
  set(CMAKE_CXX_FLAGS "-std=c++11 -g -Wall -Wno-missing-braces -Wcast-align -Wdisabled-optimization -Wextra -Wformat=2 -Winvalid-pch -Wno-format-nonliteral -Wpointer-arith -Wshadow -Wunused -Wwrite-strings -funit-at-a-time -Wno-strict-overflow -Wno-deprecated -Wno-invalid-offsetof -Woverloaded-virtual")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  # using GCC
  set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -Wall -Wno-missing-braces -Wcast-align -Wdisabled-optimization -Wextra -Wformat=2 -Winvalid-pch -Wno-format-nonliteral -Wpointer-arith -Wshadow -Wunused -Wwrite-strings -funit-at-a-time -Wno-strict-overflow -Wno-deprecated -Wno-invalid-offsetof -Woverloaded-virtual")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  # using Intel C++
  set(CMAKE_CXX_FLAGS "-std=c++11 -g -Wall")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  ## See https://msdn.microsoft.com/en-us/library/hh567368.aspx#cpp14table for details
  ## TODO: ONLY MSVS 2015 provides sufficient c++11 support for this course
  ## if(CMAKE_CXX_COMPILER_VERSION VERSIONLESS

  # using Visual Studio C++, Force to always compile with at least /W2, replacing all other lower values
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-2]")
    string(REGEX REPLACE "/W[0-2]" "/W2" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W2")
  endif()
endif()


add_library(hw5_support_lib accidents.cpp CarInsuranceAccountRec.cpp Date.cpp PersonalRec.cpp)
##================================
## Build the application
add_executable(hw5 hw5.cpp)
target_link_libraries(hw5 hw5_support_lib)

