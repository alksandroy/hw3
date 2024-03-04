#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
using std::swap;
using std::vector;

template <typename T, typename PComparator = std::less<T>>
class Heap {
   public:
    /**
     * @brief Construct a new Heap object
     *
     * @param m ary-ness of heap tree (default to 2)
     * @param c binary predicate function/functor that takes two items
     *          as an argument and returns a bool if the first argument has
     *          priority over the second.
     */
    Heap(int m = 2, PComparator c = PComparator());

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
    T const& top() const;

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

   private:
    /// Add whatever helper functions and data members you need below
    void Heapify(size_t i);
    int min(int a, int b) { return a < b ? a : b; };
    vector<T> a;
    int m;
    PComparator c;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
void Heap<T, PComparator>::Heapify(size_t id) {
    int leftChild = id * m + 1;
    int rightChild = min(size(), leftChild + m) - 1;

    if (leftChild > (int)size() - 1)
        return;
    int bestChild = leftChild;
    for (int i = leftChild + 1; i <= rightChild; i++)
        if (c(a[i], a[bestChild]))
            bestChild = i;
    if (c(a[bestChild], a[id])) {
        swap(a[id], a[bestChild]);
        Heapify(bestChild);
    }
    return;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) {
    this->m = m;
    this->c = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {
    a.clear();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
    a.push_back(item);
    for (int i = size() - 1; i > 0;) {
        int par = (i - 1) / m;
        if (c(a[i], a[par])) {
            swap(a[i], a[par]);
            i = par;
        } else
            i = 0;  // end loop
    }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return a.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return a.size();
}

// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const& Heap<T, PComparator>::top() const {
    // Here we use exceptions to handle the case of trying
    // to access the top element of an empty heap
    if (empty()) {
        // ================================
        // throw the appropriate exception
        // ================================
        throw std::underflow_error("Cannot call top on empty Heap");
    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
    return a[0];
}

// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop() {
    if (empty()) {
        // ================================
        // throw the appropriate exception
        // ================================
        throw std::underflow_error("Cannot call pop on empty Heap");
    }
    swap(a[0], a[size() - 1]);
    a.pop_back();
    Heapify(0);
}

#endif
