#ifndef LAB16_SOLUTIONS_H
#define LAB16_SOLUTIONS_H

#include "libs/data_structures/matrix/matrix.h"

void swapMaxElementRowAndMinElementRow(matrix matrix);

void sortRowsByMaxElement(matrix matrix);

void sortColsByMinElement(matrix matrix);

void getSquareOfMatrixIfSymmetric(matrix* matrix);

void transposeIfMatrixHasNotEqualSumOfRows(matrix* matrix);

bool isMutuallyInverseMatrices(matrix left, matrix right);

long long findSumOfMaxesOfPseudoDiagonal(matrix matrix);

int getMinInArea(matrix matrix);

void sortByDistances(matrix matrix);

int countEqClassesByRowsSum(matrix matrix);

int countSpecialElements(matrix matrix);

void swapPenultimateRow(matrix matrix);

int countNonDescendingRowsMatrices(const matrix* matrices, int matrixAmount);

void printMatrixWithMaxZeroRows(const matrix* matrices, int matrixAmount);

void printMatricesWithMinNorm(matrix* matrices, int matrixAmount);

int countSpecialElements2(matrix matrix);

int getVectorIndexWithMaxAngle(matrix vectorsMatrix, const int* vector);

long long getSpecialScalarProduct(matrix matrix);

#endif //LAB16_SOLUTIONS_H