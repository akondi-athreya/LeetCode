class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int cnt = 0;

        int n = words.size();
        for (int i = 0 ; i < n ; i++) {
            string curr = words[i];

            for (int j = i + 1 ; j < n ; j++) {
                string next = words[j];

                if(curr.size() != next.size()) continue;

                int k = next.size() - 1;
                bool flag = true;

                for(char ch : curr){
                    if(ch != next[k]){
                        flag = false;
                        break;
                    }
                    k--;
                }

                if(flag) cnt++;
            }
        }

        return cnt;
    }
};