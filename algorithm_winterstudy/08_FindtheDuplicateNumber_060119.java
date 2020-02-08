//https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
    public int findDuplicate(int[] nums) {
     //배열 길이-1까지의 자연수 5/ 1234 를 받고, 적어도 하나는 두번 들어간 숫 자가 있겄쥬? 그넘을 찾아라
     //배열을 수정하지말고, O(n^2)보다 작아야함
     //복제된놈은 2개, 3개가 있을수 있음
     
     for(int i=0; i<nums.length-1; i++){
         
         for(int j=i+1; j<nums.length; j++){
             if(nums[i] == nums[j])
             return nums[i]
         }


     }

    }
}