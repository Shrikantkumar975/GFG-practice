class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
    int n = arr.size();
    int need = (n + 1) / 2;
    int lucky = 0;

    // Min-heap for storing costs to make a troop lucky
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int num : arr) {
        if (num % k == 0) {
            ++lucky;
        } else {
            pq.push(k - (num % k));
        }
    }

    // If already enough lucky troops, cost is 0
    if (lucky >= need) return 0;

    int total = 0;
    int req = need - lucky;

    // Take smallest required costs from heap
    for (int i = 0; i < req && !pq.empty(); ++i) {
        total += pq.top();
        pq.pop();
    }

    return total;
}
};