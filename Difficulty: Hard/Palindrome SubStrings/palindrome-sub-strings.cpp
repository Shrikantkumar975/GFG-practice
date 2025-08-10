class Solution {
  public:
    class manacher {
public:

    // stores radius of palindromes centered 
    // at each position in ms
    vector<int> p;

    // modified string with sentinels and separators
    string ms;

    // constructor: builds modified string and 
    // runs manacher algorithm
    manacher(string &s) {
        ms = "@";

        for (char c : s) {
            ms += "#";
            ms += c;
        }

        ms += "#$";
        runManacher();
    }

    // core manacher's algorithm to compute radius array
    void runManacher() {
        int n = ms.size();

        p.assign(n, 0);

        int l = 0;
        int r = 0;

        for (int i = 1; i < n - 1; ++i) {
            int mirror = r + l - i;

            // assign minimum radius based on the 
            // mirror if within boundary
            p[i] = max(0, min(r - i, p[mirror]));

            // expand palindrome centered at i as
            // far as possible
            while (ms[i + 1 + p[i]] == ms[i - 1 - p[i]]) {
                ++p[i];
            }

            // update the current rightmost boundary 
            // if expanded past it
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    // return the length of longest palindrome centered at
    // cen in original string
    int getLongest(int cen, int odd) {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }

    // check if substring s[l...r] is a palindrome 
    // using precomputed radius
    bool check(int l, int r) {
        int len = r - l + 1;
        int center = (r + l) / 2;
        int isOdd = len % 2;
        return len <= getLongest(center, isOdd);
    }
};

// function to count palindromic substrings of 
// length >= 2
int countPS(string& s) {
    manacher m(s);

    int total = 0;

    for (int i = 0; i < m.p.size(); ++i) {
        
        // add ceil of (radius + 1) / 2 to count
        // all palindromic substrings
        total += (m.p[i] + 1) / 2;
    }

    // subtract the single-letter palindromes 
    // which are counted in the above
    return total - s.length();
}
};