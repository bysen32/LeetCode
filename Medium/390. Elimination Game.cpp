class Solution {
	public:
	int lastReamining(int n) {
		return n == 1 ? 1 : 2 * (1 + n/2 - lastReamining(n/2);
	}
}
