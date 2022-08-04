class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return kZero;
        }
        return toWords(num);
    }
    
private:
    std::string toWords(int num) {
        if (num >= 1e9) {
            const int remainder = num % static_cast<int>(1e9);
            return toWords(num / 1e9) + " Billion" + connector(remainder) + toWords(remainder);
        }
        if (num >= 1e6) {
            const int remainder = num % static_cast<int>(1e6);
            return toWords(num / 1e6) + " Million" + connector(remainder) + toWords(remainder);
        }
        if (num >= 1e3) {
            const int remainder = num % static_cast<int>(1e3);
            return toWords(num / 1e3) + " Thousand" + connector(remainder) + toWords(remainder);
        }
        if (num >= 1e2) {
            const int remainder = num % 100;
            return toWords(num / 1e2) + " Hundred" + connector(remainder) + toWords(num % 100);
        }
        if (num >= 20) {
            const int remainder = num % 10;
            return kTensDigits[(num - 20) / 10] + connector(remainder) + toWords(remainder);
        }
        return kOneDigits[num];
    }
    
    std::string connector(int num) {
        return num == 0 ? "" : " ";
    }
    
    const std::string kZero = "Zero";
    const std::array<std::string, 20> kOneDigits =
        {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
         "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
         "Eighteen", "Nineteen"};
    const std::array<std::string, 8> kTensDigits =
        {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
};
