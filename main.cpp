//THE 4
// Filiz İpek Oktay

#include <iostream>
#include <vector>
using namespace std;

void gettingChoice(int & choice) {

    cout << "Pick a choice from the list:" << endl;
    cout << "1- Addition Operation" << endl << "2- Multiplication Operation" << endl;
    cout << "3- Power Operation" << endl << "4- Transpose Operation" << endl;
    cout << "5- Exit" << endl << "Choice: ";

    cin >> choice;
    cout << endl;
}

void sumVector(vector<vector<int>> & mat1, vector<vector<int>> & mat2,int & dim11, int & dim12) {
    vector<vector<int>> res(dim11, vector<int> (dim12));
    for (int i = 0; i < dim11; i++) { //creating the vector
        for (int j = 0; j < dim12; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    cout << "Result of the Sum Operation: " << endl;
    for (int i = 0; i < dim11; i++) { //printing
        for (int j = 0; j < dim12; j++) {
            if (j != dim12 - 1)
                cout << res[i][j] << " ";
            else
                cout << res[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> mulVector(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int& dim11, int& dim12, int& dim22) {
    vector<vector<int>> res(dim11, vector<int>(dim22));
    for (int i = 0; i < dim11; i++) {
        for (int j = 0; j < dim22; j++) {
            for (int k = 0; k < dim12; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    cout << "Result of the Multiplication Operation: " << endl;
    for (int i = 0; i < dim11; i++) { //printing
        for (int j = 0; j < dim22; j++) {
            if (j != dim22 - 1)
                cout << res[i][j] << " ";
            else
                cout << res[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return res;
}

vector<vector<int>> powVector(vector<vector<int>>& mat, int& dim11, const int & n) {
    vector<vector<int>> res(dim11, vector<int>(dim11));
    if (n == 1){
        res = mat;
    } else {
        vector<vector<int>> temp(dim11, vector<int>(dim11));
        temp = mat;
        for(int m = 2; m <= n; m++) { // calculate power of matrix
            for (int i = 0; i < dim11; i++) {
                for (int j = 0; j < dim11; j++) {
                    res[i][j] = 0;
                    for (int k = 0; k < dim11; k++) {
                        res[i][j] += temp[i][k] * mat[k][j];
                    }
                }
            }
            temp = res;
        }
    }

    cout << "Result of the Power Operation: " << endl;
    for (int i = 0; i < dim11; i++) { //printing
        for (int j = 0; j < dim11; j++) {
            if (j != dim11 - 1)
                cout << res[i][j] << " ";
            else
                cout << res[i][j];
        }
        cout << endl;
    }
    cout << endl;

    return res;
}

vector<vector<int>> transVector(vector<vector<int>>& mat, int& dim11, int& dim12) {
    vector<vector<int>> res(dim12, vector<int>(dim11));
    for (int i = 0; i < dim12; i++) {
        for (int j = 0; j < dim11; j++) {
            res[i][j] = mat[j][i];
        }
    }
    cout << "Result of the Transpose Operation: " << endl;

    for (int i = 0; i < dim12; i++) { //printing
        for (int j = 0; j < dim11; j++) {
            if (j != dim11 - 1)
                cout << res[i][j] << " ";
            else
                cout << res[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return res;
}

int main() {

    int choice=0, dim11 = 0, dim12 = 0, dim21 = 0, dim22 = 0, num;
    int n;
    bool add_check = false;

    gettingChoice(choice);
    while(choice!= 5) {

        if (choice == 1 || choice == 2) {
            cout << "Please enter the dimensions of the first matrix: ";
            cin >> dim11 >> dim12;
            vector<vector<int>> mat1(dim11, vector<int> (dim12));
            cout <<  "Please enter the dimensions of the second matrix: ";
            cin >> dim21 >> dim22;
            vector<vector<int>> mat2(dim21, vector<int> (dim22));
            if (choice == 1 && (dim11 == dim21 && dim12 == dim22))  //ADDITION
                add_check = true;
            else if (choice == 2 && (dim12 == dim21)) // MULTIPLICATION
                add_check = true;

            if (add_check) {
                if (choice ==1){
                    cout << "The two matrices have the same dimensions. Addition can be performed." << endl << endl;
                } else if (choice ==2){
                    cout << "The number of columns in the first matrix is equal to the number of rows in the second matrix. Multiplication can be performed."<< endl;
                }
                cout << "Please enter the numbers for the first matrix." << endl;
                for (int i = 0; i < dim11; i++) { //creating the vector
                    cout << "Enter the numbers for row #" << i + 1 << ": ";
                    for (int j = 0; j < dim12; j++) {
                        cin >> num;
                        mat1[i][j] = num;
                    }
                }
                cout << "The first matrix is: " << endl;
                for (int i = 0; i < dim11; i++) { //printing
                    for (int j = 0; j < dim12; j++) {
                        if (j != dim12 - 1)
                            cout << mat1[i][j] << " ";
                        else
                            cout << mat1[i][j];
                    }
                    cout << endl;
                }
                cout << endl;

                cout << "Please enter the numbers for the second matrix." << endl;
                for (int i = 0; i < dim21; i++) { //creating the vector
                    cout << "Enter the numbers for row #" << i + 1 << ": ";
                    for (int j = 0; j < dim22; j++) {
                        cin >> num;
                        mat2[i][j] = num;
                    }
                }
                cout << "The second matrix is: " << endl;
                for (int i = 0; i < dim21; i++) { //printing
                    for (int j = 0; j < dim22; j++) {
                        if (j != dim22 - 1)
                            cout << mat2[i][j] << " ";
                        else
                            cout << mat2[i][j];
                    }
                    cout << endl;
                }
                cout << endl;

                if (choice == 1)
                    sumVector(mat1, mat2, dim11, dim12);
                if (choice == 2)
                    mulVector(mat1, mat2, dim11, dim12, dim22);

            } else {
                if (choice == 1)
                    cout << "The two matrices do not have the same dimensions. Addition cannot be performed." << endl;
                if (choice == 2){
                    cout << "The number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
                    cout << "Multiplication cannot be performed." << endl;
                }
            }

        } else if (choice == 3 ||choice == 4){
            cout << "Please enter the dimensions of the matrix: ";
            cin >> dim11 >> dim12;
            if (choice == 3) { //POWER
                if (dim11 == dim12) {
                    vector<vector<int>> mat(dim11, vector<int> (dim12));
                    cout << "The matrix has the same number of rows as columns. Power can be performed." << endl << endl;
                    cout << "Please enter the numbers for the matrix." << endl;

                    for (int i = 0; i < dim11; i++) { //creating the vector
                        cout << "Enter the numbers for row #" << i + 1 << ": ";
                        for (int j = 0; j < dim12; j++) {
                            cin >> num;
                            mat[i][j] = num;
                        }
                    }
                    cout << "The matrix is: " << endl;
                    for (int i = 0; i < dim11; i++) { //printing
                        for (int j = 0; j < dim11; j++) {
                            if (j != dim11 - 1)
                                cout << mat[i][j] << " ";
                            else
                                cout << mat[i][j];
                        }
                        cout << endl;
                    }
                    cout << endl;

                    cout << "Please enter the power: ";
                    cin >> n;
                    powVector(mat, dim11, n);

                } else
                    cout << "The matrix does not have the same number of rows as columns. Power cannot be performed." << endl << endl;

            } else if (choice == 4) { // TRANSPOSE
                vector<vector<int>> mat(dim11, vector<int> (dim12));
                cout << "Please enter the numbers for the matrix." << endl;
                for (int i = 0; i < dim11; i++) { //creating the vector
                    cout << "Enter the numbers for row #" << i + 1 << ": ";
                    for (int j = 0; j < dim12; j++) {
                        cin >> num;
                        mat[i][j] = num;
                    }
                }
                cout << "The matrix is: " << endl;
                for (int i = 0; i < dim11; i++) { //printing
                    for (int j = 0; j < dim12; j++) {
                        if (j != dim12 - 1)
                            cout << mat[i][j] << " ";
                        else
                            cout << mat[i][j];
                    }
                    cout << endl;
                }
                cout << endl;
                transVector(mat, dim11, dim12);
            }
        }
        gettingChoice(choice);
    }
    return 0;
}

