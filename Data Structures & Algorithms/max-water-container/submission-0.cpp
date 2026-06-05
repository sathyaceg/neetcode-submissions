class Solution {
public:
    int maxArea(vector<int>& arr) {
        
        int a = 0;

        int i = 0, j = arr.size() - 1;
        while (i < j) {
            a = max(a, (j - i) *  min(arr[i], arr[j]));
            if (arr[i] >= arr[j]) {
                j--;
            } else {
                i++;
            }
        }
        return a;
    }
};
