class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> s;
        
        for (const auto& token : tokens) 
        {
            if (isOperator(token)) 
            {
                int operand2 = s.top();
                s.pop();
                int operand1 = s.top();
                s.pop();
                
                int result;
                if (token == "+") 
                {
                    result = operand1 + operand2;
                } 
                else if (token == "-") 
                {
                    result = operand1 - operand2;
                } 
                else if (token == "*") 
                {
                    result = operand1 * operand2;
                } 
                else if (token == "/") 
                {
                    result = operand1 / operand2;
                }
                
                s.push(result);
            } 
            else 
            {
                s.push(stoi(token));
            }
        }
        
        return s.top();
    }
    
private:
    bool isOperator(const string& token) 
    {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};