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
    return true;
};

void Suduko::ccout_board()
{
    system("cls");
    cout_board();
};