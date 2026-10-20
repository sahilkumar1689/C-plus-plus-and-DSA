using namespace std;
#include <iostream>
#include <queue>

// 1. Node creation of the binary tree:
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d) : data(d)
    {
        this->left = NULL;
        this->right = NULL;
    }
};

void createTree(node *&root)
{
    cout << "Enter the data:";
    int data;
    cin >> data;

    // Base Case:
    if (data == -1)
        return;
    root = new node(data);

    cout << "Please enter the left data for " << data << endl;
    createTree(root->left);
    cout << "Please enter the right data for " << data << endl;
    createTree(root->right);
}

// 2. Level Order Traversal:
void levelOrderTraversal(node *root)
{
    // Handle edge case:
    if (root == NULL)
    {
        cout << "Tree is empty.";
        return;
    }
    queue<node *> qu;
    qu.push(root);
    qu.push(NULL);

    while (!qu.empty())
    {
        node *temp = qu.front();
        qu.pop();

        if (temp != NULL)
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                qu.push(temp->left);
            }

            if (temp->right)
            {
                qu.push(temp->right);
            }
        }
        else
        {
            cout << endl;
            if (!qu.empty())
                qu.push(NULL);
        }
    }
}

// 3. Inorder Traversal(LNR):

void inorderTraversal(node *root)
{
    // Base Case:
    if (root == NULL || root->data == -1)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// 4. Preorder Traversal(NLR):

void preorderTraversal(node *root)
{
    // Base Case:
    if (root == NULL || root->data == -1)
        return;

    cout << root->data << " ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

// 5. Postorder Traversal(LRN):

void postorderTraversal(node *root)
{
    // Base Case:
    if (root == NULL || root->data == -1)
        return;

    inorderTraversal(root->left);
    inorderTraversal(root->right);
    cout << root->data << " ";
}
// 6. Create tree using level order traversal:

void createTreeUsingLevelOrder(node *&root)
{
    queue<node *> qu;
    int data;
    cout << "Enter the data:";
    cin >> data;
    // Edge Case:
    if (data == -1)
        return;

    root = new node(data);
    qu.push(root);

    while (!qu.empty())
    {
        node *temp = qu.front();
        qu.pop();

        // Enter the left element:
        int leftelem;
        cout << "Enter the left element of " << temp->data << ":";
        cin >> leftelem;

        // Check if it's not -1:
        if (leftelem != -1)
        {
            temp->left = new node(leftelem);
            qu.push(temp->left);
        }

        // Enter the right element:
        int rightelem;
        cout << "Enter the right element for " << temp->data << ":";
        cin >> rightelem;

        // Check if it's not -1:
        if (rightelem != -1)
        {
            temp->right = new node(rightelem);
            qu.push(temp->right);
        }
    }
}
int main()
{
    // 1. Binary Tree = A binary tree is a tree type non-linear data structure.In binary tree every parent can hava a maximum of two childerns.Every node in binary tree has a left and right reference along with the data elements.
    // The top most node of the binary tree is called the root and the bottom most nodes of the binary tree are called leaves.A binary tree can be visualized as a hierarchical structure with the root at the top and the leaves at the bottom.It have many application in the computer science,including data storage,network routing and in various searching,sorting,graph alogorithm.

    // Binary tree traversals:
    // 1. Depth-First-Search = It include inorder traversal(LNR),preorder traversal(NLR),postorder traversal(LRN).
    // 2. Breadth-First-Search = It include level-order traversal.

    // 1. Creation of the binary tree:

    node *root = NULL;

    createTree(root);

    // 2. Level order Traversal:

    // cout<<endl<<"Levelorder Traversal are:"<<endl;
    // levelOrderTraversal(root);

    // // 3. Inorder Traversal(LNR):

    cout << endl
         << "Inorder Traversal are:" << endl;
    inorderTraversal(root);

    // // 4. Preorder Traversal(NLR):

    // cout<<endl<<"Preorder Traversal are:"<<endl;
    // preorderTraversal(root);

    // // 5. Postorder Traversal(LRN):

    // cout<<endl<<"Postorder Traversal are:"<<endl;
    // postorderTraversal(root);

    // 6. Create tree using level order traversal:

    // createTreeUsingLevelOrder(root);

    // levelOrderTraversal(root);

    return 0;
}