//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long lcmTriplets(long long N) {
        if(N==1) return 1LL;
        if(N==2) return 2LL;
        if(N==3) return 6LL;
        long long ans ;
        if(N%2!=0){
            ans = (N*(N-1)*(N-2));
            return ans;
        }
        if(N%3==0){
            ans = (N-1)*(N-2)*(N-3);
        }else ans = N*(N-1)*(N-3);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends