class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> hash;
        for (string& email : emails) {
            string name;
            int at = email.find('@');
            for (int i = 0; i != at; i++) {
                if (email[i] == '+')
                    break;
                else if (email[i] == '.')
                    continue;
                name += email[i];
            }
            hash.insert(name + email.substr(at));
        }
        return hash.size();
    }
};
