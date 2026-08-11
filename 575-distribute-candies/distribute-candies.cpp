class Solution {
public:
    int distributeCandies(vector<int>& c) {
        unordered_set<int> pq;
        for(int i : c){
            pq.insert(i);
        }
        return min(pq.size(),c.size()/2);
        
    }
};