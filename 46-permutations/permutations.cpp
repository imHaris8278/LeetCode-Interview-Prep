class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        function<void(int)> backtrack = [&](int start) {
            if (start == nums.size()) {
                res.push_back(nums);
                return;
            }
            for (int i = start; i < nums.size(); ++i) {
                swap(nums[start], nums[i]);
                backtrack(start + 1);
                swap(nums[start], nums[i]);
            }
        };
        backtrack(0);
        return res;
    }
};
