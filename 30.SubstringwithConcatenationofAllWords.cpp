class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty())
        	return result;
        map<string, int> recordOccured;
        for (vector<string>::iterator iterVector = words.begin();
        	    iterVector != words.end();
        	    iterVector++)
        	recordOccured[*iterVector]++;
        int wordLength = words.begin()->size();
        int endPos = s.size() - wordLength * words.size() + 1;
        for (int startPos = 0; startPos < endPos; startPos++) {
        	map<string, int> record(recordOccured);
        	int currPos;
        	for(currPos = startPos
        	        ; currPos < startPos + wordLength * words.size()
        	        ; currPos += wordLength) {
        		string word = s.substr(currPos, wordLength);
        		map<string, int>::iterator iter;
        		if ((iter = record.find(word)) != record.end() && iter->second > 0)
        			iter->second--;
        		else
        			break;
        	}
        	if (currPos == startPos + wordLength * words.size())
        		result.push_back(startPos);
        }
        return result;
    }
};