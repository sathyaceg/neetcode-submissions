class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        int n = arr.size();        
        map<vector<int>, int> ans;
        vector<vector<string>> a;

        for (int i = 0; i < arr.size(); ++i) {
            vector<int> ret(26, 0);
            for (int j = 0; j < arr[i].size(); ++j) {
                ret[arr[i][j] - 'a']++;
            }
            if (ans.find(ret) != ans.end()) {
                int index = ans[ret];
                a[index].push_back(arr[i]);
            } else {
                vector<string> temp(1);
                temp[0] = arr[i];
                a.push_back(temp);
                ans[ret] = a.size() - 1;
            }
        }
        return a;
    }
};