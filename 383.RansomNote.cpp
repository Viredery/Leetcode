class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counts;
        for (int i = 0; i != ransomNote.size(); i++) {
            if (counts.find(ransomNote[i]) == counts.end())
                counts[ransomNote[i]] = 0;
            counts[ransomNote[i]]++;
        }
        for (int i = 0; i != magazine.size(); i++) {
            if (counts.find(magazine[i]) != counts.end()) {
                counts[magazine[i]]--;
                if (counts[magazine[i]] == 0)
                    counts.erase(magazine[i]);
            }
        }
        return counts.empty();
    }
};