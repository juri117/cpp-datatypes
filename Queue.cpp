/*
 *  Created on: 20 Nov 2017
 *      Author: Juri Bieler
 */

#include "Queue.hpp"

//template <class T>
//Queue<T>::Queue(){
//	//stupid dummy constructor
//}

/**
 * @param storage is a byte array, make sure it stays alive while this instance is alive...
 * @param size is the storages size
 */
template <class T>
Queue<T>::Queue() {
	this->size = 0;
	this->writePoint = 0;
	this->readPoint = 0;
}

template <class T>
void Queue<T>::init(T* storage, uint16_t size) {
	this->buff = storage;
	this->size = size;
	this->writePoint = 0;
	this->readPoint = 0;
}

template <class T>
void Queue<T>::push(T in) {
	this->buff[this->writePoint] = in;
	this->writePoint = this->inc_pointer(this->writePoint);
}

template <class T>
T Queue<T>::top() {
	T out = this->buff[this->readPoint];
//	this->readPoint = this->inc_pointer(this->readPoint);
	return out;
}

template <class T>
T* Queue<T>::getTop() {
	T* out = &buff[this->readPoint];
//	this->readPoint = this->inc_pointer(this->readPoint);
	return out;
}

template <class T>
void Queue<T>::pop() {
	this->readPoint = this->inc_pointer(this->readPoint);
}

template <class T>
T Queue<T>::get(uint16_t index) {
	index = index % this->size;
	uint16_t i = this->readPoint;
	if(i + index >= this->size){
		i += index - this->size;
	} else{
		i += index;
	}
	T outByte = this->buff[i];
	return outByte;
}

template <class T>
bool Queue<T>::is_empty(){
	return this->readPoint == this->writePoint;
}

template <class T>
uint16_t Queue<T>::inc_pointer(uint16_t point) {
	point++;
	if (point >= this->size) {
		point = 0;
	}
	return point;
}

template <class T>
uint16_t Queue<T>::get_member_count(){
	if(this->writePoint >= this->readPoint){
		return this->writePoint - this->readPoint;
	}
	return this->size - (this->readPoint - this->writePoint);
}

template <class T>
void Queue<T>::clear(){
	this->writePoint = 0;
	this->readPoint = 0;
}

template class Queue<uint8_t>;
