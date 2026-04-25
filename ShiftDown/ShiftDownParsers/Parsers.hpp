#pragma once
#include <cstdint>

namespace ShiftDownParsers{

inline uint64_t pars_uint64_hex(const char* number) {
  uint64_t parsed_number{0};
  uint64_t miejsce{0};

  uint64_t i{0};
  do{i++;}while (number[i] != '\0' && number[i] != '\n');
  i--;

  do {
    uint64_t temp_number{0};
    switch (number[i]) {
    case '0':
      temp_number = 0b00000000;

      temp_number = temp_number << (4 * miejsce);

      parsed_number |= temp_number;
      break;
    case '1':
      temp_number = 0b00000001;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case '2':
      temp_number = 0b00000010;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case '3':
      temp_number = 0b00000011;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case '4':
      temp_number = 0b00000100;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case '5':
      temp_number = 0b00000101;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case '6':
      temp_number = 0b00000110;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case '7':
      temp_number = 0b00000111;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case '8':
      temp_number = 0b00001000;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case '9':
      temp_number = 0b00001001;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'A':
      temp_number = 0b00001010;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'B':
      temp_number = 0b00001011;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'C':
      temp_number = 0b00001100;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'D':
      temp_number = 0b00001101;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'E':
      temp_number = 0b00001110;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'F':
      temp_number = 0b00001111;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'a':
      temp_number = 0b00001010;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'b':
      temp_number = 0b00001011;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'c':
      temp_number = 0b00001100;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'd':
      temp_number = 0b00001101;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'e':
      temp_number = 0b00001110;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    case 'f':
      temp_number = 0b00001111;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    default:
      temp_number = temp_number & number[i] & 0b00001111;
      temp_number = temp_number << (4 * miejsce);
      parsed_number |= temp_number;
      break;
    }

    miejsce++;
    i--;
  } while (i+1 != 0);


  return parsed_number;
}

inline uint64_t pars_uint64(const char* number) {
  uint64_t miejsce{0};
  uint64_t parsed_number{0};
  uint64_t i{0};

  do{i++;}while (number[i] != '\0' && number[i] != '\n');
  i--;

  do {
    uint64_t temp_number{0};

    temp_number = number[i] & 0b00001111;
    for (uint64_t k = 0; k != miejsce; k++) {
      temp_number = temp_number * 10;
    }
    parsed_number += temp_number;
    miejsce++;

    i--;
  } while (i+1 > 0);

  return parsed_number;
}


}