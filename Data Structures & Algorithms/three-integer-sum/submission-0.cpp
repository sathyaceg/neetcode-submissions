class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        
        set<vector<int>> s;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); ++i) {
            int j = i + 1, k = arr.size() - 1;
            while (j < k) {                
                if (arr[i] + arr[j] + arr[k] < 0) {
                    j++;
                } else if (arr[i] + arr[j] + arr[k] > 0) {
                    k--;
                } else {                    
                    vector<int> ret(3);
                    ret[0] = arr[i], ret[1] = arr[j], ret[2] = arr[k];
                    s.insert(ret);
                    j++;
                    k--;
                }                
            }            
        }
        vector<vector<int>> a(s.begin(), s.end());
        return a;
    }
};
