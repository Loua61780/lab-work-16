#include "libs/data_structures/matrix/matrix.h"
#include "lab16_solutions.h"
#include <stdio.h>

matrix createMatrixFromArray(const int *array, int rows, int columns) {
    matrix matrix = getMemMatrix(rows, columns);
    int arrayIndex = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix.cells[i][j] = array[arrayIndex++];
        }
    }

    return matrix;
}

matrix *createArrayOfMatrixFromArray(const int *array, int matrixAmount, int rows, int columns) {
    matrix *matrices = getMemArrayOfMatrices(matrixAmount, rows, columns);
    int arrayIndex = 0;

    for (size_t k = 0; k < matrixAmount; k++) {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < columns; j++) {
                matrices[k].cells[i][j] = array[arrayIndex++];
            }
        }
    }

    return matrices;
}

void test_ex1() {
    printf("test_ex1\n");
    matrix m = createMatrixFromArray((int[]) {
                                             1, 2, 3,
                                             4, 5, 6,
                                             7, 8, 9,
                                     }, 3, 3
    );

    printf("test matrix:\n");
    outputMatrix(m);

    swapMaxElementRowAndMinElementRow(m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex2() {
    printf("test_ex2\n");
    matrix m = createMatrixFromArray((int[]) {
                                             7, 1, 2,
                                             1, 8, 1,
                                             3, 2, 3,
                                     }, 3, 3
    );

    printf("test matrix:\n");
    outputMatrix(m);

    sortRowsByMaxElement(m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex3() {
    printf("test_ex3\n");
    matrix m = createMatrixFromArray((int[]) {
                                             3, 5, 2, 4, 3, 3,
                                             2, 5, 1, 8, 2, 7,
                                             6, 1, 4, 4, 8, 3,
                                     }, 3, 6
    );

    printf("test matrix:\n");
    outputMatrix(m);

    sortColsByMinElement(m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex4() {
    printf("test_ex4\n");
    matrix m = createMatrixFromArray((int[]) {
                                             2, 0, 0, 2,
                                             0, 2, 2, 0,
                                             0, 2, 2, 0,
                                             2, 0, 0, 2,
                                     }, 4, 4
    );

    printf("test matrix:\n");
    outputMatrix(m);

    getSquareOfMatrixIfSymmetric(&m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex5() {
    printf("test_ex5\n");
    matrix m = createMatrixFromArray((int[]) {
                                             1, 2, 3, 4,
                                             5, 6, 7, 8,
                                             9, 10, 11, 12,
                                             13, 14, 15, 16,
                                     }, 4, 4
    );

    printf("test matrix:\n");
    outputMatrix(m);

    transposeIfMatrixHasNotEqualSumOfRows(&m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}

void test_ex6() {
    printf("test_ex6\n");
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1,
                                      }, 3, 3
    );

    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1,
                                      }, 3, 3
    );

    printf("test matrix 1:\n");
    outputMatrix(m1);
    printf("test matrix 2:\n");
    outputMatrix(m2);

    printf("Answer: %d", isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);

    printf("\n\n");
}


void test_ex6_1() {
    printf("test_ex6_1\n");
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 8, 7,
                                              4, 2, 3,
                                              7, 6, 5,
                                      }, 3, 3
    );

    matrix m2 = createMatrixFromArray((int[]) {
                                              4, 2, 9,
                                              4, 4, 3,
                                              0, 8, 1,
                                      }, 3, 3
    );

    printf("test matrix 1:\n");
    outputMatrix(m1);
    printf("test matrix 2:\n");
    outputMatrix(m2);

    printf("Answer: %d", isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);

    printf("\n\n");
}


void test_ex7() {
    printf("test_ex7\n");
    matrix m = createMatrixFromArray((int[]) {
                                             3, 2, 5, 4,
                                             1, 3, 6, 3,
                                             3, 2, 1, 2,
                                     }, 3, 4
    );

    printf("test matrix:\n");
    outputMatrix(m);

    long long answer = findSumOfMaxesOfPseudoDiagonal(m);

    printf("Answer: %lld\n", answer);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex8() {
    printf("test_ex8\n");
    matrix m = createMatrixFromArray((int[]) {
                                             10, 7, 5, 6,
                                             3, 11, 8, 9,
                                             4, 1, 12, 2,
                                     }, 3, 4
    );

    printf("test matrix:\n");
    outputMatrix(m);

    int answer = getMinInArea(m);

    printf("Answer: %d\n", answer);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex9() {
    printf("test_ex9\n");
    matrix m = createMatrixFromArray((int[]) {
                                             3, 5, 2, 4,
                                             2, 5, 1, 8,
                                             6, 1, 4, 4,
                                     }, 3, 4
    );

    printf("test matrix:\n");
    outputMatrix(m);

    sortByDistances(m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex10() {
    printf("test_ex10\n");
    matrix m = createMatrixFromArray((int[]) {
                                             7, 1,
                                             2, 7,
                                             5, 4,
                                             4, 3,
                                             1, 6,
                                             8, 0,
                                     }, 6, 2
    );

    printf("test matrix:\n");
    outputMatrix(m);

    int answer = countEqClassesByRowsSum(m);

    printf("Answer: %d\n", answer);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex11() {
    printf("test_ex11\n");
    matrix m = createMatrixFromArray((int[]) {
                                             3, 5, 5, 4,
                                             2, 3, 6, 7,
                                             12, 2, 1, 2,
                                     }, 3, 4
    );

    printf("test matrix:\n");
    outputMatrix(m);

    int answer = countSpecialElements(m);

    printf("Answer: %d\n", answer);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex12() {
    printf("test_ex12\n");
    matrix m = createMatrixFromArray((int[]) {
                                             1, 2, 3,
                                             4, 5, 6,
                                             7, 8, 1,
                                     }, 3, 3
    );

    printf("test matrix:\n");
    outputMatrix(m);

    swapPenultimateRow(m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex13() {
    printf("test_ex13\n");
    matrix *ms = createArrayOfMatrixFromArray((int[]) {
                                                      7, 1, 1, 1,
                                                      1, 6, 2, 2,
                                                      5, 4, 2, 3,
                                                      1, 3, 7, 9
                                              }, 4, 2, 2
    );

    printf("test matrices:\n");
    outputMatrices(ms, 4);

    int answer = countNonDescendingRowsMatrices(ms, 4);
    printf("Answer: %d\n", answer);

    freeMemMatrices(ms, 4);
    printf("\n\n");
}


void test_ex14() {
    printf("test_ex14\n");
    matrix *ms = createArrayOfMatrixFromArray((int[]) {
                                                      0, 1, 1, 0, 0, 0,
                                                      1, 1, 2, 1, 1, 1,
                                                      0, 0, 0, 0, 4, 7,
                                                      0, 0, 0, 1, 0, 0,
                                                      0, 1, 0, 2, 0, 3,
                                              }, 5, 3, 2
    );

    printf("test matrices:\n");
    outputMatrices(ms, 5);

    printf("Answer: \n");
    printMatrixWithMaxZeroRows(ms, 5);

    freeMemMatrices(ms, 5);
    printf("\n\n");
}


void test_ex15() {
    printf("test_ex15\n");
    matrix *ms = createArrayOfMatrixFromArray((int[]) {
                                                      7, 1, 1, 1,
                                                      1, 6, 2, 2,
                                                      5, 4, 2, 3,
                                                      1, 3, 7, 9
                                              }, 4, 2, 2
    );

    printf("test matrices:\n");
    outputMatrices(ms, 4);

    printf("Answer: \n");
    printMatricesWithMinNorm(ms, 4);

    freeMemMatrices(ms, 4);
    printf("\n\n");
}


void test_ex16() {
    printf("test_ex16\n");
    matrix m = createMatrixFromArray((int[]) {
                                             2, 3, 5, 5, 4,
                                             6, 2, 3, 8, 12,
                                             12, 12, 2, 1, 2,
                                     }, 3, 5
    );

    printf("test matrix:\n");
    outputMatrix(m);

    long long answer = countSpecialElements2(m);

    printf("Answer:%lld \n", answer);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex17() {
    printf("test_ex17\n");
    matrix m = createMatrixFromArray((int[]) {
                                             2, 3, 5,
                                             5, 4, 6,
                                             2, 3, 8,
                                             12, 12, 12,
                                             2, 1, 2,
                                     }, 5, 3
    );

    const int vc[] = {4, 3, 2, 6, 5};

    printf("test matrix:\n");
    outputMatrix(m);

    int answer = getVectorIndexWithMaxAngle(m, vc);

    printf("Answer: %d \n", answer);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex18() {
    printf("test_ex18\n");
    matrix m = createMatrixFromArray((int[]) {
                                             3, 5, 12, 6,
                                             0, 8, 15, 11,
                                             1, 4, 7, 9,
                                             13, 2, 10, 14
                                     }, 4, 4
    );

    printf("test matrix:\n");
    outputMatrix(m);

    long long answer = getSpecialScalarProduct(m);

    printf("Answer: %lld \n", answer);

    freeMemMatrix(&m);
    printf("\n\n");
}

int main() {
    test_ex1();
    test_ex2();
    test_ex3();
    test_ex4();
    test_ex5();
    test_ex6();
    test_ex6_1();
    test_ex7();
    test_ex8();
    test_ex9();
    test_ex10();
    test_ex11();
    test_ex12();
    test_ex13();
    test_ex14();
    test_ex15();
    test_ex16();
    test_ex17();
    test_ex18();
}