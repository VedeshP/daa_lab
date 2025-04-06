#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define fr(i, a, b) for (int i = a; i < b; i++)

#define inf INT_MAX

// note that floyd warhsall does not work for negative cycles

int **create_mat(int n);
void print_mat(int **mat, int n);
int **init_matr();
void copy_matrix(int **src, int **dest, int n);
int ***floydwar_with_hist(int **graph, int vertex);
void show_hist(int ***hist, int vertex);

int main(void)
{
    int **matr = init_matr();
    int vertex = 4;
    // int vertex = 9;
    // int vertex = sizeof(matr);
    // the above will always return 4, as it is the size of the pointer 
    // int vertex = sizeof(matr) / sizeof(matr[0]);
    // int x = sizeof(matr); printf("x===> %d\n", x);
    // int y = sizeof(matr[0]); printf("y===> %d\n", x);
    // printf("vertex ===> %d \n", vertex);

    // int **new_mat = create_mat(vertex);
    // print_mat(new_mat, vertex);

    printf("The Graph: \n");
    print_mat(matr, vertex);

    int ***hist = floydwar_with_hist(matr, vertex);
    printf("All the matrices (history using floyd warshall algo): \n");
    show_hist(hist, vertex);
    
    return 0;
}

int **create_mat(int n)
{
    int **mat = (int **)calloc(n, sizeof(int*));
    if (mat == NULL)
    {
        printf("Memory Alloc failed!\n");
        return NULL;
    }
    fr(i, 0, n)
    {
        mat[i] = (int*)calloc(n, sizeof(int));
        if (mat[i] == NULL)
        {
            printf("Memory Alloc failed!\n");
            return NULL;
        }
    }

    return mat;
}

void print_mat(int **mat, int n)
{
    fr(i, 0, n)     
    {
        fr(j, 0, n)
        {
            if (mat[i][j] == inf)
            {
                printf("inf ");
            }
            else 
                printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int **init_matr()
{
    // int matr[9][9] = {
    //     {0,1,1,1,0,0,0,0,0},
    //     {1,0,1,0,1,0,0,0,0},
    //     {1,1,0,1,1,1,1,0,0},
    //     {1,0,1,0,0,0,1,0,0},
    //     {0,1,1,0,0,0,0,0,1},
    //     {0,0,1,0,0,0,1,1,1},
    //     {0,0,1,1,0,1,0,1,0},
    //     {0,0,0,0,0,1,1,0,1},
    //     {0,0,0,0,1,1,0,1,0}
    // };   
    int matr[4][4] = {
        {0, 2, inf, 5},
        {3, 0, inf, 4},
        {inf, 1, 0, inf},
        {inf, inf, 2, 0}
    };
    // the above is the graph for the problem
    int n = sizeof(matr) / sizeof(matr[0]);
    printf("n ===> %d\n", n);
    int **new_mat = create_mat(n);
    if (!new_mat)
    {
        printf("Memory Alloc failed\n");
        return NULL;
    }

    fr(i, 0, n)
    {
        fr(j, 0, n)
        {
            new_mat[i][j] = matr[i][j];
        }
    }

    return new_mat;
}

void copy_matrix(int **src, int **dest, int n)
{
    fr(i, 0, n)
    {
        fr(j, 0, n)
        {
            dest[i][j] = src[i][j];
        }
    }
}

int ***floydwar_with_hist(int **graph, int vertex)
{
    // here graph is matr or matr is graph
    int ***hist = (int ***)malloc(vertex + 1 * sizeof(int**));
    
    hist[0] = create_mat(vertex);
    copy_matrix(graph, hist[0], vertex);

    fr(k, 0, vertex)
    {
        hist[k + 1] = create_mat(vertex);
        copy_matrix(hist[k], hist[k + 1], vertex);
        fr(i, 0, vertex)
        {
            fr(j, 0, vertex)
            {
                if (hist[k][i][k] != inf && hist[k][k][j] != inf)
                {
                    int new_dist = hist[k][i][k] + hist[k][k][j];
                    if (new_dist < hist[k + 1][i][j])
                    {
                        hist[k + 1][i][j] = new_dist;
                    }
                }
            }
        }
    }

    return hist;
}

void show_hist(int ***hist, int vertex)
{
    fr(i, 0, vertex + 1)
    {
        printf("hist[%d]:\n", i);
        print_mat(hist[i], vertex);
    }
}