#include <stdio.h>
#include<iostream>
#include <limits.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

#define R 10
#define C 10

#define INF 10000
using namespace std;
int min(int x, int y, int z);

int minCost(int cost[R][C], int m, int n)
{
    int i, j;

    int tc[R][C];

    tc[0][0] = cost[0][0];

    /* Initialize first column of total cost(tc) array */
    for (i = 1; i <= m; i++)
        tc[i][0] = tc[i - 1][0] + cost[i][0];

    /* Initialize first row of tc array */
    for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j - 1] + cost[0][j];

    /* Construct rest of the tc array */
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++) {
			cout<<"check";
            tc[i][j] = min(tc[i - 1][j - 1], tc[i - 1][j], tc[i][j - 1]) + cost[i][j];
			cout<<tc[i][j]<<" ";
		}
    return tc[m][n];
}

/* A utility function that returns minimum of 3 integers */
int min(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

/* Driver program to test above functions */
int main()
{
    srand(time(NULL));

    int i, j, rand_inp;
    int cost[R][C];
    for (i = 0; i < R; ++i)
        for (j = 0; j < C; j++)
        {
            rand_inp = (rand() % 9) + 1;
            cost[i][j] = rand_inp;
        }
    int x_dest, y_dest;
    int num_obj, randVal_pos_i, randVal_pos_j;

    printf("Enter number of obstacles needed: ");
    scanf("%d", &num_obj);
	int randVal_box;
    while(num_obj>0)
    {
	randVal_pos_i = (rand() % 5) + 1;	
	randVal_pos_j = (rand() % 5) + 1;
	
	randVal_box = (rand() % 3) + 2;
	
	
	for(i = randVal_pos_i ; i < randVal_pos_i + randVal_box ; i++)
		cost[i][randVal_pos_j] = INF;

	for(i = randVal_pos_j ; i < randVal_pos_j + randVal_box ; i++)
		cost[randVal_pos_i][i] = INF;

	for(i = randVal_pos_i; i < randVal_pos_i + randVal_box ; i++)
		cost[i][randVal_pos_j  + randVal_box] = INF;

	for(i = randVal_pos_j ; i < randVal_pos_j + 1 + randVal_box ; i++)
		cost[randVal_pos_i + randVal_box][i] = INF;
    --num_obj;
	}

    printf("The generated maze:\n");
    for (i = 0; i < R; ++i)
    {
        for (j = 0; j < C; j++)
        {
            if (cost[i][j] == INF)
                printf(" * ");
            else
                printf(" %d ", cost[i][j]);
        }
        printf("\n");
    }
	int an=0;
    do
    {
    	if(an!=0)
    		printf("Obstalce encountered or Coordinates out of matrix!\n");
    	
        printf("Enter the destination coordinate: ");
        scanf("%d%d", &x_dest, &y_dest);
    
		an++;
		
	} while (x_dest >= 10 || y_dest >= 10 || cost[x_dest][y_dest] == INF);

	int minC = minCost(cost,x_dest,y_dest);
	if(minC > 10000)
		printf("Not possible!");
	else
    	printf(
       		  "Minimum cost from (0, 0) to (%d, %d): %d", x_dest, y_dest, minC);
    return 0;
}
