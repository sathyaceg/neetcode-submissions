class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        bool a = true;

        for (int i = 0; i < s.size(); ++i) {
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); ++i) {
            count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            a &= (count[i] == 0);
        }
        return a;
    }
};
