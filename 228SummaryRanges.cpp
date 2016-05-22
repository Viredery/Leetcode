class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;        
        vector<int>::iterator i = nums.begin();
        while(i != nums.end()) {
            string s;
            int start = *i;
            int prevInt = start;
            char intChar[11];
            sprintf(intChar, "%d", start);
            s.append(intChar);
            i++;
            while(i != nums.end()) {
                if( (*i - prevInt) == 1) {
                    prevInt++;
                    i++;
                } else if (*(i-1) != start) {
                    i--;
                    s.append("->");
                    sprintf(intChar, "%d", *i);
                    s.append(intChar);
                    i++;
                    break;
                } else {
                    break;
                }
            }
            if(i == nums.end() && *(i-1) != start) {
                i--;
                s.append("->");
                sprintf(intChar, "%d", *i);
                s.append(intChar);
                i++;
            }
            result.push_back(s);
	    }
	    return result;
    }
};