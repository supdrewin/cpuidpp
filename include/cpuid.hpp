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
// the pre-B0 step Intel P5 processors return EAX=0000_05xxh.
auto largest_standard_function() -> unsigned;

// The largest CPUID extended function input value supported
// by the processor implementation.
auto largest_extended_function() -> unsigned;

// the pre-B0 step Intel P5 processors
// don't return a vendor ID string.
auto vendor() -> std::string;

// The stepping values are processor-specific.
auto stepping() -> unsigned;

// The logical processor count (deprecated)
// Only work on oooooold cpu, always return 16.
auto deprecated_cpu_count() -> unsigned;

// Notes that this func always success.
auto processor_name() -> std::string;

// get topology enumeration information (Intel)
namespace enabled_logical_processors {
// number of enabled logical processors at this level

// aka threads count per core
auto smt() -> unsigned;

// aka all logical processors
auto core() -> unsigned;

} // namespace enabled_logical_processors

// get processor frequency information

// core base frequency in MHz
// return 22 if failed
auto base_frequency() -> unsigned;

// core maximum frequency in MHz
// return 0 if failed
auto max_frequency() -> unsigned;

// bus (reference) frequency in MHz
// return 0 if failed
auto bus_frequency() -> unsigned;

} // namespace cpuid

// get processor feature flags
#include "feature.hpp"
