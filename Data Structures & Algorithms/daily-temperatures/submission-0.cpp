class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        
        stack<int> s;
        vector<int> a((int) arr.size(), 0);

        for (int i = arr.size() - 1; i >= 0; --i) {
            while (!s.empty() && arr[i] >= arr[s.top()]) {                
                s.pop();
            }
            if (!s.empty() && arr[i] < arr[s.top()]) {
                a[i] = (s.top() - i); 
                s.push(i);               
            } else {
                a[i] = 0;
                s.push(i);
            }
            // s.push(i);
        }
        return a;
    }
};
