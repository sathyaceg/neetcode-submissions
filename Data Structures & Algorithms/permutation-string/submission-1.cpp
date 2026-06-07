class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        char m[26] = {0};
        char m2[26] = {0};
        bool a = false;
        int start = 0;

        for (int i = 0; i < s1.size(); ++i) {
            m[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.size(); ++i) {
            if (m[s2[i] - 'a'] == 0) {
                for (int j = 0; j < 26; ++j) {
                    m2[j] = 0;
                }
                start = i + 1;
                continue;
            }
            m2[s2[i] - 'a']++;            
            bool ret = true;
            for (int j = 0; j < 26; ++j) {
                ret &= (m2[j] == m[j]);
            }
            if (ret == true) {
                cout << "I: " << i << '\n';
                a = true;
                return a;
            }
            if (start <= i && m2[s2[i] - 'a'] > m[s2[i] - 'a']) {
                cout << "PRESTART: " << start << " PREI: " << i << '\n';
                while (start < i && m2[s2[i] - 'a'] > m[s2[i] - 'a']) {                    
                    m2[s2[start] - 'a']--;
                    // cout << "m2s: " << m2[s2[start]] << " m2i: " << 
                    ++start;
                }
                cout << "START: " << start << " I: " << i << '\n';
            }
        }
        return a;
    }
};
