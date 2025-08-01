class Solution {
  public:
    bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

// Function to count the number of balanced subarrays
int countBalanced(vector<string>& arr) {
    int n = arr.size();
    int res = 0;
    int prefix = 0;

    // Map to store frequency of prefix sums
    unordered_map<int, int> freq;

    // Initial prefix sum is 0 
    //(empty prefix is considered balanced)
    freq[0] = 1;

    // Traverse the array of strings
    for (int i = 0; i < n; i++) {
        int score = 0;

        // Calculate net score of current 
        // string: +1 for vowel, -1 for consonant
        for (char ch : arr[i]) {
            if (isVowel(ch)) score++;
            else score--;
        }

        // Update the running prefix sum
        prefix += score;

        // If this prefix sum has been seen before, 
        // then the subarray between previous and 
        // current prefix is balanced
        res += freq[prefix];

        // Increment the frequency of this prefix sum
        freq[prefix]++;
    }

    return res;
}
};