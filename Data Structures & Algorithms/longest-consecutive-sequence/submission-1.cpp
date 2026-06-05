unordered_map<int, int> m;
unordered_map<int, int> len;

int recurse(int N) {
    if (m.find(N) == m.end()) {
        return 0;
    }
    int ret = 1 + recurse(N + 1);
    len[N] = ret;
    return ret;
}

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        m.clear();
        len.clear();
        int a = 0, ret = 1;

        for (int i = 0; i < arr.size(); ++i) {
            m[arr[i]] = 1;            
        }
        
        for (int i = 0; i < arr.size(); ++i) {
            if (len.find(arr[i]) == len.end()) {
                recurse(arr[i]);
            }
            a = max(a, len[arr[i]]);
        }
        return a;
    }
};
