/*
 *  Created on: 20 Nov 2017
 *      Author: Juri Bieler
 *  CAUTION: this implementation of a Stack is not overflow prove...
 *  it expects to be proper dimensioned, so that its head never catches its tail... if so the head will just take over
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
	uint16_t dec_pointer(uint16_t point);
	uint16_t inc_pointer(uint16_t point);

public:
	Stack();
	void init(T* storage, uint16_t size);
	void push(T in);
	T top();
	T* getTop();
	void pop();
	T get(uint16_t index);
	bool is_empty();
	bool has_line();
	uint16_t get_member_count();
	void clear();
};

#endif
