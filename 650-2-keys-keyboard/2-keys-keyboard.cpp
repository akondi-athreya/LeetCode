class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;

        if(n == 2)
            return 2;
        
        vector<int> vec(n+1, 0);
        
        vec[0] = 0; 
        vec[1] = 0;
        vec[2] = 2;
        
        for(int i = 3; i<=n; i++) {
            int f = i/2; 
            while(f >= 1) {
                if(i%f == 0) {
                    int step = vec[f];
                    int copy = 1;
                    int paste = (i/f) - 1;
                    
                    vec[i] = vec[f] + copy + paste;
                    break;
                }
                f--;
            }
        }
        
        return vec[n];
    }
};