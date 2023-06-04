# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/
# https://cmake.org/cmake/help/v3.20/manual/cmake-packages.7.html#package-configuration-file
cmake_minimum_required(VERSION 3.20)

# Use targets as include markers (variables are not scope independent).
if(TARGET micro-os-plus-libs-cpp-estd-included)
  return()
else()
  add_custom_target(micro-os-plus-libs-cpp-estd-included)
endif()

if(NOT TARGET micro-os-plus-build-helper-included)
  message(FATAL_ERROR "Include the mandatory build-helper (xpacks/@micro-os-plus/build-helper/cmake/xpack-helper.cmake)")
endif()

message(STATUS "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")

# -----------------------------------------------------------------------------
# Dependencies.

find_package(micro-os-plus-rtos REQUIRED)
# find_package(micro-os-plus-memory-allocators REQUIRED)

# -----------------------------------------------------------------------------
# The current folder.

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# -----------------------------------------------------------------------------

if(NOT TARGET micro-os-plus-libs-cpp-estd-interface)

  add_library(micro-os-plus-libs-cpp-estd-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------

  xpack_glob_recurse_cxx(source_files "${xpack_current_folder}/src")
  xpack_display_relative_paths("${source_files}" "${xpack_current_folder}")

  target_sources(
    micro-os-plus-libs-cpp-estd-interface

    INTERFACE
      ${source_files}
  )

  target_include_directories(
    micro-os-plus-libs-cpp-estd-interface

    INTERFACE
      ${xpack_current_folder}/include
  )

  target_link_libraries(
    micro-os-plus-libs-cpp-estd-interface

    INTERFACE
      micro-os-plus::rtos
  )

# -----------------------------------------------------------------------------
  # Aliases.

  add_library(micro-os-plus::libs-cpp-estd ALIAS micro-os-plus-libs-cpp-estd-interface)
  message(STATUS "=> micro-os-plus::libs-cpp-estd")

endif()

# -----------------------------------------------------------------------------
