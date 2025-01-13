long long maxSubarraySum(vector<int> arr, int n) {
    
  long long sum = 0;
  long long maxsum = 0;

  for (int i = 0; i < n; i++) {

    sum = sum + arr[i];

    maxsum = max(maxsum, sum);

    if (sum < 0) sum = 0;

  }

  return maxsum;
}
