class Solution {
public:
    // This method returns the maximum value by swapping two digits of the given number
    int maximumSwap(int num) {
        // Convert the number to a string for easy digit manipulation
        string numStr = to_string(num);
        int n = numStr.size(); // Get the length of the string representation of num
        vector<int> maxIndex(n); // Initialize a vector to store the indices of maximum digits following current
      
        // Initialize maxIndex with the indices from the string's end to the beginning
        iota(maxIndex.begin(), maxIndex.end(), 0);
      
        // Populate the maxIndex vector with the index of the maximum digit from current to the end
        for (int i = n - 2; i >= 0; --i) {
            if (numStr[i] <= numStr[maxIndex[i + 1]]) {
                maxIndex[i] = maxIndex[i + 1];
            }
        }
      
        // Traverse the string and find the first instance where swapping can maximize the number
        for (int i = 0; i < n; ++i) {
            int j = maxIndex[i]; // Get the index of the maximum digit we're considering for swap
            if (numStr[i] < numStr[j]) {
                // If the current digit is less than the max digit found, then swap and break
                swap(numStr[i], numStr[j]);
                break;
            }
        }
      
        // Convert the modified string back to an integer and return it
        return stoi(numStr);
    }
};
