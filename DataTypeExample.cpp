/*
 *  Created on: 20 Nov 2017
 *      Author: Juri
 */

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "stdint.h"
using namespace std;

#include "Queue.hpp"
#include "SafeQueue.hpp"
#include "SafeStack.hpp"
#include "Stack.hpp"

// typedef Stack<uint8_t> IntStack;
// typedef Queue<uint8_t> IntQueue;

// IntStack stack;
// IntQueue que;

/*
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
  printf("pop, top %d\n", stack.getTop());
}

void quePush(uint8_t val) {
  que.push(val);
  printf("push, top %d\n", que.getTop());
}

void quePop() {
  que.pop();
  printf("pop, top %d\n", que.getTop());
}
*/

int main() {
  uint8_t val = 2;

  printf("--------------------\n");
  printf("test Stack...\n");

  uint8_t buffS[5];
  Stack<uint8_t> stack;
  stack.init(buffS, 5);
  stack.push(1);
  // push by pointer
  stack.push(&val);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.push(6);
  stack.top();
  stack.pop();
  stack.push(7);
  stack.push(8);
  stack.push(9);

  for (uint8_t i = 0; i < 10; i++) {
    uint8_t val = stack.top();
    printf("get %d %d (s: %d -> %d)\n", i, val, stack.get_member_count(),
           stack.is_empty());
  }

  printf("--------------------\n");
  printf("test SafeStack...\n");

  SafeStack<uint8_t> safeStack;
  safeStack.init(5);
  safeStack.push(1);
  // push by pointer
  safeStack.push(&val);
  safeStack.push(3);
  safeStack.push(4);
  safeStack.push(5);
  safeStack.push(6);
  safeStack.top();
  safeStack.pop();
  safeStack.push(7);
  safeStack.push(8);
  safeStack.push(9);

  for (uint8_t i = 0; i < 10; i++) {
    uint8_t val = safeStack.top();
    printf("get %d %d (s: %d -> %d)\n", i, val, safeStack.get_member_count(),
           safeStack.is_empty());
  }

  printf("--------------------\n");
  printf("test Queue...\n");

  uint8_t buffQ[5];
  Queue<uint8_t> que;
  que.init(buffQ, 5);
  que.push(1);
  // push by pointer
  que.push(&val);
  que.push(3);
  que.push(4);
  que.push(5);
  que.push(6);
  que.top();
  que.pop();
  que.push(7);
  que.push(8);
  que.push(9);

  for (uint8_t i = 0; i < 10; i++) {
    uint8_t val = que.top();
    printf("get %d %d (s: %d -> %d)\n", i, val, que.get_member_count(),
           que.is_empty());
  }

  printf("--------------------\n");
  printf("test SafeQueue...\n");

  SafeQueue<uint8_t> safeQue;
  safeQue.init(5);
  safeQue.push(1);
  // push by pointer
  safeQue.push(&val);
  safeQue.push(3);
  safeQue.push(4);
  safeQue.push(5);
  safeQue.push(6);
  safeQue.top();
  safeQue.pop();
  safeQue.push(7);
  safeQue.push(8);
  safeQue.push(9);

  for (uint8_t i = 0; i < 10; i++) {
    uint8_t val = safeQue.top();
    printf("get %d %d (s: %d -> %d)\n", i, val, safeQue.get_member_count(),
           safeQue.is_empty());
  }

  return 0;
}
