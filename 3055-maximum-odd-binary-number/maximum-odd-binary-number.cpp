class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int x = count(s.begin(),s.end(),'1');
        int y = count(s.begin(),s.end(),'0');
        string str = "";
        for(int i=0 ; i<x-1 ; i++){
            str+='1';
        }
        for(int i=0 ; i<y ; i++){
            str+='0';
        }
        str += '1';
        return str;
    }
};