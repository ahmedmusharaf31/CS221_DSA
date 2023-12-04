#include <iostream>
#include <iomanip>

int main()
{
    const int numRows = 5;
    const int numCols = 4;

    int table[numRows][numCols] = {
        {1, 2168, 185, 785},
        {2, 1224, 175, 830},
        {3, 3457, 190, 920},
        {4, 1054, 195, 870},
        {5, 2978, 200, 770}};

    int column;
    std::cout << "Enter column number for sorting (1 for S.No, 2 for Reg No., 3 for Age, 4 for Marks): ";
    std::cin >> column;

    for (int i = 0; i < numRows - 1; ++i)
    {
        for (int j = i + 1; j < numRows; ++j)
        {
            if (column == 1 || column == 2)
            {
                if (table[j][column - 1] > table[i][column - 1])
                {
                    for (int k = 0; k < numCols; ++k)
                    {
                        std::swap(table[i][k], table[j][k]);
                    }
                }
            }
            else if (column == 3 || column == 4)
            {
                if (table[j][column - 1] < table[i][column - 1])
                {
                    for (int k = 0; k < numCols; ++k)
                    {
                        std::swap(table[i][k], table[j][k]);
                    }
                }
            }
            else
            {
                std::cout << "Invalid column number." << std::endl;
                return 1;
            }
        }
    }

    std::cout << std::setw(5) << "S.No" << std::setw(15) << "Reg No." << std::setw(10) << "Age" << std::setw(10) << "Marks" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            std::cout << std::setw(10) << table[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
