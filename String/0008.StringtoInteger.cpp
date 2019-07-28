class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;

        int found = str.find_first_not_of(' ');
        if (found == std::string::npos)
            return 0;
        str = str.substr(found);

        bool is_signed = false;
        if (str[0] == '-') {
            is_signed = true;
            str = str.substr(1);
        } else if (str[0] == '+')
            str = str.substr(1);
        int myRes = 0;
        for (int i = 0; i != str.size(); i++) {
            if (str[i] < '0' || str[i] > '9')
                break;
            
            if ((!is_signed && myRes == INT_MAX / 10 && str[i] >= '7') 
                || (!is_signed && myRes > INT_MAX / 10))
                return INT_MAX;
            else if ((is_signed && myRes == INT_MAX / 10 && str[i] >= '8')
                || (is_signed && myRes > INT_MAX / 10))
                return INT_MIN;
            
            myRes = myRes * 10 + (str[i] - '0');
        }
        return is_signed ? -myRes : myRes;
    }
};
