/*
 *  Created on: 20 Nov 2017
 *      Author: Juri
 *  CAUTION: this implementation of a ring Buffer (aka. Queue) is not overflow
 * prove... it expects to be proper dimensioned, so that its head never catches
 * its tail... if so the head will just take over
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "stdint.h"

template <class T>

class Queue {
 private:
  T* buff;
  uint16_t size;
  uint16_t writePoint;
  uint16_t readPoint;
  uint16_t inc_pointer(uint16_t point) {
    point++;
    if (point >= this->size) {
      point = 0;
    }
    return point;
  }

 public:
  Queue() {
    this->size = 0;
    this->writePoint = 0;
    this->readPoint = 0;
    this->buff = nullptr;
  }
  void init(T* storage, uint16_t size) {
    this->buff = storage;
    this->size = size;
    this->writePoint = 0;
    this->readPoint = 0;
  }
  void push(const T* in) {
    this->buff[this->writePoint] = *in;
    this->writePoint = this->inc_pointer(this->writePoint);
  }
void push(const T in) {
    this->buff[this->writePoint] = in;
    this->writePoint = this->inc_pointer(this->writePoint);
  }
  T push_get_pointer() {
    T pointer = this->buff[this->writePoint];
    this->writePoint = this->inc_pointer(this->writePoint);
    return pointer;
  }
  T top() {
    T out = this->buff[this->readPoint];
    this->readPoint = this->inc_pointer(this->readPoint);
    return out;
  }
  T* getTop() {
    T* out = &buff[this->readPoint];
    return out;
  }
  void pop() { this->readPoint = this->inc_pointer(this->readPoint); }
  T get(uint16_t index) {
    index = index % this->size;
    uint16_t i = this->readPoint;
    if (i + index >= this->size) {
      i += index - this->size;
    } else {
      i += index;
    }
    T outByte = this->buff[i];
    return outByte;
  }
  bool is_empty() { return this->readPoint == this->writePoint; }
  uint16_t get_member_count() {
    if (this->writePoint >= this->readPoint) {
      return this->writePoint - this->readPoint;
    }
    return this->size - (this->readPoint - this->writePoint) + 1;
  }
  void clear() {
    this->writePoint = 0;
    this->readPoint = 0;
  }
};

#endif
