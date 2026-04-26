#pragma once

#include "Devices/Devices.hpp"
#include "Input/Input.hpp"
#include "Output/Output.hpp"


namespace ShiftDown {
  inline void ShiftDownInputStart() {
    ShiftDownDevices::Devices devices;
    //devices.debug_test();
    ShiftDownInput::Input input(&devices);
    input.debug_test();
    
    //ShiftDownOutput::Output output;

  }
}