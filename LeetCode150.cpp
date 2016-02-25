// accepetd
// include <sstream>
// pay attention to that vector.pop_back() has no return value.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        int value;
        int i = 0;
        while(i < tokens.size()){
            if(IsNum(tokens[i])){
                stringstream ss(tokens[i]);
                ss >> value;
                stack.push_back(value);
            }
            else if(tokens[i] == "+"){
                int y = stack.back();
                stack.pop_back();
                int x = stack.back();
                stack.pop_back();
                stack.push_back(x + y);
            }
            else if(tokens[i] == "-"){
                int y = stack.back();
                stack.pop_back();
                int x = stack.back();
                stack.pop_back();
                stack.push_back(x - y);
            }
            else if(tokens[i] == "*"){
                int y = stack.back();
                stack.pop_back();
                int x = stack.back();
                stack.pop_back();
                stack.push_back(x * y);
            }
            else if(tokens[i] == "/"){
                int y = stack.back();
                stack.pop_back();
                int x = stack.back();
                stack.pop_back();
                stack.push_back(x / y);
            }
            else
                return -1;
            i++;
        }
        return stack.back();
    }
    
private:
    bool IsNum(string token){
        if(token != "+" && token != "-" && token != "*" && token != "/")
            return true;
        else
            return false;
    }
};
