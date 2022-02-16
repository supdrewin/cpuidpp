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

namespace cpuid {

// Warning: at least pointer `info + 3` still vailed
inline auto get(unsigned *info) -> void {
  asm volatile("cpuid"
               : "+a"(info[0]), "+b"(info[1]), // We will directly modify
                 "+c"(info[2]), "+d"(info[3])  // elements info[0..=3]
  );
}

} // namespace cpuid
