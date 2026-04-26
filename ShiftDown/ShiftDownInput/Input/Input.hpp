#pragma once
#include "../../ShiftDownParsers/Parsers.hpp"
#include "../Devices/Devices.hpp"

#include <cstdint>

namespace ShiftDownDevices {
class Devices;
}

namespace ShiftDownInput {

class Input {

  ShiftDownDevices::Devices* devices;

  char keyboard_events[16][8]{{'\0'},{'\0'}};
  char mouse_events[16][8]{{'\0'},{'\0'}};
  char joysticks_events[16][8]{{'\0'},{'\0'}};
  char headphones_events[16][8]{{'\0'},{'\0'}};

public:
  Input(ShiftDownDevices::Devices* devices_pointer) : devices(devices_pointer) {
    for (uint64_t i = 0; i < 16; i++) {
      if (devices->keyboards[i].name[0] != '\0' && devices->keyboards[i].name[0] != '\n') {
        keyboard_events[i][0] = 'e';
        keyboard_events[i][1] = 'v';
        keyboard_events[i][2] = 'e';
        keyboard_events[i][3] = 'n';
        keyboard_events[i][4] = 't';
        char temp_buf[21]{'\0'};
        ShiftDownParsers::pars_char(devices->keyboards[i].event, temp_buf);
        uint64_t kurwa_nie_wiem{0};
        uint64_t kurwa_znowu_nie_wiem{0};
        for (uint64_t j = 5; j < 8; j++) {
          if (temp_buf[17 + kurwa_nie_wiem] != '0' && temp_buf[17 + kurwa_nie_wiem] != '1' && temp_buf[17 + kurwa_nie_wiem] != '2' && temp_buf[17 + kurwa_nie_wiem] != '3' && temp_buf[17  + kurwa_nie_wiem] != '4' && temp_buf[17  + kurwa_nie_wiem] != '5' && temp_buf[17 + kurwa_nie_wiem] != '6' && temp_buf[17 + kurwa_nie_wiem] != '7' && temp_buf[17 + kurwa_nie_wiem] != '8' && temp_buf[17 + kurwa_nie_wiem] != '9') {
            kurwa_znowu_nie_wiem++;
          }
          else {
            keyboard_events[i][j-kurwa_znowu_nie_wiem] = temp_buf[17 + kurwa_nie_wiem];
          }
          kurwa_nie_wiem++;
        }
      }
    }
    for (uint64_t i = 0; i < 16; i++) {
      if (devices->mouses[i].name[0] != '\0' && devices->mouses[i].name[0] != '\n') {
        mouse_events[i][0] = 'e';
        mouse_events[i][1] = 'v';
        mouse_events[i][2] = 'e';
        mouse_events[i][3] = 'n';
        mouse_events[i][4] = 't';
        char temp_buf[21]{'\0'};
        ShiftDownParsers::pars_char(devices->mouses[i].event, temp_buf);
        uint64_t kurwa_nie_wiem{0};
        uint64_t kurwa_znowu_nie_wiem{0};
        for (uint64_t j = 5; j < 8; j++) {
          if (temp_buf[17 + kurwa_nie_wiem] != '0' && temp_buf[17 + kurwa_nie_wiem] != '1' && temp_buf[17 + kurwa_nie_wiem] != '2' && temp_buf[17 + kurwa_nie_wiem] != '3' && temp_buf[17  + kurwa_nie_wiem] != '4' && temp_buf[17  + kurwa_nie_wiem] != '5' && temp_buf[17 + kurwa_nie_wiem] != '6' && temp_buf[17 + kurwa_nie_wiem] != '7' && temp_buf[17 + kurwa_nie_wiem] != '8' && temp_buf[17 + kurwa_nie_wiem] != '9') {
            kurwa_znowu_nie_wiem++;
          }
          else {
            mouse_events[i][j-kurwa_znowu_nie_wiem] = temp_buf[17 + kurwa_nie_wiem];
          }
          kurwa_nie_wiem++;
        }
      }
    }
    for (uint64_t i = 0; i < 16; i++) {
      if (devices->joysticks[i].name[0] != '\0' && devices->joysticks[i].name[0] != '\n') {
        joysticks_events[i][0] = 'e';
        joysticks_events[i][1] = 'v';
        joysticks_events[i][2] = 'e';
        joysticks_events[i][3] = 'n';
        joysticks_events[i][4] = 't';
        char temp_buf[21]{'\0'};
        ShiftDownParsers::pars_char(devices->joysticks[i].event, temp_buf);
        uint64_t kurwa_nie_wiem{0};
        uint64_t kurwa_znowu_nie_wiem{0};
        for (uint64_t j = 5; j < 8; j++) {
          if (temp_buf[17 + kurwa_nie_wiem] != '0' && temp_buf[17 + kurwa_nie_wiem] != '1' && temp_buf[17 + kurwa_nie_wiem] != '2' && temp_buf[17 + kurwa_nie_wiem] != '3' && temp_buf[17  + kurwa_nie_wiem] != '4' && temp_buf[17  + kurwa_nie_wiem] != '5' && temp_buf[17 + kurwa_nie_wiem] != '6' && temp_buf[17 + kurwa_nie_wiem] != '7' && temp_buf[17 + kurwa_nie_wiem] != '8' && temp_buf[17 + kurwa_nie_wiem] != '9') {
            kurwa_znowu_nie_wiem++;
          }
          else {
            joysticks_events[i][j-kurwa_znowu_nie_wiem] = temp_buf[17 + kurwa_nie_wiem];
          }
          kurwa_nie_wiem++;
        }
      }
    }
    for (uint64_t i = 0; i < 16; i++) {
      if (devices->headphones[i].name[0] != '\0' && devices->headphones[i].name[0] != '\n') {
        headphones_events[i][0] = 'e';
        headphones_events[i][1] = 'v';
        headphones_events[i][2] = 'e';
        headphones_events[i][3] = 'n';
        headphones_events[i][4] = 't';
        char temp_buf[21]{'\0'};
        ShiftDownParsers::pars_char(devices->headphones[i].event, temp_buf);
        uint64_t kurwa_nie_wiem{0};
        uint64_t kurwa_znowu_nie_wiem{0};
        for (uint64_t j = 5; j < 8; j++) {
          if (temp_buf[17 + kurwa_nie_wiem] != '0' && temp_buf[17 + kurwa_nie_wiem] != '1' && temp_buf[17 + kurwa_nie_wiem] != '2' && temp_buf[17 + kurwa_nie_wiem] != '3' && temp_buf[17  + kurwa_nie_wiem] != '4' && temp_buf[17  + kurwa_nie_wiem] != '5' && temp_buf[17 + kurwa_nie_wiem] != '6' && temp_buf[17 + kurwa_nie_wiem] != '7' && temp_buf[17 + kurwa_nie_wiem] != '8' && temp_buf[17 + kurwa_nie_wiem] != '9') {
            kurwa_znowu_nie_wiem++;
          }
          else {
            headphones_events[i][j-kurwa_znowu_nie_wiem] = temp_buf[17 + kurwa_nie_wiem];
          }
          kurwa_nie_wiem++;
        }
      }
    }
  }
  ~Input() = default;

  void debug_test();
};
}