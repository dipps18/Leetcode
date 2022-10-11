class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> operands;
        string operators = "+-/*";
        for(string t : tokens)
        {
            if(operators.find(t) != string::npos && t.length() == 1)
            {
                long num2 = operands.top();
                operands.pop();
                long num1 = operands.top();
                operands.pop();
                operands.push(calc(num1, num2, t));
            }
            else
                operands.push(stoi(t));
        }
        return operands.top();
    }
    
    long calc(long num1, long num2, string ch)
    {
        
        if(ch == "+") return num1 + num2;
        if(ch == "-") return num1 - num2;
        if(ch == "*") return num1 * num2;
        else return num1 / num2;
    }
};