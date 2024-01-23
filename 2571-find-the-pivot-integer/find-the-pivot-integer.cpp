class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        if(n==0) return 0;
        vector<int> pre;
        vector<int> sum;
        int x=0;
        for(int i=1 ; i<=n ; i++){
            pre.emplace_back(i);
            x+=i;
            sum.emplace_back(x);
        }
        int i=0;
        int j=sum.size()-1;
        int k=i+1;
        while(true){
            if(sum[k-1]==sum[j]-sum[k]){
                return k+1;
            }
            if(k==j){
                break;
            }
            k+=1;
        }
        return -1;
    }
};