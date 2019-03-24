#pragma once

#include <vector>
#include <stdexcept>

using namespace std;

template<class T>
class Deque {
private:
    vector<T> front_;
    vector<T> back_;

    void CheckIndex(size_t index) const {
        if (index >= Size()) {
            throw out_of_range("Index is out of range");
        }
    }

    T& GetValueByIndex(size_t index) {
        if (index < front_.size()) {
            return front_[front_.size() - index - 1];
        } else {
            return back_[index - front_.size()];
        }
    }

    const T& GetValueByIndex(size_t index) const {
        if (index < front_.size()) {
            return front_[front_.size() - index - 1];
        } else {
            return back_[index - front_.size()];
        }
    }

public:
    Deque() {}

    bool Empty() const {
        return !Size();
    }

    size_t Size() const {
        return front_.size() + back_.size();
    }

    T& operator[](size_t index) {
        return GetValueByIndex(index);
    }

    const T& operator[](size_t index) const {
        return GetValueByIndex(index);
    }

    T& At(size_t index) {
        CheckIndex(index);
        return GetValueByIndex(index);
    }

    const T& At(size_t index) const {
        CheckIndex(index);
        return GetValueByIndex(index);
    }

    T& Front() {
        return GetValueByIndex(0);
    }

    const T& Front() const {
        return GetValueByIndex(0);
    }

    T& Back() {
        return GetValueByIndex(Size() - 1);
    }

    const T& Back() const {
        return GetValueByIndex(Size() - 1);
    }

    void PushFront(const T& value) {
        front_.push_back(value);
    }

    void PushBack(const T& value) {
        back_.push_back(value);
    }
};