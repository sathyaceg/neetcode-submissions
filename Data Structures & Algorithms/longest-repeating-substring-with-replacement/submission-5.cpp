class Solution {
public:
    int characterReplacement(string s, int k) {
        // Not optimal - see prev submission
        int a = 1;  
        
        int start = 0;
        for (int j = 0; j < 26; ++j) {
            char c = (j + 'A');
            start = 0;
            int count = 0;
            for (int i = 0; i < s.size(); ++i) {
                count = (count + (s[i] == c));
                while (((i - start + 1) - count) > k) {
                    if (s[start] == c) {
                        count--;
                    }
                    start++;
                }
                a = max(a, i - start + 1);
            }
        }
        return a;
    }    
};
