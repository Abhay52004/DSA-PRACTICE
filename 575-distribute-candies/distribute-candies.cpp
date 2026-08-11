class Solution {
public:
    int distributeCandies(vector<int>& c) {
        sort(c.begin(),c.end());
        int count = 1;
        for(int i = 1 ; i<c.size() ; i++){
            if(c[i] != c[i-1])
            count++;
        }
        if(count == c.size()/2)
        return c.size()/2;

       return min(count, (int)c.size() / 2);
    }
};