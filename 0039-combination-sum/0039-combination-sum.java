import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public List<List<Integer>> combinationSum(int[] cand, int target) {
        List<List<Integer>> resultList = new ArrayList<>();
        Set<List<Integer>> resultSet = new HashSet<>();
        List<Integer> comb = new ArrayList<>();

        allComb(cand, target, comb, resultSet);
        System.out.println(resultSet);

        for (List<Integer> i : resultSet) {
            resultList.add(i);
        }
        
        return resultList;
    }

    public static void allComb(int[] cand, int target, List<Integer> comb, Set<List<Integer>> result) {
        if (target == 0) {
            result.add(comb);
        }

        if (target < 0)
            return;

        int len = cand.length;
        for (int i = 0; i < len; i++) {
            List<Integer> temp = new ArrayList<>(comb);
            insert(temp, cand[i]);
            allComb(cand, target - cand[i], temp, result);
        }
    }

    public static void insert(List<Integer> list, Integer num) {
        int len = list.size();
        for (int i = 0; i < len; i++) {
            if (num <= list.get(i)) {
                list.add(i, num);
                return;
            }
        }
        list.add(num);
    }
}
