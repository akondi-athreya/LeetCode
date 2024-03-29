class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int max = 0;
        int[] dp = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > dp[max]) {
                max = i;
            }
        }
        List<Integer> res = new ArrayList<>();
        res.add(nums[max]);
        for (int i = max - 1; i >= 0; i--) {
            if (nums[max] % nums[i] == 0 && dp[max] == dp[i] + 1) {
                max = i;
                res.add(nums[max]);
            }
        }
        return res;
    }
}