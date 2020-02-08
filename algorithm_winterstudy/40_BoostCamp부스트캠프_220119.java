class BoostCamp{
    public List<String> solution (list<String> movie){
        List<String> result = new ArrayList<>();
        //먼저 사전순으로 정렬ㄹ하고  솔팅하면 도리듯
        //Collectios.sort(movie, new AscendingString());

        Map<String, Integer> map = new HashMap<String, Integer>();
        for(int i=0; i< movie.size(); i++){
            String title = new String(movie.get(i).toString());
            if(!map.containsKey(title){// 새친구
                map.put(title, 0);
            }
            else {//원래 잇는 친구
                int value = map.get(title)+1;
                map.remove(title);
                map.put(title , value);//?
            }
        }
        //1 밸류정렬ㄹ
        List<Entry<String,Integer>> list = new LinkedList<Entry<String, Integer>>(map.entrySet());
        Collection.sort(list, new Comparator<Entry<String, Integer>>()){
            @Override
            public int compare(Entry<String,Integer> o1, Entry<String, Integer> o2){
                return o1.getValue().compareTo(o2.getValue());
            }
        });
        Collections.reverse(list); //내림차순으로 밸류 정렬
        
        //2 i=j+1로 하는 부분정렬.
        //짜면 댐

        //1. 밸류로 내림차순 정렬 -> F4 E3 A3 D2 B1 C1
        //2. 같은것 이라면 오름차순(사전순)정렬 -> F4 A3 E3 D2 B1 C1
        /* b2g2h2 -> while([i]>=[j]){j++} -> for(int i = j ; *//

}