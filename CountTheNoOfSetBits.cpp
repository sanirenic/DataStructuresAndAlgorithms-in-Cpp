#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);  // drops the lowest set bit
        count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countSetBits(n) << endl;
}
