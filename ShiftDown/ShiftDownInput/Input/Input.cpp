#include "Input.hpp"

#include <iostream>
#include <fstream>

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


void ShiftDownInput::Input::start_reading_input() {
  uint64_t i{0};

  //wymaga uprawnien root do odpalenia sie wszystkich plikow pomyslnie

  char file_path[11+8] = "/dev/input/";
  while (keyboard_events[i][5] != '\0') {
    for (uint64_t k = 0; k < 8; k++) {
      file_path[k+11] = keyboard_events[i][k];
    }
    keyboards_files[i].open(file_path, std::ios::binary);
    // if (keyboards_files[i]) {
    //   std::cout << "Plik otwarty keyboard: " << file_path <<std::endl;
    // }
    i++;
  }
  i = 0;
  while (mouse_events[i][5] != '\0') {
    for (uint64_t k = 0; k < 8; k++) {
      file_path[k+11] = mouse_events[i][k];
    }
    mouse_files[i].open(file_path, std::ios::binary);
    // if (mouse_files[i]) {
    //   std::cout << "Plik otwarty mouse: " << file_path <<std::endl;
    // }
    i++;
  }
  i = 0;
  while (joysticks_events[i][5] != '\0') {
    for (uint64_t k = 0; k < 8; k++) {
      file_path[k+11] = joysticks_events[i][k];
    }
    joysticks_files[i].open(file_path, std::ios::binary);
    // if (joysticks_files[i]) {
    //   std::cout << "Plik otwarty joystick: " << file_path <<std::endl;
    // }
    i++;
  }
  i = 0;
  while (headphones_events[i][5] != '\0') {
    for (uint64_t k = 0; k < 8; k++) {
      file_path[k+11] = headphones_events[i][k];
    }
    headphones_files[i].open(file_path, std::ios::binary);
    // if (headphones_files[i]) {
    //   std::cout << "Plik otwarty headphones: " << file_path <<std::endl;
    // }
    i++;
  }

  i = 0;
  while (keyboard_events[i][5] != '\0') {
    keyboards_files[i].close();
    i++;
  }
  i = 0;
  while (mouse_events[i][5] != '\0') {
    mouse_files[i].close();
    i++;
  }
  i = 0;
  while (joysticks_events[i][5] != '\0') {
    joysticks_files[i].close();
    i++;
  }
  i = 0;
  while (headphones_events[i][5] != '\0') {
    headphones_files[i].close();
    i++;
  }


  get_keyboard_input();
  get_mouse_position_and_input();
};


char ShiftDownInput::Input::get_keyboard_input() {


  return 0;
}

uint64_t ShiftDownInput::Input::get_mouse_position_and_input() {


  return 0;
}