bool comparator(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr;
        int n = position.size();
        stack<int> s;
        int a = 1;

        for (int i = 0; i < n; ++i) {
            arr.push_back({position[i], speed[i]});
        }

        sort(arr.rbegin(), arr.rend());

        double prev = (double) (target - arr[0].first) / arr[0].second;

        for (int i = 1; i < arr.size(); ++i) {
            double time = (double) (target - arr[i].first) / arr[i].second;
            if (time > prev) {
                a++;
                prev = time;
            }
        }
        return a;

    }
};
