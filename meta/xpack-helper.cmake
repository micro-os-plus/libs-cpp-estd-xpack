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

message(STATUS "Including micro-os-plus-libs-cpp-estd...")

# -----------------------------------------------------------------------------

function(target_sources_micro_os_plus_libs_cpp_estd target)

  get_filename_component(xpack_root_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_sources(
    ${target}

    PRIVATE
      ${xpack_root_folder}/src/chrono.cpp
      ${xpack_root_folder}/src/condition-variable.cpp
      ${xpack_root_folder}/src/memory-resource.cpp
      ${xpack_root_folder}/src/mutex.cpp
      ${xpack_root_folder}/src/new.cpp
      ${xpack_root_folder}/src/thread.cpp
  )

endfunction()

# -----------------------------------------------------------------------------

function(target_include_directories_micro_os_plus_libs_cpp_estd target)

  get_filename_component(xpack_root_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_include_directories(
    ${target}

    PUBLIC
      ${xpack_root_folder}/include
  )

endfunction()

# -----------------------------------------------------------------------------
