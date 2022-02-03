/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2016 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

#include <micro-os-plus/estd/thread>

namespace micro_os_plus
{
  namespace estd
  {
    // ==========================================================================

#include "thread-cpp.h"

    // ==========================================================================
  } // namespace estd
} // namespace micro_os_plus

#if defined(MICRO_OS_PLUS_HAS_STD_THREADS)

namespace std
{
  // ============================================================================

#include "thread-cpp.h"

  // ============================================================================
} // namespace std

#endif

// ----------------------------------------------------------------------------
