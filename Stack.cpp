/*
 *  Created on: 20 Nov 2017
 *      Author: Juri Bieler
 */

#include "Stack.hpp"

/**
 * @param storage is an array of type T, make sure it stays alive while this instance is alive...
 * @param size is the storages size
 */
template <class T>
Stack<T>::Stack() {
	this->size = 0;
	this->writePoint = 0;
	this->memberCount = 0;
}

template <class T>
void Stack<T>::init(T* storage, uint16_t size) {
	this->buff = storage;
	this->size = size;
	this->writePoint = 0;
	this->memberCount = 0;
}

template <class T>
void Stack<T>::push(T in) {
	this->buff[this->writePoint] = in;
	this->writePoint = this->inc_pointer(this->writePoint);
	if(this->memberCount < this->size){
		this->memberCount++;
	}
}

template <class T>
T Stack<T>::top() {
	T out = this->buff[this->dec_pointer(this->writePoint)];
	return out;
}

template <class T>
T* Stack<T>::getTop() {
	T* out = &buff[this->dec_pointer(this->writePoint)];
	return out;
}

template <class T>
void Stack<T>::pop() {
	this->writePoint = this->dec_pointer(this->writePoint);
	if(this->memberCount > 0){
		this->memberCount--;
	}
}

template <class T>
T Stack<T>::get(uint16_t index) {
	index = index % this->size;
	uint16_t i = this->dec_pointer(this->writePoint);
	if(i < index){
		i = this->size - (index - i);
	} else {
		i -= index;
	}
	T outByte = this->buff[i];
	return outByte;
}

template <class T>
bool Stack<T>::is_empty(){
	return this->memberCount == 0;
}

template <class T>
uint16_t Stack<T>::dec_pointer(uint16_t point) {
	if (point == 0) {
		point = this->size;
	}
	point--;
	return point;
}

template <class T>
uint16_t Stack<T>::inc_pointer(uint16_t point) {
	point++;
	if (point >= this->size) {
		point = 0;
	}
	return point;
}

template <class T>
uint16_t Stack<T>::get_member_count(){
	return this->memberCount;
}

template <class T>
void Stack<T>::clear(){
	this->writePoint = 0;
	this->memberCount = 0;
}

template class Stack<uint8_t>;
