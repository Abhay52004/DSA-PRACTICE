class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mintillnow = prices[0];
        int maxprofit = 0;
        int n = prices.size();
        int profit;
        for(int i = 0; i<n ; i++){
            mintillnow = min(mintillnow,prices[i]);
            profit = prices[i] - mintillnow;
            maxprofit = max(maxprofit,profit);
        }
        return maxprofit;
    }
};