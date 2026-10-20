using namespace std;
#include <iostream>
#include<unordered_map>
#include<list>
#include<vector>
class graph{
    unordered_map<int,vector<int>>mpp; // you can also use the list<int>.
    public:
    void addEdge(int a,int b,bool direction){
        mpp[a].push_back(b);
        if(direction==0){
            mpp[b].push_back(a);
        }
    }
    void printGraph(){
        for(auto it:mpp){
            cout<<it.first<<"->";
            for(auto i:it.second){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
};
void storeGraph(vector<vector<int>>vec,int nodes,int edges,unordered_map<int,vector<int>>&mpp){
    for(int i=0;i<edges;i++){
        int start=vec[i][0];
        int end=vec[i][1];

        mpp[start].push_back(end);
        mpp[end].push_back(start);
    }
}
void printGraph(unordered_map<int,vector<int>>mpp){
    for(auto it:mpp){
        cout<<it.first<<"->";
        for(auto i:it.second){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
void storeGraph1(vector<vector<int>>vec,int nodes,int edges){
    vector<int>ans[nodes];
    for(int i=0;i<edges;i++){
        int start=vec[i][0];
        int end=vec[i][1];

        ans[start].push_back(end);
        ans[end].push_back(start);
    }

    for(int i=0;i<nodes;i++){
        cout<<i<<"->";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
void storeGraph2(vector<vector<int>>vec,int nodes,int edges,vector<vector<int>>&matrix){
    
    for(int i=0;i<edges;i++){
        int start=vec[i][0];
        int end=vec[i][1];

        matrix[start][end]=1;
        matrix[end][start]=1;
    }

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    // Graphs = It is non linear data structure.

    // 1. Adjacency Matrix:
    vector<vector<int>>matrix(nodes,vector<int>(nodes,0));
    storeGraph2(vec,nodes,edges,matrix);

    // 2. Adjacency List:
    // (i). Stored in map one by one:
    // int u,v,direction;
    // cout<<"Please enter the number of nodes:";
    // cin>>u;
    // cout<<"Please enter the number of edges:";
    // cin>>v;
    // cout<<"Please enter the 0 for undirected and 1 for directed:";
    // cin>>direction;
    
    // graph g;
    // for(int i=0;i<v;i++){
    //     int start,end;
    //     cin>>start>>end;
    //     g.addEdge(start,end,direction);
    // }
    // g.printGraph();

    // (ii). Stored in map when collective matrix given:
    vector<vector<int>>vec{{0,1},{0,2},{2,1},{2,3}};
    int nodes=4;
    int edges=4;

    // unordered_map<int,vector<int>>mpp;
    // storeGraph(vec,nodes,edges,mpp);
    // printGraph(mpp);

    // (iii). Stored in array of vectors:

    // storeGraph1(vec,nodes,edges);




    return 0;
}