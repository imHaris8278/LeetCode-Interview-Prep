class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> charSet;
        int maxLength = 0, i = 0, j = 0;

        while (i < n && j < n) 
        {
            if (charSet.find(s[j]) == charSet.end()) 
            {
                charSet.insert(s[j]);
                j++;
                maxLength = max(maxLength, j - i);
            } 
            else 
            {
                charSet.erase(s[i]);
                i++;
            }
        }

        return maxLength;
    }
};