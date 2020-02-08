public class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> ends = new HashMap<Integer, Integer>();
        int maxend = 0;
        for (int i = 0; i < wall.size(); i++) {
            int sum = 0;
            for (int j = 0; j + 1 < wall.get(i).size(); j++) {
                sum += wall.get(i).get(j);
                ends.put(sum, ends.getOrDefault(sum, 0) + 1);
                maxend = Math.max(maxend, ends.get(sum));
            }
        }

        return wall.size() - maxend;
    }
}