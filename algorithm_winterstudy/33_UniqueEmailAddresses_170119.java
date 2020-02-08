
class Solution {
    public int numUniqueEmails(String[] emails) {
        List<String> storage = new ArrayList<>();
        for(String e : emails){
            String estring = new String();
            int temp =0;
            int i=0;
            for(i=0; e.charAt(i)!= '@'; i++){
                if(e.charAt(i) != '.' && e.charAt(i) !='+') {
                    if(e.charAt(temp) == '.') temp =i; //점드를 지나서 점 아닌걸로 온겨
                    continue;
                }
                else if(e.charAt(i) =='+') {
                    estring += e.substring(temp, i-1);
                    while(e.charAt(i) !='@'){i++;} //i위치를 @에 있게 만들고
                    break; //반복문 탈출
                }
                else { //.일때
                    if(e.charAt(temp) == '.'){  //.이 2개 이상같은 경우일때는
                        temp++; continue;
                    }
                    estring += e.substring(temp, i-1);
                    if(temp == i-1) estring += e.charAt(temp);
                    temp =i+1;
                }

            } //for문이 끝나면 i는  @위치 에 있게됩니다.
            estring += e.substring(i, e.length() -1); //estring에 도메인 입력 완료.
            if (!storage.contains(estring)) storage.add(estring); //새로운건디?
            else continue; //같은거있다.
            
        }
        return storage.size();
        
    }
}