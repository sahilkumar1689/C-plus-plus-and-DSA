using namespace std;
#include <iostream>
#include <bits/stdc++.h>

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

void insertAtTree(node *&root, int data)
{
    // Base Case:
    if (root == NULL)
    {
        root = new node(data);
        return;
    }
    else if (data > root->data)
    {
        insertAtTree(root->right, data);
    }
    else
    {
        insertAtTree(root->left, data);
    }
}

void createBinarySearchTree(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertAtTree(root, data);
        cin >> data;
    }
}

void levelOrder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    node *temp = NULL;
    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

node *minValue(node *root)
{
    if (root == NULL || root->left == NULL)
    {
        return root;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

node *deleteNode(node *root, int data)
{
    // Base Case:
    if (root == NULL)
        return root;

    if (root->data == data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->left != NULL && root->right != NULL)
        {
            int min = minValue(root->right)->data;
            root->data = min;
            root->right = deleteNode(root->right, min);
            return root;
        }
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
        root->left = deleteNode(root->left, data);
    return root;
}

int main()
{

    node *root = NULL;

    createBinarySearchTree(root);

    levelOrder(root);

    int data;
    cout << endl
         << "Enter data to delete:";
    cin >> data;

    root = deleteNode(root, data);
    cout << endl;
    levelOrder(root);
    return 0;
}