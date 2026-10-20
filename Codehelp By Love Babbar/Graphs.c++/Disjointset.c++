using namespace std;
#include <iostream>
#include<bits/stdc++.h>
class Disjoint{
    vector<int> rank,size,parent;
    public:
    Disjoint(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int find(int i){
        // Base Case:
        if(parent[i]==i) return i;
        return (parent[i]=find(parent[i]));
    }

    void unionRank(int u,int v){
        // Step 1 = Find the parent:
        int parentU=find(u);
        int parentV=find(v);
        // Check the cylce:
        if(parentU==parentV) return;

        // Step 2 = Find the rank and accordingly change the link:
        if(rank[parentU]<rank[parentV]){
            parent[parentU]=parentV;
        }
        else if(rank[parentU]>rank[parentV]){
            parent[parentV]=parentU;
        }
        else{
            parent[parentV]=parentU;
            rank[parentU]++;
        }
    }
    void unionSize(int u,int v){
        // Step 1 = Find the parent:
        int parentU=find(u);
        int parentV=find(v);
        // Check the cylce:
        if(parentU==parentV) return;

        // Step 2 = Find the rank and accordingly change the link:
        if(size[parentU]<size[parentV]){
            parent[parentU]=parentV;
            size[parentV]+=size[parentU];
        }
        else{
            parent[parentV]=parentU;
            size[parentU]+=size[parentV];
        }
    }

};
int main(){
    // Disjoints Set Data structure = It is also known as the union find and the merge find data structure basically it is the collection of disjoints set.
    // Disjoints Sets = It is defined as the subset where there is no common elements between the two sets.
    // Operations:
    // 1. Find = It is used to find the parent of the given node.
    // 2. Union = It takes two nodes as the input and find there parent and after that union them according to some condition.

    // To implment the above operation we use the union by rank/size method with the path compression mechanism.

    // (i) Union by rank:
    Disjoint disj(7);
    disj.unionRank(1,2);
    disj.unionRank(2,3);
    disj.unionRank(4,5);
    disj.unionRank(6,7);
    disj.unionRank(5,6);
    if(disj.find(5)==disj.find(6)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;
    disj.unionRank(3,7);
    if(disj.find(3)==disj.find(7)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;

    // (ii) Union by size:
    disj.unionSize(1,2);
    disj.unionSize(2,3);
    disj.unionSize(4,5);
    disj.unionSize(6,7);
    disj.unionSize(5,6);
    if(disj.find(5)==disj.find(6)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;
    disj.unionSize(3,7);
    if(disj.find(3)==disj.find(7)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;

    return 0;
}