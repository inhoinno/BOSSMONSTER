

//최대값 에서 내려가기!



class Solution {
public:
    int largestRectangleArea(int[] height) {
        int widt =0;
        int heit =0;
        int output =0;
        int leng = height.length;
        int height_max_index[height.length];
        int max = height[0];

        for(int i=0; i<height.length; i++){
            for(int j=0; j<height.length-1; j++){

                if(height[j] < height[j+1]){
                    height_max_index[]



                }   













                


            }
                if(height[i]< height[i+1]){



                    







                }

            }








        }


















        for(int i =0; i<leng; i++){
            int pivot = height[i];
            
            if(i!=0){
                
                for(j =0; height[i-j-1]>=value; j++, widt++){              
                }                      
                //가로재기 
                result = pivot * widt;
                
                
                
                
                
                if(output < ) output = ;
            }
            else{                
                output = pivot;
                continue;
            }   
            
        }
        
        
       return output;
        
    }


};