//Matrix Operations(6):
//Operations-6 : Addition|Subtraction|Multiplication|Transpose|Determinent|Inverse|

#include<stdio.h>
#include<stdlib.h>
void print(int **a, int r, int c);
int** add(int** a, int** b, int r, int c);
int** sub(int** a, int** b, int r, int c);
int** prod(int** a, int** b, int r1, int r2);
int** transpose(int** a, int r, int c);
int det(int** a, int n); 
int** inverse(int** a, int n); //n is the length of row or col(both must be equal)

int main(){
    char* operation[] = {"Addition", "Subtraction", "Multiplication", "Transpose", "Determinent", "Inverse"};
    int index;

    //Printing all the matrix operatins, this program can handle
    printf("Matrix Operations :\n");
    for(int i = 0; i < 6; i++){
        printf("%-16s - %d\n", operation[i], i+1);
    }

    //Prompting the user to choose a matrix operation
    printf("Enter the index of an operation(1 to 6) : ");
    scanf("%d", &index);

    //Operations to be performed based on index value
    //Operations which include two matrices
    if(index >= 1 && index <= 3){
        int row1, col1, row2, col2;
        printf("\nEnter the number of rows for the first matrix : ");
        scanf("%d", &row1);
        printf("\nEnter the number of columns for the first matrix : ");
        scanf("%d", &col1);
        printf("\nEnter the number of rows for the second matrix : ");
        scanf("%d", &row2);
        printf("\nEnter the number of columns for the second matrix : ");
        scanf("%d", &col2);

        int** a; int** b;//a and b are two different matrices
        //Assigning the memory for a and b in the heap
        a = (int**)malloc(row1 * sizeof(int*));
        b = (int**)malloc(row2 * sizeof(int*));
        for(int i = 0; i < row1; i++){
            a[i] = (int*)malloc(col1 * sizeof(int));
        }
        for(int i = 0; i < row2; i++){
            b[i] = (int*)malloc(col2 * sizeof(int));
        }

        //Inputting the elements of first matrix
        printf("\nEnter first matrix elements :\n");
        for(size_t i = 0; i < row1; i++){
            for(size_t j = 0; j < col1; j++){
                printf("\nEnter the element a[%u][%u] = ", i, j);
                scanf("%d", &a[i][j]);
            }
        }
        //Inputting the elements of second matrix
        printf("\nEnter second matrix elements :\n");
        for(size_t i = 0; i < row2; i++){
            for(size_t j = 0; j < col2; j++){
                printf("\nEnter the element b[%u][%u] = ", i, j);
                scanf("%d", &b[i][j]);
            }
        }

        switch (index)
        {
        case 1 ://Addition
            if(row1 == row2 && col1 == col2){
                int** x = add(a, b, row1, col1);
                printf("\nAddition of a and b : \n");
                print(x, row1, col1);
            }
            else{
                printf("\nInvalid matrix size to add!\n");
            }
            break;

        case 2 ://Subtraction
            if(row1 == row2 && col1 == col2){
                int** x = sub(a, b, row1, col1);
                printf("\nSubtraction of a and b : \n");
                print(x, row1, col1);
            }
            else{
                printf("\nInvalid matrix size to subtract!\n");
            }
            break;
        
        default://Multiplication
            if(row1 == col2 && row2 == col1){
                int** x = prod(a, b, row1, row2);
                printf("\nMultiplication of a and b : \n");
                print(x, row1, col2); 
            }
            else{
                printf("Invalid matrix size to multiply!");
            }
            break;
        }
    }

    //Operations which includes only single matrix
    else if(index >= 4 && index <= 6){
        int row, col;
        printf("\nEnter the number of rows for matrix:");
        scanf("%d", &row);
        printf("\nEnter the number of columns for matrix :");
        scanf("%d", &col);
        int ** a = (int **)malloc(row * sizeof(int*));
        for(int i = 0; i < row; i++){
            a[i] = (int*)malloc(col * sizeof(int));
        }

        //Inputting the elements of matrix
        printf("\nEnter the elements of the matrix :\n");
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col;  j++){
                printf("\nEnter the element a[%d][%d] = ", i, j);
                scanf("%d", &a[i][j]);
            }
        }
            
        switch(index){

            case 4://Transpose
                if(row > 0 && col > 0){
                    int** x = transpose(a, row, col);
                    printf("\nTranspose of a :\n");
                    print(x, col, row);
                }
                else{
                    printf("Invalid matrix size!\n");
                }
                break;

            case 5://Determinent
                if(row == col){
                    printf("Determinent of a : %d\n", det(a, row));
                }
                else{
                    printf("Invalid matrix size to find the det!\n");
                }
                break;

            default://Inverse
                if(row == col){
                    if(det(a, row) != 0){
                        int ** x = inverse(a, row);
                        printf("\nInverse of a :\n");
                        print(x, row, row);
                    }
                    else{
                        printf("Inverse do not exist since determinent of given matrix is ZERO\n");
                    }
                }
                else{
                    printf("Invalid size to find inverse matrix!\n");
                }
                break;
        }
    }
    else
        printf("Invalid index!");
    return 0;
}

//Printing the matrix
void print(int **a, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

//Function which adds two matrices
int** add(int** a, int** b, int r, int c){
    int** p = (int**)malloc(r * sizeof(int*));
    for(int i = 0; i < r; i++){
        p[i] = (int *)malloc(c * sizeof(int));
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            p[i][j] = a[i][j] + b[i][j];
        }
    }
    return p;
}

//Function which subtracts two matrices
int** sub(int** a, int** b, int r, int c){
    int** p = (int**)malloc(r * sizeof(int*));
    for(int i = 0; i < r; i++){
        p[i] = (int *)malloc(c * sizeof(int));
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            p[i][j] = a[i][j] - b[i][j];
        }
    }
    return p;
}

//Function which multiplies two matrices
int** prod(int** a, int** b, int r1, int r2){
    int** p = (int**)malloc(r1 * sizeof(int*));
    for(int i = 0; i < r1; i++){
        p[i] = (int *)malloc(r1 * sizeof(int));
    }
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < r1; j++){
            p[i][j] = 0;
            for(int k = 0; k < r2; k++){
                p[i][j] += a[i][k] * b[k][i];
            }
        }
    }
    return p;
}

//Function which returns the tranpose of a matrix
int** transpose(int** a, int r, int c){
    int** p = (int**)malloc(c * sizeof(int*));
    for(int i = 0; i < c; i++){
        p[i] = (int*)malloc(r * sizeof(int));
    }
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            p[i][j] = a[j][i];
        }
    }
    return p;
}

//Function which calculates the det of a square matrix
int det(int** a, int n){
    if(n == 2){
        return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    }

    int d = 0;
    int** b = (int**)malloc((n-1) * sizeof(int*));
    for(int i = 0; i < n-1; i++){
        b[i] = (int*)malloc((n-1) * sizeof(int));
    }
    
    for(int j = 0; j < n; j++){
        int r = 0;
        for(int x = 1; x < n; x++){
            int c = 0;
            for(int y = 0; y < n; y++){
                if(y != j){
                    b[r][c] = a[x][y];
                    c++;
                }
            }
            r++;
        }
        if(j%2 == 0){
            d = d + (a[0][j] * det(b, n-1));
        }
        else{
            d = d - (a[0][j] * det(b, n-1));
        }
    }

    for(int i = 0; i < n-1; i++){
        free(b[i]);
    }
    free(b);
    return d;
}

//Function returns the inverse of a matrix
int** inverse(int** a, int n){
    int d = det(a, n);
    
    int** p = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        p[i] = (int*)malloc(n * sizeof(int));
    }

    if(n == 2){
        p[0][0] = a[1][1] / d;
        p[0][1] = (a[0][1] * (-1) ) / d;
        p[1][0] = (a[1][0] * (-1)) / d;
        p[1][1] = a[0][0] / d;
        return p;
    }

    int** b = (int**)malloc((n-1) * sizeof(int*));
    
    for(int i = 0; i < n-1; i++){
        b[i] = (int*)malloc((n-1) * sizeof(int));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int r = 0;
            for(int x = 0; x < n; x++){
                int c = 0;
                if(x == i){
                    continue;
                }
                for(int y = 0; y < n; y++){
                    if(y == j){
                        continue;
                    }
                    b[r][c] = a[x][y];
                    c++;
                }
                r++;
            }
            p[j][i] = ((i+j)%2 == 0 ? 1 : -1) * det(b, n-1) / d;
        }
    }
    return p;
}

