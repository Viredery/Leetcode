class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack_num;
        vector<string>::iterator ptr = tokens.begin();
        while(ptr != tokens.end()) {
            if(ptr->at(0) == '+') {
                int num_one = stack_num.top();
                stack_num.pop();
                int num_two = stack_num.top();
                stack_num.pop();
                stack_num.push(num_one + num_two);
            } else if(ptr->at(0) == '-' && ptr->size() == 1) {
                int num_one = stack_num.top();
                stack_num.pop();
                int num_two = stack_num.top();
                stack_num.pop();
                stack_num.push(num_two - num_one);
            } else if(ptr->at(0) == '*') {
                int num_one = stack_num.top();
                stack_num.pop();
                int num_two = stack_num.top();
                stack_num.pop();
                stack_num.push(num_one * num_two);                
            } else if(ptr->at(0) == '/') {
                int num_one = stack_num.top();
                stack_num.pop();
                int num_two = stack_num.top();
                stack_num.pop();
                stack_num.push(num_two / num_one);
            } else {
                int num = atoi(ptr->c_str());
                stack_num.push(num);
            }
            ptr++;
        }
        return stack_num.top();
    }
};
