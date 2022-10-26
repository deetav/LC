//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int r=0;
        int g=0;
        int b=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='R') r++;
            else if(a[i]=='G') g++;
            else b++;
        }
        if(r==n or g==n or b==n) return n;
        if(g%2==0 and b%2==0 and r%2==0) return 2;
        if(g%2==1 and b%2==1 and r%2==1) return 2;
         return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends