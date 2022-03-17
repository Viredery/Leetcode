class Solution {
public:
    string convertToTitle(int columnNumber) {
        std::string reverse_result;
        int num = 0;
        while (columnNumber != 0) {
            reverse_result += 'A' + (columnNumber - 1) % 26;
            columnNumber = (columnNumber - 1) / 26;
        }
        std::reverse(reverse_result.begin(),reverse_result.end());
        return reverse_result;
    }
};
