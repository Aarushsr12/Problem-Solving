class Solution {
    public int maximumWealth(int[][] accounts) {
         int ans =  Integer.MIN_VALUE;
        for (int[] account : accounts) {
            int acsum = 0;
            for (int i : account) {
                acsum += i;
            }
            if (acsum > ans) {
                ans = acsum;
            }
        }
        return ans;
    }
}