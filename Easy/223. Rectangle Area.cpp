class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int space = getCrossSpace(A, B, C, D, E, F, G, H);
        return (C-A)*(D-B)-space+(G-E)*(H-F);
    }
    int getCrossSpace(int A, int B, int C, int D, int E, int F, int G, int H) {
        if ( E>=C || G<=A || F>=D || H<=B ) {
            return 0;
        }
        int a = max(A, E);
        int b = max(B, F);
        int c = min(C, G);
        int d = min(D, H);
        return (c-a)*(d-b);
    }
};
/*
Better Solution!
*/
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int left = max(A,E), right = max(min(C,G), left);
    int bottom = max(B,F), top = max(min(D,H), bottom);
    return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
}
