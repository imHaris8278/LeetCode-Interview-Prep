class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;
        int wordLen = words[0].size(), wordCount = words.size(), totalLen = wordLen * wordCount;
        if (s.size() < totalLen) return res;

        unordered_map<string, int> wordMap;
        for (auto &w : words) wordMap[w]++;

        for (int i = 0; i < wordLen; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> seen;
            for (int j = i; j <= (int)s.size() - wordLen; j += wordLen) {
                string sub = s.substr(j, wordLen);
                if (wordMap.count(sub)) {
                    seen[sub]++;
                    count++;
                    while (seen[sub] > wordMap[sub]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == wordCount) res.push_back(left);
                } else {
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return res;
    }
};