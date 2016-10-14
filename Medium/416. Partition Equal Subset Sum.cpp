class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<5001> bits(1);
        int sum = 0;
        for (n :nums) {
            sum += n;
            bits |= (bits<<n);
        }
        return !(sum&1) && bits[sum>>1];
    }
};