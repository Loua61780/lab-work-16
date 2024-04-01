#include "libs/data_structures/matrix/matrix.h"
#include <minmax.h>
#include "libs/util/util.h"
#include <math.h>

void swapMaxElementRowAndMinElementRow(matrix matrix) {
    int min = INT_MAX, minRow = -1, max = 0, maxRow = -1;

    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            int value = matrix.cells[i][j];

            if (value < min) {
                min = value;
                minRow = i;
            } else if (value > max) {
                max = value;
                maxRow = i;
            }
        }
    }

    swapRows(matrix, minRow, maxRow);
}

void sortRowsByMinElement(matrix matrix) {
    sortRowsByCriteria(matrix, findMax);
}
