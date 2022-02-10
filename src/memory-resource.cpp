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

/*
 * [Partly inspired from the LLVM libcxx sources].
 * Copyright (c) 2009-2013 by the contributors listed in
 * 'LLVM libcxx Credits.txt'. See 'LLVM libcxx License.txt' for details.
 *
 * References are to ISO/IEC 14882:2011(E) Third edition (2011-09-01).
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/rtos.h>
#include <micro-os-plus/estd/memory_resource>

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

    [[noreturn]] void
    __throw_bad_alloc (void)
    {
#if defined(__EXCEPTIONS)
      throw std::bad_alloc ();
#else
      trace::printf ("bad_alloc()\n");
      std::abort ();
#endif
    }

    namespace pmr
    {
      // ----------------------------------------------------------------------

      memory_resource*
      set_default_resource (memory_resource* res) noexcept
      {
        trace::printf ("estd::pmr::%s(%p) \n", __func__, res);

        memory_resource* old = default_resource;
        default_resource = res;

        return old;
      }

      // ----------------------------------------------------------------------
    } // namespace pmr
  } // namespace estd
} // namespace micro_os_plus

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
