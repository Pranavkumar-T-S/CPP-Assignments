#include<iostream>

using namespace std;

//declaring number of rows and columns
const int m=5,n=5;
 
// To find a group in the city at the given i,j location using dfs 
void find_group(int* arr, bool* visited, int i, int j, int count,int* res){

    visited[i*m+j] =true;

    if (i+1 < m && !visited[(i+1)*m+j] && arr[(i+1)*m+j] != 0)
        find_group(arr, visited, i+1, j, count, res);
    if (i-1 >= 0 && !visited[(i-1)*m+j]  && arr[(i-1)*m+j] != 0)
        find_group(arr, visited,i-1, j, count, res);
    if (j+1 < n && !visited[i*m+j+1] && arr[i*m+j+1] != 0)
        find_group(arr, visited, i, j+1, count, res);
    if (j-1 >= 0 && !visited[i*m+j-1] && arr[i*m+j-1] != 0)
        find_group(arr, visited,i, j-1, count, res);
    res[count] += arr[i*m+j];
}
// To find all groups in the city
void find_groups(int* arr, int* res, int &count){
    // bool** visited = new bool*[m];
    // for (int i = 0; i < m; ++i)
    //     visited[i] = new bool[n];

    // allocating memory for Is visited flag and initializing 
    bool* visited = new bool[m*n]();

    for(int i = 0; i< m ; i++){
        for(int j = 0 ; j<n; j++){
            if (visited[i*m+j] == false && arr[i*m+j] != 0){
                find_group(arr, visited, i,j, count, res);
                count +=1;
            }
        }
    }

    // deleting allocated memory
    delete[] visited;

}

int main(){
    int input[m][n] = {{0,2,0,3,1},
                       {4,1,2,0,0},
                       {2,0,0,0,0},
                       {0,1,0,2,3},
                       {0,0,1,1,0}};

    int* matrix =new int[m*n];

    for(int i=0; i<m;i++){
        for(int j =0; j<n; j++){
            *(matrix+i*m+j) = input[i][j];
        }
    }
    // allocating initializing memory for result array
    int* res = new int[m*n]();
    
    // variable to count number of groups
    int count = 0;

    find_groups(matrix, res, count);

    // variable to represent leader group index
    int leaderGroupIndex = 0;

    cout << "The groups are ";
    for(int i =0;i<count;i++) {
        leaderGroupIndex = res[i] >res[leaderGroupIndex]? i: leaderGroupIndex;
        cout << res[i] << ", ";
    }
    cout << endl;
    cout << "The strength of leader group is "<< res[leaderGroupIndex];

// deleting allocated memory
    delete[] matrix, res;

}
