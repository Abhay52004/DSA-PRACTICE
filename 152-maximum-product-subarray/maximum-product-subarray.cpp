class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mintillnow , maxtillnow , ans;
        ans = nums[0];
        mintillnow =maxtillnow = ans;

        for(int i = 1 ;i<n ; i++){
            if(nums[i]<0)
            swap(mintillnow , maxtillnow);
            maxtillnow = max(maxtillnow * nums[i] , nums[i]);
            mintillnow = min(mintillnow*nums[i] , nums[i]);
            ans = max(maxtillnow, ans);
        }
        return ans;
    }
};