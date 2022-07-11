#include <iostream>

using namespace std;

// declaring number of rows and columns
const int m = 5, n = 5;

// To find a group in the city at the given i,j location using dfs
void find_group(int *arr, bool *visited, int i, int j, int count, int *res, int *groups)
{
    visited[i * m + j] = true;

    if (i + 1 < m && !visited[(i + 1) * m + j] && arr[(i + 1) * m + j] != 0)
        find_group(arr, visited, i + 1, j, count, res, groups);
    if (i - 1 >= 0 && !visited[(i - 1) * m + j] && arr[(i - 1) * m + j] != 0)
        find_group(arr, visited, i - 1, j, count, res, groups);
    if (j + 1 < n && !visited[i * m + j + 1] && arr[i * m + j + 1] != 0)
        find_group(arr, visited, i, j + 1, count, res, groups);
    if (j - 1 >= 0 && !visited[i * m + j - 1] && arr[i * m + j - 1] != 0)
        find_group(arr, visited, i, j - 1, count, res, groups);

    res[count] += arr[i * m + j];
    groups[i * m + j] = count + 1;
}
// To find all groups in the city
void find_groups(int *arr, int *res, int &count, int *groups)
{
    
    // allocating memory for Is visited flag and initializing
    bool *visited = new bool[m * n]();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i * m + j] == false && arr[i * m + j] != 0)
            {
                find_group(arr, visited, i, j, count, res, groups);
                count += 1;
            }
        }
    }

    // deleting allocated memory
    delete[] visited;
}

void flood_fill(int *dist, int *groups, int m, int n, int i, int j, int distance)
{

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dist[i * m + j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    dist[i * m + j] = distance;
    if (i + 1 < m && (dist[i * m + j] + 1 < dist[(i + 1) * m + j]))
    {
        flood_fill(dist, groups, m, n, i + 1, j, dist[i * m + j] + 1);
    }
    if (i - 1 >= 0 && (dist[i * m + j] + 1 < dist[(i - 1) * m + j]))
    {
        flood_fill(dist, groups, m, n, i - 1, j, dist[i * m + j] + 1);
    }
    if (j + 1 < n && (dist[i * m + j] + 1 < dist[i * m + j + 1]))
    {
        flood_fill(dist, groups, m, n, i, j + 1, dist[i * m + j] + 1);
    }
    if (j - 1 >= 0 && (dist[i * m + j] + 1 < dist[i * m + j - 1]))
    {
        flood_fill(dist, groups, m, n, i, j - 1, dist[i * m + j] + 1);
    }
}

int main()
{

    int input[m][n] = {{0, 2, 0, 3, 1},
                       {4, 1, 2, 0, 0},
                       {2, 0, 0, 0, 0},
                       {0, 1, 0, 2, 3},
                       {0, 0, 1, 1, 0}};

    int *matrix = new int[m * n];

    // writing input data to matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(matrix + i * m + j) = input[i][j];
        }
    }

    // allocating memory and initializing the result array
    int *res = new int[m * n]();

    // allocating memory and initializing the groups array matrix which represents group of each houses in the city
        int *groups = new int[m * n]();

    // variable to count number of groups
    int count = 0;

    // To find groups in the city(matrix) and its strength
    find_groups(matrix, res, count, groups);

    // variable to represent leader group index
    int leaderGroupIndex = 0;

    // To print the groups, its strengths and the leader  
    cout << "The groups are ";
    for (int i = 0; i < count; i++)
    {
        leaderGroupIndex = res[i] > res[leaderGroupIndex] ? i : leaderGroupIndex;
        cout << res[i] << ", ";
    }
    cout << endl;
    cout << "The strength of leader group is " << res[leaderGroupIndex] << endl;

    // // To print groups(to which each house belongs) in the city
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << groups[i * m + j] << " ";
    //     }
    //     cout << endl;
    // }

    // allocating memory and initializing for distance matrix which tells distance of each house from leader group
    int *dist = new int[m * n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i * m + j] = (groups[i * m + j] == leaderGroupIndex + 1) ? 0 : INT32_MAX;
        }
    }

    // To flood fill the distance from the leader group
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (groups[i * m + j] == leaderGroupIndex + 1)
                flood_fill(dist, groups, m, n, i, j, 0);
        }
    }

    // To print flood filled distance matrix
    // for (int i = 0; i < m; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << dist[i * m + j] << " ";
    //     }
    //     cout << endl;
    // }

    // Allocating and Initializing array to store shortest distances for every group
    int *shortest_distances = new int[count];
    for (int i = 0; i < count; i++)
        shortest_distances[i] = INT32_MAX;

    // Determining shortest distances for each group using dist matrix array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i * m + j] < shortest_distances[groups[i * m + j] - 1])
                shortest_distances[groups[i * m + j] - 1] = dist[i * m + j];
        }
    }
    // printing shortest distance to each groups
    for (int i = 0; i < count; i++)
    {
        cout << "The shortest distance for group with strength " << res[i] << " is " << shortest_distances[i] << endl;
    }

    // deleting allocated memory
    delete[] matrix, res, groups, dist, shortest_distances;
}
