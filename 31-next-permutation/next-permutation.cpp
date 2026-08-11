class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breaki = -1;
        int n = nums.size();
        for(int i = n-1 ; i>0 ; i-- ){
            if(nums[i]>nums[i-1])
            {breaki = i-1;
            break;}
        }
        if(breaki == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }int j;
        for( j = n-1 ; j>breaki ; j--){
            if(nums[j] > nums[breaki]){
                break;
            }
            
           
          

        }
        swap(nums[breaki] , nums[j]);
         reverse(nums.begin() + breaki + 1 , nums.end());
          return; 
    }
};