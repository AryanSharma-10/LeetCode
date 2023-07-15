class Solution {
public:
    vector<vector<string>> solutions;

vector<string> generateBoard(int n)
{
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        temp += ".";
    }

    return vector<string>(n, temp);
}

bool isSafe(vector<string> &board, int i, int j)
{
    int x = i;
    int y = j;

    // top
    while (i >= 0)
    {
        if (board[i--][j] == 'Q')
        {
            return false;
        }
    }
    i = x;

    // left top diagonal
    while (i >= 0 && j >= 0)
    {
        if (board[i--][j--] == 'Q')
        {
            return false;
        }
    }
    i = x;
    j = y;

    // right top diagonal
    while (i >= 0 && j < board[i].length())
    {
        if (board[i--][j++] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void nQueens(vector<string> &board, int i, int n)
{
    if (n == 0)
    {
        solutions.push_back(board);
        return;
    }

    for (int j = 0; j < board[0].length(); j++)
    {
        if (isSafe(board, i, j))
        {
            board[i][j] = 'Q';
            nQueens(board, i + 1, n - 1);
            board[i][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) 
{
    vector<string> board = generateBoard(n);

    nQueens(board, 0, n);

    return solutions;
}

};