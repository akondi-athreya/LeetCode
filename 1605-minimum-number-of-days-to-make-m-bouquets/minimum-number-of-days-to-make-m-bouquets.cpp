class Solution {
public:
    bool fun(vector<int>& v, int day , int m, int k){
        int cnt=0;
        int noB=0;
        for(int i=0 ; i<v.size() ; i++){
            if(v[i] <= day) cnt++;
            else{
                noB+=(cnt/k);
                cnt=0;
            }
        }
        noB+=(cnt/k);
        return noB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m*1LL*k*1LL;
        if(val>bloomDay.size()) return -1;
        int mi=INT_MAX , mx = INT_MIN;
        for(int i=0 ; i<bloomDay.size() ; i++){
            mi = min(mi , bloomDay[i]);
            mx = max(mx , bloomDay[i]);
        }
        int l=mi , h=mx;
        while(l<=h){
            int mid = (l+h)/2;
            if(fun(bloomDay , mid , m , k)) h = mid-1;
            else l = mid+1;
        }
        return l;
    }
};