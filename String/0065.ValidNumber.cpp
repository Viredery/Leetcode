class Solution {
public:
    bool isNumber(string s) {
        static vector<unordered_map<string, int>> states = {
            {{"Space", 0}, {"Sign", 1}, {"Number", 2}, {"Dot", 3}},
            {{"Number", 2}, {"Dot", 3}},
            {{"Number", 2}, {"Dot", 4}, {"Exp", 5}, {"Space", 8}},
            {{"Number", 4}},
            {{"Number", 4}, {"Exp", 5}, {"Space", 8}},
            {{"Sign", 6}, {"Number", 7}},
            {{"Number", 7}},
            {{"Number", 7}, {"Space", 8}},
            {{"Space", 8}},
        };
        unordered_set<int> endStates = {2, 4, 7, 8};
        int idx = 0;
        for (char c : s) {
            string state;
            if (c == ' ')
                state = "Space";
            else if (c == '+' || c == '-')
                state = "Sign";
            else if (c == '.')
                state = "Dot";
            else if (c == 'e')
                state = "Exp";
            else if (c >= '0' && c <= '9')
                state = "Number";
            else
                return false;
            
            if (states[idx].find(state) == states[idx].end())
                return false;
            idx = states[idx][state];

        }
        return endStates.find(idx) != endStates.end();
    }
};
