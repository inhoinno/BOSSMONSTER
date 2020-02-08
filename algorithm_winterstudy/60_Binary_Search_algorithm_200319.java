public static int binarySearch(String[] items, String target, int begin, int end){
    if(begin > end) // 못찾은거임
        return -1;
    else{
        int middle = (begin + end)/2;
        int compResult =target.compareTo(items[middle]);
        if(compResult == 0)
            return middle; //미들이 타겟인경우
        if(compResult<0)
            return binarySearch(items, target, begin, middle-1);
        else 
            return binarySearch(items, target, middle+1, end);
             
    }
}