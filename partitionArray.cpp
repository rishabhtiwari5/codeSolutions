#include <vector>
using namespace std;

class Solution {
public:
    // This function checks whether we can partition the array into three parts with equal sum
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum = 0;

        // Calculate the sum of all elements in the array
        for (int value : arr) {
            totalSum += value;
        }

        // If the total sum is not divisible by 3, we can't partition it into three parts with equal sum
        if (totalSum % 3 != 0) return false;

        // The target sum for each of the three parts
        int targetSum = totalSum / 3;
      
        // Indices to iterate over the array from start (i) and end (j)
        int i = 0, j = arr.size() - 1;
        int sumFromStart = 0, sumFromEnd = 0;

        // Find the partition from the start of the array
        while (i < arr.size()) {
            sumFromStart += arr[i];
            // If we've reached the target sum, stop the loop
            if (sumFromStart == targetSum) {
                break;
            }
            ++i;
        }

        // Find the partition from the end of the array
        while (j >= 0) {
            sumFromEnd += arr[j];
            // If we've reached the target sum, stop the loop
            if (sumFromEnd == targetSum) {
                break;
            }
            --j;
        }

        // After finding the two partitions, check if there is at least one element between them
        return i < j - 1;
    }
};

// Example usage:
// int main() {
//     Solution obj;
//     vector<int> arr = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
//     bool result = obj.canThreePartsEqualSum(arr);
//     // Expected output: true, because the array can be partitioned as [0, 2, 1], [-6, 6, -7, 9, 1], [2, 0, 1] with equal sum of 3.
// }
