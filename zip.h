//
// Created by aliye on 4/28/2023.
//

#ifndef LABWORK_11_SCANERIST__ZIP_H_
#define LABWORK_11_SCANERIST__ZIP_H_

#include <utility>
#include <stdexcept>

template<typename Iter1, typename Iter2>
class zip_iterator {
 public:
  using value_type = std::pair<typename Iter1::value_type, typename Iter2::value_type>;
  using difference_type = std::ptrdiff_t;
  using pointer = const value_type*;
  using reference = const value_type&;
  using iterator_category = std::input_iterator_tag;

  zip_iterator(Iter1 iter1, Iter2 iter2) : iter1_(iter1), iter2_(iter2) {}

  reference operator*() const { return value_; }
  pointer operator->() const { return &value_; }

  zip_iterator& operator++() {
      ++iter1_;
      ++iter2_;
      value_ = std::make_pair(*iter1_, *iter2_);
      return *this;
  }

  zip_iterator operator++(int) {
      zip_iterator tmp(*this);
      ++(*this);
      return tmp;
  }

  bool operator==(const zip_iterator& other) const {
      return iter1_ == other.iter1_ && iter2_ == other.iter2_;
  }

  bool operator!=(const zip_iterator& other) const {
      return !(*this == other);
  }

 private:
  Iter1 iter1_;
  Iter2 iter2_;
  value_type value_ = std::make_pair(*iter1_, *iter2_);
};

template<typename Container1, typename Container2>
class zip_ {
 public:
  using iterator = zip_iterator<typename Container1::const_iterator, typename Container2::const_iterator>;

  zip_(const Container1& c1, const Container2& c2)
      : begin_(c1.begin(), c2.begin()),
        end_(std::next(c1.begin(), std::min(c1.size(), c2.size())),
             std::next(c2.begin(), std::min(c1.size(), c2.size()))) {}


  iterator begin() const { return begin_; }
  iterator end() const { return end_; }

 private:
  iterator begin_;
  iterator end_;
};

template<typename Container1, typename Container2>
zip_<Container1, Container2> zip(const Container1& c1, const Container2& c2) {
    return zip_<Container1, Container2>(c1, c2);
}

#endif //LABWORK_11_SCANERIST__ZIP_H_
