#include <vector>
#include <algorithm>

class Solution {
public:
    // Function to calculate the minimum size of a set so that for every
    // interval in 'intervals' there are at least two distinct set elements which
    // are in the interval.
    int intersectionSizeTwo(std::vector<std::vector<int>>& intervals) {
        // Sort the intervals based on their end points. If end points are the same,
        // sort based on the start points in decreasing order. This way, we prefer
        // intervals with larger start points for same end points.
        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });

        int ans = 0; // Initialize the answer to 0.
        int smallest = -1, secondSmallest = -1; // Initialize the two smallest elements seen so far to -1.

        // Iterate through the sorted intervals
        for (const auto& interval : intervals) {
            int start = interval[0], end = interval[1];

            // If the current start is less than or equal to smallest, this interval is already covered
            // by the elements chosen so far.
            if (start <= smallest) continue;

            // If the current start is greater than secondSmallest, we need to add two more elements to the set.
            if (start > secondSmallest) {
                ans += 2;
                // The secondSmallest is now the end of the interval minus one, and the smallest
                // is the end of the interval.
                secondSmallest = end - 1;
                smallest = end;
            } else {
                // If start is between smallest and secondSmallest, we need to add one more element.
                ans += 1;
                // The new secondSmallest becomes the smallest we had, and the new smallest becomes the end of this interval.
                secondSmallest = smallest;
                smallest = end;
            }
        }
      
        // Return the total number of elements added to the set.
        return ans;
    }
};
