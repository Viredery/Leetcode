class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> cntS(10, 0), cntG(10, 0);
        for (int i = 0; i != secret.size(); i++)
            if (secret[i] == guess[i])
                bulls++;
            else
                cntS[secret[i] - '0']++, cntG[guess[i] - '0']++;
            
        for (int i = 0; i != 10; i++)
            cows += min(cntS[i], cntG[i]);
        return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
    }
};
