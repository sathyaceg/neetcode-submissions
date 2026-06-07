class Solution {
public:
    bool isValid(string arr) {
        stack<int> s;
        bool a = true;

        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{') {
                s.push(arr[i]);
            }           
            if (arr[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    a = false;
                }
            }
            if (arr[i] == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    a = false;
                }
            }
            if (arr[i] == '}') {
                if (!s.empty() && s.top() == '{') {
                    s.pop();
                } else {
                    a = false;
                }
            }
        }

        a &= (s.empty());

        return a;
    }
};
