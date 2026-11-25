class Solution {
  public:
    typedef long long ll;
    static const ll MOD = 1000000007LL;

    ll A, B, M;

    ll T(ll p) {
        if (p <= 0) return 0;
        ll x = max(0LL, p - A);
        ll k = (x + M - 1) / M;
        return p + 2 * B * k;
    }

    // sum_{x=1..X} ceil(x/M), exact (fits in long long)
    ll F(ll X) {
        if (X <= 0) return 0;
        ll q = X / M, rem = X % M;
        return M * (q * (q + 1) / 2) + rem * (q + 1);
    }

    // sum_{p=1..P} ceil(max(0,p-A)/M)
    ll G(ll P) {
        if (P <= 0) return 0;
        return F(max(0LL, P - A));
    }

    int minTime(int a, int b, int d, int l, int r) {
        A = a; B = b; M = a - b;
        ll lo = (ll)d - r, hi = (ll)d - l;
        ll Td = T(d);

        // largest p in [lo,hi] with T(p)+1 <= Td
        ll L = lo, R = hi, t = lo - 1;
        while (L <= R) {
            ll mid = (L + R) / 2;
            if (T(mid) + 1 <= Td) { t = mid; L = mid + 1; }
            else R = mid - 1;
        }

        ll ans = 0;
        if (t >= lo) {
            ll cnt = t - lo + 1;
            ll sumP = (lo + t) * cnt / 2;           // up to ~1e16, fine
            ll sumK = G(t) - G(lo - 1);              // sum of ceil terms
            ll total = sumP + cnt;                   // +1 per jump
            ans = (total % MOD + (2 * B % MOD) * (sumK % MOD)) % MOD;
        }
        ll rest = hi - max(t, lo - 1);
        ans = (ans + (rest % MOD) * (Td % MOD)) % MOD;
        return (int)ans;
    }
};