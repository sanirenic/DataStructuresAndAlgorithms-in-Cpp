#include <iostream>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};
