#include <cpuid++/cpuid.hpp>
#include <iostream>

int main() {
  std::cout << "vendor_id       : " << cpuid::vendor() << std::endl;
  std::cout << "model name      : " << cpuid::processor_name() << std::endl;
  std::cout << "cpuid level     : " << cpuid::largest_standard_function()
            << std::endl;
  return 0;
}
