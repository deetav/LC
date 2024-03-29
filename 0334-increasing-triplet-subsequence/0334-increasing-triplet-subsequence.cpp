
class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
            int a = INT32_MAX, b = INT32_MAX;
            for (auto e: nums) {
                    if (e <= a) a = e;
                    else if (e <= b) b = e;
                    else return true;
            }
            return false;
    }
};