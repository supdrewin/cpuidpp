#include <iostream>
#include <string>

#include <cpuid++/cpuid.hpp>

int main() {
  std::cout << "vendor id: " << cpuid::vendor() << std::endl;

  std::cout << "model name: " << cpuid::processor_name() << std::endl;

  std::cout << "stepping: " << cpuid::stepping() << std::endl;

  std::cout << std::hex
            << "max standard func: " << cpuid::largest_standard_function()
            << "\nmax extended func: " << cpuid::largest_extended_function()
            << std::dec << std::endl;

  std::cout << "base MHz : " << cpuid::base_frequency() << std::endl;

  std::cout << "max MHz  : " << cpuid::max_frequency() << std::endl;

  std::cout << "bus MHz  : " << cpuid::bus_frequency() << std::endl;

  std::string flags;

  if (cpuid::check_feature(cpuid::feature::FPU))
    flags += "fpu ";

  if (cpuid::check_feature(cpuid::feature::VME))
    flags += "vme ";

  if (cpuid::check_feature(cpuid::feature::DE))
    flags += "de ";

  if (cpuid::check_feature(cpuid::feature::PSE))
    flags += "pse ";

  if (cpuid::check_feature(cpuid::feature::TSC))
    flags += "tsc ";

  if (cpuid::check_feature(cpuid::feature::MSR))
    flags += "msr ";

  if (cpuid::check_feature(cpuid::feature::PAE))
    flags += "pae ";

  if (cpuid::check_feature(cpuid::feature::MCE))
    flags += "mce ";

  if (cpuid::check_feature(cpuid::feature::CX8))
    flags += "cx8 ";

  if (cpuid::check_feature(cpuid::feature::APIC))
    flags += "apic ";

  if (cpuid::check_feature(cpuid::feature::SEP))
    flags += "sep ";

  if (cpuid::check_feature(cpuid::feature::MTRR))
    flags += "mtrr ";

  if (cpuid::check_feature(cpuid::feature::PGE))
    flags += "pge ";

  if (cpuid::check_feature(cpuid::feature::MCA))
    flags += "mca ";

  if (cpuid::check_feature(cpuid::feature::CMOV))
    flags += "cmov ";

  if (cpuid::check_feature(cpuid::feature::PAT))
    flags += "pat ";

  if (cpuid::check_feature(cpuid::feature::PSE36))
    flags += "pse36 ";

  if (cpuid::check_feature(cpuid::feature::CLFSH))
    flags += "clflush ";

  if (cpuid::check_feature(cpuid::feature::DTES64))
    flags += "dts ";

  if (cpuid::check_feature(cpuid::feature::ACPI))
    flags += "acpi ";

  if (cpuid::check_feature(cpuid::feature::MMX))
    flags += "mmx ";

  if (cpuid::check_feature(cpuid::feature::FXSR))
    flags += "fxsr ";

  if (cpuid::check_feature(cpuid::feature::SSE))
    flags += "sse ";

  if (cpuid::check_feature(cpuid::feature::SSE2))
    flags += "sse2 ";

  if (cpuid::check_feature(cpuid::feature::SS))
    flags += "ss ";

  if (cpuid::check_feature(cpuid::feature::HTT))
    flags += "ht ";

  if (cpuid::check_feature(cpuid::feature::TM))
    flags += "tm ";

  if (cpuid::check_feature(cpuid::feature::PBE))
    flags += "pbe";

  std::cout << "flags: " << flags << std::endl;

  std::cout << "SMT  : " << cpuid::enabled_logical_processors::smt()
            << std::endl;

  std::cout << "core : " << cpuid::enabled_logical_processors::core()
            << std::endl;

  return 0;
}
