class Solution {
public:
    bool isPalindrome(string s) {
        bool a = true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);
            if (!isalpha(s[i]) && !isdigit(s[i])) {
                i++;
                continue;
            }
            if (!isalpha(s[j]) && !isdigit(s[j])) {
                j--;
                continue;
            }
            if (s[i] == s[j] && (isalpha(s[i]) || isdigit(s[i])) 
            && (isalpha(s[j]) || isdigit(s[j]))) {
                i++;
                j--;                
            } else if ((isalpha(s[i]) || isdigit(s[i])) 
            && (isalpha(s[j]) || isdigit(s[j]))) {
                a = false;
                break;
            }
        }
        return a;
    }
};
