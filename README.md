# cppDatatypes

* Template implementations of Queue and Stack in c++.
* The stack or queue will be instanciated with a fixed size.
* Implementation is in the header file to prevent problems with template class creation using different data-types.

## example

build:
```
g++ DataTypeExample.cpp
```

```cpp
/*
 *  Created on: 20 Nov 2017
 *      Author: Juri
 */

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

void stackPush(uint8_t* val) {
	stack.push(val);
	printf("push by pointer, top %d\n", stack.top());
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
	printf("--------------------\n");
	printf("test Stack...\n");

	uint8_t buffS[5];
	stack.init(buffS, 5);
	stackPush(1);
    // push by pointer
    uint8_t val = 2;
	stackPush(&val);
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
	printf("get 1 %d\n", stack.get(1));
	printf("get 2 %d\n", stack.get(2));
	printf("get 3 %d\n", stack.get(3));
	printf("get 4 %d\n", stack.get(4));
	printf("get 5 %d\n", stack.get(5));
	printf("get 6 %d\n", stack.get(6));
	printf("get 7 %d\n", stack.get(7));

	printf("--------------------\n");
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
	printf("get 1 %d\n", que.get(1));
	printf("get 2 %d\n", que.get(2));
	printf("get 3 %d\n", que.get(3));
	printf("get 4 %d\n", que.get(4));
	printf("get 5 %d\n", que.get(5));
	printf("get 6 %d\n", que.get(6));
	printf("get 7 %d\n", que.get(7));

	return 0;
}
```
