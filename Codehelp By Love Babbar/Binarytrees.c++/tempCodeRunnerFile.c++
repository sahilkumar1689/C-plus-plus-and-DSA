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

void createTree(node *&root)
{
    int data;
    cout << endl
         << "Enter the data:";
    cin >> data;

    if (data == -1)
        return;
    root = new node(data);

    cout << "Please enter the left data for " << data;
    createTree(root->left);
    cout << "Please enter the right data for " << data;
    createTree(root->right);
}

void levelOrderTraversal(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty." << endl;
        return;
    }

    queue<node *> q;
    q.push(root);
    node *temp = NULL;

    while (!q.empty())
    {
        temp = q.front();
        cout << temp->data << " ";
        q.pop();

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

void creatTreeUsingLevelTraversal(node *&root)
{
    int data;
    cout << "Enter the data:";
    cin >> data;

    if (data == -1)
        return;

    root = new node(data);
    queue<node *> q;
    node *temp = NULL;
    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        int leftData;
        cout << "Please enter the data for " << temp->data;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Please enter the data for " << temp->data;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
};

int main()
{

    node *root = NULL;

    // createTree(root);

    creatTreeUsingLevelTraversal(root);

    levelOrderTraversal(root);

    return 0;
}