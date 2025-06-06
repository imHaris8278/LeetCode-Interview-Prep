class KthLargest
{
public:
    vector<int> stream;
    int k;

    KthLargest(int k, vector<int>& nums)
    {
        this->k = k;
        for (int num : nums)
        {
            stream.push_back(num);
        }
        
        sort(stream.begin(), stream.end());
    }

    int add(int val)
    {
        int index = getIndex(val);
        stream.insert(stream.begin() + index, val);
        return stream[stream.size() - k];
    }

private:
    int getIndex(int val)
    {
        int left = 0;
        int right = stream.size() - 1;
    
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int midValue = stream[mid];
        
            if (midValue == val)
            {
                return mid;
            }
        
            if (midValue > val)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return left;
    }
};