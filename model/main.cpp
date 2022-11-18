#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[10][10], visited[10], n, cost = 0;

// Function to find the path
int least(int c)
{
    int i, nc = 999;
    int min = 999, kmin;
    for (i = 0; i < n; i++)
    {
        // check if the city is visited or not
        if ((a[c][i] != 0) && (visited[i] == 0))

            // if not visited then check for minimum cost
            if (a[c][i] < min)
            {
                min = a[i][0] + a[c][i];
                kmin = a[c][i];
                nc = i;
            }
    }
// if minimum cost city is not same as current city
    if (min != 999)
        // add the cost of the city to the total cost
        cost += kmin;
    // return the city number
    return nc;
}

// function to find the minimum cost
void mincost(int city)
{
    int i, ncity;
    visited[city] = 1;
    cout << city + 1 << "--->";
    ncity = least(city);
    if (ncity == 999)
    {
        ncity = 0;
        cout << ncity + 1;
        cost += a[city][ncity];
        return;
    }
    mincost(ncity);
}

int main()
{

    int i, j;
    cout << "Enter the number of cities: ";
    cin >> n;
    cout << "Enter the cost matrix: ";
    for (i = 0; i < n; i++)
    {
        cout << "Enter the elements of row: " << i + 1 << endl;
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    // uncomment the following line to print the cost matrix if you want
    // cout << "The cost matrix is: " << endl;
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "Enter starting city: ";
    int start;
    cin >> start;

    cout << "The path is: " << endl;
    mincost(start - 1);
    cout << endl;
    cout << "Minimum cost is: " << cost;
    return 0;
}

// bellman ford algorithm
#include <iostream>
#define INF 99999
using namespace std;

// structure to represnt a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// function for bellman ford algorithm
void BellmanFord(Edge edges[], int V, int E, int src)
{
    // dist array to store shortest path
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    // relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // check for negative-weight cycles
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v])
            cout << "Graph contains negative weight cycle";
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

// main function
int main()
{

    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    struct Edge edges[e];
    for (int i = 0; i < e; i++)
    {
        cout << "Enter source, destination and weight of edge " << i + 1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    BellmanFord(edges, v, e, src);

    return 0;
}

/*
      you can try this sample input
      5
      8
      0 1 -1
      0 2 4
      1 2 3
      1 3 2
      1 4 2
      3 2 5
      3 1 1
      4 3 -3
      0
  */

// nqueen cpp

/*
    @author : suraj pisal
*/

#include <iostream>
#include <vector>
using namespace std;

// print all solutions of nqueen

// function to print the solution
void printSolution(vector<vector<int>> &board)
{
    // static int k = 1;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

// function to check if a queen can be placed on board[row][col]
// Note that this function is called when "col" queens are already placed in columns from 0 to col -1
// So we need to check only left side for attacking queens
bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int i, j;

    // check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // check lower diagonal on left side
    for (i = row, j = col; i < board.size() && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// function to solve N Queen problem
bool solveNQueen(vector<vector<int>> &board, int col)
{
    // if all queens are placed then return true
    if (col >= board.size())
        return true;

    // consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < board.size(); i++)
    {
        // check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col))
        {
            // place this queen in board[i][col]
            board[i][col] = 1;

            // recur to place rest of the queens
            if (solveNQueen(board, col + 1))
                return true;

            // if placing queen in board[i][col] doesn't lead to a solution then remove queen from board[i][col]
            board[i][col] = 0; // backtrack
        }
    }

    // if the queen can not be placed in any row in this column col then return false
    return false;
}

// driver program to test above function
int main()
{
    int n;
    cout << "Enter the size of board: ";
    n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solveNQueen(board, 0) == false)
    {
        cout << "Solution does not exist";
        return 0;
    }
    else
    {
        cout << "Solution for " << n << " X " << n << " chessboard is : \n";
        printSolution(board);
    }

    return 0;
}

// fractional knapsack cpp
/*
    @author : Suraj Pisal
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// fractional knapsack
struct Item
{
    int value, weight;
};

// Comparison function to sort Item according to val/weight ratio
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int n)
{

    // sorting Item on basis of ratio
    sort(arr, arr + n, cmp);

    // Uncomment to see new order of Items with their ratio
    /*
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].value << "  " << arr[i].weight << " : "
             << ((double)arr[i].value / arr[i].weight) << endl;
    }
    */

    int curWeight = 0;       // Current weight in knapsack
    double finalvalue = 0.0; // Result (value in Knapsack)

    // Looping through all Items
    for (int i = 0; i < n; i++)
    {
        // If adding Item won't overflow, add it completely
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }

        // If we can't add current Item, add fractional part of it
        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    // Returning final value
    return finalvalue;
}

// driver program to test above function
int main()
{
    int W;
    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item arr[n];
    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << " value and weight: ";
        cin >> arr[i].value >> arr[i].weight;
    }

    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n);

    return 0;
}

// knapsack 01
#include <bits/stdc++.h>
using namespace std;

// 0/1 knapsack problem using dynamic programming

struct item
{
    int weight;
    int value;
};

int knapsack(int W, item arr[], int n)
{
    // create a 2D array to store the results of subproblems
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (arr[i - 1].weight <= j)
            {
                /*if the weight of the item is less than or equal to the capacity of the knapsack then we have two options
                either we include the item or we don't include the item in the knapsack and we take the maximum of the two
                values */
                dp[i][j] = max(arr[i - 1].value + dp[i - 1][j - arr[i - 1].weight], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of knapsack: ";
    cin >> W;
    cout << "Enter the weight and value of each item: ";
    item arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].weight >> arr[i].value;
    }
    cout << "Maximum value that can be put in knapsack is: " << knapsack(W, arr, n);

    return 0;
}