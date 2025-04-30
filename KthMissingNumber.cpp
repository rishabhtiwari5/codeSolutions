class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        int ans = 0;
        // Binary search to find the greatest index where missing numbers < k
        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // After the loop, high is the largest index where missing < k
        return k + ans + 1;
    }
};
