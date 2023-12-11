
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

#include "PriorityQueue.h"

void PqPush(PriorityQueue *queue, int index, int priority) {
  // if queue is full, cannot add more elements
  if (queue->size == MAX_TASK_ID) {

  } else {
    int i;
    for (i = queue->size - 1; i >= 0; i--) {
      if (priority > queue->nodes[i].priority) {
        // Shift elements to make room for new element
        queue->nodes[i + 1] = queue->nodes[i];
      } else {
        break;
      }
    }
    queue->nodes[i + 1].index = index;
    queue->nodes[i + 1].priority = priority;
    queue->size++;
  }
}

int PqPop(PriorityQueue *queue) {
  int status;
  if (queue->size == 0) {
    // queue is empty, cannot pop elements
    status = -1;
  } else {
    status = queue->nodes[0].index;

    for (int i = 0; i < (queue->size - 1); i++) {
      queue->nodes[i] = queue->nodes[i + 1];
    }
    queue->size--;
  }

  return status;
}

int PqGetRoot(PriorityQueue *queue) {
  int status;

  // if queue is empty, cannot get root element
  if (queue->size != 0) {
    status = queue->nodes[0].index;
  } else {
    status = -1;
  }
  return status;
}

void PriorityQueue_init(PriorityQueue *queue) { queue->size = 0; }
