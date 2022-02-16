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

  // What we need is: ebx - edx - ecx - '\0'.
  asm volatile("\txchg %0, %2\n" // swap(%0(eax), %2(edx));
               "\txchg %0, %1\n" // swap(%0(edx), %1(ebx));
               : "+a"(info[0]), "+b"(info[1]), "+c"(info[3]));
  info[3] <<= 8; // terminate with a byte '\0'

  return reinterpret_cast<const char *>(info);
}

auto cpuid::stepping() -> unsigned {
  unsigned info[]{0x00000001, {}, {}, {}};
  cpuid::get(info);

  // The stepping is encoded in bits 3...0.
  return info[0] & 0x0000000f;
}

auto cpuid::deprecated_cpu_count() -> unsigned {
  unsigned info[]{0x00000001, {}, {}, {}};
  cpuid::get(info);

  // The logical processor count is encoded in bits 23...16.
  return (info[1] & 0x00ff0000) >> 16;
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

auto cpuid::enabled_logical_processors::smt() -> unsigned {
  unsigned info[]{0x0000000b, {}, 0x00000000, {}};
  cpuid::get(info); // 00h = SMT level
  return info[1];
}

auto cpuid::enabled_logical_processors::core() -> unsigned {
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
