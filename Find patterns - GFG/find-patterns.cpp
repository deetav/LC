//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
         // code here 
        int n=W.size();                  // S="abcdrtbwerrcokokokd"
                                          //W = "bcd" 
        int cnt=0;
        int j=0;
        for(int i=0;i<S.size();i++){
            if(W[j]==S[i]){
                S[i]='@';
                j++;
                
            }
            if(j==n){
                    cnt++;
                    j=0;
                    i=0;//
            }
            
        }
        
        return cnt; 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends