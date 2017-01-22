/* 题意:
 * 蠢题，占数用。
*/
public class Solution {
	char SHIP = 'X';
	char BLANK = '.';
	public int CountBattleships(char[,] board) {
		int ret = 0;
		for(int i = 0; i < board.GetLength(0); ++i)
			for(int j = 0; j < board.GetLength(1); ++j)
			{
			    if (board[i, j] == BLANK) continue;
			    if (i > 0 && board[i - 1,j ] == SHIP) continue;
			    if (j > 0 && board[i, j - 1] == SHIP) continue;
			    ret += 1;
			}
		return ret;
	}
}
