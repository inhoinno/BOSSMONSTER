class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int len=0;
        for(int i=0; i<wall.front().size(); i++)
            len += wall[0][i];
        vector<int> LaserIndex(len, 0);

        for(vector<int> K : wall){ //K 에 1 2 2 1 받아줌
            int laser_pivot=0;  //여기다 1, 1+2, 1+2+2, 1+2+2+1 을 받아줄거고 
            for(int i=0; i<K.size(); i++){
                laser_pivot += K[i];
                LaserIndex[laser_pivot]++;  //받아준 곳이 레이저가 벽돌을 자르지 않으면서 가는 곳
            }
        }// LaserIndex에는 각 요소당 레이저가 지나갈수 있는 갯수가 적힌다. 
        //(= 이걸 사이즈 - 최대값하면 레이저에 걸리는 벽돌의 최소갯수가 나온다)
        int ans = LaserIndex.front(); // 배열의 최댓값 받아준다
        for(int i=1; i< LaserIndex.size()-2; i++){ //6에는 당연히 최대니까 -2 
            if(LaserIndex[i] > ans)
                ans = LaserIndex[i];
        } //ans는 example 에 경우 4가 담기게 된다.
        return len - ans;   // 6-4 =2
    }
};
