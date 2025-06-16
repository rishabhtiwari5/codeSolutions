class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         int n = nums.size(); 
        vector<int> ans(n, -1);

        stack<int> s;

        for(int i = (2*n)-1; i >= 0; i--){
            int index = i % n;

            while(!s.empty() && s.top() <= nums[index]){
                s.pop();
            }

            if(!s.empty()) ans[index] = s.top();
            else ans[index] = -1;

            s.push(nums[index]);


        }

        return ans;
        
    }
};
