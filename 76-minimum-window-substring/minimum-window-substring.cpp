class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
        {
            return "";
        }
        
        unordered_map<char, int> target;
        for (char c : t) 
        {
            target[c]++;
        }
        
        int left = 0, right = 0;
        int requiredChars = t.size();
        int minLen = INT_MAX;
        int minStart = 0;
        
        while (right < s.size()) 
        {
            if (target[s[right]] > 0) 
            {
                requiredChars--;
            }

            target[s[right]]--;
            right++;
            
            while (requiredChars == 0) 
            {
                if (right - left < minLen) 
                {
                    minLen = right - left;
                    minStart = left;
                }
                
                target[s[left]]++;
                if (target[s[left]] > 0) 
                {
                    requiredChars++;
                }
                
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};