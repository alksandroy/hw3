#include "heap.h"
#include <iostream>
using namespace std;

int main() {
    int a[10] = {10, 3, 5, 2, 4, 6, 8, 7, 9, 1};
    Heap<int, less<int>> myHeap;
    for (int i = 0; i < 10; i++)
        myHeap.push(a[i]);
    for (int i = 0; i < 10; i++) {
        cout << myHeap.top() << " ";
        myHeap.pop();
    }
}