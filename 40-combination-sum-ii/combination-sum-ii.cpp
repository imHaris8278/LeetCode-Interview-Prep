class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        function<void(int, int)> dfs = [&](int start, int t) {
            if (t == 0) {
                res.push_back(path);
                return;
            }
            for (int i = start; i < candidates.size(); ++i) {
                if (i > start && candidates[i] == candidates[i - 1]) continue;
                if (candidates[i] > t) break;
                path.push_back(candidates[i]);
                dfs(i + 1, t - candidates[i]);
                path.pop_back();
            }
        };
        dfs(0, target);
        return res;
    }
};