#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int INF = 1e9; // Use uppercase for constant values
        int n = nums.size(); // Size of the input vector
        int left = -1, right = -1; // Initialize the left and right pointers of the subarray
        int minVal = INF, maxVal = -INF; // Initialize the minimum and maximum values seen so far
        for (int i = 0; i < n; ++i) {
            // Iterate forward through the vector to find the right boundary of the unsorted subarray
            if (maxVal > nums[i]) {
                right = i;
            } else {
                maxVal = nums[i];
            }
            // Iterate backward through the vector to find the left boundary of the unsorted subarray
            if (minVal < nums[n - i - 1]) {
                left = n - i - 1;
            } else {
                minVal = nums[n - i - 1];
            }
        }
        // If right is -1, the array is already sorted; otherwise, calculate the length of the unsorted subarray
        return right == -1 ? 0 : right - left + 1;
    }
};
