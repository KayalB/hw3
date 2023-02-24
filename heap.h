#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>



#include <iostream>

using namespace std;


template <typename T, typename PComparator = std::less<T> >
class Heap
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

  void popRec(int index);

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

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> tree_;
  int posBranch_;
  PComparator comp_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
  : posBranch_(m), comp_(c)
{
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  tree_.push_back(item);
  std::size_t index = tree_.size() - 1;
  while (index != 0) {
      std::size_t parent_index = (index - 1) / posBranch_;
      T& current = tree_[index];
      T& parent = tree_[parent_index];
      if (!comp_(current, parent)) {
          break;
      }
      std::swap(current, parent);
      index = parent_index;
  }
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
    throw(std::underflow_error("The Heap is Empty"));
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return tree_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw(std::underflow_error("Don't Pop, the Heap is Empty!"));
  }
  tree_[0] = tree_.back(); 
  tree_.pop_back();


  int index = 0;
  while(index < (int)size())
  {
    int tempIndex = index;

    for(int i = 0; i <= posBranch_; i++){
      int curChildIdx = posBranch_*index;
      curChildIdx += i;
      if(curChildIdx < (int)size()){
        if(comp_(tree_[curChildIdx], tree_[tempIndex])){
          tempIndex = curChildIdx;
        }
      }
    }

    if(tempIndex == index){
      break;
    }

    std::swap(tree_[index], tree_[tempIndex]);
    index = tempIndex;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::popRec(int index)
{

}


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if(tree_.size() == 0){
    return true;
  }
  return false;
}

  /**
  * @brief Returns size of the heap
  * 
  */

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return tree_.size();
}



#endif

