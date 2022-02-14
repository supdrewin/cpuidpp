/// CPUID++ - C++ wrappers for X86 cpu model detection.
/// Copyright (C) 2022  Supdrewin
///
/// This library is free software: you can redistribute it and/or modify it
/// under the terms of the GNU General Public License as published by the Free
/// Software Foundation, either version 3 of the License, or (at your option)
/// any later version.
///
/// This library is distributed in the hope that it will be useful, but WITHOUT
/// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
/// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
/// more details.
///
/// You should have received a copy of the GNU General Public License along with
/// this program.  If not, see <https://www.gnu.org/licenses/>.

#include <cpuid.h>

#include "cpuid.hpp"

auto cpuid::largest_standard_function() -> unsigned {
  return static_cast<unsigned>(__get_cpuid_max(0, nullptr));
}

auto cpuid::largest_extended_function() -> unsigned {
  return static_cast<unsigned>(__get_cpuid_max(0x80000000, nullptr));
}

auto cpuid::vendor() -> std::string {
  // 12 8-bit ASCII character codes
  // without null terminated
  unsigned vendor[4]{}, _;
  // ebx - edx - ecx
  if (__get_cpuid(0, &_, vendor, vendor + 2, vendor + 1))
    return {reinterpret_cast<const char *>(vendor)};
  return {};
}

auto cpuid::processor_name() -> std::string {
  // The three extended functions from Fn8000_0002 to Fn8000_0004 are
  // initialized to and return a null terminated ASCII string up to 48
  // characters in length corresponding to the processor name.
  unsigned name[12];
  if (__get_cpuid(0x80000002, name, name + 1, name + 2, name + 3))
    if (__get_cpuid(0x80000003, name + 4, name + 5, name + 6, name + 7))
      if (__get_cpuid(0x80000004, name + 8, name + 9, name + 10, name + 11))
        return {reinterpret_cast<const char *>(name)};
  return {};
}

auto cpuid::threads_number_per_core() -> unsigned {
  unsigned ebx, _; // 00h = SMT level
  if (__get_cpuid_count(0xb, 0, &_, &ebx, &_, &_))
    return ebx;
  return {};
}

auto cpuid::logical_processors_number() -> unsigned {
  unsigned ebx, _; // 01h = core level
  if (__get_cpuid_count(0xb, 1, &_, &ebx, &_, &_))
    return ebx;
  return {};
}
