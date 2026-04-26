#include "ShiftDownParsers/Parsers.hpp"

#include "ShiftDownInput/Devices/Devices.hpp"


#include <iostream>

int main() {
  //uint64_t liczba = ShiftDownParsers::pars_uint64("3");
  //std::cout << liczba;


  ShiftDownDevices::Devices test;
  test.debug_test();


  return 0;
}