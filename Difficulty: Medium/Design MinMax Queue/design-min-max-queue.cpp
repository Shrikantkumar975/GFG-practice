class SpecialQueue {
    queue<int> q;         // normal queue
    deque<int> minDeque;  // increasing deque for min
    deque<int> maxDeque;  // decreasing deque for max

public:
    // Insert element into the queue
    void enqueue(int x) {
        q.push(x);

        // maintain minDeque (increasing order)
        while (!minDeque.empty() && minDeque.back() > x) {
            minDeque.pop_back();
        }
        minDeque.push_back(x);

        // maintain maxDeque (decreasing order)
        while (!maxDeque.empty() && maxDeque.back() < x) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(x);
    }

    // Remove element from the queue
    void dequeue() {
        if (q.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        int frontVal = q.front();

        if (frontVal == minDeque.front()) {
            minDeque.pop_front();
        }
        if (frontVal == maxDeque.front()) {
            maxDeque.pop_front();
        }

        q.pop();
    }

    // Get minimum element
    int getMin() const {
        if (q.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return minDeque.front();
    }

    // Get maximum element
    int getMax() const {
        if (q.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return maxDeque.front();
    }

    // Get front element
    int getFront() const {
        if (q.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return q.front();
    }

    // Check if empty
    bool isEmpty() const {
        return q.empty();
    }

    // Get size
    int size() const {
        return q.size();
    }
};
