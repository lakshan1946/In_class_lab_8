#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify
    int left  = 2*root+1;//
    int right = 2*root+2;
    int large = root;

    //check left child is larger than root
    if(left<n && arr[left]>arr[large]) 
        large=left;

   //check right child is larger than root
    if(right<n && arr[right]>arr[large])
        large=right;
    
    if(large!=root){
        swap(arr[root],arr[large]);
        heapify(arr,n,large);
    }

}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    // extracting elements from heap one by one
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
   int size;
   cout<<"enter array size: ";
   cin>>size;
   int heap_arr[size];
   for(int j=0;j<size;j++){
      int random=rand()%100;
      heap_arr[j]=random;
   }
    
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}