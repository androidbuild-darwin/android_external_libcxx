//===----------------------------------------------------------------------===//
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03

// Darwin's headers request rsize_t from Clang after the libc++ stddef.h
// wrapper has already been included.
#include <stddef.h>

#if defined(__APPLE__) && defined(__clang__)
#define __need_rsize_t
#include <stddef.h>

#ifdef __need_rsize_t
#error __need_rsize_t was not handled by the compiler header
#endif

#include <type_traits>
static_assert((std::is_same<rsize_t, size_t>::value), "");
#endif

int main() {}
