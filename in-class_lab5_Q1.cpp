#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
#include <stack>

using namespace std;
using namespace std::chrono;

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot element
    int i = low - 1; // index of smaller element
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

// Recursive function to perform Quick Sort
void recursivequickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // partition index
        recursivequickSort(arr, low, pi-1);
        recursivequickSort(arr, pi+1, high);
    }
}

// Non-recursive function to perform Quick Sort
void iterativequickSort(int arr[], int low, int high) {
    stack<int> s;
    s.push(low);
    s.push(high);
    
    while (!s.empty()) {
        high = s.top();
        s.pop();
        low = s.top();
        s.pop();
        
        int pi = partition(arr, low, high); // partition index
        
        if (pi-1 > low) {
            s.push(low);
            s.push(pi-1);
        }
        if (pi+1 < high) {
            s.push(pi+1);
            s.push(high);
        }
    }
}

int main()
{
   int sz;
   printf("Enter the size of array::");
   scanf("%d",&sz);
   int arr[sz],i;
   for(i=0;i<sz;i++)
     arr[i]=rand()%100;
    
    
    
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    auto start1 = high_resolution_clock::now();
    recursivequickSort(arr,0,n-1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Time taken by recursive function: "
         << duration1.count() << " microseconds" << endl;
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    auto start2 = high_resolution_clock::now();
    iterativequickSort(arr,0,n-1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time taken by iterative function: "
         << duration2.count() << " microseconds" << endl;
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
