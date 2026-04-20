class Solution {
public:

    int findPivot(vector<int> &nums,int n){
        int l = 0, r = n-1;
        while(l < r){
            int mid = l + (r - l) /2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return r;
    }

    int binarySearch(int l , int r, vector<int> &nums, int target){
        int idx = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                idx = mid;
                break;
            }else if(nums[mid] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
           
        }
        return idx;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();


        int pivotIdx = findPivot(nums,n);

        int idx = binarySearch(0, pivotIdx - 1, nums, target);

        if(idx != -1){
            return idx;
        }

        idx = binarySearch(pivotIdx, n-1, nums, target);
        return idx;
    }
};
