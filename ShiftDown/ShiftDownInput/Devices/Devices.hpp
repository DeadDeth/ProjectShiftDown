#pragma once

#include <fstream>
#include <immintrin.h>

namespace ShiftDownDevices {

class Devices {
  //zmienne dla tablic z eventami i urzadzeniami :)
  uint64_t event_count{64};
  uint64_t name_lenght{64};
  uint64_t* evs;
  uint64_t* events;
  char* names;
  void find_devices() const; // ta funckja szuka tego gowna w /proc/bus/input/devices
  //========================================================

  //kategoryzowanie tego syfu XDDD zeby dalo sie korzystac ze wszystkiego :)
  struct alignas(64) device_info {
    char name[64]{'\0'};
    uint64_t ev{0};
    uint64_t event{0};

    device_info(uint64_t device_name_index, uint64_t device_ev, uint64_t device_event, uint64_t name_lenght,const char* names){
      for (uint64_t i = 0; i < name_lenght; i++) {
        name[i] = names[device_name_index + i];
      }
      ev = device_ev;
      event = device_event;
    }
    ~device_info() = default;
  };
  device_info* keyboards;
  device_info* mouses;
  device_info* joysticks;
  device_info* headphones;
  device_info* speakers;
  device_info* chuj_wie_co_to;
  void categorize() const;
  //========================================================

public:
  Devices() {

    evs = (uint64_t*)_mm_malloc(sizeof(uint64_t) * event_count, 64);
    events = (uint64_t*)_mm_malloc(sizeof(uint64_t) * event_count, 64);
    names = (char*)_mm_malloc(sizeof(char) * event_count * name_lenght, 64);


    keyboards = (device_info*)_mm_malloc(sizeof(device_info) * 16, 64);
    mouses = (device_info*)_mm_malloc(sizeof(device_info) * 16, 64);
    joysticks = (device_info*)_mm_malloc(sizeof(device_info) * 16, 64);
    headphones = (device_info*)_mm_malloc(sizeof(device_info) * 16, 64);
    speakers = (device_info*)_mm_malloc(sizeof(device_info) * 16, 64);
    chuj_wie_co_to = (device_info*)_mm_malloc(sizeof(device_info) * 16, 64);

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
    //kategoryzowanie syfu
    categorize();

    //usuwanie tablic bo smieca tylko i w chuj ramu to je

  }
  ~Devices(){
    _mm_free(evs);
    _mm_free(names);
    _mm_free(events);
    _mm_free(keyboards);
    _mm_free(mouses);
    _mm_free(joysticks);
    _mm_free(headphones);
    _mm_free(speakers);
    _mm_free(chuj_wie_co_to);
  }
  void debug_test() const;
};

}



