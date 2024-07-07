#include <iostream>

#include "[h]Suduko.hpp"
#include "[h]func.hpp"

void Suduko::cout_board()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // cout vertical seperator every 3 digit
            std::cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0 && j != 9 - 1)
            {
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
        // cout horizontal seperator "---" 6 times every 3 row
        if ((i + 1) % 3 == 0 && i != 9 - 1)
        {
            for (int k = 0; k < 6; k++)
            {
                std::cout << "--- ";
            }
            std::cout << std::endl;
        }
    }
};

bool Suduko::validate_board()
{
    // check row
    for (int i = 0; i < 9; i++)
    {
        for (int j = 1; j <= 9; j++)
            if (ecount(board[i], j) >= 2)
            {
                return false;
            };
    };

    // check column
    for (int i = 0; i < 9; i++)
    {
        // tmp int[9]
        int _row[9];
        for (int j = 0; j < 9; j++)
        {
            _row[j] = board[j][i];
        };
        // check
        for (int j = 1; j <= 8; j++)
        {
            if (ecount(_row, j) >= 2)
            {
                return false;
            };
        };
    }

    // check 3x3 square
    for (int offset_i = 0; offset_i < 3; offset_i++)
    {
        for (int offset_j = 0; offset_j < 3; offset_j++)
        {
            int _square[9];
            int _sq_index = 0;
            for (int m = 3 * offset_i; m < 3 + 3 * offset_i; m++)
            {
                for (int n = 3 * offset_j; n < 3 + 3 * offset_j; n++)
                {
                    _square[_sq_index] = board[m][n];
                    _sq_index++;
                }
            }

            // check
            for (int jj = 1; jj <= 9; jj++)
            {
                if (ecount(_square, jj) >= 2)
                {
                    return false;
                }
            }
        }
    }

    // default
    return true;
};

void Suduko::ccout_board()
{
    system("cls");
    cout_board();
};

bool Suduko::solve_board()
{
    // loop through each coordinate
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                // loop through 1-9
                for (int x = 1; x <= 9; x++)
                {
                    // fill in a first possible number(from 1-9) to first empty cell
                    board[i][j] = x;
                    ccout_board(); // cls and cout board
                    if (!validate_board())
                    {
                        board[i][j] = 0;
                        ccout_board(); // cls and cout board
                        continue;
                    };

                    // recursive function
                    if (!solve_board())
                    {
                        board[i][j] = 0;
                        ccout_board(); // cls and cout board
                        continue;
                    }
                };
                // if cannot fill in 1-9 number in a cell
                return false;
            };
        };
    };
    return true;
};