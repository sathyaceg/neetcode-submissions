class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int a = s.size() == 0 ? 0 : 1;
        int start = 0;
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); ++i) {
            m[s[i]]++;
            while (m[s[i]] > 1 && start < i) {
                a = max(a, i - start);
                m[s[start]]--;
                if (m[s[start]] == 0) {
                    m.erase(m[start]);
                }
                start++;
            }
        }
        a = max(a, (int) s.size() - start);
        return a;
    }
};
