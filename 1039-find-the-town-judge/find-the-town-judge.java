class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] people = new int[n+1];
        for(int i=0;i<trust.length;i++){
            people[trust[i][1]]++;
            people[trust[i][0]]--;
        }
        int l=-1,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(l==-1 && people[i]==n-1){
                l=i;
                cnt++;
            }
            if(cnt>1) return -1;
        }
        return l;
        
    }
}