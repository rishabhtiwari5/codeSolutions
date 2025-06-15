#include <vector>
#include <algorithm> // For use of the max function

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunkCount = 0; // Variable to count chunks
        int maxElement = 0; // Variable to store the maximum element found so far

        // Iterate through the vector elements
        for (int index = 0; index < arr.size(); ++index) {
            maxElement = std::max(maxElement, arr[index]); // Update maxElement with the highest between maxElement and the current element

            // If the maximum element we've found so far is equal to the index,
            // it means all previous elements are ≤ index and can form a chunk
            if (index == maxElement) {
                ++chunkCount; // Increment the chunk count as we can make a new chunk
            }
        }

        return chunkCount; // Return the total number of chunks
    }
};
