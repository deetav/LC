class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
            sort(nums.begin(), nums.end());
            int N = (int) nums.size();
            int64_t closest = INT32_MAX;
            for (int ptr1 = 0; ptr1 + 2 < N; ++ptr1) {
                    int ptr2 = ptr1 + 1;
                    int ptr3 = N - 1;
                    while(ptr2 < ptr3){
                        int64_t cur_sum = nums[ptr1] + nums[ptr2] + nums[ptr3];
                    if (abs(closest - target) > abs(cur_sum - target)) {
                            closest = cur_sum;
                    }
                    if (cur_sum > target) --ptr3;
                    else if (cur_sum < target) ++ptr2;
                    else return target;
                    }
            }
            return closest;
    }
};