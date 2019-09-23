//Büşra GÖKMEN
//150116027
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  double  elements_of_graph = 0;//elements number of graph
  int total_edge_number=0;//number of edges
    int i,k,j,z,x,w,s=0;
    double measure[10];//total number of steps of a node to or from other nodes
  typedef enum {
UNDIRECTED=0,DIRECTED
} graph_type;

    typedef struct adjlist_node
    { char *name;//name of nodes
        int vertex;                //Index to adjacency list array
        struct adjlist_node *next; //Pointer to the next node
         int Number;// number of edges attached to the node
    }
    adjlist_node_1, *adjlist_node_2;
    // Adjacency list
    typedef struct adjlist
    {
         adjlist_node_1 *head; //head of the adjacency linked list
    }adjlist_1, *adjlist_2;

    typedef struct graph
    {// Graph structure

        graph_type type;        //Directed or undirected graph
        int num_vertices;         //Number of vertices
        adjlist_2 adjListArr;     //Adjacency lists' array
    }graph_1, *graph_2;





  adjlist_node_2 createNode(int v)//Function to create an adjacency list node
  {
      adjlist_node_2 newNode = (adjlist_node_2)malloc(sizeof(adjlist_node_1));

      newNode->vertex = v;
      newNode->next = NULL;

      return newNode;
  }


  graph_2 createGraph(int n, graph_type type)// Function to create a graph with n vertices
  {
      int i;
      graph_2 graph = (graph_2)malloc(sizeof(graph_1));

      graph->num_vertices = n;
      graph->type = type;

      graph->adjListArr = (adjlist_2)malloc(n * sizeof(adjlist_1));  //Create an array of adjacency lists
      for(i = 0; i < n; i++)
      {
          graph->adjListArr[i].head = NULL;
          elements_of_graph++;
      }
return graph;

  }





  void addEdge(graph_1 *graph, int src, int dest)//Adds an edge to a graph
  {

     if(graph->type == UNDIRECTED)
      {
           adjlist_node_2 newNode = createNode(dest);
          newNode->next = graph->adjListArr[src].head;
          graph->adjListArr[src].head = newNode;

          newNode = createNode(src);
          newNode->next = graph->adjListArr[dest].head;
          graph->adjListArr[dest].head = newNode;
      }
  }

int m[10][10];
void initialiarray(){//initial array for not attached nodes
  int k,l;
  for(k=0;k<10;k++){
    for(l=0;l<10;l++){
m[k][l]=0;
    }
    printf("\n");
  }
}
  void displayGraph(graph_2 graph)// Function to print the adjacency list of graph
  {
    graph->adjListArr[0].head->name="Cem";
    graph->adjListArr[1].head->name="Ayse";
    graph->adjListArr[2].head->name="Belma";
    graph->adjListArr[3].head->name="Edip";
    graph->adjListArr[4].head->name="Dundar";
    graph->adjListArr[5].head->name="Gamze";
    graph->adjListArr[6].head->name="Ferit";
    graph->adjListArr[7].head->name="Halit";
    graph->adjListArr[8].head->name="Ilke";
    graph->adjListArr[9].head->name="Jale";

      int k,l,j;
      for (i = 0; i < graph->num_vertices; i++)
      {
          adjlist_node_2 adjListPtr = graph->adjListArr[i].head;
          printf("\n%s: ", graph->adjListArr[i].head->name);
          while (adjListPtr)
          {
              printf("%s->", graph->adjListArr[adjListPtr->vertex].head->name);
              total_edge_number++;
              graph->adjListArr[i].head->Number++;//number of edges attached to the i th node
              m[i][adjListPtr->vertex]=1;//array for attached nodes
              adjListPtr = adjListPtr->next;
      }
    }
    printf("\n\nAdjacency Matrix\n");
   printf("\n       Cem     Ayşe   Belma   Edip    Dundar   Gamze    Ferit  Halit  Ilke  Jale");
    printf("\n");
      for(k=0;k<10;k++){
  printf("%s\t",graph->adjListArr[k].head->name);
        for(l=0;l<10;l++){
     printf("%d\t",m[k][l]);
        }
      printf("\n");
      }
  }
  void DegreeCentrality(graph_2 graph){//Function to calculate edges number to attached to a node
  printf("\tDegree Centrality\t\n");
  printf("Node\tScore\tStandardized Score\n");
  printf("==================================\n");
  printf("\nCem\t%d\t%lf",(graph->adjListArr[0].head->Number),((graph->adjListArr[0].head->Number)/(elements_of_graph-1)));
  printf("\nAyşe\t%d\t%lf",(graph->adjListArr[1].head->Number),((graph->adjListArr[1].head->Number)/(elements_of_graph-1)));
    printf("\nBelma\t%d\t%lf",(graph->adjListArr[2].head->Number),((graph->adjListArr[2].head->Number)/(elements_of_graph-1)));
      printf("\nEdip\t%d\t%lf",(graph->adjListArr[3].head->Number),((graph->adjListArr[3].head->Number)/(elements_of_graph-1)));
        printf("\nDundar\t%d\t%lf",(graph->adjListArr[4].head->Number),((graph->adjListArr[4].head->Number)/(elements_of_graph-1)));
          printf("\nGamze\t%d\t%lf",(graph->adjListArr[5].head->Number),((graph->adjListArr[5].head->Number)/(elements_of_graph-1)));
            printf("\nFerit\t%d\t%lf",(graph->adjListArr[6].head->Number),((graph->adjListArr[6].head->Number)/(elements_of_graph-1)));
              printf("\nHalit\t%d\t%lf",(graph->adjListArr[7].head->Number),((graph->adjListArr[7].head->Number)/(elements_of_graph-1)));
                printf("\nIlke\t%d\t%lf",(graph->adjListArr[8].head->Number),((graph->adjListArr[8].head->Number)/(elements_of_graph-1)));
                  printf("\nJale\t%d\t%lf",(graph->adjListArr[9].head->Number),((graph->adjListArr[9].head->Number)/(elements_of_graph-1)));
  }
  void ClosenessCentrality(graph_2 graph){//Function to calculate closenes of nodes
    for (i= 0; i< graph->num_vertices; i++){
         measure[i]=0;
    for (z = 0; z<10; z++){
     if(m[i][z] == 1)
     measure[i]+=1;
     else if(m[i][z] == 0){
  for (s = 0; s<10; s++){
     if(m[i][s]==1 && m[z][s]==1 && m[i][z]==0)
      measure[i]+=2;
      else {
      for (j = 0; j<10; j++){
        if(m[i][s]==1 && m[z][s]==0 && m[z][j]==1 &&  m[s][j] ==1 && m[i][j] ==0 && m[i][z] ==0)
          measure[i]+=3;
          else{
              for (w = 0; w<10; w++){
                 if(m[i][s]==1 && m[z][s]==0 && m[z][j]==1 &&  m[s][j] == 0 && m[s][w] == 1 && m[j][w] == 1 && m[i][j] ==0)
            measure[i]+=4;
            else{
              for (x = 0; x<10; x++){
                if(m[i][s]==1 && m[z][s]==0 && m[z][j]==1 &&  m[s][j] == 0 && m[s][w] == 0 && m[j][w] == 1 && m[s][x] == 1 && m[w][x] == 1 && m[j][x] == 0 && m[i][x] == 0 && m[z][x] == 0 && m[w][z] == 1 && m[i][j] == 0)
                measure[i]+=5;
              }
            }
                 }
              }
          }
}
}}}

    }
    printf("\n\tCloseness Centrality\t\n");
    printf("Node\tScore\tStandardized Score\n");
    printf("==================================\n");
    printf("\nCem\t%lf\t%lf",(1/measure[0]),((elements_of_graph-1)*(1/measure[0])));
printf("\nAyşe\t%lf\t%lf",(1/measure[1]),((elements_of_graph-1)*(1/measure[1])));
printf("\nBelma\t%lf\t%lf",(1/measure[2]),((elements_of_graph-1)*(1/measure[2])));
  printf("\nEdip\t%lf\t%lf",(1/measure[3]),((elements_of_graph-1)*(1/measure[3])));
printf("\nDundar\t%lf\t%lf",(1/measure[4]),((elements_of_graph-1)*(1/measure[4])));
printf("\nGamze\t%lf\t%lf",(1/measure[5]),((elements_of_graph-1)*(1/measure[5])));
printf("\nFerit\t%lf\t%lf",(1/measure[6]),((elements_of_graph-1)*(1/measure[6])));
printf("\nHalit\t%lf\t%lf",(1/measure[7]),((elements_of_graph-1)*(1/measure[7])));
printf("\nJale\t%lf\t%lf",(1/measure[8]),((elements_of_graph-1)*(1/measure[8])));
printf("\nIlke\t%lf\t%lf",(1/measure[9]),((elements_of_graph-1)*(1/measure[9])));
 }
  void BetweennessCentrality(graph_2 graph){

  }


  int main()
  {
      graph_2 undir_graph = createGraph(10, UNDIRECTED);

      addEdge(undir_graph, 0,1);
      addEdge(undir_graph, 0, 6);
      addEdge(undir_graph, 0, 4);
      addEdge(undir_graph, 1, 6);
      addEdge(undir_graph, 1, 2);
      addEdge(undir_graph, 1, 4);
      addEdge(undir_graph, 2, 3);
      addEdge(undir_graph, 2, 4);
      addEdge(undir_graph, 3, 4);
      addEdge(undir_graph, 3, 5);
      addEdge(undir_graph, 4, 5);
      addEdge(undir_graph, 4, 6);
      addEdge(undir_graph, 5, 6);
      addEdge(undir_graph, 5, 7);
      addEdge(undir_graph, 6, 7);
      addEdge(undir_graph, 7, 8);
      addEdge(undir_graph, 8, 9);

        initialiarray();
      printf("\n-GRAPH-\n");
      printf("Adjacency List\n");
      displayGraph(undir_graph);
      printf("\n");
      DegreeCentrality(undir_graph);
      printf("\n");
      ClosenessCentrality(undir_graph);
      return 0;
  }
