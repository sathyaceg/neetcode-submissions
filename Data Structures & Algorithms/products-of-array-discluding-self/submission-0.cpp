class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> a(n), pre(n);

        int ret = arr[0];

        for (int i = 1 ; i < n; ++i) {            
            a[i] = ret;
            ret *= arr[i];
        }
        ret = arr[n - 1];
        for (int i = n - 2; i >= 1; --i) {
            a[i] *= ret;
            ret *= arr[i];
        }
        a[0] = ret;

        return a;
    }
};
