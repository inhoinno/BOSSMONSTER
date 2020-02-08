//이진트리 배우러 후퇴했다고 한다.
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans(nums.size()-k+1);
        if(k%2 == 0){ //짝수 even number 다 더하고 나눈다
            vector<int> temp(k);
            for(int i=0; i<nums.size()-k+1; i++){
                copy(nums.begin()+i, nums.begin()+i+k, temp.begin());
                sort(temp.begin(), temp.end());
                ans[i] = (double)(temp[k/2] + temp[k/2 -1]) / 2;
            }
        }
        else if(k%2 == 1){ // odd num start 정렬한것의 중간값을 넣는다
            /*int i=0;*/
            vector<int> temp(k);
            for(int i=0; i<nums.size()-k+1; i++){
                copy(nums.begin()+i, nums.begin()+i+k, temp.begin());
                sort(temp.begin(), temp.end());
                ans[i]=(double)temp[k/2];
            }
            /*
            for_each(ans.begin(), ans.end(), [&](){   
                copy(nums[i], nums.at(i+k), temp.begin());
                i++;
                ans.push_back((double)temp[k/2]);
            });
            */
        } //odd num
    return ans;
    }
};