//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        long long int X = 0;
        for (int i = 0; i < N; ++i) X ^= Arr[i];
        long long int right_most = X & (~X + 1);
        long long int x = 0, y = 0;
        for (int i = 0; i < N; ++i) {
                if ((right_most & Arr[i]) != 0) x ^= Arr[i];
                else y ^= Arr[i];
        }
        if (x > y) swap(x, y);
        return {y, x};
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends