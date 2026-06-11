class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {

        deque<int> q;
        vector<int> a;
        int start = 0;

        for (int i = 0; i < arr.size(); ++i) {
            while (!q.empty() && arr[i] > arr[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (!q.empty() && i - q.front() >= k) {
                q.pop_front();
            }
            if (i + 1 >= k) {
                a.push_back(arr[q.front()]);
            }
        }
        return a;
        
    }
};
