using namespace std;
#include <iostream>
// 1. Insertion in max heap using array:
class heap{
    int arr[100];
    int size;
    public:
    heap(){
        // Because we use the 1-based indexing for simplicity.
        arr[0]=-1;
        size=0;
    }
    void insertArrHeap(int val){
        // Step 1=Insert at the end of the array.
        size++; 
        int i=size;
        arr[i]=val;

        // Step 2=Insert at the right position.
        while(i>1){
            int parentIndex=i/2; // find the parent index using the formula.
            if(arr[parentIndex]<arr[i] && parentIndex!=0){
                swap(arr[parentIndex],arr[i]);
                i=parentIndex;
            }
            else return;
        }
    }
    void printHeap(){
        for(int i=1;i<=size;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    void deletionHeap(){
        if(size==0){
            cout<<"Empty Heap.";
            return;
        }

        // Step 1=Put the last element at the place of first.
        arr[1]=arr[size];

        // Step 2=Decrement the size.
        size--;

        // Step 3=Make you max heap valid.
        int i=1;
        // Check if left child is present if present then go for the furthre process if not then it means it is the only node in the heap.
        while (2*i<=size)
        {   
            int leftChildIndex=2*i;
            int rightChildIndex=2*i+1;
            int maxIndex=-1;
            // We check if the rightchild is present and it is bigger than left child,if it is then it means it is your maxindex else leftchild is you max index.
            if(rightChildIndex<=size && arr[rightChildIndex]>arr[leftChildIndex]){
                maxIndex=rightChildIndex;
            }
            else maxIndex=leftChildIndex;

            if(arr[i]<arr[maxIndex]){
                swap(arr[i],arr[maxIndex]);
                i=maxIndex;
            }
            else return;
        }
    }
};
void maxHeapify(int *arr,int i,int size){

    while(2*i<=size){
        int leftIndex=2*i;
        int rightIndex=2*i+1;
        int maxIndex=-1;

        if(rightIndex<=size && arr[rightIndex]>arr[leftIndex]){
            maxIndex=rightIndex;
        }
        else maxIndex=leftIndex;

        if(arr[i]<arr[maxIndex]){
            swap(arr[i],arr[maxIndex]);
            i=maxIndex;
        }
        else return;
    }
}
void minHeapify(int *arr,int i,int size){

    while(2*i<=size){
        int leftIndex=2*i;
        int rightIndex=2*i+1;
        int maxIndex=-1;

        if(rightIndex<=size && arr[rightIndex]<arr[leftIndex]){
            maxIndex=rightIndex;
        }
        else maxIndex=leftIndex;

        if(arr[i]>arr[maxIndex]){
            swap(arr[i],arr[maxIndex]);
            i=maxIndex;
        }
        else return;
    }
}
void printHeap(int arr[],int size){
    for(int i=1;i<=size;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
void maxHeapSort(int *arr,int size){
    int tempSize=size;
    while(tempSize>1){
        // Step 1=Swap the first and the last elements:
        swap(arr[1],arr[tempSize]);
        // Step 2=Decrement the size:
        tempSize--;
        // Step 3=Call the heapify function:
        maxHeapify(arr,1,tempSize);
    }
}

int main(){
    // Heap= It is a special tree based data structure in which the tree is a complete binary tree which follow the heap order property.
    // Complete binary tree = A complete binary tree is a tree in which all thr levels are completely filled excepts the last level which filled from the left to right manner.

    // Types of three :
    // 1. Max Heap = It is type of tree in which the value of root element are greather then it child elements and this property is applied on all its left subtree and right subtree.
    // 2. Min Heap = It is type of tree in which the value of root element are smaller then it child elements and this property is applied on all its left subtree and right subtree.

    // Property of heap:
    // 1. It form the complete binary tree.
    // 2. Root element always will be minimum or maximum depending upon the type.
    // 3. Parent-child relationship=Basically when we implement the heap using array how we know the left and right element of that element, it can be found by using the formula:
    // For 1-based indexing:
    // for left element=2i,for right element=2i+1,for parent element=i/2;
    // For 0-based indexing:
    // for left element=2i+1,for right element=2i+2,for parent element=(i/2) or (i/2)-1 for odd and even respectively.
    // 4. Efficient insertion, deletion and accesing the elements. 

    // Implementation = We implements the heap using array and using stl data structure called priority queue.
    // (i) Array implementation = Basically while implementing the heap using array,you need to visualize the tree side by side for every operation.

    // 1. Insertion in max heap:
    // heap maxheap;
    // maxheap.insertArrHeap(10);
    // maxheap.insertArrHeap(20);
    // maxheap.insertArrHeap(30);
    // maxheap.insertArrHeap(40);
    // maxheap.printHeap();
    // 2. Insertion at the min heap is similar but the only change in the condition inside the while loop insert of less that check for grather than.

    // 3. Deletion in the max heap:
    // maxheap.deletionHeap();
    // maxheap.printHeap();
    // 4. In the case of deletion in min heap you only need to change the condition at the palace of ">" use "<" and at the pace of "<" use the ">".

    // 5. Heapify Function=Basically heapify function convert the given array in the min or max heap.Complecity O(n),O(1);

    // In this we basically start coverting from the (n/2 to 0) because in the 
    // complete binary tree from [(n/2)-1 to n] we have leaf node and the leaf node itself is already a heap so we only need to process from the (n/2 to 0).

    // Creating max heap:
    // int arr[6] ={-1,10,50,55,20,30};
    // int size=5;// because 1-based indexing.
    // for(int i=size/2;i>0;i--){
    //     maxHeapify(arr,i,size);
    // }
    // printHeap(arr,size);
    // In the case of min heap only change the conditions.
    // for(int i=size/2;i>0;i--){
    //     minHeapify(arr,i,size);
    // }
    // printHeap(arr,size);



    // 6. Heap Sort=In this you given an max heap you need to sort the heap.

    // int arr[6]={-1,50,25,20,10,5};
    // int size=5;
    // maxHeapSort(arr,size);
    // printHeap(arr,size);


    // Note = 1. In case of min or max only condition is change.
    // 2. In case of 1 based or 0 based indexing only formula change.
    return 0;
}