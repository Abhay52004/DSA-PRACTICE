class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> pq;
        int n = nums.size();
        vector<int> ans;
        for(int   i  = 0 ; i<n ; i++){
            int com = target - nums[i];
            if(pq.count(com)){
                ans.push_back(pq[com]);
                ans.push_back(i);
                return ans;
            }

            pq[nums[i]] = i;
            
        }
        return ans;
    }
};