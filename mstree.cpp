class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size(), ans = 0;
        string l, r;
        for (int i = 0; i < n; i++) {
            // build subtect from the left
            l = l + text[i];
            // build subtect from the right
            r = text[n - 1 - i] + r;
            // if they are same,
            if (l == r) {
                // then increase answer by 1
                ans += 1;
                // reset l & r
                l = r = "";
            }
        }
        return ans;
    }
};
