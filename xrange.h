//
// Created by aliye on 4/28/2023.
//

#ifndef LABWORK_11_SCANERIST__XRANGE_H_
#define LABWORK_11_SCANERIST__XRANGE_H_

#include <iterator>

template<typename T>
class xrange_iterator {
 public:
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = const T*;
  using reference = const T&;
  using iterator_category = std::input_iterator_tag;

  xrange_iterator(T value, T step) : value_(value), step_(step) {}

  reference operator*() const { return value_; }
  pointer operator->() const { return &value_; }

  xrange_iterator& operator++() {
      value_ += step_;
      return *this;
  }

  xrange_iterator operator++(int) {
      xrange_iterator tmp(*this);
      ++(*this);
      return tmp;
  }

  bool operator==(const xrange_iterator& other) const {
      return step_ > 0 ? value_ >= other.value_ : value_ <= other.value_;
  }

  bool operator!=(const xrange_iterator& other) const {
      return !(*this == other);
  }

 private:
  T value_;
  T step_;
};

template<typename T>
class xrange {
 public:
  using value_type = T;
  using iterator = xrange_iterator<T>;
  using const_iterator = xrange_iterator<T>;

  xrange(T start, T end, T step) : start_(start), end_(end), step_(step) {}
  xrange(T start, T end) : start_(start), end_(end), step_(1){}
  xrange(T end) : start_(0), end_(end), step_(1) {}

  const_iterator begin() const { return const_iterator(start_, step_); }
  const_iterator end() const { return const_iterator(end_, step_); }

 private:
  T start_;
  T end_;
  T step_;
};

template <typename T>
xrange<T> range( const T& begin, const T& end, const T& step){
    return xrange<T>(begin, end, step);
}
template <typename T>
xrange<T> range( const T& begin, const T& end){
    return xrange<T>(begin, end);
}

template <typename T>
xrange<T> range(const T& end){
    return xrange<T>(end);
}

#endif //LABWORK_11_SCANERIST__XRANGE_H_
