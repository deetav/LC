//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    
    int n = nums.size();
 
    // base case
    if (n == 0) {
        return 0;
    }
 
    // `I[i]` store the length of the longest increasing subsequence,
    // ending at `nums[i]`
    vector<int> I(n);
 
    // `D[i]` stores the length of the longest decreasing subsequence,
    // starting with `nums[i]`
    vector<int> D(n);
 
    I[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i] && I[j] > I[i]) {
                I[i] = I[j];
            }
        }
        I[i]++;
    }
 
    D[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (nums[j] < nums[i] && D[j] > D[i]) {
                D[i] = D[j];
            }
        }
        D[i]++;
    }
 
    // consider each element as a peak and calculate LBS
    int lbs = 1;
    for (int i = 0; i < n; i++) {
        lbs = max(lbs, I[i] + D[i] - 1);
    }
 
    return lbs;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends