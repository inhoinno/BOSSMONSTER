
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans =new int[2];
        for(int i = 0; i<nums.length(); i++){
            for(int j= nums.length()-1; j>i ; --j){
                if(nums[i] + nums[j] != target) continue;
                else { ans[0] =i ; ans[1] =j; return ans; }
            }
        }
        return NULL;
    }
}
int main(){

    return 0;
}