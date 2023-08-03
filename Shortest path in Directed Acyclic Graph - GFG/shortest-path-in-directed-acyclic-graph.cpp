//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> D(N, INT32_MAX / 4);
        D[0] = 0;
        for(int i = 0; i < N - 1; ++i) {
            for(auto &e : edges) {
                int s = e[0];
                int d = e[1];
                int w = e[2];
                if(D[s] != INT32_MAX / 4 and D[s] + w < D[d]) {
                    D[d] = D[s] + w;
                }
            }
        }
        for(int i = 0; i < N; ++i) {
            if(D[i] == INT32_MAX / 4) {
                D[i] = -1;
            }
        }
        return D;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends