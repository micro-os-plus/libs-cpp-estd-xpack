/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2016 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

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
