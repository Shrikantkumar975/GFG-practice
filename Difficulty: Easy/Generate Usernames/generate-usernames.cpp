
class Solution {
public:
    vector<string> generateUsernames(vector<string> arr) {

        unordered_set<string> used;

        // Initially reserve all usernames
        for (auto &s : arr) {
            used.insert(s);
        }

        unordered_map<string, int> next;
        vector<string> ans;

        for (auto &s : arr) {

            // First occurrence: keep unchanged
            if (next[s] == 0) {
                ans.push_back(s);
                next[s] = 1;
            }
            else {
                int num = next[s];
                string temp = s + to_string(num);

                // Find smallest available suffix
                while (used.count(temp)) {
                    num++;
                    temp = s + to_string(num);
                }

                ans.push_back(temp);
                used.insert(temp);

                next[s] = num + 1;
            }
        }

        return ans;
    }
};
