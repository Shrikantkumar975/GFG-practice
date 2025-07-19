class Solution {
  public:
    int vowelCount(string& s) {
        unordered_map<char, int> freq;
        string vowels = "aeiou";

        // Count frequency of vowels in the string
        for (char ch : s) {
            if (vowels.find(ch) != string::npos) {
                freq[ch]++;
            }
        }

        int k = freq.size(); // number of unique vowels
        if (k == 0) return 0;

        int product = 1;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            product *= it->second;
        }

        // calculate factorial of k (permutations)
        int perm = 1;
        for (int i = 2; i <= k; i++) {
            perm *= i;
        }

        return product * perm;
    }
};
