//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int L = 0, R = m - 1;
 		int U = 0, D = n - 1;
 		int ans = -1;
 		int cnt = 0;
 		while(L < R || U < D) {
 		    for(int i = L; i <= R; ++i) {
 		        ++cnt;
 		        ans = a[U][i];
 		        if(cnt == k) return ans;
 		    }
 		    ++U;
 		    for(int i = U; i <= D; ++i) {
 		        ++cnt;
 		        ans = a[i][R];
 		        if(cnt == k) return ans;
 		    }
 		    --R;
 		    for(int i = R; i >= L; --i) {
 		        ++cnt;
 		        ans = a[D][i];
 		        if(cnt == k) return ans;
 		    }
 		    --D;
 		    for(int i = D; i >= U; --i) {
 		        ++cnt;
 		        ans = a[i][L];
 		        if(cnt == k) return ans;
 		    }
 		    ++L;
 		}
 		return ans;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends