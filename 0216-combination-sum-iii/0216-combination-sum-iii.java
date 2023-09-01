class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> comb = new ArrayList<>();
        allComb(result, comb, k, n, 1);
        return result;
    }

    public static void allComb(List<List<Integer>> result, List<Integer> comb, int k, int n, int i) {
        if (n == 0 && k == 0)
            result.add(comb);

        if (n < 0 || k == 0)
            return;

        for (; i <= 9; i++) {
            List<Integer> temp = new ArrayList<>(comb);
            temp.add(i);
            allComb(result, temp, k - 1, n - i, i + 1);
        }

    }
}