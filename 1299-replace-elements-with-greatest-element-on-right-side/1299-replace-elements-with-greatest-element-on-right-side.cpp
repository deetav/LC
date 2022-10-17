class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int N = (int) arr.size();
            int smax = -1, temp = 0;
            for (int i = N - 1; i >= 0; --i) {
                    temp = arr[i];
                    arr[i] = smax;
                    smax = max(smax, temp);
            }
            return arr;
    }
};