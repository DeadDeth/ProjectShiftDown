#pragma once

#include <fstream>
#include <immintrin.h>

#include <iostream>

namespace ShiftDownDevices {

class Devices {
  //zmienne dla tablic z eventami i urzadzeniami :)
  uint64_t event_count{64};
  uint64_t name_lenght{64};

  uint64_t* evs;
  uint64_t* events;
  char* names;


  void find_devices() const; // ta funckja szuka tego gowna w /proc/bus/input/devices


public:
  Devices() {

    evs = (uint64_t*)_mm_malloc(sizeof(uint64_t) * event_count, 64);
    names = (char*)_mm_malloc(sizeof(char) * event_count * name_lenght, 64);
    events = (uint64_t*)_mm_malloc(sizeof(uint64_t) * event_count, 64);

    //zerowanie tablic
    for (uint64_t i = 0; i < event_count; i++) {
      evs[i] = 0;
    }
    for (uint64_t i = 0; i < event_count * name_lenght; i++) {
      names[i] = '\0';
    }
    for (uint64_t i = 0; i < event_count; i++) {
      events[i] = 0;
    }
    //wolanie tego co tego szuka XD
    find_devices();
  }
  ~Devices(){
    _mm_free(evs);
    _mm_free(names);
    _mm_free(events);
  }
  void debug_test() const;
};



}



