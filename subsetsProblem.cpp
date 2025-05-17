class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        auto ret = vector<vector<int>>();
        auto tmp = vector<int>();
        backtrack(ret, tmp, nums, 0);
        return ret;
    }
    
    void backtrack(vector<vector<int>>& list, vector<int>& tempList, vector<int>& nums, int start) {
        list.push_back(tempList);
        for (auto i = start; i < nums.size(); ++i) {
            tempList.push_back(nums[i]);
            backtrack(list, tempList, nums, i + 1);
            tempList.pop_back();
        }
    }
};
