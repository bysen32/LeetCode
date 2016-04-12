class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	int n=nums.size();
        k=k%n;
        reverse(nums, 0, n-k);
        reverse(nums, n-k, n);
        reverse(nums, 0, n);
    }
    void reverse(vector<int>& nums, int s, int e) {
        if ( s<0 || s>=e ) {
            return;
        }
        for ( int i=s; i<(s+e)/2; i++ ) {
            swap(nums[i], nums[e+s-1-i]);
        }
    }
};
