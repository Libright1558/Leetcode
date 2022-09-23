class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int result = 0;
        int right = nums.length - 1;
        int pivot = (left + right) / 2;
        
        while(left <= right) {
            if(nums[pivot] == target) {
                result = pivot;
                break;
            }
            else if(nums[pivot] > target) {
                right = pivot - 1;
                pivot = (left + right) / 2;
            }
            else if(nums[pivot] < target) {
                left = pivot + 1;
                pivot = (left + right) / 2;
            }
        }
        
        if(left > right) {
            result = -1;
        }
        
        return result;
    }
}
