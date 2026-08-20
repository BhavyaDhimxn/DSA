class Solution {
public:
    int firstOccurance(vector<int>&nums, int target, int n) {

        int first = -1, low = 0, high = n - 1;

        while(low <= high) {

            int mid = (low + high)/2;

            if(nums[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target) {
                high = mid - 1;
            }
            else low = mid + 1;

        }

        return first;

    }

    int lastOccurance(vector<int>&nums, int target, int n) {

        int last = -1, low = 0, high = n - 1;

        while(low <= high) {

            int mid = (low + high)/2;

            if(nums[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target) {
                high = mid - 1;
            }
            else low = mid + 1;

        }

        return last;

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOccurance(nums, target, n);
        if(first == -1) return {-1, -1};
        return {first, lastOccurance(nums, target, n)};
    }
};