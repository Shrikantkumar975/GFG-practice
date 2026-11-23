
class Solution {
  public:
    char posInfinite(string &s, int pos) {
        long long len = s.size();
        long long step = 1;

        // Find the step in which pos exists
        while (len < pos) {
            len = 2 * len + step;
            step++;
        }

        // Work backwards
        while (pos > s.size()) {
            step--;

            long long oldLen = (len - step) / 2;

            if (pos > oldLen && pos <= oldLen + step) {
                return '$';
            }

            if (pos > oldLen + step) {
                pos = 2 * oldLen + step - pos + 1;
            }

            len = oldLen;
        }

        return s[pos - 1];
    }
};
