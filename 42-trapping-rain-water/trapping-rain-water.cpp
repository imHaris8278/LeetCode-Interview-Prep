class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int trappedWater = 0;

        while (left < right)
        {
            if (height[left] <= height[right])
            {
                maxLeft = max(maxLeft, height[left]);
                trappedWater += maxLeft - height[left];
                left++;
            }
            else
            {
                maxRight = max(maxRight, height[right]);
                trappedWater += maxRight - height[right];
                right--;
            }
        }

        return trappedWater;
    }
};