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
  T *buff;
  uint16_t size;
  uint16_t writePoint;
  uint16_t readPoint;
  uint16_t current_size = 0;

  void inc_read_pointer() {
    if (!is_empty()) {
      this->readPoint++;
      if (this->readPoint >= this->size) {
        this->readPoint = 0;
      }
      if (this->current_size > 0) this->current_size--;
    }
    // printf("read %d (size: %d)\n", this->readPoint, this->current_size);
  }

  void inc_write_pointer() {
    this->writePoint++;
    if (this->writePoint >= this->size) {
      this->writePoint = 0;
    }
    if (!this->is_full()) {
      this->current_size++;
    } else {
      this->readPoint++;
      if (this->readPoint >= this->size) {
        this->readPoint = 0;
      }
    }
    // printf("write %d (size: %d)\n", this->writePoint, this->current_size);
  }

 public:
  Queue() {
    this->size = 0;
    this->writePoint = 0;
    this->readPoint = 0;
    this->buff = nullptr;
  }
  void init(T *storage, uint16_t size) {
    this->buff = storage;
    this->size = size;
    this->writePoint = 0;
    this->readPoint = 0;
  }
  void push(const T *in) {
    this->buff[this->writePoint] = *in;
    this->inc_write_pointer();
  }
  void push(const T in) {
    this->buff[this->writePoint] = in;
    this->inc_write_pointer();
  }
  T push_get_pointer() {
    T pointer = this->buff[this->writePoint];
    this->inc_write_pointer();
    return pointer;
  }
  T top() {
    T out = this->buff[this->readPoint];
    this->inc_read_pointer();
    return out;
  }
  T *getTopPoint() {
    T *out = &buff[this->readPoint];
    return out;
  }
  T getTop() {
    T out = buff[this->readPoint];
    return out;
  }
  void pop() { this->inc_read_pointer(); }
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
  bool is_empty() { return this->current_size == 0; }
  bool is_full() { return this->current_size >= size; }
  uint16_t get_member_count() { return this->current_size; }
  void clear() {
    this->writePoint = 0;
    this->readPoint = 0;
    this->current_size = 0;
  }
};

#endif