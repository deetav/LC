//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  vector<int> ans;
  void preorder(int a[], int l, int h ){
    if(l>h) return;
    if(l==h) ans.push_back(a[l]);
    int i;
    for(i=l+1; i<=h; i++){
        if(a[i] > a[l]) break;
    }
    preorder(a,l+1,i-1);
    preorder(a,i,h);
}

    vector<int> leafNodes(int arr[],int N) {
         preorder(arr,0,N-1);
         return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends