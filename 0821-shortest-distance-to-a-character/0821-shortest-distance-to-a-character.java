class Solution {
    public int[] shortestToChar(String s, char c) {
        int n = s.length();
        int pre[] = new int[n];
        int suf[] = new int[n];
        int mx = n-1;
        boolean char_came = false;
        for (int i = 0 ; i < n ; i++) {
            if (s.charAt(i) == c) {
                mx=0;
                char_came = true;
            }
            pre[i] = mx;
            if (char_came) {
                mx++;
            }
            else {
                mx--;
            }
        }
        char_came = false;
        mx = n-1;
        for (int i = n-1 ; i >= 0 ; i--) {
            if (s.charAt(i) == c) {
                mx = 0;
                char_came = true;
            }
            suf[i] = mx;
            if (char_came) {
                mx++;
            }
            else {
                mx--;
            }
        }
        int ans[] = new int[n];
        for (int i = 0 ; i < n ; i++) {
            ans[i] = Math.min(pre[i], suf[i]);
        }
        return ans;
    }
}