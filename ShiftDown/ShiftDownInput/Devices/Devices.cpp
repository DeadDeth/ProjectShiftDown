#include "Devices.hpp"
#include "fstream"


void ShiftDownDevices::Devices::find_devices() {

  uint64_t evs_index{0};
  uint64_t names_index{0};
  uint64_t events_index{0};


  std::ifstream devices("/proc/bus/input/devices", std::ios::binary);
  char sign{'\0'};
  while (devices.get(sign)) {

    if (sign == 'N') {
      devices.get(sign);
      if (sign == ':') {
        devices.get(sign);
        if (sign == ' ') {
          uint64_t names_local_index{0};
          //logika brania name :)

          //sekcja Name=" pomineta
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);

          while (sign != '"') {
            names[names_index + names_local_index] = sign;
            names_local_index++;
            devices.get(sign);
          }
          names_index += name_lenght;
        }
      }
    }

    if (sign == 'H') {
      devices.get(sign);
      if (sign == ':') {
        //logika brania eventu :)
      }
    }

    if (sign == 'B') {
      devices.get(sign);
      if (sign == ':') {
        devices.get(sign);
        devices.get(sign);
        if (sign == 'E') {
          if (sign == 'V') {
            //logika brania eventu :)
          }
        }
      }
    }
  }
}