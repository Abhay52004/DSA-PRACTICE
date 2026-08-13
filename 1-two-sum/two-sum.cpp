class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> pq;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            int com = target - nums[i];
            if(pq.count(com))
            return {pq[com],i};
            pq[nums[i]] = i;
        }
        return {};

    }
};