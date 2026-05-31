class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        vector<int> a;
        unordered_map<int, int> m;
        unordered_multimap<int, int> freq_to_num;

        for (int i = 0; i < arr.size(); ++i) {
            m[arr[i]]++;
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            freq_to_num.insert({it->second, it->first});
        }

        for (auto it = freq_to_num.begin(); it != freq_to_num.end(); ++it) {
            if (q.size() < k) {
                q.push({it->first, it->second});
            } else if (it->first >= q.top().first) {
                q.pop();
                q.push({it->first, it->second});
            }
        }
   
        while (!q.empty()) {
            a.push_back(q.top().second);
            q.pop();
        }
        return a;
    }
};
