//   Copyright 2023 AUC-Siemens Thesis Project
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#include "RegisterMacros.h"

void WriteToRegister(uint32_t baseAddress, uint32_t offSet, uint32_t value,
                     uint32_t bitOffsetStart, uint32_t bitOffsetEnd) {

  // Calculate the memory address of the register to write to
  uint32_t address = baseAddress | offSet;

  // Create a pointer to the register in memory
  volatile uint32_t *setter = (uint32_t *)address;

  // Create a bit mask to isolate the bits of the register that will be modified
  uint32_t UnsignedOne = 1;
  uint32_t mask =
      ((UnsignedOne << (bitOffsetEnd - bitOffsetStart + UnsignedOne)) -
       UnsignedOne)
      << bitOffsetStart;

  // Read the current value of the register
  uint32_t currentValue = *setter;

  // Clear the bits of the register that correspond to the mask
  currentValue &= ~mask;

  // Set the bits of the register that correspond to the masked value of 'value'
  currentValue |= (value << bitOffsetStart) & mask;

  // Write the modified value back to the register
  *setter = currentValue;
}

// To read from 32 bit register
uint32_t ReadFromRegister(uint32_t baseAddress, uint32_t offSet) {

  // Calculate the memory address of the register to read from
  uint32_t address = baseAddress | offSet;

  // Create a pointer to the register in memory
  volatile uint32_t *getter = (volatile uint32_t *)address;

  // Read the current value of the register
  uint32_t currentValue = *getter;

  return currentValue;
}

// To read from 64 bit register
uint64_t ReadFromRegister64(uint32_t baseAddress, uint32_t offSet) {

  // Calculate the memory address of the register to read from
  uint32_t address = baseAddress | offSet;

  // Create a pointer to the register in memory
  volatile uint32_t *const getter = (uint32_t *const)address;

  // Read the current value of the register
  uint64_t currentValue = *getter;

  return currentValue;
}