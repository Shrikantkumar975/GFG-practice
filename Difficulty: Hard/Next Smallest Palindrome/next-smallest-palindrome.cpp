class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();

        // Step 0: check all 9's
        bool all9 = true;
        for (int x : num) {
            if (x != 9) {
                all9 = false;
                break;
            }
        }

        if (all9) {
            vector<int> res(n + 1, 0);
            res[0] = res[n] = 1;
            return res;
        }

        // Step 1: create palindrome by mirroring
        vector<int> pal = num;
        for (int i = 0; i < n / 2; i++) {
            pal[n - 1 - i] = pal[i];
        }

        // Step 2: check if already greater
        if (pal > num) return pal;

        // Step 3: increment middle
        int carry = 1;
        int mid = n / 2;

        // odd length → start from middle
        if (n % 2 == 1) {
            pal[mid] += carry;
            carry = pal[mid] / 10;
            pal[mid] %= 10;
            mid--;
        } else {
            mid = n / 2 - 1;
        }

        // propagate carry to left side
        while (mid >= 0 && carry) {
            pal[mid] += carry;
            carry = pal[mid] / 10;
            pal[mid] %= 10;
            mid--;
        }

        // Step 4: mirror again
        for (int i = 0; i < n / 2; i++) {
            pal[n - 1 - i] = pal[i];
        }

        return pal;
    }
};