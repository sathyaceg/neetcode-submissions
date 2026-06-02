class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {

        int i = 0, j = arr.size() - 1;
        vector<int> a(2);

        while (i < j) {
            if (i == j) {
                break;
            }
            if (arr[i] + arr[j] == target) {
                a[0] = i + 1;
                a[1] = j + 1;
                break;
            } else if (arr[i] + arr[j] < target) {
                i++;                
            } else {
                j--;
            }
        }
        return a;
    }
};
