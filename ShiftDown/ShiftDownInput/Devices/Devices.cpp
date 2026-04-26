#include "Devices.hpp"
#include "../../ShiftDownParsers/Parsers.hpp"

#include <iostream>
#include <fstream>

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
    std::cout << "EV: " << std::hex << evs[evs_index];
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

  //debug kategorii czy to dziala ? w ogole XD
  std::cout << std::endl;
  std::cout << "=================KEYBOARDS=================" << std::endl;
  for (uint64_t i = 0; i < 16; i++) {
    if (keyboards[i].name[0] == '\0') continue;
    std::cout << "NAME=" << keyboards[i].name << std::endl;
    std::cout << "EV=" << keyboards[i].ev << std::endl;
    std::cout << "EVENT=" << keyboards[i].event << std::endl;
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "=================MOUSES=================" << std::endl;
  for (uint64_t i = 0; i < 16; i++) {
    if (mouses[i].name[0] == '\0') continue;
    std::cout << "NAME=" << mouses[i].name << std::endl;
    std::cout << "EV=" << mouses[i].ev << std::endl;
    std::cout << "EVENT=" << mouses[i].event << std::endl;
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "=================JOYSTICKS=================" << std::endl;
  for (uint64_t i = 0; i < 16; i++) {
    if (joysticks[i].name[0] == '\0') continue;
    std::cout << "NAME=" << joysticks[i].name << std::endl;
    std::cout << "EV=" << joysticks[i].ev << std::endl;
    std::cout << "EVENT=" << joysticks[i].event << std::endl;
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "=================HEADPHONES=================" << std::endl;
  for (uint64_t i = 0; i < 16; i++) {
    if (headphones[i].name[0] == '\0') continue;
    std::cout << "NAME=" << headphones[i].name << std::endl;
    std::cout << "EV=" << headphones[i].ev << std::endl;
    std::cout << "EVENT=" << headphones[i].event << std::endl;
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "=================SPEAKERS=================" << std::endl;
  for (uint64_t i = 0; i < 16; i++) {
    if (speakers[i].name[0] == '\0') continue;
    std::cout << "NAME=" << speakers[i].name << std::endl;
    std::cout << "EV=" << speakers[i].ev << std::endl;
    std::cout << "EVENT=" << speakers[i].event << std::endl;
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "=================CHUJ WIE CO=================" << std::endl;
  for (uint64_t i = 0; i < 16; i++) {
    if (chuj_wie_co_to[i].name[0] == '\0') continue;
    std::cout << "NAME=" << chuj_wie_co_to[i].name << std::endl;
    std::cout << "EV=" << chuj_wie_co_to[i].ev << std::endl;
    std::cout << "EVENT=" << chuj_wie_co_to[i].event << std::endl;
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
              evs[evs_index-1] = ShiftDownParsers::pars_uint64_hex(ev_temp_buffer);
            }
          }
        }
      }
    }
  }
}

void ShiftDownDevices::Devices::categorize() const{

  uint64_t ki{0};
  uint64_t mi{0};
  uint64_t ji{0};
  uint64_t hi{0};
  uint64_t si{0};
  uint64_t ci{0};

  for (uint64_t i = 0; i < event_count; i++) {
    uint64_t temp_evs = evs[i];

    if (temp_evs == 0) continue;

    //bool ev_sync = temp_evs & 0x1;
    bool ev_key  = temp_evs & 0x2;
    bool ev_rel  = temp_evs & 0x4;
    bool ev_abs  = temp_evs & 0x8;
    //bool ev_msv  = temp_evs & 0x10;
    //bool ev_sw   = temp_evs & 0x20;
    //bool ev_led  = temp_evs & 0x20000;
    bool ev_snd  = temp_evs & 0x40000;
    bool ev_rep  = temp_evs & 0x100000;
    //bool ev_ff   = temp_evs & 0x200000;

    device_info info(i * name_lenght, evs[i], events[i], name_lenght, names);

    if (ev_key) {
      // ma przyciski to filtracja leci
      if (ev_rel) {
        // osie relatywne, myszki maja
        mouses[mi++] = info;
      }
      else if (ev_abs) {
        //osie absolutne, to bardziej joysticki
        joysticks[ji++] = info;
      }
      else if (ev_rep) {
        // jesli nie myszka to klawa co nie?
        keyboards[ki++] = info;
      }
      else {
        //sluchawki, jak ma klikanie ale bez innych pierdol
        headphones[hi++] = info;
      }
    }
    else if (ev_snd) {
      // piszczy, bez klawiszy
      speakers[si++] = info;
    }
    else {
      //reszta syfu i gowna co nie ma kategorii XD
      chuj_wie_co_to[ci++] = info;
    }
  }
}