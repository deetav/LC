//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
          stack<int> s;
        map<int, Node*> m;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == ')') {
                int child = s.top();
                Node* c;
                if(m.find(child) == m.end())
                    c = new Node(child);
                else 
                    c = m[child];
                s.pop();
                int parent = s.top();
                if(m.find(parent) == m.end()) {
                    Node* p = new Node(parent);
                    p->left = c;
                    m[parent] = p;
                }
                else {
                    Node* p = m[parent];
                    p->right = c;
                }
            }
            else {
                int num = 0;
                if(str[i] == '(') {
                    continue;
                }
                else {
                    while(isdigit(str[i])) {
                        num = num*10 + (str[i]-'0');
                        i++;
                    }
                    i--;
                    s.push(num);
                }
            }
        }
        if(m.size() == 0) return new Node(s.top());
        return m[s.top()];
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends