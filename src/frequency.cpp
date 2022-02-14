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

#include "frequency.hpp"

auto cpuid::base_frequency() -> unsigned {
  unsigned freq, _;
  if (__get_cpuid(0x16, &freq, &_, &_, &_))
    return freq;
  return {};
}

auto cpuid::max_frequency() -> unsigned {
  unsigned freq, _;
  if (__get_cpuid(0x16, &_, &freq, &_, &_))
    return freq;
  return {};
}

auto cpuid::bus_frequency() -> unsigned {
  unsigned freq, _;
  if (__get_cpuid(0x16, &_, &_, &freq, &_))
    return freq;
  return {};
}
