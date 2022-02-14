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

#include "feature.hpp"

auto cpuid::check_feature(cpuid::feature::LEAF_1_ECX feature) -> bool {
  unsigned ecx, _;
  if (__get_cpuid(1, &_, &_, &ecx, &_))
    return ecx & feature;
  return false;
}

auto cpuid::check_feature(cpuid::feature::LEAF_1_EDX feature) -> bool {
  unsigned edx, _;
  if (__get_cpuid(1, &_, &_, &_, &edx))
    return edx & feature;
  return false;
}
