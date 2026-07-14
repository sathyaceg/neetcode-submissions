vector<int> arr;
vector<vector<int>> a;

void recurse(int index, vector<int> ret) {
    if (index >= arr.size()) {
        return;
    }
    ret.push_back(arr[index]);
    a.push_back(ret);
    recurse(index + 1, ret);
    ret.pop_back();
    recurse(index + 1, ret);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        arr = nums;
        a.clear();

        vector<int> ret;
        a.push_back(ret);
        recurse(0, ret);
        return a;
    }
};
