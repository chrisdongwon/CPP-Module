/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:01:03 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 11:55:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(unsigned int n) : size_(n) {
  data_ = NULL;
  if (n)
    data_ = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : size_(other.size_) {
  data_ = new T[size_];
  for (unsigned int i = 0; i < size_; ++i) {
    data_[i] = other.data_[i];
  }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
  if (this != &other) {
    delete[] data_;
    size_ = other.size_;
    data_ = new T[size_];
    for (unsigned int i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }
  return *this;
}

template <typename T>
Array<T>::~Array() {
  delete[] data_;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
  if (index >= size_)
    throw std::exception();
  return data_[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
  if (index >= size_)
    throw std::exception();
  return data_[index];
}

template <typename T>
unsigned int Array<T>::size() const {
  return size_;
}
