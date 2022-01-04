/**
 * @file SafeQueue.hpp
 * @author Juri Bieler (juribieler@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-02-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SAFE_QUEUE
#define SAFE_QUEUE

#include <mutex>
#include <queue>

template <class T>
class SafeQueue {
 public:
  SafeQueue(void) : q(), m(), max_length(16), tag() {}

  ~SafeQueue(void) {}

  void init(uint16_t max_length, const char* tag = "SafeQueue") {
    this->max_length = max_length;
    this->tag = tag;
  }

  bool is_empty() {
    std::lock_guard<std::mutex> lock(m);
    return this->q.empty();
  }

  uint16_t get_member_count() {
    std::lock_guard<std::mutex> lock(m);
    return this->q.size();
  }

  bool is_full() {
    std::lock_guard<std::mutex> lock(m);
    return this->q.size() >= this->max_length;
  }

  void push(T* t) {
    std::lock_guard<std::mutex> lock(m);
    while (this->q.size() >= this->max_length) {
      printf("WARNING, %s is full(%d), type: %s\n", tag, this->q.size(),
             typeid(T).name());
      q.pop();
    }
    q.push(*t);
  }

  void push(T t) {
    std::lock_guard<std::mutex> lock(m);
    while (this->q.size() >= this->max_length) {
      printf("WARNING, %s is full(%d), type: %s\n", tag, this->q.size(),
             typeid(T).name());
      q.pop();
    }
    q.push(t);
  }

  /**
   * @brief get first element and remove it
   * if the queue is empty, return empty element
   *
   * @return T
   */
  T top(void) {
    std::unique_lock<std::mutex> lock(m);
    if (q.empty()) {
      return {};
    }
    T val = q.front();
    q.pop();
    return val;
  }

  T getTop(void) {
    std::unique_lock<std::mutex> lock(m);
    if (q.empty()) {
      return {};
    }
    T val = q.front();
    return val;
  }

  void pop(void) {
    std::unique_lock<std::mutex> lock(m);
    if (q.empty()) {
      return;
    }
    q.pop();
  }

 private:
  std::queue<T> q;
  mutable std::mutex m;
  uint16_t max_length;
  const char* tag;
};
#endif