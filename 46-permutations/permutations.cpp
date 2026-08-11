class Solution {
public:

    void solve(int index , vector<int>arr , vector<vector<int>> &ans){
        if(arr.size()==index){
            ans.push_back(arr);
        }
        int n = arr.size();
        for(int i = index ; i<n ;i++){
            swap(arr[index] , arr[i]);
            solve(index + 1 , arr,ans);
            swap(arr[index] , arr[i]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return  ans;
    }
};