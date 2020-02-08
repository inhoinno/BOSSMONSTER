class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        
        
        for(int i=0; i<A.length- 1; i++){
            for(int j=1 j<A.length-i-1 ; j++){

                //evennumber일때
                if(!(A[j] % 2))
                    continue;
                    
                else{
                    int temp = A[j];
                    A[j]= A[j+1];
                    A[j+1] =temp;
                }





                
            }






        }
        
    }
};