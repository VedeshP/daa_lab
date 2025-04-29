#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <numeric>

#define fr(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int,int>

using namespace std;

#define inf INT_MAX

typedef struct Node {
    pii edge;
    int cost;
} Node;

int main(void)
{
    int graph2[4][4] = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 9, 0, 12},
        {8, 8, 9, 0}
    };
    int graph[5][5] = {
        {inf, 10, 8, 9, 7},
        {10, inf, 10, 5, 6},
        {8, 10, inf, 8, 9},
        {9, 5, 8, inf, 6},
        {7, 6, 9, 6, inf}
    };
    int n = sizeof(graph) / sizeof(graph[0]);
    int n2 = sizeof(graph2) / sizeof(graph2[0]);

    int most_min = 0;
    fr (i, 0, n)
    {
        int min = inf;
        fr (j, 0, n)
        {
            if (graph[i][j] < min)
            {
                min = graph[i][j];
            }
            most_min += min;
        }
    }

    int level = 0;
    int tour_size = 1;
    vector<vector<Node>> nodes;
    vector<Node> selected;
    fr(i, 0, n)
    {

    }
    return 0;
}

int calculat_node_cost();