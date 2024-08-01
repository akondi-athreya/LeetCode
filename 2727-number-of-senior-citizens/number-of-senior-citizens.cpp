class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(int i=0 ; i<details.size() ; i++){
            int dig=0;
            string str ="";
            for(int j=11 ; j<=12 ; j++) str+=details[i][j];
            int age = stoi(str);
            if(age>60) cnt++;
        }
        return cnt;
    }
};