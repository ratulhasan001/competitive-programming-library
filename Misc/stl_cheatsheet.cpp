// Quick reference for common C++ STL container operations.
// Not meant to be compiled as one program -- copy the relevant snippet.

#include <bits/stdc++.h>
using namespace std;

void vector_ops() {
    vector<int> v = {10, 20, 30, 40};
    int index = 2;
    v.insert(v.begin() + index, {99, 100}); // insert values at index
    v.erase(v.begin() + 2);                 // delete by index
}

void priority_queue_ops() {
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
}

void deque_ops() {
    deque<int> dq;
    vector<int> v = {1, 2, 3};
    dq.insert(dq.begin() + 1, v.begin(), v.end()); // insert a range
    dq.insert(dq.begin() + 2, 99);                 // insert a single value
}

void string_ops() {
    string s = "hello world";
    s.erase(2, 1);      // delete 1 char starting at index 2
    s.insert(2, "XX");  // insert "XX" at index 2
}

void set_ops() {
    set<int> s = {10, 20, 30, 40};
    auto it = s.find(40);
    if (it != s.end()) s.erase(it);
}

int32_t main() {
    return 0;
}
