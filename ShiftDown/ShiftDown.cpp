#include <iostream>

int main() {

  uint64_t iterations{0};

  for (uint64_t i = 0; i < 1024; i++) {
    iterations++;
  }
  std::cout << "Iterations after normal loop: " << iterations << std::endl;
  uint64_t iterations_temp = iterations;
  iterations = 0;

  for (uint64_t i = 0; i < 1024; i+=16) {
    iterations++;
  }
  std::cout << "Iterations after avx512 loop: " << iterations << std::endl;


  std::cout << "This much faster: " << iterations_temp / iterations << " times" << std::endl;
  return 0;
}



