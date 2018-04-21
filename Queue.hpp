/*
 *  Created on: 20 Nov 2017
 *      Author: Juri Bieler
 *  CAUTION: this implementation of a ring Buffer (aka. Queue) is not overflow prove...
 *  it expects to be proper dimensioned, so that its head never catches its tail... if so the head will just take over
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
	uint16_t inc_pointer(uint16_t point);

public:
	Queue();
	void init(T* storage, uint16_t size);
	void push(T in);
	T top();
	T* getTop();
	void pop();
	T get(uint16_t index);
	bool is_empty();
	uint16_t get_member_count();
	void clear();
};

#endif
