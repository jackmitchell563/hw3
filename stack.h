#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
    public:
        Stack();
        bool empty() const;
        size_t size() const;
        void push(const T& item);
        void pop();  // throws std::underflow_error if empty
        const T& top() const;
        // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack() : std::vector<T>() {
}
template<typename T>
void Stack<T>::push(const T& item){
    std::vector<T>::push_back(item);
}
template<typename T>
const T& Stack<T>::top() const{
    if(this->empty()) throw std::underflow_error("underflow");
    return std::vector<T>::back();
}  // throws std::underflow_error if empty
template<typename T>
bool Stack<T>::empty() const{
  return !(this->size());
}
template<typename T>
size_t Stack<T>::size() const{
  return std::vector<T>::size();
}
template<typename T>
void Stack<T>::pop(){
  if(this->empty()) throw std::underflow_error("underflow");
  std::vector<T>::pop_back();
}  // throws std::underflow_error if empty

#endif