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

void sortColsByMinElement(matrix matrix) {
    sortColumnsByCriteria(matrix, findMin);
}

void getSquareOfMatrixIfSymmetric(matrix* matrix) {
    if (isSymmetricMatrix(matrix)) {
        *matrix = multiply(*matrix, *matrix);
    }
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix* matrix) {
    long long sums[matrix->rows];

    for (int i = 0; i < matrix->rows; ++i) {
        sums[i] = sum(matrix->cells[i], matrix->columns);
    }

    if (isSet(sums, matrix->rows)) {
        transposeMatrix(matrix);
    }
}

bool isMutuallyInverseMatrices(matrix left, matrix right) {
    matrix multiplication = multiply(left, right);

    return isEMatrix(&multiplication);
}

long long findSumOfMaxesOfPseudoDiagonal(matrix matrix) {
    int arraySize = matrix.rows + matrix.columns - 1;
    int maxes[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        maxes[i] = INT_MIN;
    }

    int increment = matrix.columns - 1;

    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            int index = i - j + increment;

            maxes[index] = max(maxes[index], matrix.cells[i][j]);
        }
    }

    long long sum = 0;

    for (int i = 0; i < arraySize; ++i) {
        if (i != increment) {
            sum += maxes[i];
        }
    }

    return sum;
}
