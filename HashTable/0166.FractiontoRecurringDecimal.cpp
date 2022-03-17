class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        
        std::string result = (numerator > 0) ^ (denominator > 0) ? "-" : ""; 
        long l_numerator = std::abs(static_cast<long>(numerator));
        long l_denominator = std::abs(static_cast<long>(denominator));
        result += std::to_string(l_numerator / l_denominator);
        long remainder = l_numerator % l_denominator;
        if (!remainder) {
            return result;
        }
        
        result += ".";
        std::unordered_map<long, int> num_pos;
        std::string decimal;
        while (remainder != 0) {
            num_pos[remainder] = decimal.size();
            remainder *= 10;
            while (remainder / l_denominator == 0) {
                remainder *= 10;
                decimal += "0";
            }
            decimal += std::to_string(remainder / l_denominator);
            remainder = remainder % l_denominator;
            if (num_pos.count(remainder)) {
                std::string left_decimal = decimal.substr(0, num_pos[remainder]);
                std::string right_decimal = "(" + decimal.substr(num_pos[remainder]) + ")";
                return result + left_decimal + right_decimal;
            }
            num_pos[remainder] = decimal.size();
        }
        return result + decimal;
    }
};
