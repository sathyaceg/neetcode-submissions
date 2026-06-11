class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {

        multiset<int> s;
        vector<int> a;
        int start = 0;

        for (int i = 0; i < k; ++i) {
            s.insert(arr[i]);
        }
        auto it = s.end();
        --it;

        a.push_back(*it);
        s.erase(s.find(arr[start]));
        ++start;

        for (int i = k; i < arr.size(); ++i) {
            cout << "I: " << i << " AS: " << arr[start] << '\n';            
            s.insert(arr[i]);
            it = s.end();
            --it;
            a.push_back(*it);
            s.erase(s.find(arr[start]));
            start++;
        }
        return a;
        
    }
};
