# CPUID++

C++ wrappers for X86 cpu model detection.

### Pre-Request

- Compiler: g++ / clang++
- OS:       any `Unix-like` OS is Ok.
- git
- cmake
- pkg-config

First Step, use `git` to clone this repository:

``` shell
$ git clone https://github.com/supdrewin/cpuidpp.git
$ cd cpuidpp
```

### Build

``` shell
$ cmake -S . -B build
$ cmake --build build
```

### Install

This step requests root permission,
you need to use `sudo` or others if you aren't root.

``` shell
$ cmake --install build
```

### Usage

Start your new project, like following:

``` text
<Project Root>
|_ CMakeLists.txt
|_ main.cpp
```

Minimized `CMakeLists.txt`:

``` cmake
# `pkg_check_modules()`'s `IMPORTED_TARGET` request 3.6.
cmake_minimum_required ( VERSION 3.6 )

# Replace `project_name` to your own project name.
project ( project_name CXX )

# Request the `PkgConfig` package.
find_package ( PkgConfig REQUIRED )

# Import `cpuid++` as `CPUID++` so we can call `PkgConfig::CPUID++`.
pkg_check_modules ( CPUID++ REQUIRED IMPORTED_TARGET cpuid++ )


# Add your executable, replace `target_name`.
add_executable ( target_name
  # Add your source files here.
  main.cpp
)

# Link the library using `PkgConfig::CPUID++` we previous imported.
target_link_libraries ( target_name PRIVATE PkgConfig::CPUID++ )

```

We have added `main.cpp` to `CMakeLists.txt`.

Now we can hacking with `main.cpp`, e.g.

``` cpp
// We need to see output...
#include <iostream>

// All we do just include it.
#include <cpuid++/cpuid.hpp>

int main() {
  // All methods leading with `cpuid` namespace.
  // Then we call `processor_name()` to get a string
  // contains your processor's name.
  std::cout << cpuid::processor_name() << std::endl;

  // We use `check_feature(cpuid::feature)` to check a feature.
  // Then we check if the processor support PAE.
  if (cpuid::check_feature(cpuid::feature::PAE))
    std::cout << "This processor support PAE!" << std::endl;

  return 0;
}
```

Everything is Ok now, then we build it.

Do this from your project root:

``` shell
$ cmake -S . -B build # src dir is current dir, build dir is `build`
$ cmake --build build # use cmake to build the `build` dir
```

Then we run the program:

``` shell
$ build/target_name # If you replace the `target_name` previous,
                    # replacing it here together.
```

This is a possible output with previous sample:

``` output
Intel(R) Core(TM) XX-XXXXXX CPU @ X.XXGHz
This processor support PAE!
```

### Bugs

If you have any issues,
[Open issues here](https://github.com/supdrewin/cpuidpp/issues).

Also,
[Pull requests](https://github.com/supdrewin/cpuidpp/pulls)
is welcome!
