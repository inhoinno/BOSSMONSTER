class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int D[1000000001]={0};  // 너무 많아서 안돼나바
        
        int cnt=0;
        for(int i=0; i<hand.size();i++){
            if(D[hand[i]] == 0){ //이미 나온값이 ex  D[3] =3 해놓고 hand에 또3 이 있을경우에 else로 보낼생각
                D[hand[i]] =1;
                    // 2-3 일때는 걸러야함
                if(hand[i] != 0 && D[hand[i] -1] != 0) { //해당거 전에게 잇다면
                   D[hand[i]] += D[hand[i]-1];
                }
                else continue;
                        
            }
            else continue;
        }
        int max = *max_element(hand.begin() , hand.end());
        for(int i=1; i<=max; i++){
            if(D[i] >= W) cnt++;
        }
        return cnt>=W ? true : false;

    }
    
};