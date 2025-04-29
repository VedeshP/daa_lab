#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For memset
#include <limits.h> 

#include <stdbool.h>
#include <time.h>

#define inf INT_MAX
#define fr(i, a, b) for (int i = a; i < b; i++)

int min_bf(int a, int b);
int solve_tsp(int mask, int curr_city);
int tsp_dp(int **cost_matrix, int n);
int tsp_bruteforce(int **cost_matrix, int n);
void tsp_recursive(int **graph, int n, int curr_city, bool *visited, int cost_so_far, int cities_visited_count);

int main(void)
{
    int n = 5;
    int costs_data[5][5] = {
        {inf, 10, 8, 9, 7},
        {10, inf, 10, 5, 6},
        {8, 10, inf, 8, 9},
        {9, 5, 8, inf, 6},
        {7, 6, 9, 6, inf}
    };

    int **cost_matrix = (int **)malloc(n * sizeof(int *));
    if (!cost_matrix) return 1;
    for (int i = 0; i < n; ++i) {
        cost_matrix[i] = (int *)malloc(n * sizeof(int));
        if (!cost_matrix[i]) { 
            // Basic cleanup on failure
            while (--i >= 0) free(cost_matrix[i]);
            free(cost_matrix);
            return 1; 
        }
        for (int j = 0; j < n; ++j) {
            cost_matrix[i][j] = costs_data[i][j];
             // Handle 0 cost on diagonal if preferred
             if (i == j) cost_matrix[i][j] = inf; // Or 0 depending on problem def
        }
    }
    
    printf("Cost Matrix (%dx%d):\n", n, n);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(cost_matrix[i][j] == inf) printf(" INF ");
            else printf("%4d ", cost_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // --- Run DP version ---
    printf("Running TSP with Dynamic Programming (O(n^2 * 2^n))...\n");
    clock_t start_dp = clock();
    int result_dp = tsp_dp(cost_matrix, n);
    clock_t end_dp = clock();
    double time_dp = ((double)(end_dp - start_dp)) / CLOCKS_PER_SEC;

    if (result_dp != -1) {
        printf("Minimum Cost (DP): %d\n", result_dp);
    } else {
        printf("No feasible solution found (DP).\n");
    }
     printf("Time taken (DP): %f seconds\n", time_dp);
    printf("------------------------------------\n");

    // --- Run Brute-Force version ---
     // WARNING: Only run for small N (e.g., N < 12-13)
     if (n <= 12) {
         printf("Running TSP with Brute-Force Recursion (O(n!))...\n");
         clock_t start_bf = clock();
         int result_bf = tsp_bruteforce(cost_matrix, n);
         clock_t end_bf = clock();
         double time_bf = ((double)(end_bf - start_bf)) / CLOCKS_PER_SEC;


         if (result_bf != -1) {
             printf("Minimum Cost (Brute Force): %d\n", result_bf);
         } else {
             printf("No feasible solution found (Brute Force).\n");
         }
         printf("Time taken (Brute Force): %f seconds\n", time_bf);
         printf("------------------------------------\n");
     } else {
         printf("Skipping Brute-Force (O(n!)) for n=%d as it would be too slow.\n", n);
         printf("------------------------------------\n");
     }
}

int **dp;
// Cost matrix (adjacency matrix)
int **graph;
// Number of cities
int N;
// Mask representing all cities visited
int ALL_VISITED_MASK;


// Global variable to store the minimum TSP cost found
int min_tsp_cost_bruteforce;



// Recursive function with memoization
int solve_tsp(int mask, int curr_city) 
{
    // Base Case: All cities visited
    if (mask == ALL_VISITED_MASK) {
        // Return cost from current city back to the starting city (0)
        // Check if path exists
        return (graph[curr_city][0] != inf) ? graph[curr_city][0] : inf;
    }

    // Check if state is already computed
    if (dp[curr_city][mask] != -1) {
        return dp[curr_city][mask];
    }

    int min_cost = inf;

    // Try visiting every unvisited city 'next_city' from 'curr_city'
    for (int next_city = 0; next_city < N; ++next_city) {
        // Check if 'next_city' is not visited yet (i-th bit is 0 in mask)
        if (!(mask & (1 << next_city))) {
            // Check if there is an edge from curr_city to next_city
            if (graph[curr_city][next_city] != inf) {
                int cost_to_next = graph[curr_city][next_city];
                int remaining_cost = solve_tsp(mask | (1 << next_city), next_city);

                // Check for potential overflow if using INT_MAX
                if (remaining_cost != inf) {
                    min_cost = min_bf(min_cost, cost_to_next + remaining_cost);
                } else {
                     // If remaining_cost is inf, this path is not feasible yet
                     // but don't immediately make min_cost inf unless it's the only option
                }
            }
        }
    }

    // Store the result in the memoization table
    return dp[curr_city][mask] = min_cost;
}

// Wrapper function to initialize and call the solver
int tsp_dp(int **cost_matrix, int n) {
    if (n <= 0) return 0;
    if (n == 1) return 0; // Cost of TSP for 1 city is 0

    N = n;
    graph = cost_matrix;
    ALL_VISITED_MASK = (1 << N) - 1;

    // Allocate memory for the DP table
    // dp[N][1 << N] => N rows, 2^N columns
    int num_masks = (1 << N);
    dp = (int **)malloc(N * sizeof(int *));
    if (dp == NULL) {
        perror("Failed to allocate memory for dp rows");
        return -1; // Indicate error
    }
    for (int i = 0; i < N; ++i) {
        dp[i] = (int *)malloc(num_masks * sizeof(int));
        if (dp[i] == NULL) {
            perror("Failed to allocate memory for dp columns");
            // Clean up previously allocated memory
            for (int j = 0; j < i; ++j) free(dp[j]);
            free(dp);
            return -1; // Indicate error
        }
        // Initialize DP table with -1 (or another value indicating not computed)
        memset(dp[i], -1, num_masks * sizeof(int));
    }

    // Start the recursion from city 0, with only city 0 visited (mask = 1)
    int result = solve_tsp(1, 0); // Mask 1 means only city 0 is visited

    // Free the allocated memory for DP table
    for (int i = 0; i < N; ++i) {
        free(dp[i]);
    }
    free(dp);

    return (result == inf) ? -1 : result; // Return -1 if no solution found
}


// Recursive function to explore paths
void tsp_recursive(int **graph, int n, int curr_city, bool *visited, int cost_so_far, int cities_visited_count) {

    // Base Case: All cities have been visited
    if (cities_visited_count == n) {
        // Check if there's a path back to the starting city (0)
        if (graph[curr_city][0] != inf) {
            int total_cost = cost_so_far + graph[curr_city][0];
            min_tsp_cost_bruteforce = min_bf(min_tsp_cost_bruteforce, total_cost);
        }
        // Optimization: If cost so far already exceeds minimum, prune (optional but good)
        // else {
        //     // Cannot return to start, this path is invalid
        // }
        return;
    }

    // Optimization: Pruning - if current path cost exceeds best found, stop exploring
    if (cost_so_far >= min_tsp_cost_bruteforce) {
        return;
    }


    // Recursive Step: Try visiting every unvisited city 'next_city'
    for (int next_city = 0; next_city < n; ++next_city) {
        // If 'next_city' is not visited and there's a path
        if (!visited[next_city] && graph[curr_city][next_city] != inf) {

             // Check for potential overflow before adding
            if (cost_so_far > inf - graph[curr_city][next_city]) {
                continue; // Skip if adding cost causes overflow
            }

            int new_cost = cost_so_far + graph[curr_city][next_city];

            // Mark 'next_city' as visited
            visited[next_city] = true;

            // Recursively call for the next step
            tsp_recursive(graph, n, next_city, visited, new_cost, cities_visited_count + 1);

            // Backtrack: Unmark 'next_city' to explore other paths
            visited[next_city] = false;
        }
    }
}

// Wrapper function for the brute-force method
int tsp_bruteforce(int **cost_matrix, int n) {
    if (n <= 0) return 0;
    if (n == 1) return 0;

    // Allocate memory for the visited array
    bool *visited = (bool *)malloc(n * sizeof(bool));
    if (visited == NULL) {
        perror("Failed to allocate memory for visited array");
        return -1; // Indicate error
    }

    // Initialize visited array (all false initially)
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }

    // Initialize global minimum cost
    min_tsp_cost_bruteforce = inf;

    // Start the process from city 0
    visited[0] = true;
    tsp_recursive(cost_matrix, n, 0, visited, 0, 1); // Start at city 0, cost 0, 1 city visited

    // Free the visited array
    free(visited);

    return (min_tsp_cost_bruteforce == inf) ? -1 : min_tsp_cost_bruteforce; // Return -1 if no solution
}


int min_bf(int a, int b) 
{
    return (a < b) ? a : b;
}