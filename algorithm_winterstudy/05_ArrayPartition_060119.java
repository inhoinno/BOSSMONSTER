class Solution {
    public int arrayPairSum(int[] nums) {
        int min=0;
        int result=0;

        for(int i=0; i< nums.length/2;i++){
            min=Math.min(nums[2n], nums[2n+1]);
            result+=min;
            
        }
        return result;
    }
}