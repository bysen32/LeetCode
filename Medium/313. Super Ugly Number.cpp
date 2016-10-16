class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ret;
        ret.push_back(1);
        vector<int> idx(primes.size(), 0);
        while (ret.size() < n) {
            int minNum = ret[idx[0]]*primes[0];
            for (int i=0; i<primes.size(); ++i) {
                minNum = min(minNum, ret[idx[i]]*primes[i]);
            }
            for (int i=0; i<primes.size();++i) {
                if (minNum == ret[idx[i]]*primes[i]) {
                    idx[i]+=1;
                }
            }
            ret.push_back(minNum);
        }
        return ret[n-1];
    }
};