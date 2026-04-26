#include "Input.hpp"

#include <iostream>

void ShiftDownInput::Input::debug_test() {

  uint64_t i{0};

  while (keyboard_events[i][5] != '\0') {
    std::cout << "Keyboard: " << keyboard_events[i] << std::endl;
    i++;
  }
  i = 0;
  while (mouse_events[i][5] != '\0') {
    std::cout << "Mouse: " << mouse_events[i] << std::endl;
    i++;
  }
  i = 0;
  while (joysticks_events[i][5] != '\0') {
    std::cout << "Joystick: " << joysticks_events[i] << std::endl;
    i++;
  }
  i = 0;
  while (headphones_events[i][5] != '\0') {
    std::cout << "Headphones: " << headphones_events[i] << std::endl;
    i++;
  }
}