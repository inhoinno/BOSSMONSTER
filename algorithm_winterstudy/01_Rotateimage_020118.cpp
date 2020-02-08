/*
No 1 180105

2018년 1월 5일 수용일 작성자 : 송인호 & 이예슬
스터디 멤버 이예슬 송인호 박현주 허예지
스터디 장소 이지스터디룸 7시-9시

*/


class Solution {
public:
    
   
    void rotate(vector<vector<int>>& matrix) {
        //3x3
        int arr[3][3] = {1,2,3,4,5,6,7,8,9 };
        int rarr[3][3] = { };
        
        for(int i=0; i<3; i++){            
            for(int j =0; j<3; j++){
                rarr[i][j] = arr[2-j][i]; //n-1-j
            }
        }
    
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%d\t",rarr[i][j]);
            }
            printf("\n");
        } //3x3 출력 반복문
        
        //4x4
        int arr2[4][4] = {5,1,9,11,2,4,8,10,13,3,6,7,15,14,12,16 };
        int rarr2[4][4] = { };
        
        
        for(int i=0; i<4; i++){
            
            for(int j =0; j<4; j++){
                rarr2[i][j] = arr2[3-j][i];
            }
        }
        
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                printf("%d\t",rarr2[i][j]);
            }
            printf("\n");
        } //4x4 출력반복문
    }
};