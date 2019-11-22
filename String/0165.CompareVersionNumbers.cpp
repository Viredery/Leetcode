class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (i < version1.size() || j < version2.size()) {
            int x = i, y = j;
            while (x < version1.size() && version1[x] != '.')
                x++;
            while (y < version2.size() && version2[y] != '.')
                y++;
            int num1 = i < version1.size() ? std::stoi(version1.substr(i, x-i)) : 0;
            int num2 = j < version2.size() ? std::stoi(version2.substr(j, y-j)) : 0;
            if (num1 > num2)
                return 1;
            if (num1 < num2)
                return -1;
            i = x + 1;
            j = y + 1;
        }
        return 0;
    }
};
