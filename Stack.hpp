/*
 *  Created on: 20 Nov 2017
 *      Author: Juri
 *  CAUTION: this implementation of a Stack is not overflow prove...
 *  it expects to be proper dimensioned, so that its head never catches its
 * tail... if so the head will just take over
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdint.h>

template <class T>

class Stack {
 private:
  T* buff;
  uint16_t size;

  uint16_t writePoint;
  uint16_t memberCount;
  uint16_t dec_pointer(uint16_t point) {
    if (point == 0) {
      point = this->size;
    }
    point--;
    return point;
  }
  uint16_t inc_pointer(uint16_t point) {
    point++;
    if (point >= this->size) {
      point = 0;
    }
    return point;
  }

 public:
  Stack() {
    this->size = 0;
    this->writePoint = 0;
    this->memberCount = 0;
    this->buff = nullptr;
  }
  void init(T* storage, uint16_t size) {
    this->buff = storage;
    this->size = size;
    this->writePoint = 0;
    this->memberCount = 0;
  }
  void push(const T* in) {
    this->buff[this->writePoint] = *in;
    this->writePoint = this->inc_pointer(this->writePoint);
    if (this->memberCount < this->size) {
      this->memberCount++;
    }
  }
  void push(const T in) {
    this->buff[this->writePoint] = in;
    this->writePoint = this->inc_pointer(this->writePoint);
    if (this->memberCount < this->size) {
      this->memberCount++;
    }
  }
  T top() {
    T out = this->buff[this->dec_pointer(this->writePoint)];
    this->pop();
    return out;
  }
  T* getTop() {
    T* out = &buff[this->dec_pointer(this->writePoint)];
    return out;
  }
  void pop() {
    this->writePoint = this->dec_pointer(this->writePoint);
    if (this->memberCount > 0) {
      this->memberCount--;
    }
  }
  T get(uint16_t index) {
    index = index % this->size;
    uint16_t i = this->dec_pointer(this->writePoint);
    if (i < index) {
      i = this->size - (index - i);
    } else {
      i -= index;
    }
    T outByte = this->buff[i];
    return outByte;
  }
  bool is_empty() { return this->memberCount == 0; }
  uint16_t get_member_count() { return this->memberCount; }
  void clear() {
    this->writePoint = 0;
    this->memberCount = 0;
  }
};

#endif
