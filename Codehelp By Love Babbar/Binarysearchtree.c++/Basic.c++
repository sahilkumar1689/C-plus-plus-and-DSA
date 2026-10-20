using namespace std;
#include <iostream>
#include<queue>
class node{
    public:
    int data;
    node* left;
    node*right;
    node(int d):data(d){
        left=NULL;
        right=NULL;
    }
};

// 1. Insertion in Binary Search Tree:
void insertBST(node* &root,int data){

    if(root==NULL) {
        root=new node(data);
        return;
    }
    else if(data>root->data){
        insertBST(root->right,data);
    }
    else{
        insertBST(root->left,data);
    }
}

// Traversal :

// Level order traversal:
void levelBST(node* root){
    // Edge Case:
    if(root==NULL) return;

    queue<node*>qu;
    qu.push(root);
    qu.push(NULL);

    while(!qu.empty()){
        node* temp=qu.front();
        qu.pop();

        if(temp!=NULL){
            cout<<temp->data<<" ";
            if(temp->left) qu.push(temp->left);
            if(temp->right) qu.push(temp->right);
        }
        else{
            cout<<endl;
            if(!qu.empty()) qu.push(NULL);
        }
    }
}

// Inorder Traversal(LNR):
void inOrderBST(node* root){
    // Base Case:
    if(root==NULL) return;

    inOrderBST(root->left);
    cout<<root->data<<" ";
    inOrderBST(root->right);
}
// Preorder Traversal(NLR):
void preOrderBST(node* root){
    // Base Case:
    if(root==NULL) return;

    cout<<root->data<<" ";
    inOrderBST(root->left);
    inOrderBST(root->right);
}
// Postorder Traversal(LRN):
void postOrderBST(node* root){
    // Base Case:
    if(root==NULL) return;

    inOrderBST(root->left);
    inOrderBST(root->right);
    cout<<root->data<<" ";
}

// Seaching in Binary search tree:
bool searchBST(node* root,int element){
    // Base Case:
    if(root==NULL) return false;
    if(root->data==element) return true;

    if(element>root->data) {
        return searchBST(root->right,element);
    }
    else {
        return searchBST(root->left,element);
    }
}

// Get minimum and maximum value from the binary search tree:
int getMin(node* root){
    // Base Case:
    if(root->left==NULL) {
        return root->data;
    }

    return getMin(root->left);
}
int getMax(node* root){
    // Base Case:
    if(root->right==NULL) {
        return root->data;
    }

    return getMax(root->right);
}

// Delete from the Binary search tree:

node* deleteBST(node* root,int element){
    // Base Case:
    if(root==NULL) return root;
    if(root->data==element){
        // No child:
        if(root->left==NULL && root->right==NULL) {
            delete root;
            return NULL;
        }
        // One child:
        // (i) Left child:
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        // (ii) Right child:
        if(root->left==NULL && root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        // Two child= Here we have two option first we find the larger number from the left side and copy it with the current node after that delete that larger number node from the left side or we find smaller number from the right side and copy it with the current node and after that delete that smaller number node from the right side.
        if(root->left && root->right){
            int min = getMin(root->right);
            root->data=min;
            root->right=deleteBST(root->right,min);
            return root;
        }
    }

    if(element>root->data){
        root->right=deleteBST(root->right,element);
    }
    else{
       root->left=deleteBST(root->left,element);
    }
    return root;
}
int main(){
    // Binary Search Tree = Binary search tree is a special type of a binary tree in which each node have atmost two child and also the left node must have smaller value than the parent node and similarly the right node must have larger element than its parent node.This property also applied recursively on its left subtree and right subtree.

    // 1. Insertion in Binary Search Tree = Complexity[O(n) in worst or O(log(n)) in average case,O(n)].

    node* root=NULL;

    int size;
    cout<<"Please enter the number of element you want to insert:";
    cin>>size;
    
    while(size!=0){
        int data;
        cout<<"Please enter the data you want to insert:";
        cin>>data;
        insertBST(root,data);
        size--;
    }

    // 2. Traversal in Binary search tree = Treaversal in binary search tree is similar to the traversal in binary tree no change.Complexity[O(n),O(n)].

    // // (i) Levelorder Traversal:
    // cout<<endl;
    // levelBST(root);

    // // (ii) Inorder Traversal= In binary search tree the inorder traversal print the element in the sorted order.
    // cout<<endl;
    // inOrderBST(root);

    // // (iii) Preorder Traversal:
    // cout<<endl;
    // preOrderBST(root);

    // // (iv) Postorder Traversal:
    // cout<<endl;
    // postOrderBST(root);

    // // 3. Searching in Binary search tree = Complexity[O(n) in worst or O(log(n)) in average case,O(n)].

    // int element;
    // cout<<"Please enter the data you want to search in the tree:";

    // cin>>element;
    // cout<<searchBST(root,element)<<endl;

    // 4. Find the minimum and maximum value from the binary search tree=To fins the minimum element we only need to find the left leaf node and for larger we only need to finf the right leaf node.Complexity[O(n) in worst or O(log(n)) in average case,O(n)].
    // int min=getMin(root);
    // int max=getMax(root);
    // cout<<"Minimum value is:"<<min<<endl<<"Maximum value is:"<<max<<endl;

    // 5. Deletion in binary search tree = It is little bit complex because in this we need to handle three cases and two sub cases.Complexity[O(n) in worst or O(log(n)) in average case,O(n)].

    int data;
    cout<<"Please enter the data you want on to delete:";
    cin>>data;

    root=deleteBST(root,data);

    levelBST(root);



    return 0;
}