/**
 * @file SafeStack.hpp
 * @author Juri Bieler (juribieler@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-02-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SAFE_STACK
#define SAFE_STACK

#include <cstring>
#include <mutex>
#include <stack>

template <class T>
class SafeStack {
 public:
  SafeStack(void) : s(), m(), max_length(16), tag() {}

  ~SafeStack(void) {}

  void init(uint16_t max_length, const char* tag = "SafeStack") {
    this->max_length = max_length;
    this->tag = tag;
  }

  bool is_empty() { return s.empty(); }

  uint16_t get_member_count() { return s.size(); }

  bool is_full() { return this->get_member_count() >= max_length; }

  void push(T* t) {
    std::lock_guard<std::mutex> lock(m);
    if (this->is_full()) {
      printf("WARNING, %s is full(%d), type: %s\n", tag,
             this->get_member_count(), typeid(T).name());
      s.pop();
    }
    s.push(*t);
  }

  void push(T t) {
    std::lock_guard<std::mutex> lock(m);
    if (this->is_full()) {
      printf("WARNING, %s is full(%d), type: %s\n", tag,
             this->get_member_count(), typeid(T).name());
      s.pop();
    }
    s.push(t);
  }

  /**
   * @brief get first element and remove it
   * if the stack is empty, return empty element
   *
   * @return T
   */
  T top(void) {
    std::unique_lock<std::mutex> lock(m);
    if (s.empty()) {
      return {};
    }
    T val = s.top();
    s.pop();
    return val;
  }

  T getTop(void) {
    std::unique_lock<std::mutex> lock(m);
    if (s.empty()) {
      return {};
    }
    T val = s.top();
    return val;
  }

  void pop(void) {
    std::unique_lock<std::mutex> lock(m);
    if (s.empty()) {
      return;
    }
    s.pop();
  }

 private:
  std::stack<T> s;
  mutable std::mutex m;
  uint16_t max_length;
  const char* tag;
};
#endif