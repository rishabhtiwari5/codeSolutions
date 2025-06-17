class Solution {
public:
    int digits[12];
    int memo[12][12];

    // This method calculates the number of digit '1's that appear when counting from 1 to the given number n.
    int countDigitOne(int n) {
        int length = 0; // Initialize the length to store the number of digits in n.
        // Store the digits of n in reverse order.
        while (n) {
            digits[++length] = n % 10; // Store the last digit of n.
            n /= 10; // Remove the last digit from n.
        }
        memset(memo, -1, sizeof memo); // Initialize the memoization array to -1.
        return dfs(length, 0, true); // Start the DFS from the most significant digit.
    }

    // This method uses depth-first search to count the number of occurrences of the digit '1'.
    int dfs(int pos, int count, bool limit) {
        if (pos <= 0) {
            return count; // Base case: If all positions are traversed, return the count of '1's.
        }
        if (!limit && memo[pos][count] != -1) {
            return memo[pos][count]; // If we are not at the limit and we have a memoized result, return it.
        }
        int ans = 0; // Initialize the answer for the current recursion level.
        int upperBound = limit ? digits[pos] : 9; // Determine the upper bound for the current digit.
        // Enumerate possibilities for the current digit.
        for (int i = 0; i <= upperBound; ++i) {
            // Calculate the count of '1's for the next position, updating count if the current digit is '1'.
            ans += dfs(pos - 1, count + (i == 1), limit && i == upperBound);
        }
        if (!limit) {
            memo[pos][count] = ans; // If not at the limit, memoize the result.
        }
        return ans; // Return the computed answer for the current digit position.
    }
};
