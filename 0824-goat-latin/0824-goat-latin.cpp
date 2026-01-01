class Solution {
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        vector<string> v;
        string st;
        while (getline(ss, st, ' ')) {
            v.push_back(st);
        }

        int n = v.size();

        st = "a";

        for (int i = 0 ; i < n ; i++) {

            if (!(
                v[i][0] == 'a' || v[i][0] == 'A' ||
                v[i][0] == 'e' || v[i][0] == 'E' ||
                v[i][0] == 'i' || v[i][0] == 'I' ||
                v[i][0] == 'o' || v[i][0] == 'O' ||
                v[i][0] == 'u' || v[i][0] == 'U'
            )) {
                string temp;
                for (int j = 1 ; j < v[i].size() ; j++) temp += v[i][j];
                temp += v[i][0];
                v[i] = temp;
            }


            v[i] += "ma";

            v[i] += st;
            st += "a";
        }

        st = "";

        for (int i = 0 ; i < v.size() ; i++) {
            st += v[i];
            if (i != n-1) st += " ";
        }

        return st;
    }
};

// I speak Goat Latin

// cond 1 : if consonant

// peaks

// cond 2 : +"ma" to every word

// str = "a"
// cond 3 : adding str to every word
// str +="a"
