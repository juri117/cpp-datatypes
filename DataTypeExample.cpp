//============================================================================
// Name        : CppPlayground.cpp
// Author      : Juri Bieler
// Version     :
// Copyright   : none
// Description : test file for Stack and Queue
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "stdint.h"
using namespace std;

#include "Stack.hpp"
#include "Queue.hpp"

typedef Stack<uint8_t> IntStack;
typedef Queue<uint8_t> IntQueue;

IntStack stack;
IntQueue que;

void stackPush(uint8_t val) {
	stack.push(val);
	printf("push, top %d\n", stack.top());
}

void stackPop() {
	stack.pop();
	printf("pop, top %d\n", stack.top());
}

void quePush(uint8_t val) {
	que.push(val);
	printf("push, top %d\n", que.top());
}

void quePop() {
	que.pop();
	printf("pop, top %d\n", que.top());
}

int main() {
	printf("--------------------n");
	printf("test Stack...\n");

	uint8_t buffS[5];
	stack.init(buffS, 5);
	stackPush(1);
	stackPush(2);
	stackPush(3);
	stackPush(4);
	stackPop();
	stackPop();
	stackPush(5);
	stackPush(6);
	stackPush(7);
	stackPush(8);
	stackPush(9);
	stackPush(10);
	stackPop();
	printf("get 0 %d\n", stack.get(0));
	printf("get 0 %d\n", stack.get(0));
	printf("get 1 %d\n", stack.get(1));
	printf("get 2 %d\n", stack.get(2));
	printf("get 3 %d\n", stack.get(3));
	printf("get 4 %d\n", stack.get(4));
	printf("get 5 %d\n", stack.get(5));
	printf("get 6 %d\n", stack.get(6));
	printf("get 7 %d\n", stack.get(7));

	printf("--------------------n");
	printf("test Queue...\n");

	uint8_t buffQ[5];
	que.init(buffQ, 5);
	quePush(1);
	quePush(2);
	quePush(3);
	quePush(4);
	quePop();
	quePop();
	quePush(5);
	quePush(6);
	quePop();
	printf("get 0 %d\n", que.get(0));
	printf("get 0 %d\n", que.get(0));
	printf("get 1 %d\n", que.get(1));
	printf("get 2 %d\n", que.get(2));
	printf("get 3 %d\n", que.get(3));
	printf("get 4 %d\n", que.get(4));
	printf("get 5 %d\n", que.get(5));
	printf("get 6 %d\n", que.get(6));
	printf("get 7 %d\n", que.get(7));

	return 0;
}