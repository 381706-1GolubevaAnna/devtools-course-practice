// Copyright 2020 Tanskii Yurii

#include "include/modify_stack.h"
#include <algorithm>

Stack::Stack(int size) {
    if (size < 0) {
        throw "Size cannot be below zero";
    } else {
        if (size == 0) {
            this->size = 50;
        } else {
            this->size = size;
        }
    }
    src = new double[this->size];
    min_items = new double[this->size];
    top = 0;
}

Stack::Stack(const Stack& stack) {
    this->size = stack.size;
    this->src = new double[this->size];
    this->min_items = new double[this->size];
    this->top = stack.top;
    for (int i = 0; i < top; i++) {
        this->src[i] = stack.src[i];
        this->min_items[i] = stack.min_items[i];
    }
}

Stack::~Stack() {
    delete[] src;
    delete[] min_items;
}

int Stack::getSize() const {
    return size;
}

int Stack::getTop() const {
    return top;
}

bool Stack::isEmpty() const {
    return (top == 0);
}

bool Stack::isFull() const {
    return (top == size);
}

void Stack::put(const double elem) {
    src[top] = elem;
    int tmp = top;
    tmp--;
    if (tmp >= 0) {
        if (min_items[tmp] > elem)
            min_items[top] = elem;
        else
            min_items[top] = min_items[tmp];
    } else
        min_items[top] = elem;
    top++;
}

double Stack::pop() {
    top--;
    return src[top];
}

double Stack::getUpper() {
    return src[top-1];
}

double Stack::getMin() {
    return min_items[top-1];
}

void Stack::operator = (const Stack& stack) {
    this->size = stack.size;
    this->src = new double[size];
    this->min_items = new double[size];
    this->top = stack.top;
    for (int i = 0; i < top; i++) {
        this->src[i] = stack.src[i];
        this->min_items[i] = stack.min_items[i];
    }
}

bool Stack::operator == (const Stack& stack) const {
    bool equal = false;
    if (this->size == stack.size) {
        if (this->top == stack.top) {
            equal = true;
            for (int i = 0; i < size; i++) {
                if (this->src[i] != stack.src[i]) {
                    equal = false;
                    break;
                }
            }
        }
    }
    return equal;
}

bool Stack::operator != (const Stack& stack) const {
    return !(*this == stack);
}
