class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> arr(10, 0);
        int bulls = 0;
        for (int i = 0; i != secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                continue;
            }
            arr[secret[i] - '0']++;
        }
        int cows = 0;
        for (int i = 0; i != secret.size(); i++) {
            if (secret[i] == guess[i]) {
                continue;
            }
            if (arr[guess[i] - '0'] > 0) {
                arr[guess[i] - '0']--;
                cows++;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};