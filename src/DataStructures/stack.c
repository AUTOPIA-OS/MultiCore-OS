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

#include "stack.h"

bool StackIsEmpty(Stack *stack) { return (stack->size == 0); }

void StackPush(Stack *stack, int index) {
  // check ifstack is full
  if (stack->size == STACK_SIZE) {
  } else {
    stack->nodes[stack->size] = index;
    stack->size++;
  }
}

int StackPop(Stack *stack) {
  int status;
  if (stack->size > 0) {
    status = stack->nodes[0];
    for (int i = 0; i < (stack->size - 1); i++) {
      stack->nodes[i] = stack->nodes[i + 1];
    }
    stack->size--;
  } else {
    status = -1;
  }
  return status;
}

void StackInit(Stack *stack) { stack->size = 0; }
