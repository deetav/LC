//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMiddleUtil(stack<int> &inputStack, int N, int count)
{
    
    // Base Case
    // If stack is empty OR count is equal to N
    if(inputStack.empty())
    {
        return;
    }
    
    // Initialise top as top element of stack
    int top = inputStack.top();
    inputStack.pop();
    
    // Recursively call for rest of the stack
    deleteMiddleUtil(inputStack, N, count + 1);
    
    // If count is not equal to (N - 1) / 2
    if(count != (N) / 2)
    {
        inputStack.push(top);
    }
}
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
         int count = 0;
    
    // Initialising recursive function
	deleteMiddleUtil(s, sizeOfStack, count);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends