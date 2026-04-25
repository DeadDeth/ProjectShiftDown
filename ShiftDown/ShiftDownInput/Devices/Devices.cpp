#include "Devices.hpp"
#include "../../ShiftDownParsers/Parsers.hpp"

#include "fstream"

void ShiftDownDevices::Devices::debug_test() const{

  uint64_t evs_index{0};
  uint64_t event_index{0};
  for (uint64_t i = 0; i < event_count * name_lenght; i+= name_lenght) {
    if (names[i] == '\0') break;
    uint64_t k = i;
    while (names[k] != '\0') {
      std::cout << names[k];
      k++;
    }
    for (uint64_t j = k; j < i+name_lenght - 20; j++) {
      std::cout << " ";
    }
    std::cout << "EV: " << evs[evs_index];
    evs_index++;

    uint64_t temp_number_evs{evs[evs_index-1]};
    uint64_t lines_number{0};
    while (temp_number_evs >= 10) {
      temp_number_evs /= 10;
      lines_number++;
    }
    for (uint64_t j = 0; j < 10 - lines_number; j++) {
      std::cout << " ";
    }
    std::cout << "EVENT" << events[event_index];
    event_index++;
    std::cout << std::endl;
  }
}

void ShiftDownDevices::Devices::find_devices() const{

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
          evs_index++;
          events_index++;
        }
      }
    }

    if (sign == 'H') {
      devices.get(sign);
      if (sign == ':') {
        devices.get(sign);
        if (sign == ' ') {
          //logika brania eventu :)

          //skipwoanie handlesr reczenie bo czemu nie
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);
          devices.get(sign);

          char temp_event_buffor[8]{'\0'};
          while (true) {
            while (sign != '0' && sign != '1' && sign != '2' && sign != '3' && sign != '4' && sign != '5' && sign != '6' &&sign != '7' && sign != '8' &&sign != '9') {
              devices.get(sign);
            }
            for (uint64_t i = 0; i < 6; i++) {
              devices.unget();
            }
            for (uint64_t i = 0; i < 8; i++) {
              temp_event_buffor[i] = '\0';
            }
            for (uint64_t i = 0; i < 5; i++) {
              devices.get(temp_event_buffor[i]);
            }
            if (temp_event_buffor[0] == 'e' && temp_event_buffor[1] == 'v' && temp_event_buffor[2] == 'e' && temp_event_buffor[3] == 'n' && temp_event_buffor[4] == 't') {
              char temp_event_number_buffor[8]{'\0'};
              uint64_t temp_event_number_buffor_index{0};
              devices.get(sign);
              while (sign != '\n' && sign != ' ') {
                temp_event_number_buffor[temp_event_number_buffor_index] = sign;
                temp_event_number_buffor_index++;
                devices.get(sign);
              }
              events[events_index-1] = ShiftDownParsers::pars_uint64(temp_event_number_buffor);
              break;
            }
            else {
              devices.get(sign);
              devices.get(sign);
            }
          }
        }
      }
    }

    if (sign == 'B') {
      devices.get(sign);
      if (sign == ':') {
        devices.get(sign);
        devices.get(sign);
        if (sign == 'E') {
          devices.get(sign);
          if (sign == 'V') {
            devices.get(sign);
            if (sign == '=') {
              //logika brania eventu :)
              uint64_t ev_local_index{0};
              char ev_temp_buffer[8]{'\0'};
              while (sign != '\n') {
                devices.get(sign);
                ev_temp_buffer[ev_local_index] = sign;
                ev_local_index++;
              }
              evs[evs_index-1] = ShiftDownParsers::pars_uint64(ev_temp_buffer);
            }
          }
        }
      }
    }
  }
}