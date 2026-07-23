class Solution {
public:
    void solve(int open,int close,string curr, vector<string> & ans){
        if(open==0 && close==0){
            ans.push_back(curr);
            return;
        }
        if(open>0){
        
        solve(open -1 , close,curr+'(', ans);
        // curr = curr +'(';
        }
        if(close>0 && open<close){
           
            solve(open, close-1 , curr+')', ans);
        //  ;    curr = curr + ')'
        }
    
    }
    vector<string> generateParenthesis(int n) {
        int open;
        int close;
        open=n;
        close = n;
        vector<string> ans;
        string curr= "" ; 

        solve(open,close,curr,ans);
    return  ans;
    }
};