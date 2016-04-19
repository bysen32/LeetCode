class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int head1=0, head2=0;
        vector<int> ret;
        while (true) {
            if ( head1<m && head2<n ) {
                if ( nums1[head1] < nums2[head2] ) {
                    ret.push_back(nums1[head1]);
                    head1+=1;
                }
                else {
                    ret.push_back(nums2[head2]);
                    head2+=1;
                }
            }
            else if ( head1 < m ) {
                ret.push_back(nums1[head1]);
                head1+=1;
            }
            else if ( head2 < n ) {
                ret.push_back(nums2[head2]);
                head2+=1;
            }
            else {
                break;
            }
        }
        nums1 = ret;
    }
};
/*
见到一个很酷的逆向思维算法，如下 
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int head1=m-1, head2=n-1, tail=m+n-1;
        while ( nums1.size()<m+n ) {
            nums1.push_back(0);
        }
        while (true) {
            if ( head1>=0 && head2>=0 ) {
                if ( nums1[head1]>nums2[head2] ) {
                    nums1[tail] = nums1[head1];
                    head1-=1;tail-=1;
                }
                else {
                    nums1[tail] = nums2[head2];
                    head2-=1;tail-=1;
                }
            }
            else {
                break;
            }
        }
        while ( head2>=0 ) {
            nums1[tail] = nums2[head2];
            head2-=1;tail-=1;
        }
    }
};
