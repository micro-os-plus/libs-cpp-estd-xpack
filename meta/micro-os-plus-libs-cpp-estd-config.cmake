#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# This Source Code Form is subject to the terms of the MIT License.
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.18/
# https://cmake.org/cmake/help/v3.18/manual/cmake-packages.7.html#package-configuration-file

if(micro-os-plus-libs-cpp-estd-included)
  return()
endif()

set(micro-os-plus-libs-cpp-estd-included TRUE)

message(STATUS "Including micro-os-plus-libs-cpp-estd...")

# -----------------------------------------------------------------------------
# Dependencies.

# find_package(micro-os-plus-utils-lists REQUIRED)
# find_package(micro-os-plus-memory-allocators REQUIRED)

# -----------------------------------------------------------------------------
# The current folder.

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# -----------------------------------------------------------------------------

if(NOT TARGET micro-os-plus-libs-cpp-estd-interface)

  add_library(micro-os-plus-libs-cpp-estd-interface INTERFACE EXCLUDE_FROM_ALL)

  # ---------------------------------------------------------------------------

  target_sources(
    micro-os-plus-libs-cpp-estd-interface

    INTERFACE
      ${xpack_current_folder}/src/chrono.cpp
      ${xpack_current_folder}/src/condition-variable.cpp
      ${xpack_current_folder}/src/memory-resource.cpp
      ${xpack_current_folder}/src/mutex.cpp
      ${xpack_current_folder}/src/new.cpp
      ${xpack_current_folder}/src/thread.cpp
  )

  target_include_directories(
    micro-os-plus-libs-cpp-estd-interface

    INTERFACE
      ${xpack_current_folder}/include
  )

  target_link_libraries(
    micro-os-plus-libs-cpp-estd-interface

    INTERFACE
      # ...
  )

  # ---------------------------------------------------------------------------
  # Aliases.

  add_library(micro-os-plus::libs-cpp-estd ALIAS micro-os-plus-libs-cpp-estd-interface)
  message(STATUS "micro-os-plus::libs-cpp-estd")

endif()

# -----------------------------------------------------------------------------
