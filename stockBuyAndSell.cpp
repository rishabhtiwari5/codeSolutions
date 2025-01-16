int bestTimeToBuyAndSellStock(vector<int> &prices) {
  
  int minPrice = prices[0];
  int maxProfit = 0;
  int profit = 0;

  for (int i = 0; i < prices.size(); i++) {

    minPrice = min(minPrice, prices[i]);

    profit = prices[i] - minPrice;

    maxProfit = max(maxProfit, profit);
  }

  return maxProfit;
}
