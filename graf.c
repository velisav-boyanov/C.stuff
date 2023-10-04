#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct graphNode{
	int key;
	int connections[10];
};

int countSubgraphs(struct graphNode graph[8]){
	int count = 0;
	static int visited[100];//we use for the default 0 values

	for(int i = 0; i <= 7; i++){
		if(graph[i].connections[0]==0 && visited[i]==0){//node has no connections
			count++; 
			visited[i] = 1;//node i has been visited
		}else if(graph[i].connections[1]==0 && 
		graph[graph[i].connections[0]-1].connections[1]==0){//node has 1 connection that also has 1 connection
			if(visited[i]==0 && visited[graph[i].connections[0]-1]==0){//the first time these two nodes are visited
				count++;
				visited[i]=1;//node is visited
				visited[graph[i].connections[0]-1]=1;
			}
		}else if(visited[i]==0){//element with more than one connection
			visited[i]=1;//set the starting node as visited
			int connected = 0;//set to 1 when the first and last nodes are connected
			for(int k = 0; graph[i].connections[k] != 0; k++){//check the elements connections
				for(int n = 0; graph[graph[i].connections[k]-1].connections[n] != 0; n++){//check each connected elements connections(going down the nodes)
					if(graph[graph[i].connections[k]-1].connections[n]==graph[i].key){//find where the element from line 27 is connected to the last node from the above line
						if(connected == 0){
							count++;
							connected = 1;
						}
						for(int h = 1; graph[i].connections[h-1] != 0; h++){//set connected nodes as visited
							visited[graph[graph[i].connections[k]-h].key-1]=1;	
						}
					}
				}
			}
		}
	}
	return count;
}

void createGraf(struct graphNode graf[8]){
	graf[0].key = 1;
	graf[0].connections[0] = 2;
	graf[0].connections[1] = 4;
	graf[0].connections[2] = 0;//should be zero without setting but returns Core Dump sometimes

	graf[1].key = 2;
	graf[1].connections[0] = 1;
	graf[1].connections[1] = 3;
	graf[1].connections[2] = 0;

	graf[2].key = 3;
	graf[2].connections[0] = 2;
	graf[2].connections[1] = 4;
	graf[2].connections[2] = 0;

	graf[3].key = 4;
	graf[3].connections[0] = 1;
	graf[3].connections[1] = 3;
	graf[3].connections[2] = 0;

	graf[4].key = 5;
	graf[4].connections[0] = 6;
	graf[4].connections[1] = 0;

	graf[5].key = 6;
	graf[5].connections[0] = 5;
	graf[5].connections[1] = 0;

	graf[6].key = 7;
	graf[6].connections[0] = 8;
	graf[6].connections[1] = 0;

	graf[7].key = 8;
	graf[7].connections[0] = 7;
	graf[7].connections[1] = 0;

}

int main()
{
	struct graphNode graph[10];
	createGraf(graph);
	printf("Result:%d\n", countSubgraphs(graph));
	return 0;
}
