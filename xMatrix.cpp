// Given a matrix of bits, print the size of the biggest X on the matrix

#include <iostream>

using namespace std;

void printMatrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void printMatrix(bool **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int min(int a, int b) {
    return (a<b) ? a : b;
}

// Matrix is m by n
// 0 0
// 0 0
// 0 1
// is m = 3
//    n = 2
int findGreatestX(bool **matrix, int m, int n) {
    int **topLeft = new int*[m];
    for (int i = 0; i < m; i++)
        topLeft[i] = new int[n];

    int **topRight = new int*[m];
    for (int i = 0; i < m; i++)
        topRight[i] = new int[n];

    int **botLeft = new int*[m];
    for (int i = 0; i < m; i++)
        botLeft[i] = new int[n];

    int **botRight = new int*[m];
    for (int i = 0; i < m; i++)
        botRight[i] = new int[n];

    // Calculating topLeft
    for (int i = 0; i < m; i++)
        topLeft[i][0] = matrix[i][0];

    for (int i = 0; i < n; i++)
        topLeft[0][i] = matrix[0][i];

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            topLeft[i][j] = (matrix[i][j]) ? topLeft[i-1][j-1] + 1 : 0;

    // Calculating topRight
    for (int i = 0; i < m; i++)
        topRight[i][n-1] = matrix[i][n-1];

    for (int i = 0; i < n; i++)
        topRight[0][i] = matrix[0][i];

    for (int i = 1; i < m; i++)
        for (int j = n-2; j >= 0; j--)
            topRight[i][j] = (matrix[i][j]) ? topRight[i-1][j+1] + 1 : 0;

    // Calculating botLeft
    for (int i = 0; i < m; i++)
        botLeft[i][0] = matrix[i][0];

    for (int i = 0; i < n; i++)
        botLeft[m-1][i] = matrix[m-1][i];

    for (int i = m-2; i >= 0; i--)
        for (int j = 1; j < n; j++)
            botLeft[i][j] = (matrix[i][j]) ? botLeft[i+1][j-1] + 1 : 0;


    // Calculating botRight
    for (int i = 0; i < m; i++)
        botRight[i][n-1] = matrix[i][n-1];

    for (int i = 0; i < n; i++)
        botRight[m-1][i] = matrix[m-1][i];

    for (int i = m-2; i >= 0; i--)
        for (int j = n-2; j >= 0; j--)
            botRight[i][j] = (matrix[i][j]) ? botRight[i+1][j+1] + 1 : 0;


    int maxMinVal = 0;
    int curMinVal;

    for (int i = 1; i < m-1; i++) {
        for (int j = 1; j < n-1; j++) {
            curMinVal = min(min(botRight[i+1][j+1],
                                botLeft[i+1][j-1]),
                            min(topRight[i-1][j+1],
                                topLeft[i-1][j-1]));
            if (curMinVal > maxMinVal)
                maxMinVal = curMinVal;
        }
    }
    
    return (2*maxMinVal) + 1;
}

int main() {
    int m = 6;
    int n = 7;
    bool **matrix = new bool*[m];

    for (int i = 0; i < m; i++)
        matrix[i] = new bool[n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = true;

    matrix[0][0] = false;
    matrix[1][0] = false;
    matrix[2][0] = false;
             
    matrix[3][1] = false;
    matrix[4][1] = false;
             
    matrix[1][2] = false;
    matrix[3][2] = false;
             
    matrix[1][3] = false;
    matrix[2][3] = false;
             
    matrix[0][4] = false;
    matrix[1][4] = false;
    matrix[4][4] = false;
             
    matrix[0][5] = false;
    matrix[1][5] = false;
    matrix[2][5] = false;
    matrix[5][5] = false;
             
    matrix[0][6] = false;
    matrix[1][6] = false;
    matrix[3][6] = false;
    matrix[4][6] = false;

    // printMatrix(matrix, m, n);
    cout << findGreatestX(matrix, m, n) << endl;

    bool **matr = new bool*[3];
    for (int i = 0; i < 3; i++)
        matr[i] = new bool[5];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            matr[i][j] = true;

    cout << findGreatestX(matr, 3, 5) << endl;

    return 0;
}

