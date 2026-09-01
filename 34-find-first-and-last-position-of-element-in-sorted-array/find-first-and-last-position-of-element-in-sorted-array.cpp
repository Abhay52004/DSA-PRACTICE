class Solution {
public:

    int firstocc(vector<int> & arr , int tar,int n){
        int s   = 0 ;
        int e = n-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[mid] == tar){
                ans = mid;
                e = mid -1;
            }

            else if(arr[mid] < tar)
            s = mid +1;
            else
            e = mid -1;
            mid = s + (e-s)/2;
        }

        return ans;
    }
  int lastocc(vector<int> & arr , int tar,int n){
        int s   = 0 ;
        int e = n-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[mid] == tar){
                ans = mid;
                s = mid +1;
            }

              else if(arr[mid] < tar)
            s = mid +1;
            else
            e = mid -1;
            mid = s + (e-s)/2;
        }

        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int n  = nums.size();
        result.push_back(firstocc(nums,target,n));
        result.push_back(lastocc(nums,target,n));
        return result;
    }
};