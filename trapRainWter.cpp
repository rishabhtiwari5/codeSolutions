class Solution {
public:
    void findLongestBarOnRightside(vector<int>& height, vector<int>& longestBarOnRightside) {

        int longest = 0;

        for (int i = 0; i < height.size(); i++) {
            longestBarOnRightside[i] = longest;
            longest = max(longest, height[i]);
        }

    }

    void findLongestBarOnLeftside(vector<int>& height, vector<int>& longestBarOnLeftside) {

        int longest = 0;

        for (int i = height.size() - 1; i >= 0; i--) {
            longestBarOnLeftside[i] = longest;
            longest = max(longest, height[i]);
        }

    }

    int trap(vector<int>& height) {

        int water = 0;

        vector<int> longestBarOnRightside(height.size(), 0);
        vector<int> longestBarOnLeftside(height.size(), 0);

        findLongestBarOnRightside(height, longestBarOnRightside);
        findLongestBarOnLeftside(height, longestBarOnLeftside);

        for (int i = 0; i < height.size(); i++) {
            
            int waterAboveCurrentBar = 0;

            int smallerBar = min(longestBarOnRightside[i], longestBarOnLeftside[i]);

            if (smallerBar > height[i]) {
                waterAboveCurrentBar = smallerBar - height[i];
            }

            water += waterAboveCurrentBar;
        }

        return water;
    }
};
