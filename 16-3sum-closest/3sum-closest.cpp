class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long closestSum = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                {
                    return sum;
                }
                else if (sum < target)
                {
                    ++j;
                }
                else
                {
                    --k;
                }

                if (abs(sum - target) < abs(closestSum - target))
                {
                    closestSum = sum;
                }
            }
        }

        return closestSum;
    }
};