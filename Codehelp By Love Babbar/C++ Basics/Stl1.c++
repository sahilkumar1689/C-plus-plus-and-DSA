using namespace std;
#include <iostream>
#include<array>
#include<vector>
#include<list>
#include<deque>

int main(){
    // STL = The full form of the stl is standard template library.It divided into two parts:
    
    // 1. Algorithms = Basically,algorithms are the functions used across a variety of containers for processing their contents.
    // 2. Containers = Basically,containers are the object that are used to holds the data of the same type.
    // 3. Iterators = Iterators are the objects which points each element of the containers.In simple,words iterators are the pointer type entity which is used to access individual element of the containers.It moves sequentially from one element to another element in the conatiner.


    // 2. Containers = Containers further are of four types:

    // 1. Sequence Container = Array,Vector,Deque,List,Forward_last.
    // 2. Sequence Adaptors = Stack,Queue,Priority Queue.
    // 3. Associative Containers = Set,Map,Multiset,Multimap.
    // 4. Unordered Associative Containers = Unordered set,unordered multiset,unordered map,unordered multimap.

    // 3. Iterator syntax:
    // container_name<data_type>:: iterator iterator_object_name;




    // 1. Array = Array is a fixed type sequence container.It is similar to the actual array.But the only difference is that we can use some predefined function init.To use array container firstly include the <array> header file:

    // Syntax:
    // Array<data_type,size> array_object_name;
    // array<int,5> arr = {2,2,3,4,5};


    // Capacity Related Functions:
    // 1. Size() = It is used to return the total number of element a array can contains.
    // cout<<arr.size()<<endl;
    // 2. max_size() = Similar to the size() functions.
    // cout<<arr.max_size()<<endl;
    // 3. empty() = It return the array is empty or not.
    // cout<<arr.empty()<<endl;

    // Member Functions:
    // 1. begin() and end() = These are the pointer function point towards the first and the last element of the array,to access the element use dereference operator(*).
    // auto f = arr.begin();
    // auto l = arr.end();

    // cout<<*f<<endl;
    // cout<<*l<<endl;


    // Element Access Functions:
    // 1. front() and back() = Access the first and the last element.
    // cout<<arr.front()<<endl;
    // cout<<arr.back()<<endl;
    // 2. at() and [] operator = Both are used to access the random element.
    // cout<<arr.at(1)<<endl;
    // cout<<arr[1]<<endl;
    // 3. fill() and swap() = Fill all the element by any specific value and swap is used to swap to array.
    // array<int,5> arr2;
    // arr2.fill(5);
    // arr.swap(arr2);
    // for (auto i:arr) cout<<i<<" ";



    // 2. Vectors = Vector is a class,which is used to make dynamic array.It means its size can be increases dynamicaly.To use vector containers we need to include the <vector> header file.

    // Syntax:
    // Vector<data_type> object_name;      // It means vector with zero size.
    // Vector<data_type> object_name(n);  //  It means vector with n size.

    // vector<int> v;

    // Elementary Operations:
    // 1. push_back() and pop_back() = It is used to insert the new element and delete the element.
    // v.push_back(1);
    // v.push_back(2);

    // v.pop_back();
    // for (auto i:v)cout<<i<<" ";
    
    // 2. insert(iterrator,value) = It is used to insert the new value at the given index value.    
    // vector<int>::iterator it = v.begin();
    // v.insert(it+1,3);
    // for(auto i:v)cout<<i<<" ";
    // 3. Erase() and clear() = It is used to erase any specified element and clear is used to clear all the vector.
    // v.erase(v.begin()+1);
    // for(auto i:v)cout<<i<<" ";
    // v.clear();
    // 4. Empty() and swap() = User to check the vector is empty or not and swap is used to swap two vector:
    // cout<<v.empty()<<endl;
    // vector<int> v2(5,5);
    // v.swap(v2);
    // for(auto i:v2)cout<<i<<" ";


    // Capacity Functions:
    // 1. Size() and max_size() = Both are used to return the size;
    // cout<<v.size()<<endl;
    // cout<<v2.size()<<endl;

    // 2. capacity() = It is used to tell the capacity of the vector.
    // cout<<v.capacity();
    // v.pop_back();
    // cout<<v.capacity();


    // Access element operation:
    // 1. begin() and end() = These are the pointer function point towards the first and the last element of the array,to access the element use dereference operator(*).
    // 2. front() and back() = Access the first and the last element.
    // 3. at() and [] operator = Fill all the element by any specific value and swap is used to swap to array.



    // 3. List = List is a sequence container that allow insertion and deletion from both ends from the list.There are numbers of member functions are present in the list to use them firstly insert the <list> header file.

    // Syntax:
    // list<data_type> object_name;
    // list<int> li;

    // Elementary Operations:
    // 1. push_back() and push_front() = It is used to add element in the front and in the last of the list.
    // li.push_back(1);
    // li.push_front(2);
    // li.push_front(3);
    // li.push_front(4);
    // li.push_front(5);
    // for(auto i:li)cout<<i<<" ";
    // cout<<endl;

    // 2. pop_back() and pop_front() = It is used to delete the element from the front and the back.
    // li.pop_front();
    // li.pop_back();
    // for(auto i:li)cout<<i<<" ";
    // cout<<endl;
    

    // 3. insert(iterator,value) = It is used to insert the any new value at the specified index value by using the iteator.
    // list<int>::iterator it = li.begin();
    // li.insert(it,1);
    // for(auto i:li)cout<<i<<" ";
    // cout<<endl;
    
    // 4. erase(iterator) = It is used to erase any value from the list.
    // li.erase(it);
    // for(auto i:li)cout<<i<<" "<<endl;

    // 5. remove(value_to_be_removed) = It is used to remove any value from the list.
    // li.remove(3);
    // for(auto i:li)cout<<i<<" "<<endl;

    // 6. Sort() = sort the list;
    // li.sort();

    // 7. Merge() = It is used to merge two list.
    // list<int> li2(5,5);
    // li.merge(li2);
    
    // 8. reverse() = It is used to reverse the list.
    // li.reverse();
    // for(auto i:li)cout<<i<<" ";cout<<endl;

    // 9. Splice(iterator,list_to_be_spliced) = It is used to splice the two list.
    // list<int> l1, l2;
    // l1.push_back(1);
    // l1.push_back(2);
    // l1.push_back(2);
    // l1.push_back(2);

    // l2.push_back(3);
    // l2.push_back(4);

    // list<int>::iterator it2 = l1.begin();
    // int a;
    // cout << "Please enter the place were you want splice:";
    // cin >> a;
    // for (int i = 0; i < (a - 1); i++)
    // {
    //     it2++;
    // }
    // l1.splice(it2, l2);
    // for(auto i:l1)cout<<i<<" ";cout<<endl;

    // Capacity and iterator functions:
    // size(),max_size(),empty(),front(),back(),begin(),end().



    // 4. Deque = It is also called double ended queue.It is a sequence container with dynamic size that can be expanded or contracted on both side.In simple words deque is similar to the vector but the only difference is,element can be added or delete from both ends,rest of the member function will be similar to the vector.Include file <deque>

    // Synatx:
    // deque<data_type> object_name;
    deque<int> dq;

    // Elementary function:
    // 1. Push_back() and push_front() = It is used to add the element in the front and the end.
    dq.push_back(1);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    dq.push_front(2);

    for(auto i:dq)cout<<i<<" ";cout<<endl;
    // 2. pop_back() and pop_front() = It is used to delete the element from the both ends.
    dq.pop_back();
    dq.pop_front();
    for(auto i:dq)cout<<i<<" ";cout<<endl;

    // 3. insert(iterator,value) = Used to inser the value to the given index value.
    deque<int>::iterator it = dq.begin()+1;
    dq.insert(it+1,2);
    for(auto i:dq)cout<<i<<" ";cout<<endl;
    // cout<<*it<<endl; 

    // 4. erase() and clear() and empty() = It is used to erase any element and clear is used to clear all the elements and empty tells the dq is empty or not.
    dq.erase(it+1);
    for(auto i:dq)cout<<i<<" ";cout<<endl;
    dq.clear();
    cout<<dq.empty()<<" ";

    // 5. swap() = It is used to swap two deque.
    deque<int> dq2(5,5);

    dq.swap(dq2);
    for(auto i:dq)cout<<i<<" ";cout<<endl;

    // capacity and the iterators functions:
    // size(),max_size(),front(),back(),begin(),end().

   
    return 0;
}