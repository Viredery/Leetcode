class Solution {
public:
    string removeDuplicateLetters(string s) {
        std::unordered_set<char> visited;
        std::vector<char> st;
        std::unordered_map<char, int> last_pos;
        for (int i = 0; i != s.size(); ++i) {
            last_pos[s[i]] = i;
        }

        for (int i = 0; i != s.size(); ++i) {
            if (visited.count(s[i])) {
                continue;
            }
            while (!st.empty() && st.back() > s[i] && last_pos[st.back()] >= i) {
                visited.erase(st.back());
                st.pop_back();
            }

            st.push_back(s[i]);
            visited.insert(s[i]);
        }
        
        return std::string{st.begin(), st.end()};
    }
};
