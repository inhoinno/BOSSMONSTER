//정답?
public String[] solution(String[] movie) {

        new ArrayList<String>(Arrays.asList(movie)).stream().collect(Collectors.groupingBy(Function.identity(), Collectors.counting())).forEach((key, value) -> {  });
}