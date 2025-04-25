class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy = 0;
        int maxProfit = 0;

        for (int sell = 1; sell < prices.size(); sell++)
        {
            if (prices[buy] > prices[sell])
            {
                buy = sell;
            }

            maxProfit = max(maxProfit, prices[sell] - prices[buy]);
        }

        return maxProfit;
    }
};