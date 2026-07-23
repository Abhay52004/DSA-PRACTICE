class Solution {
public:
    void solve(int s , int n , int k , vector<int> & curr, vector<vector<int>> &ans ){
        if(n == 0 && k==0)
        {
            ans.push_back(curr);
            return;
        }
        if(s>9 || n<0 || k<0)
        return;
        for(int i = s ; i<=9 ; i++){
            if(i>n)
            break;
            curr.push_back(i);
            solve(i+1,n-i,k-1,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;

        
        solve(1,n,k,curr,ans);
        return ans;
    }
};