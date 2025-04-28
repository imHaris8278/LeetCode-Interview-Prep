class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> counter;
        for (int num : nums)
        {
            counter[num]++;
        }
    
        auto cmp = [](pair<int, int>& a, pair<int, int>& b)
        {
            return a.second > b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    
        for (auto& entry : counter)
        {
            pq.push(entry);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().first);
            pq.pop();
        }
    
        reverse(result.begin(), result.end());
        return result;
    }
};