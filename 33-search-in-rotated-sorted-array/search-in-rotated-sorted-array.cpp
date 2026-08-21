class Solution {
public:

    /*
    BRUTE FORCE APPROACH: LINEAR SEARCH
    */

    /* 
    OPTIMAL APPROACH
    */
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = (low + high)/2;
            
            if(nums[mid] == target) return mid;
            //If left half is sorted:
            if(nums[low] <= nums[mid]) {
                if(target <= nums[mid] && target >= nums[low]) high = mid - 1;
                else low = mid + 1;
            }
            //If right half is sorted:
            else {
                if(target >= nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};