    class Solution {
    public:
    bool isValid(string str) {
            stack<char> s;
            for(char &c:str){
                if(c == '[' || c == '{' || c == '(')
                    s.push(c);
                else{
                    if(s.empty())return false;
                    if(s.top() == '[' && c == ']' || s.top() == '{' && c == '}' || s.top() == '(' && c == ')')
                    s.pop();
                    else
                        return false;
                }
            }
            return s.empty();
        }
    };