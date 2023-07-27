//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int cur = arr[i];
      int par = arr[(i - 1) / 2];
      while(i > 0 and par < cur) {
          swap(arr[i], arr[(i - 1) / 2]);
          i = (i - 1) / 2;
          cur = arr[i];
          if(i > 0) {
              par = arr[(i - 1) / 2];
          }
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i = 1; i < n; ++i) {
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr, n);
        int last = n;
        while(last > 0) {
            swap(arr[0], arr[--last]);
            int c1 = -1, c2 = -1;
            int idx = 0;
            int cur = arr[idx];
            if(2 * idx + 1 < last) c1 = arr[2 * idx + 1];
            if(2 * idx + 2 < last) c2 = arr[2 * idx + 2];
            while(c1 > cur or c2 > cur) {
                if(c1 > cur and c1 > c2) {
                     swap(arr[2 * idx + 1], arr[idx]);
                     idx = 2 * idx + 1;
                } else if(c2 > cur ) {
                    swap(arr[2 * idx + 2], arr[idx]);
                    idx = 2 * idx + 2;
                }
                 c1 = c2 = -1;
            if(2 * idx + 1 < last) {
                c1 = arr[2 * idx + 1];
            }
            if(2 * idx + 2 < last) {
                c2 = arr[2 * idx + 2];
            } 
            }
           
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends