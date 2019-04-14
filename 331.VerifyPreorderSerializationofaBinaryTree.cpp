class Solution {
public:
    bool isValidSerialization(string preorder) {
        int diff = 1;
        size_t pos = 0;
        while (pos != preorder.size() && pos != std::string::npos) {
            if (--diff < 0) return false;
            if (preorder[pos] != '#')
                diff += 2;
            pos = preorder.find(',', pos);
            if (pos != std::string::npos)
                pos++;
        }
        return diff == 0;
    }  
};
