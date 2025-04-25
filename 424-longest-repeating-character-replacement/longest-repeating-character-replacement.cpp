class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int start = 0, maxLen = 0, maxFreq = 0;
        for(int end = 0; end < s.size(); end++)
        {
            freq[s[end] - 'A']++;
            maxFreq = max(maxFreq, freq[s[end] - 'A']);
            if (end - start + 1 - maxFreq > k)
            {
                freq[s[start] - 'A']--;
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};