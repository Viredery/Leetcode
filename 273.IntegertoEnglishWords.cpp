class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        return helper(num).substr(1);
        
    }
private:
    string helper(int num) {
        if (num >= 1000000000)
            return helper(num / 1000000000) + " Billion" + helper(num % 1000000000);
        else if (num >= 1000000)
            return helper(num / 1000000) + " Million" + helper(num % 1000000);
        else if (num >= 1000)
            return helper(num / 1000) + " Thousand" + helper(num % 1000);
        else if (num >= 100)
            return helper(num / 100) + " Hundred" + helper(num % 100);
        else if (num >= 20)
            return " " + TEN_NUMBERS[num / 10 - 2] + helper(num % 10);
        else if (num >= 1)
            return " " + NUMBERS[num - 1];
        else
            return "";   
    }
    static string NUMBERS[];
    static string TEN_NUMBERS[];
};

string Solution::NUMBERS[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                              "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string Solution::TEN_NUMBERS[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};