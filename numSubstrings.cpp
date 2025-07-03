
class Solution {
public:
    int numberOfSubstrings(string s) {

        int substringCount = 0;
        vector<int> lastOccurence(3, -1);

        for (int i = 0; i < s.size(); i++) {

            lastOccurence[s[i] - 'a'] = i;

            if (lastOccurence[0] != -1 && lastOccurence[1] != -1 && lastOccurence[2] != -1) {
                substringCount = substringCount + (1 + min({lastOccurence[0], lastOccurence[1], lastOccurence[2]}));
            }
        }

        return substringCount;
    }
};
