class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        std::vector<double> double_cards;
        for (const auto& card : cards) {
            double_cards.push_back(card);
        }
        return judgePoint24(double_cards);
    }
private:
    bool judgePoint24(vector<double>& cards) {
        if (cards.size() == 1 && abs(cards[0] - 24.0) < 1e-3) {
            return true;
        }
        for (int i = 0; i != cards.size(); ++i) {
            const double left_num = cards[i];
            cards.erase(cards.begin() + i);
            for (int j = 0; j != cards.size(); ++j) {
                const double right_num = cards[j];
                cards.erase(cards.begin() + j);
                
                cards.push_back(left_num + right_num);
                if (judgePoint24(cards)) {
                    return true;
                }
                cards.back() = left_num - right_num;
                if (judgePoint24(cards)) {
                    return true;
                }
                cards.back() = left_num * right_num;
                if (judgePoint24(cards)) {
                    return true;
                }
                if (right_num != 0) {
                    cards.back() = left_num / right_num;
                    if (judgePoint24(cards)) {
                        return true;
                    }
                }
                cards.pop_back();
                cards.insert(cards.begin() + j, right_num);
            }
            cards.insert(cards.begin() + i, left_num);
        }
        return false;
    }
};
