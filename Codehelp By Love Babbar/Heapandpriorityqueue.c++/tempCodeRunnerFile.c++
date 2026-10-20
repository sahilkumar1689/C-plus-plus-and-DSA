using namespace std;
#include <iostream>
#include <queue>
void printHeap(priority_queue<int>heap){
    while(heap!=empty) {
        cout<<heap.top()<<" ";
        heap.pop();
    }
}
int main(){
    // Priority Queue=It is the implementation of the heap data structure in which the fron element always give the max or min value according the type of the priority queue.By default it gives the max value.To implement the priority queue we need to include the queue header file.

    // Max Priority Queue:
    priority_queue<int>minHeap;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(30);
    minHeap.push(40);
    minHeap.push(50);

    printHeap(minHeap);
    // Emplace function is used to insert the element in the queue,it is similar to the push function but the only differnece is it avoid the un-neccessary copying of the objects.
    // minHeap.emplace(90);
    // printHeap(minHeap);

    

    return 0;
}