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

#include <micro-os-plus/estd/condition_variable>

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
    condition_variable::notify_one () noexcept
    {
      rtos::result_t res;
      res = ncv_.signal ();
      if (res != rtos::result::ok)
        {
          estd::__throw_rtos_error (static_cast<int> (res),
                                    "condition_variable::notify_one() failed");
        }
    }

    void
    condition_variable::notify_all () noexcept
    {
      rtos::result_t res;
      res = ncv_.broadcast ();
      if (res != rtos::result::ok)
        {
          estd::__throw_rtos_error (static_cast<int> (res),
                                    "condition_variable::notify_all() failed");
        }
    }

    void
    condition_variable::wait (std::unique_lock<mutex>& lk)
    {
      if (!lk.owns_lock ())
        {
          estd::__throw_system_error (
              EPERM, "condition_variable::wait: mutex not locked");
        }
      rtos::result_t res = ncv_.wait ((*(lk.mutex ()->native_handle ())));
      if (res != rtos::result::ok)
        {
          estd::__throw_rtos_error (static_cast<int> (res),
                                    "condition_variable wait failed");
        }
    }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-noreturn"

    void
    notify_all_at_thread_exit (condition_variable& cond,
                               std::unique_lock<mutex> lk)
    {
      //__thread_local_data()->notify_all_at_thread_exit(&cond, lk.release());
      std::abort (); // Not implemented
    }

#pragma GCC diagnostic pop

    // ==========================================================================
  } // namespace estd
} // namespace micro_os_plus

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
