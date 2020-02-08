#include <iostream>
#include <cstdio>
#include <stack>

class Solution{
    private:
    int Vol;
    public:
    Solution(){};
    void rainVolume(int[] Input){
        int result=0;
        int len = input.length();
        stack <int> s;
        for( int i=len-1; i>=0; --i){ 
            //같거나 큰넘을 만나기 전까지는 물이 채워질수있음
            //작은 녀석들을 스택에 넣어주고 (j-i-1) * input[i or j둘중에 작은거] - stack에 있는 작은녀석들 계속 pop하면서 -
            for(int j=i; j>=0; --j ){
                if(j!=0){
                    if(Input[j] < Input[i]){ //j가물이들어갈 수 있는 위치라면
                        s.push(j); //j를 기억해줌
                        continue;
                    }
                    else { //벽이라는 뜻= 계산해야지?
                        int height = input[i] == input[j] ? input[j], input
                        result += 


                        i=j+1; break;
                    } 
                } // else 면 4같은 놈임지혼자 높은애
                else if(s.size() ==  i) break; //4같은 애
                

            } 



        }
        this->Vol = result;

    }
    void getVolume(){
        cout << Vol ;
    }
}