class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> result;
        string current;
        int left = 0, right = 0;

        generateParenthesisHelper(n, left, right, current, result);

        return result;
    }

    void generateParenthesisHelper(int n, int left, int right, string current, vector<string>& result)
    {
        if (left == n && right == n)
        {
            result.push_back(current);
            return;
        }

        if (left < n)
        {
            generateParenthesisHelper(n, left + 1, right, current + '(', result);
        }

        if (right < left)
        {
            generateParenthesisHelper(n, left, right + 1, current + ')', result);
        }
    }
};