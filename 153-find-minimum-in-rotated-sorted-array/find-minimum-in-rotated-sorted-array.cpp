class Solution {
public:

    /*
    BRUTE FORCE APPROACH: LINEAR SEARCH
    */

    /*
    OPTIMAL APPROACH:
    */
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;

        while(low <= high) {
            int mid = (low + high)/2;
            //Optimisation of edge case -> nums[low] <= nums[high];
            if(nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }
            //Check for sorted half and its elimination:
            if(nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};