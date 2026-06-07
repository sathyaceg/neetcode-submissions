class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int a = 1;
        unordered_map<char, int> m;
        int mx = 1;    
        
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            mx = max(mx, ++m[s[i]]);            
            while ((i - start + 1) > k + mx) {
                m[s[start]]--;
                start++;
            }
            a = max(a, i - start + 1);
        }
        return a;
    }    
};
