#include "stack.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    Stack<int> st;
    for (int i = 1; i <= 10; i++)
        st.push(i);
    for (int i = 1; i <= 10; i++) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << st.empty() << " ";
    st.push(11);
    cout << st.size() << "\n";
    st.pop();
    st.pop();

    return 0;
}