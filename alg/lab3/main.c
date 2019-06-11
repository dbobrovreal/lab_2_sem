#include "graph.h"
#include <sys/time.h>
#include <time.h>
#include <math.h> 

#define CON_GRAPH_SIZE 20
#define LAT_GRAPH_SIZE 9

int getrand(int min, int max);
double wtime();

int main()
{
    FILE *in = fopen("res.txt", "w");

	srand(time(NULL));
    
    struct graph* g = graph_create(CON_GRAPH_SIZE);

    int d[CON_GRAPH_SIZE];
    int prev[CON_GRAPH_SIZE];
    int path[CON_GRAPH_SIZE];

	// граф уже связный
	for (int i = 1; i < CON_GRAPH_SIZE; i++) {
		graph_set_edge(g, i, i + 1, getrand(1, 10));
	}
	// Рандомом соединить вершины
    int a, b;
    for (int i = 1; i < CON_GRAPH_SIZE * getrand(2, 7); i++) {
        a = rand() % (CON_GRAPH_SIZE - 1);
        b = rand() % (CON_GRAPH_SIZE - 1);
        if (a == i || a == i + 1 || i == a + 1 || a == 0 || a == b || b == 0 || b == i + 1 || b == i - 1) {
            continue;
        }
        graph_set_edge(g, a, b, getrand(1, 10));
    } 
    
    // Вывод
    printf("CONNECTED GRAPH : \n");
    printf("   ");
    for (int k = 0; k < g->nvertices; k++) {
        printf("%2.d ", k + 1);
    }
    printf("\n");

    for (int i = 0; i < g->nvertices; i++) {
        printf("\n%2.d ", i + 1);
        for (int j = 0; j < g->nvertices; j++) {
            printf("%2.d ", g->m[i * g->nvertices + j]);
            if(g->m[i * g->nvertices + j] == ' '){
                fprintf(in, "0\n");
            }else{
                fprintf(in, "1\n");
            }
        }
        printf("\n");
    }
    
	double t = wtime();
	ShortestPathDijkstra(g, 1, d, prev);
	t = wtime() - t;

    
    int i, j, len;
    for (i = 1; i <= CON_GRAPH_SIZE; i++)
    {
        len = RecoveryPath(g, 1, i, path, prev);
        printf("1 >> %d = %d\n", i, d[i]);
        printf("Vertex = ");

        path[1] = 1;

        for (j = 1; j < len; j++)
        {
            printf("%d -> ", path[j]);
        }
        printf("%d\n\n", path[j]);
    }
   
    printf("\n");
    printf("CONNECTED GRAPH TIME : %f\n", t);

    fclose(in);
    
    return 0;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}
double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}