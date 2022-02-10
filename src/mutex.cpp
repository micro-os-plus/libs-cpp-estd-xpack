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

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/estd/mutex>

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

namespace micro_os_plus
{
  namespace estd
  {
    // ========================================================================

    void
    mutex::lock ()
    {
      rtos::result_t res;
      res = nm_.lock ();
      if (res != rtos::result::ok)
        {
          estd::__throw_rtos_error (static_cast<int> (res),
                                    "mutex lock failed");
        }
    }

    bool
    mutex::try_lock ()
    {
      rtos::result_t res;
      res = nm_.try_lock ();
      if (res == rtos::result::ok)
        {
          return true;
        }
      else if (res == EWOULDBLOCK)
        {
          return false;
        }

      estd::__throw_rtos_error (static_cast<int> (res),
                                "mutex try_lock failed");
      // return false;
    }

    void
    mutex::unlock ()
    {
      rtos::result_t res;
      res = nm_.unlock ();
      if (res != rtos::result::ok)
        {
          estd::__throw_rtos_error (static_cast<int> (res),
                                    "mutex unlock failed");
        }
    }

    // ========================================================================

    void
    recursive_mutex::lock ()
    {
      rtos::result_t res;
      res = nm_.lock ();
      if (res != rtos::result::ok)
        {
          estd::__throw_rtos_error (static_cast<int> (res),
                                    "recursive_mutex lock failed");
        }
    }

    bool
    recursive_mutex::try_lock () noexcept
    {
      rtos::result_t res;
      res = nm_.try_lock ();
      if (res == rtos::result::ok)
        {
          return true;
        }
      else if (res == EWOULDBLOCK)
        {
          return false;
        }

      estd::__throw_rtos_error (static_cast<int> (res),
                                "recursive_mutex try_lock failed");
      // return false;
    }

    void
    recursive_mutex::unlock ()
    {
      rtos::result_t res;
      res = nm_.unlock ();
      if (res != rtos::result::ok)
        {
          estd::__throw_rtos_error (static_cast<int> (res),
                                    "recursive_mutex unlock failed");
        }
    }

    // ==========================================================================
  } // namespace estd
} // namespace micro_os_plus

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
