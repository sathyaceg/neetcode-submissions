class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int mn = INT_MAX;
        int a = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] <= mn) {
                mn = arr[i];
            } else {
                a = max(a, arr[i] - mn);
            }
        }
        return a;
    }
};
