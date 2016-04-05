class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        vector<int> flag(n, 1);
        for(int i=2; i<n; ++i) {
            if(flag[i]) {
	        	ans+=flag[i];
        		if( i*i>n ) {
		        	continue;
		        }
                for(int j=i*2; j<n; j+=i) {
                    flag[j]=0;
                }
            }
        }
        return ans;
    }
};