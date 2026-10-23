class Solution {
    long long ans = 0;

    void dfs(Node* root, vector<int>& arr) {
        if (!root) return;

        dfs(root->left, arr);
        arr.push_back(root->data);
        dfs(root->right, arr);
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        vector<int> temp;
        int i = l, j = mid + 1;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                ans += mid - i + 1;
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);

        for (int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }
    }

public:
    int pairsViolatingBST(Node* root) {
        vector<int> arr;
        ans = 0;

        dfs(root, arr);
        mergeSort(arr, 0, (int)arr.size() - 1);

        return (int)ans;
    }
};