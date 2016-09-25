class Solution {
public:
    int findNthDigit(int n) {
        int cnt = 0;
        while(true) {
            cnt += 1;
            double digit = 9 * cnt * pow(10, cnt - 1);
            if (n <= digit) {
                break;
            }
            n -= digit;
        }
        int base = pow(10, cnt - 1);
        int num = base + (n - 1) / cnt;
        char str[32];
        sprintf(str, "%d", num);
        return str[(n - 1) % cnt] - '0';
    }
};
