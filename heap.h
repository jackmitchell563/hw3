#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>
// #include<iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap : private std::vector<T>
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  // void testprint(){
  //   for(size_t i = 0; i < this->size(); i++)
  //     std::cout << std::vector<T>::at(i) << " ";
  //   std::cout << std::endl;
  // }
  
private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> *data;
  int _ary;
  PComparator comp;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : _ary(m), comp(c) {
  this->data = new std::vector<T>;
}
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
  delete data;
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  std::vector<T>::push_back(item);
  // bubble up
  int curr = this->size() - 1;
  while(curr > 0){
    int parent = (curr - 1) / _ary;
    if(comp(std::vector<T>::at(curr), std::vector<T>::at(parent))){ std::swap(std::vector<T>::at(curr), std::vector<T>::at(parent)); curr = parent; }
    else break;
  }
}
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return !(this->size());
}
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return std::vector<T>::size();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error(0);

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return std::vector<T>::at(0);
}


// We will start pop() for you to handle the case of 
// calling pop on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error(0);

  }
  // testprint();
  std::swap(std::vector<T>::at(0), std::vector<T>::back()); // swap top and bottom elements
  std::vector<T>::pop_back(); // remove the element that used to be at the top

  // trickle down
  int curr = 0;
  while(curr < this->size()){
    int firstchild = _ary*curr + 1, bestdex = firstchild;
    if(firstchild >= this->size()) break; // if no children
    while(firstchild - (_ary*curr + 1) < _ary){ // find the best child
      if(firstchild + 1 >= this->size()) break; // if no other children to compare current child to
      bestdex = (comp(std::vector<T>::at(firstchild + 1), std::vector<T>::at(bestdex)) ? (firstchild + 1) : bestdex);
      firstchild++;
    }
    if(comp(std::vector<T>::at(curr), std::vector<T>::at(bestdex))) break; // if the parent's better than the best child
    std::swap(std::vector<T>::at(curr), std::vector<T>::at(bestdex));
    curr = bestdex;
  }
}



#endif

