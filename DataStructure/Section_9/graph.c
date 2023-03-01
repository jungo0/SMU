#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0
// �׷����� ���� ����Ʈ�� ǥ���ϱ� ���� ����ü ����

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;					// ���� ����
	GraphNode* adj_list[MAX_VERTICES];	// ���� ����Ʈ�� ��� ��� �迭
} GraphType;

void graph_init(GraphType* g);
void insert_vertex(GraphType* g, int v);
void insert_edge(GraphType* g, int u, int v);
// �ʺ� �켱 Ž���� ���� �ʱ� ���� �׷����� �����ϴ� ����
void graph_init(GraphType* g) {
   int v;
   g->n = 0;         // �׷����� ���� ������ 0���� �ʱ�ȭ
   for (v = 0; v<MAX_VERTICES; v++) {
      g->adj_list[v] = NULL;      
   }
}

// �׷��� g�� ���� v�� ����
void insert_vertex(GraphType* g, int v) {
   if (((g->n) + 1)>MAX_VERTICES) {
      printf("�׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
      return;
   }
   g->n++;
}

// �׷��� g�� ���� (u, v)�� ����
void insert_edge(GraphType* g, int u, int v) {
   GraphNode* node;
   if (u >= g->n || v >= g->n) {
      printf(" �׷����� ���� �����Դϴ�!");
      return;
   }
   node = (GraphNode *)malloc(sizeof(GraphNode));
   node->vertex = v;
   node->link = g->adj_list[u];
   g->adj_list[u] = node;
} 
int visited[MAX_VERTICES];

typedef struct QNode {
   int data;
   struct QNode *link;
} QNode;

typedef struct {
   QNode *front, *rear;
} LQueueType;


LQueueType *createLinkedQueue();
int isEmpty(LQueueType *LQ);
void enQueue(LQueueType *LQ, int item);
int deQueue(LQueueType *LQ);
void dfs_list(GraphType *g, int v);
void bfs_list(GraphType *g, int v);
void find_connected_component_1(GraphType *g);
void find_connected_component_2(GraphType *g);
void Show(GraphType * g);
LQueueType *createLinkedQueue() {
   LQueueType *LQ;
   LQ = (LQueueType *)malloc(sizeof(LQueueType));
   LQ->front = NULL;
   LQ->rear = NULL;
   return LQ;
}

int isEmpty(LQueueType *LQ) {
   if (LQ->front == NULL) {
      printf("\n Linked Queue is empty! \n");
      return 1;
   }
   else return 0;
}

void enQueue(LQueueType *LQ, int item) {
   QNode *newNode = (QNode *)malloc(sizeof(QNode));
   newNode->data = item;
   newNode->link = NULL;
   if (LQ->front == NULL) {
      LQ->front = newNode;
      LQ->rear = newNode;
   }
   else {
      LQ->rear->link = newNode;
      LQ->rear = newNode;
   }
}

int deQueue(LQueueType *LQ) {
   QNode *old = LQ->front;
   int item;
   if (isEmpty(LQ)) return 0;
   else {
      item = old->data;
      LQ->front = LQ->front->link;
      if (LQ->front == NULL)
         LQ->rear = NULL;
      free(old);
      return item;
   }
} 

void bfs_list(GraphType *g, int v) //�ʺ�켱Ž��  
{
   GraphNode *w;
   LQueueType q=(*createLinkedQueue());

   visited[v]=TRUE;
   printf("%d ",v);
   enQueue(&q, v);
   while(!isEmpty(&q)){
      v=deQueue(&q);
      for(w=g->adj_list[v];w;w=w->link)
         if(!visited[w->vertex]){
            visited[w->vertex]=TRUE;
            printf("%d ",w->vertex);
            enQueue(&q, w->vertex);
         }
   }
}
void dfs_list(GraphType *g, int v) //���̿켱Ž��  
{
   GraphNode *w;
   visited[v]= TRUE;
   printf("%d ", v);
   for(w=g->adj_list[v]; w; w=w->link)
      if(!visited[w->vertex])
         dfs_list(g,w->vertex);
}

void find_connected_component_1(GraphType *g) //���Ἲ��_���̿켱Ž�� 
{
   int i;
   
   int count=0;
   for(i=0;i<g->n; i++){
      if(!visited[i]){
         count++;
         dfs_list(g,i); printf("\n");
      }
      printf("visited[%d]-> %d \n", i, count);
   }
}
void find_connected_component_2(GraphType *g) //���Ἲ��_�ʺ�켱Ž��  
{
   int i;
   int  count=0;
   for(i=0;i<g->n; i++)
      if(!visited[i]){
         count++;
         bfs_list(g,i);
      }
}

void Show(GraphType *g)
{
   int i= 0;
   GraphNode *n;
   while(i<10)
   {
      n=g->adj_list[i];
      printf("vertex %d -> ", i);
      while(1)
      {
         printf("%d ", n->vertex);
         n=n->link;
         if(n==NULL) 
			 break;
      }
      printf("\n");
      i++;
   }
}


int main() 
{
	int i;
	GraphType g;

	graph_init(&g);

	for (i = 0; i < 10; i++) 
		insert_vertex(&g, i);

		insert_edge(&g, 0, 1);
		insert_edge(&g, 1, 0);
		insert_edge(&g, 0, 2);
		insert_edge(&g, 2, 0);
		insert_edge(&g, 1, 2);
		insert_edge(&g, 2, 1);

		insert_edge(&g, 3, 4);
		insert_edge(&g, 4, 3);
		insert_edge(&g, 4, 5);
		insert_edge(&g, 5, 4);
		insert_edge(&g, 5, 6);
		insert_edge(&g, 6, 5);
		insert_edge(&g, 6, 3);
		insert_edge(&g, 3, 6);

		insert_edge(&g, 7, 8);
		insert_edge(&g, 8, 7);
		insert_edge(&g, 7, 9);
		insert_edge(&g, 9, 7);
		insert_edge(&g ,9, 8);
		insert_edge(&g ,8, 9);

		printf(" �������\n");
		Show(&g);
		printf("\n���̿켱Ž��\n");
		find_connected_component_1(&g);
		for(i=0; i<MAX_VERTICES; i++)
	    visited[i]=0;
		printf("\n");
		printf("\n�ʺ�켱Ž��\n");
		find_connected_component_2(&g);
   
   
	   system("pause");
}
