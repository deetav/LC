//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int median(vector<vector<int>> &matrix, int R, int C) {
        auto ok = [&](int x) {
            int cnt = 0;
            for (int i = 0; i < R; ++i) {
                    auto I = upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
                    cnt += I;
                    
            }
            if (cnt < ((R * C) / 2) + 1) {
                            return false;
                    }
                    return true;
        };
        int l = 0, r = 3000;
        while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (ok(m)) {
                        r = m;
                } else l = m;
        }
        return r;
}

};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends