class Solution {
public:
    string simplifyPath(string path) {
        string s1("."), s2(".."), s;
        vector<string> stack;
        string::size_type pos = 1, nums = path.size(), next_slash;
        while(pos != nums) {
            next_slash = path.find('/', pos);
            if(next_slash == string::npos)
            {
                s = path.substr(pos, nums - pos);
                next_slash = nums - 1;
            } else if(next_slash == pos) {
                pos++;
                continue;
            } else
                s = path.substr(pos, next_slash - pos);
            if(s.compare(s1) == 0) {
                ;
            } else if(s.compare(s2) == 0) {
                if(!stack.empty())
                    stack.pop_back();
            } else {
                stack.push_back(s);
            }
            pos = next_slash + 1;
        }
        if(stack.empty())
            return string("/");
        vector<string>::iterator p = stack.begin();
        string result;
        while(p != stack.end()) {
            result.append(1, '/');
            result.append(*p);
            p++;
        }
        return result;
    }
};
