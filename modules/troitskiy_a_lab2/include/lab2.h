// Copyright 2024 Troitskiy Alexander

#ifndef MODULES_TROITSKIY_A_LAB2_INCLUDE_LAB2_H_
#define MODULES_TROITSKIY_A_LAB2_INCLUDE_LAB2_H_

#include <algorithm>
#include <array>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

template <int N> class Heap {
private:
  std::array<double, N + 2> t;
  int real_size = 0;
  void heapify(int n) {
    int left = 2 * n + 1;
    int right = 2 * n + 2;
    if (left < real_size) {
      if (t[n] < t[left]) {
        std::swap(t[n], t[left]);
        heapify(left);
      }
    }
    if (right < real_size) {
      if (t[n] < t[right]) {
        std::swap(t[n], t[right]);
        heapify(right);
      }
    }
  }

public:
  Heap() = default;
  Heap(const std::vector<double> &arr) {
    for (const auto &el : arr)
      push(el);
  }
  void push(const double &el) {
    int i = real_size;
    t[i] = el;
    int parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
      if (t[i] > t[parent]) {
        std::swap(t[i], t[parent]);
      }
      i = parent;
      parent = (i - 1) / 2;
    }
    real_size++;
  }
  void pop() {
    if (real_size == 0)
      throw std::logic_error("Empty heap");
    t[0] = t[real_size--];
    heapify(0);
  }
  double top() {
    if (real_size == 0)
      throw std::logic_error("Empty heap");
    return t[0];
  }
  int size() { return real_size; }
};
#endif // MODULES_TROITSKIY_A_LAB2_INCLUDE_LAB2_H_
