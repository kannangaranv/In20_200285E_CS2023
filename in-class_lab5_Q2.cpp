#include <iostream>
#include <algorithm>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

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
void recursivequickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // partition index
        recursivequickSort(arr, low, pi-1);
        recursivequickSort(arr, pi+1, high);
    }
}

double findMedian(int arr[], int n) {
    recursivequickSort(arr,0,n); // Sort the array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }    
    
    if (n % 2 != 0) { // If the array has odd number of elements
        return (double)arr[n/2] ;
    }
    else { // If the array has even number of elements
        return (double)(arr[(n-1)/2] + arr[n/2]) / 2.0;
    }
}
int main() {
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
    for (int j=1;j<=n;j++){
        int a[j];
        for(int k=0;k<j;k++){
            a[k]=arr[k];
        }
        double median = findMedian(a,j );
        double scaled_median = round(median * 10)/ 10.0;
        cout <<"Median is : "<<fixed << setprecision(1) << scaled_median << endl; 
    }

    return 0;
}
