cmake_minimum_required ( VERSION 3.6 )

project ( tests CXX )

find_package ( PkgConfig REQUIRED )

pkg_check_modules ( CPUID++ REQUIRED IMPORTED_TARGET cpuid++ )

add_executable ( test main.cpp )

target_link_libraries ( test PRIVATE PkgConfig::CPUID++ )
