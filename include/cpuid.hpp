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

#pragma once

#include <string>

namespace cpuid {

// The largest CPUID standard function input value supported
// by the processor implementation.
auto largest_standard_function() -> unsigned;

// The largest CPUID extended function input value supported
// by the processor implementation.
auto largest_extended_function() -> unsigned;

// the pre-B0 step Intel P5 processors
// don't return a vendor ID string.
auto vendor() -> std::string;

auto processor_name() -> std::string;

// get topology enumeration information

auto threads_number_per_core() -> unsigned;

auto logical_processors_number() -> unsigned;

// get processor frequency information

// core base frequency in MHz
auto base_frequency() -> unsigned;

// core maximum frequency in MHz
auto max_frequency() -> unsigned;

// bus (reference) frequency in MHz
auto bus_frequency() -> unsigned;

} // namespace cpuid

// get processor feature flags
#include "feature.hpp"
