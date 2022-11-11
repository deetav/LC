//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
string isSumOfTwo(int N) {
        string y = "Yes", n = "No";
        set<int> collect;
        N += 100000;
        bool prime[N + 1];
        memset(prime, true, sizeof(prime));
        for (int p = 2; p * p <= N; p++) {
                if (prime[p]) {
                        for (int i = p * p; i <= N; i += p)
                                prime[i] = false;
                }
        }
        for (int p = 2; p <= N; p++){
            if (prime[p]) collect.insert(p);
        }
        N -= 100000;
        for(auto e : collect){
                    if(collect.find(N-e)!=collect.end()) return y;
        }
        return n;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends