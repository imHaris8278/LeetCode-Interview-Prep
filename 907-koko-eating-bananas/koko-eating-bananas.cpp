class Solution
{
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (canEatInTime(piles, mid, h)) 
            {
                right = mid;
            } 
            else 
            {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool canEatInTime(const vector<int>& piles, int speed, int h)
    {
        int hoursRequired = 0;

        for (int pile : piles) 
        {
            hoursRequired += (pile + speed - 1) / speed;
        }
        
        return hoursRequired <= h;
    }
};