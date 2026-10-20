using namespace std;
#include <iostream>
#include <queue>
void printHeap1(priority_queue<int>heap){
    while(!heap.empty()) {
        cout<<heap.top()<<" ";
        heap.pop();
    }
}
class customCompare{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
            // return a.second>b.second; // for min heap.
            return a.second<b.second;  // for max heap.
        }
        // return a.first>b.first;  // for min heap.
        return a.first<b.first;  // for max heap.
    }
};
int main(){
    // 1. Priority Queue=It is the implementation of the heap data structure in which the top element always give the max or min value according the type of the priority queue.By default it gives the max value.To implement the priority queue we need to include the queue header file.

    // Max Priority Queue:
    // priority_queue<int>maxheap;
    // maxheap.push(10);
    // maxheap.push(20);
    // maxheap.push(30);
    // maxheap.push(40);
    // maxheap.push(50);

    // printHeap1(maxheap);
    // cout<<endl;
    // // Emplace function is used to insert the element in the queue,it is similar to the push function but the only differnece is it avoid the un-neccessary copying of the objects.
    // maxheap.emplace(90);
    // printHeap1(maxheap);

    // // To implement the minheap:
    // priority_queue<int,vector<int>,greater<int>>minheap;
    // // Rest of the function will be similar we use in the max heap:
    // minheap.push(10);
    // minheap.push(20);
    // minheap.push(30);
    // minheap.push(40);
    // minheap.push(50);
    // // Emplace function is used to insert the element in the queue,it is similar to the push function but the only differnece is it avoid the un-neccessary copying of the objects.
    // minheap.emplace(90);
    // printHeap2(minheap);



    // 2. Custom Comparator function in heap = Basically custom comparator is used to implement the min heap or max heap on the basics of complex value stored by the heap.It is used to make you heap generic it means it make your heap independent from the data they stored.Any kind of data heap store they can be implement the heap property on the basic of comparator.

    priority_queue<pair<int,int>,vector<pair<int,int>>,customCompare>heap;

    heap.push({1,0});
    heap.push({4,0});
    heap.push({3,0});
    heap.push({5,1});
    heap.push({5,0});

    while(!heap.empty()){
        cout<<heap.top().first<<" "<<heap.top().second;
        cout<<endl;
        heap.pop();
    }

    // Note = Give opposite condition insted what you want.Example if you want to store the element in the minheap oreder it means you want the first element need to be smaller than the second element then write the opposite command e.g. : Instead of writting "a<b" we write "a>b". Similarly it work for the maxheap insted of using the "a>b" we write the opposite command "a<b".
    


    

    return 0;
}