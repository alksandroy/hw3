#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <vector>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> {
   public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();            // throws std::underflow_error if empty
    const T& top() const;  // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack() : std::vector<T>() {
    // std::vector<T>::std::vector();
}

template <typename T>
Stack<T>::~Stack() {
    // std::vector<T>::std::~vector();
}

template <typename T>
bool Stack<T>::empty() const {
    return std::vector<T>::empty();
}

template <typename T>
size_t Stack<T>::size() const {
    return std::vector<T>::size();
}

template <typename T>
void Stack<T>::push(const T& item) {
    std::vector<T>::push_back(item);
    return;
}

template <typename T>
void Stack<T>::pop() {
    if (empty())
        throw std::underflow_error("Cannot use pop on an empty Stack");
    std::vector<T>::pop_back();
    return;
}

template <typename T>
const T& Stack<T>::top() const {
    if (empty())
        throw std::underflow_error("Cannot use top on an empty Stack");
    return std::vector<T>::back();
}

#endif