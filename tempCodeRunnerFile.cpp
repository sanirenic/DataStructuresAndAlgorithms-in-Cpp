#include <iostream>

 double findAverageRecursive(int arr[], int size) {
     if (size == 0)
         return 0;
    else
         return (arr[size - 1] + findAverageRecursive(arr, size - 1) * (size - 1)) / size;
 }

 int main() {
     int arr[] = {5, 10, 15, 20, 25};
     int size = sizeof(arr) / sizeof(arr[0]);
     double average = findAverageRecursive(arr, size);
     std::cout << "Average of the array (recursive): " << average << std::endl;
     return 0;
 }
