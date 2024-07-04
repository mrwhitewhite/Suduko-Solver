class Suduko
{
private:
    int board[9][9] = {
        {6, 8, 0, 1, 0, 0, 0, 9, 0},
        {0, 3, 4, 5, 0, 8, 0, 2, 0},
        {2, 1, 0, 0, 6, 0, 3, 0, 0},
        {5, 0, 0, 4, 0, 7, 0, 0, 9},
        {3, 4, 2, 9, 0, 0, 0, 0, 6},
        {0, 0, 7, 0, 8, 0, 5, 0, 0},
        {9, 2, 0, 8, 0, 0, 0, 5, 3},
        {0, 0, 3, 2, 0, 0, 9, 1, 8},
        {0, 0, 0, 3, 0, 0, 0, 6, 7},
    };

public:
    void cout_board(); // cout board
    void ccout_board(); // clear terminal then cout board
    bool validate_board(); // validate board(check no repeated 1-9 for each column and row)
    bool solve_board(); // solve board
};