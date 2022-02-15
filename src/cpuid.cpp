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

#include "cpuid.hpp"
#include "core.hpp"

auto cpuid::largest_standard_function() -> unsigned {
  unsigned info[]{0x00000000, {}, {}, {}};
  cpuid::get(info);
  return info[0];
}

auto cpuid::largest_extended_function() -> unsigned {
  unsigned info[]{0x80000000, {}, {}, {}};
  cpuid::get(info);
  return info[0];
}

auto cpuid::vendor() -> std::string {
  // 12 8-bit ASCII character codes
  // without null terminated

  unsigned info[]{0x00000000, {}, {}, {}};

  cpuid::get(info);

  // We need 'ebx - edx - ecx - eax(\0)',
  // so do eax <=> edx, edx <=> ebx.
  asm("\txchg %0, %2\n"
      "\txchg %0, %1\n"
      : "+a"(info[0]), "+b"(info[1]), "+c"(info[3]));

  return reinterpret_cast<const char *>(info);
}

auto cpuid::processor_name() -> std::string {
  // The three extended functions from Fn8000_0002 to Fn8000_0004 are
  // initialized to and return a null terminated ASCII string up to 48
  // characters in length corresponding to the processor name.

  unsigned info[]{
      0x80000002, {}, {}, {}, // Fn8000_0002
      0x80000003, {}, {}, {}, // Fn8000_0003
      0x80000004, {}, {}, {}, // Fn8000_0004
  };

  cpuid::get(info);
  cpuid::get(info + 4);
  cpuid::get(info + 8);

  return reinterpret_cast<const char *>(info);
}

auto cpuid::threads_number_per_core() -> unsigned {
  unsigned info[]{0x0000000b, {}, 0x00000000, {}};
  cpuid::get(info); // 00h = SMT level
  return info[1];
}

auto cpuid::logical_processors_number() -> unsigned {
  unsigned info[]{0x0000000b, {}, 0x00000001, {}};
  cpuid::get(info); // 01h = core level
  return info[1];
}

auto cpuid::base_frequency() -> unsigned {
  unsigned info[]{0x00000016, {}, {}, {}};
  cpuid::get(info);
  return info[0];
}

auto cpuid::max_frequency() -> unsigned {
  unsigned info[]{0x00000016, {}, {}, {}};
  cpuid::get(info);
  return info[1];
}

auto cpuid::bus_frequency() -> unsigned {
  unsigned info[]{0x00000016, {}, {}, {}};
  cpuid::get(info);
  return info[2];
}
