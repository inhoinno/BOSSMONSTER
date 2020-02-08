class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i =0;
        int j=1;
        int k=2;
        for(i =0; i<nums.length()-2; i++){
             while(j<nums.length()-1){
                if( nums[i] + nums[j] + nums[k] == 0; ){
                push()
                   j++; k++;

                }
            }
        }
    }
};
// N^3
//2 정렬이 맞았대! 
// 정렬을 하는 것은 원하는 수를 빠르게 찾을수 있기 때문이다!
//정렬을 하자! 
//아쉽지만 느낌 살리기
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        //정렬 하고
        if(nums.size()<3)
            return result;
        for(int i = 0; i < nums.size(); ++i){
            /* code */
            if(i == 0 || nums[i]> nums[i-1]){
                int j= i+1;
                int k = nums.size()-1;

                while(j<k){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        result.push_back(temp);
                        //중복을 막아주는 부분이 되겠습니다. 이런 부분같은경우에는 돌려보면서 알아가야 할것 같네요
                        while(j<k && nums[j] == nums[j-1])
                            j++;
                        while(j<k && nums[k] == nums[k+1])
                            k--;                        
                    }
                    else if(nums[i]+ nums[j]+ nums[k] <0)
                        j++;
                    else             
                        k--;
                    
                }
            }
        }
        return result;
        
    }
};