class Solution {
public:
    void reverseWords(string &s) {
        vector<string> v;
        string::size_type pos = 0, nums = s.size(); 
        while(pos != nums) {
            string::size_type start = s.find_first_not_of(' ', pos);
            if(start == string::npos)
                break;
            string::size_type end = s.find_first_of(' ', start);
            if(end == string::npos) {
                end = nums - 1;
                v.push_back(s.substr(start, nums - start));
            } else
                v.push_back(s.substr(start, end - start));
            pos = end + 1;
        }
        s.clear();
        vector<string>::reverse_iterator p = v.rbegin();
        if(v.empty())
            return;
        s.append(*p);
        while(++p != v.rend()) {
            s.append(" ");
            s.append(*p);
        }
    }
};
