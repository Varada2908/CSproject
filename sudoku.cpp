#include <iostream>
#include <vector>
using namespace std;


void printGrid(const vector<vector<int>>& grid){
//printing the solve puzzzle with outline and borders    
    for (int row = 0; row < 9; row++) {
        
                
        for (int col = 0; col < 9; col++) {
            if(col==0 ){
                if(row!=0){
                   cout<<"|"; 
                }
               
                if(row==0){
                    cout<<"----------------------";
                    cout<<endl;
                    cout<<"|";
                }
            }
            cout << grid[row][col] << " ";
            if(col==2 || col==5 || col==8){
                    cout<<"|";
            }
            if((row==2 || row==5 || row==8) && col==8){
                    cout<<endl;
                    cout<<"----------------------";
            }   
        }
        cout << endl;
    }
}

bool valid(const vector<vector<int>>& grid, int row, int col, int num) {
//checking if the entry is valid for that number and index in matrix and it follows all rules of sudoku
    //checking repetetion in row and column
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }
    //checking repetetion in the smaller grid of 3 X 3 grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}


bool solve(vector<vector<int>>& grid) {
    int row = -1, col = -1;
    bool isEmpty = false;
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) { 
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
            break;
    }

    if (!isEmpty)
        return true;

    for (int num = 1; num <= 9; num++) {
        if (valid(grid, row, col, num)) {
            grid[row][col] = num; 

            if (solve(grid))
                return true;

            grid[row][col] = 0; 
        }
    }

    return false; 
}

int main() {
    int n, m;  
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m));  

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    if (solve(matrix)){
        printGrid(matrix);
    }
    else{
        cout << "No solution exists" << endl;
    }
       
    return 0;
}

