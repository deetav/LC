//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	     int i=0,maxm=0,count=0,start=0,end=-1;
    int fstart=-1,fend=-1;
    long long int sum=0,maxsum=0;
    vector<int> res;
    while(i<n){
        if(a[i]>=0){
            sum+=a[i];
            count++;
            end++;
        }
        if(sum>maxsum){
            maxsum=sum;
            fstart=start;
            fend=end;
        }
        else if(sum==maxsum&&count>maxm){
            maxm=count;
            fstart=start;
            fend=end;
        }
        if(a[i]<0){
            count=0;
            start=i+1;end=i;
            sum=0;
        }
        i++;
    }
    if(fstart!=-1&&fend!=-1){
        for(int i=fstart;i<=fend;i++)
         res.push_back(a[i]);
    }
    if(res.empty()) res.push_back(-1);
    return res;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends