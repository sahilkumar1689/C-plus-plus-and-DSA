using namespace std;
#include <iostream>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<string>


int main(){
    // 5. Stack = Stack is a type of container adaptor,specially designed to operate in a LIFO system.In stack elements are inserted or extracted only one end.Include the <stack>

    // Syntax:
    // stack<data_type> object_name;
    // stack<int> st;

    // Elementary Operations:
    // 1. push() and pop() = It is used to add the element and pop is used to delete the element.
    // for(int i=1;i<=5;i++)st.push(i);
    // st.pop();
    // int size = st.size();
    // 2. top() = It is used to get the top most value.
    // for(int i=0;i<size;i++){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    // 3. size() and swap() and empty() = To find the size and swap two stacks and check the stack is empty or not.
    // cout<<st.size()<<endl;
    // stack<int> st2;
    // st2.push(1);
    // st2.push(2);

    // st.swap(st2);
    // int size = st.size();
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    
    // cout<<st.empty()<<endl;



    // 6. Queue = It is a type of container adaptor specially designed to operate in the FIFO system.In queue also element are inserted and extracted only from the one end.Insert <queue> header file.

    // Syntax:
    // queue<data_type> object_name;
    // queue<int> qu;

    // Elementary Operations:
    // 1. push() and pop() = It is used to insert the element and delete the elements.
    // for(int i=1;i<=5;i++)qu.push(i);
    // qu.pop();
    // 2. front() and back() = It is used to access the front and last element.
    // int size = qu.size();
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<qu.front()<<" ";
    //     qu.pop();
    // }

    // 3. size(), swap(),empty()



    // 7. priority queue = Prority queue is a type of container adaptors,specially designed such that its first element always a maximum of all the elements.Include <queue>

    // Syntax:
    // priority_queue<int> pq;
    // priority_queue<int> pq;

    // Elemetary Operations:
    // 1. push() and pop() =
    // pq.push(10);
    // pq.push(20);
    // pq.push(100);   // element store in the priority queue in the maximum to minimum order.
    // pq.push(30);
    // pq.push(40);

    // pq.pop();
    // 2. top()=
    // int size = pq.size();
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }
    // 3. size(),swap(),empty().



    // 8. Set = These are the containers that store the unique elements and the elements always stored in the sorted format.Include <set>

    // Syntax:
    // set<data_type> object_name;
    // set<int> st;

    // Elementary Operations:
    // 1. Insert() = It is used to insert elements in the set.


    // for(int i=1;i<=5;i++)st.insert(i);
 
    // int arr[] = {5,3,4,2,1,3};
    // st.insert(arr,arr+5);

    // for (auto i:st)cout<<i<<" ";

    // 2. lower_bound() and upper_bound() = It is used to get the element pointer of the minimum element and the maximum element.
    // auto lw = st.lower_bound(2);            // 1,2,3,4,5
    // auto up = st.upper_bound(5);

    // cout<<*lw<<" "<<*up<<endl;

    // 3. size(),swap(),empty(),erase(),clear(),begin(),end().


    // 9. Map = Maps are associative container which is used to store the elements in the key value combination.Map does'nt use any index value,so to access the element from the maps we use keys inside brackets and iterators.Include <map>

    // Syntax:
    // map<key_data_type,value_data_type> object_name;

    // map<string,int> mp;

    // Elementary Operations:
    // 1. at() and [] brackets = It is used to inert or access any element in the map.
    // mp["first"] = 1;
    // mp["second"] = 2;       // insert any key with their value.

    // mp.at("second") = 3;   // Used to overright the value of any present key
    // for(auto i= mp.begin();i!=mp.end();i++){

    //     cout<<i->first<<" "<<i->second<<endl;
    // }

    // 2. erase(iterator) and clear() = It is used to erase any element and clear to clear all the map.
    // map<string,int>::iterator it = mp.begin();
    // mp.erase(it);
    // for(auto i:mp)cout<<i.first<<" "<<i.second<<endl;
    // mp.clear();

    // 3. empty()=
    // cout<<mp.empty()<<endl;

    // 4. lower_bound() and upper_bound() = It is used to give the emenet poiner of the minimum element and the maximum element.
    // auto lw = mp.lower_bound("first");
    // auto up = mp.upper_bound("second");
    // cout<<lw->first<<" "<<endl;
    // 5. size(),max_size(),begin(),end().



    // 10. Algorithms = These are the some predefined functions which is used to perform some actuall algorithms.Include <algorithm>

    // Some of them are:
    // 1. v.Sort(first_iterator,last_iterator)
    // 2. v.Sort(first_iterator,last_iterator,greather<int>()) // it is used to sort the element in the desending order.
    // 3. v.reverse(first_iterator,second_iterator)
    // 4. v.*max_element(first_iterator,second_iterator)
    // 5. v.*min_element(first_iterator,second_iterator)
    // 6. v.count(first_iterator,second_iterator,x)  // used to find the occurance
    // 7. v.binary_search(first_iterator,second_iterator,x)
    // 8. v.unique(first_iterator,second_iterator)
    
    return 0;
}