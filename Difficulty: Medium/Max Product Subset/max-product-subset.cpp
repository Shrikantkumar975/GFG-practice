class Solution {
  public:
    long long findMaxProduct(vector<int>& arr) {

        const long long MOD = 1e9 + 7;

        int negCnt = 0;
        int zeroCnt = 0;
        int mxNeg = -11;

        for(int x : arr){
            if(x < 0){
                negCnt++;
                mxNeg = max(mxNeg, x);
            }
            if(x == 0) zeroCnt++;
        }

        if(arr.size() == 1)
            return arr[0];

        if(zeroCnt == arr.size())
            return 0;

        if(negCnt == 1 && negCnt + zeroCnt == arr.size())
            return 0;

        bool skipped = false;
        long long ans = 1;

        for(int x : arr){

            if(x == 0) continue;

            if(negCnt & 1){
                if(x == mxNeg && !skipped){
                    skipped = true;
                    continue;
                }
            }

            ans = (ans * ((x % MOD + MOD) % MOD)) % MOD;
        }

        return ans;
    }
};