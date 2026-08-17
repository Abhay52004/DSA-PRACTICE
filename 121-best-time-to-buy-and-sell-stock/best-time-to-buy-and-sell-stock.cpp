class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int mintillnow = pr[0];
        int n = pr.size();
        int maxpro = 0;
        for(int i = 1; i< n ; i++){
            mintillnow = min(mintillnow,pr[i]);
            int profit = pr[i] - mintillnow;
            maxpro = max(maxpro,profit);
        }
        return maxpro;
        
    }
};