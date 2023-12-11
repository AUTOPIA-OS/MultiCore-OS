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

#ifndef REGISTER_OP_H
#define REGISTER_OP_H

/* ********************************************************************** */

#include <stdint.h>

/* ********************************************************************** */

void WriteToRegister(uint32_t baseAddress, uint32_t offSet, uint32_t value,
                     uint32_t bitOffsetStart, uint32_t bitOffsetEnd);
void writeFullRegister(uint32_t baseAddress, uint32_t value);
uint32_t ReadFromRegister(uint32_t baseAddress, uint32_t offSet);
uint64_t ReadFromRegister64(uint32_t baseAddress, uint32_t offSet);
void writeFull(uint32_t baseAddress, uint32_t value);

/* ********************************************************************** */

#endif /* REGISTER_OP_H */