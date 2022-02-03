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
// This file is for internal use in µOS++ and should not be included
// in applications.

#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

thread::thread (thread&& t) noexcept
{
  swap (t);
}

thread&
thread::operator= (thread&& t) noexcept
{
  if (joinable ())
    {
      micro_os_plus::trace::printf (
          "%s() @%p attempt to assign a running thread\n", __func__, this);
      std::abort (); // in ISO it is std::terminate()
    }
  swap (t);
  return *this;
}

void
thread::delete_system_thread (void)
{
  if (id_ != id ())
    {
      void* arguments = id_.native_thread_->function_args ();
      if (arguments != nullptr && function_object_deleter_ != nullptr)
        {
          // Manually delete the function object used to store arguments.
          function_object_deleter_ (arguments);
        }

      // Manually delete the system thread.
      delete id_.native_thread_;
    }
}

thread::~thread ()
{
  micro_os_plus::trace::printf ("%s() @%p\n", __func__, this);
  if (joinable ())
    {
      micro_os_plus::trace::printf (
          "%s() @%p attempt to destruct a running thread\n", __func__, this);
      std::abort (); // in ISO it is std::terminate()
    }

  delete_system_thread ();
}

// ------------------------------------------------------------------------

void
thread::swap (thread& t) noexcept
{
  std::swap (id_, t.id_);
  std::swap (function_object_deleter_, t.function_object_deleter_);
}

bool
thread::joinable () const noexcept
{
  return !(id_ == thread::id ());
}

void
thread::join ()
{
  micro_os_plus::trace::printf ("%s() @%p\n", __func__, this);

  delete_system_thread ();

  id_ = id ();
  micro_os_plus::trace::printf ("%s() @%p joined\n", __func__, this);
}

void
thread::detach ()
{
  micro_os_plus::trace::printf ("%s() @%p\n", __func__, this);
  if (id_ != id ())
    {
      id_.native_thread_->detach ();
    }

  // The detached thread will continue to run, but we'll not have
  // access to it from here, not even to delete it.
  // TODO: arrange to delete it at exit()?

  id_ = id ();
  micro_os_plus::trace::printf ("%s() @%p detached\n", __func__, this);
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
