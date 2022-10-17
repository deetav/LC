//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution {
public:
    vector<int> findLeastGreater(vector<int> &arr, int n) {
            multiset<int> M;
            int N = (int) arr.size();
            if (N == 1) return {-1};
            for (int i = N - 1; i >= 0; --i) {
                    M.insert(arr[i]);
                    auto I = M.upper_bound(arr[i]);
                    if (I == M.end()) {
                            arr[i] = -1;
                    } else arr[i] = *I;
            }
            return arr;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends