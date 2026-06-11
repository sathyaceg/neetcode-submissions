class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int a = INT_MIN, sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            a = max(a, sum);
            if (sum < 0) sum = 0;
        }
        return a;
    }
};
