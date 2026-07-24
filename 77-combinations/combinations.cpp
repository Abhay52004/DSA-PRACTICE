class Solution {
public:

    void solve(int start , int n, int k , vector<int> &path, vector<vector<int>> &res){
        if(k  == path.size()){
            res.push_back(path);
            return;
        }
        int l = k - path.size();
        for(int i = start ; i<=n - l + 1 ; i++){
            path.push_back(i);
            solve(i+ 1 ,n , k, path , res);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> path;
        vector<vector<int>> res;
        solve(1,n , k , path ,res);
        return res;


    }
};