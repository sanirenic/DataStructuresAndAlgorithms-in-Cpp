
//PEHLA CODE
// #include <iostream>

// bool isPalindrome(int num) {
//     int reversedNum = 0;
//     int originalNum = num;

//     // Reverse the number
//     while (num > 0) {
//         int digit = num % 10;
//         reversedNum = reversedNum * 10 + digit;
//         num /= 10;
//     }

//     // Check if the reversed number is equal to the original number
//     return originalNum == reversedNum;
// }

// int main() {
//     int num;
//     std::cout << "Enter a number: ";
//     std::cin >> num;

//     if (isPalindrome(num)) {
//         std::cout << num << " is a palindrome number." << std::endl;
//     } else {
//         std::cout << num << " is not a palindrome number." << std::endl;
//     }

//     return 0;
// }




//DUSRA CODE

// #include <iostream>
// using namespace std;

// int sum(int k) {
//   if (k > 0) {
//     return k + sum(k - 1);
//   } else {
//     return 0;
//   }
// }

// int main() {
//   int result = sum(10);
//   cout << result;
//   return 0;
// }

// Fibonacci Series using Recursion 


// #include <bits/stdc++.h> 
// using namespace std; 

// int fib(int n) 
// { 
// 	if (n <= 1) 
// 		return n; 
// 	return fib(n - 1) + fib(n - 2); 
// } 

// int main() 
// { 
// 	int n;
//     cout<<"enter the number :"<<endl;
//     cin>>n;
// 	cout << fib(n); 
// 	getchar(); 
// 	return 0; 
// } 


// TEESRA CODE<3

// C++ program to illustrate how to swap two variables using 
// a function in C++ 
// #include <iostream> 
// using namespace std; 

// // function to swap two variables 
// void swap(int* a, int* b) 
// { 
// 	int temp = *a; //pointers are used here
// 	*a = *b; 
// 	*b = temp; 
// } 

// // driver code 
// int main() 
// { 
// 	int a = 10; 
// 	int b = 22; 

// 	cout << "Before Swapping: " << endl; 
// 	cout << " a: " << a << " b: " << b << endl; 

// 	// calling swap 
// 	swap(&a, &b); 

// 	cout << "After Swapping: " << endl; 
// 	cout << " a: " << a << " b: " << b << endl; 

// 	return 0; 
// }



// CHOUTHA CODE LOL LOL LOL


// #include <iostream>
// using namespace std;

// bool arraysAreEqual(int arr1[], int arr2[], int size1, int size2) {
//     // If sizes of arrays are not equal, they can't be equal
//     if (size1 != size2)
//         return false;

//     // Check each element of the arrays
//     for (int i = 0; i < size1; ++i) {
//         if (arr1[i] != arr2[i])
//             return false;
//     }
    
//     // If all elements are same, return true
//     return true;
// }

// int main() {
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[] = {1, 2, 3, 4, 5};

//     int size1 = sizeof(arr1) / sizeof(arr1[0]);
//     int size2 = sizeof(arr2) / sizeof(arr2[0]);

//     if (arraysAreEqual(arr1, arr2, size1, size2))
//         cout << "Arrays are equal" << endl;
//     else
//         cout << "Arrays are not equal" << endl;

//     return 0;
// }


//PANCHVA CODE LMAO LMAO LMAO LMAO

// iterative approach
// #include <iostream>

// double findAverageIterative(int arr[], int size) {
//     double sum = 0;
//     for (int i = 0; i < size; ++i) {
//         sum += arr[i];
//     }
//     return sum / size;
// }

// int main() {
//     int arr[] = {5, 10, 15, 20, 25};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     double average = findAverageIterative(arr, size);
//     std::cout << "Average of the array (iterative): " << average << std::endl;
//     return 0;
// }

//RECURSIVE APPROACH

//  #include <iostream>

//  double findAverageRecursive(int arr[], int size) {
//      if (size == 0)
//          return 0;
//      else
//          return (arr[size - 1] + findAverageRecursive(arr, size - 1) * (size - 1)) / size;
//  }

//  int main() {
//      int arr[] = {5, 10, 15, 20, 45};
//      int size = sizeof(arr) / sizeof(arr[0]);
//      double average = findAverageRecursive(arr, size);
//      std::cout << "Average of the array (recursive): " << average << std::endl;
//      return 0;
//  }


//CHHATTA CODE YES YES YES YES YES LOL LOL LOL LOL LOL

// #include <iostream>

// void findMinAndMax(int arr[], int size, int& min, int& max) {
//     if (size <= 0) {
//         std::cout << "Array is empty." << std::endl;
//         return;
//     }
    
//     // Initialize min and max with the first element of the array
//     min = max = arr[0];
    
//     // Traverse the array to find min and max
//     for (int i = 1; i < size; ++i) {
//         if (arr[i] < min) {
//             min = arr[i]; // Update min if current element is smaller
//         } else if (arr[i] > max) {
//             max = arr[i]; // Update max if current element is larger
//         }
//     }
// }

// int main() {
//     int arr[] = {5, 10, 3, 8, 15, 6};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int min, max;
    
//     // Call function to find min and max
//     findMinAndMax(arr, size, min, max);
    
//     // Output results
//     std::cout << "Minimum element: " << min << std::endl;
//     std::cout << "Maximum element: " << max << std::endl;
    
//     return 0;
// }


//SATVA CODE

// #include <iostream>

// // Function to perform linear search
// int linearSearch(int arr[], int size, int key) {
//     for (int i = 0; i < size; ++i) {
//         if (arr[i] == key) {
//             return i; // Return the index if key is found
//         }
//     }
//     return -1; // Return -1 if key is not found
// }

// int main() {
//     int arr[] = {5, 10, 3, 8, 15, 6};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int key = 9; // Element to be searched

//     // Perform linear search
//     int index = linearSearch(arr, size, key);

//     // Check if element is found or not
//     if (index != -1) {
//         std::cout << "Element found at index: " << index << std::endl;
//     } else {
//         std::cout << "Element not found in the array." << std::endl;
//     }

//     return 0;
// }


//AATHVA CODE PLEASE BEAR WITH ME AND BHAGWAN JI MUJHE JALDI SE CODING SIKHA DO

// #include <iostream>

// void rightRotate(int arr[], int size, int k) {
//     // Normalize k to be within the range of array size
//     k = k % size;

//     // Reverse the entire array
//     int start = 0;
//     int end = size - 1;
//     while (start < end) {
//         std::swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }

//     // Reverse the first k elements
//     start = 0;
//     end = k - 1;
//     while (start < end) {
//         std::swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }

//     // Reverse the remaining elements
//     start = k;
//     end = size - 1;
//     while (start < end) {
//         std::swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
// }

// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int k = 2; // Number of times to right rotate

//     std::cout << "Original array: ";
//     printArray(arr, size);

//     // Right rotate the array k times
//     rightRotate(arr, size, k);

//     std::cout << "Array after right rotation " << k << " times: ";
//     printArray(arr, size);

//     return 0;
// }


//NAUVA CODE AAJ KA PEHLA CODE HE BHAGWAN INCONSISTENCY 

// #include <iostream>
// #include <vector>

// using namespace std;

// void computeDiagonalSums(const vector<vector<int>>& matrix) {
//     int n = matrix.size();
//     if (n == 0) {
//         cout << "Empty matrix!\n";
//         return;
//     }

//     int mainDiagonalSum = 0;
//     int antiDiagonalSum = 0;

//     for (int i = 0; i < n; ++i) {
//         mainDiagonalSum += matrix[i][i];
//         antiDiagonalSum += matrix[i][n - i - 1];
//     }

//     cout << "Sum of main diagonal: " << mainDiagonalSum << endl;
//     cout << "Sum of anti-diagonal: " << antiDiagonalSum << endl;
// }

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 2, 4},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     cout << "Matrix:\n";
//     for (const auto& row : matrix) {
//         for (int val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }

//     computeDiagonalSums(matrix);

//     return 0;
// }

#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void computeDiagonalSums(int matrix[][MAX_SIZE], int size) {
    int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (int i = 0; i < size; ++i) {
        primaryDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][size - i - 1];
    }

    cout << "Sum of primary diagonal: " << primaryDiagonalSum << endl;
    cout << "Sum of secondary diagonal: " << secondaryDiagonalSum << endl;
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    int matrix[MAX_SIZE][MAX_SIZE];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    computeDiagonalSums(matrix, n);

    return 0;
}


// DASVA CODE GUYSSSSS








