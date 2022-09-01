#pragma once

#include "DoubleList.tpp"

template <typename T>
DoubleList<T>::DoubleList(T *a, unsigned n) {}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList<T> &dl) {}

template <typename T>
typename DoubleList<T>::Node *DoubleList<T>::get(unsigned index,
                                                 Color color) const {
  return nullptr;
}

template <typename T>
typename DoubleList<T>::Node *DoubleList<T>::insert(T value, unsigned redIndex,
                                                    unsigned blueIndex) {
  return nullptr;
}

template <typename T>
void DoubleList<T>::remove(unsigned index, Color color) {}

template <typename T>
void DoubleList<T>::append(DoubleList<T> &dl) {}

template <typename T>
DoubleList<T>::~DoubleList() {}