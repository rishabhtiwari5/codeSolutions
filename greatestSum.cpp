class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int INF = 1 << 30;                             // Define a large number to represent infinity.
        vector<int> dp = {0, -INF, -INF};                    // Initialize dp array to store max sums for modulo 3 values (0, 1, 2).

        for (int x : nums) {                                 // Iterate through each number in nums.
            vector<int> new_dp = dp;                         // Make a copy of the current state of dp.
            for (int j = 0; j < 3; ++j) {
                // Calculate the index for the updated sum in the original dp array.
                int idx = (j - x % 3 + 3) % 3;
                // Choose the maximum between not taking the current number (f[j])
                // and taking the current number (f[idx] + x)
                new_dp[j] = max(dp[j], dp[idx] + x);
            }
            dp = move(new_dp);                               // Update the dp array with the new values.
        }
        return dp[0];                                        // Return the maximum sum that is divisible by 3.
    }
};
