//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
vector<int> reverseSpiral(int R, int C, vector<vector<int>> &a) {
        vector<vector<int>> matrix = a;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, left = 0;
        int bottom = m - 1, right = n - 1;
        vector<int> result;
        while (top <= bottom && left <= right) {
                for (int i = left; i <= right && top <= bottom; i++) {
                        result.push_back(matrix[top][i]);
                }
                top++;
                
                for (int i = top; i <= bottom && left <= right; i++) {
                        result.push_back(matrix[i][right]);
                }
                right--;
                
                for (int i = right; i >= left && top <= bottom; i--) {
                        result.push_back(matrix[bottom][i]);
                }
                bottom--;
                
                for (int i = bottom; i >= top && left <= right; i--) {
                        result.push_back(matrix[i][left]);
                }
                left++;
        }
        reverse(result.begin(), result.end());
        return result;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends