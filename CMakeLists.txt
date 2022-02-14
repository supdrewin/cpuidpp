## CPUID++ - C++ wrappers for X86 cpu model detection.
## Copyright (C) 2022  Supdrewin
##
## This library is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by the Free
## Software Foundation, either version 3 of the License, or (at your option)
## any later version.
##
## This library is distributed in the hope that it will be useful, but WITHOUT
## ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
## FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
## more details.
##
## You should have received a copy of the GNU General Public License along with
## this program.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required ( VERSION 3.12 )

project ( cpuid++ VERSION 0.1 LANGUAGES CXX )

set ( CMAKE_CXX_STANDARD 11 )

set ( CMAKE_CXX_STANDARD_REQUIRED ON )

set ( CMAKE_CXX_EXTENSIONS OFF )

if ( NOT UNIX )
  message ( FATAL_ERROR "Your OS is unsupported!" )
endif ( NOT UNIX )

include ( GNUInstallDirs )

add_compile_options (
  -Wall
  -Wextra
  -Weffc++
  -Wsign-conversion
  -pedantic-errors
)

add_library ( cpuid++ SHARED
  src/cpuid.cpp
  src/feature.cpp
)

install ( TARGETS cpuid++ LIBRARY )

target_include_directories ( cpuid++ PUBLIC include )

install (
  DIRECTORY   include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_PROJECT_NAME}
)

configure_file ( cpuid++.pc.in cpuid++.pc @ONLY )

install (
  FILES       ${CMAKE_BINARY_DIR}/cpuid++.pc
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
