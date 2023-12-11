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

#include "PriorityQueueTimer.h"

void PriorityQueueTimerPush(PriorityQueueTimer *queue, int index,
                            uint64_t time) {

  // if queue is full, cannot add more elements
  if (queue->size == MAX_TASK_ID) {
  } else {
    int i;
    for (i = queue->size - 1; i >= 0; i--) {
      if (time < queue->nodes[i].time) {
        // Shift elements to make room for new element
        queue->nodes[i + 1] = queue->nodes[i];
      } else {
        break;
      }
    }
    queue->nodes[i + 1].index = index;
    queue->nodes[i + 1].time = time;
    queue->size++;
  }
  return;
}

int PqPopTimer(PriorityQueueTimer *queue) {
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

int PqGetRootTimer(PriorityQueueTimer *queue) {
  int status;
  // if queue is empty, cannot get root element
  if (queue->size != 0) {
    status = queue->nodes[0].index;
  } else {
    status = -1;
  }
  return status;
}

int PqGetLastTimer(PriorityQueueTimer *queue) {
  int status;
  // if queue is empty, cannot get last element
  if (queue->size != 0) {
    status = queue->nodes[queue->size - 1].index;
  } else {
    status = -1;
  }
  return status;
}

int PqPopElementTimer(PriorityQueueTimer *queue, int index) {
  int status = -1;
  if (queue->size == 0) {
    // queue is empty, cannot pop elements
  } else {
    int i;
    for (i = 0; i < queue->size; i++) {
      if (queue->nodes[i].index == index) {
        // Found the element to remove
        status = queue->nodes[i].index;
        for (int j = i; j < (queue->size - 1); j++) {
          queue->nodes[j] = queue->nodes[j + 1];
        }
        queue->size--;
        break;
      }
    }
  }
  return status;
}

void PriorityQueueTimer_init(PriorityQueueTimer *queue) { queue->size = 0; }


