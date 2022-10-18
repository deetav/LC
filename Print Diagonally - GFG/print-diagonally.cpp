//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A) {
        vector<int> ans;
        for (int i = 0; i <= N - 1; ++i) {
                int T = i;
                for (int j = 0; j <= T; ++j) {
                        ans.push_back(A[j][T - j]);
                }
        }
        int D = 1;
        for (int i = N; i <= 2 * (N - 1); ++i) {
                int T = i;
                for (int j = D; j <= T - D; ++j) {
                        ans.push_back(A[j][T - j]);
                }
                ++D;
        }
        return ans;
}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends