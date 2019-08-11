class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size(), size2 = num2.size();
        string prod(size1 + size2, '0');
        for (int i = size1 - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = size2 - 1; j >= 0; j--) {
                int tmp = carry + int(prod[i+j+1]-'0') + 
                        int(num1[i]-'0') * int(num2[j]-'0');
                carry = tmp / 10;
                prod[i+j+1] = tmp % 10 + '0';
            }
            prod[i] = prod[i] + carry;
        }
        
        size_t start = prod.find_first_not_of("0");
        if (start != string::npos) {
            return prod.substr(start);
        }
        return "0";
    }
};
