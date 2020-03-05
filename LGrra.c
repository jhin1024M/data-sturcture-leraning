
#define MaxVertexNum 100  /*z最大顶点数*/
typedef int Vertex;  /*顶点下标表示顶点*/
typedef int WeightType;  /*权值*/
typedef char DataType;/*顶点储存的数据类型*/
typedef struct GNode* PtrToGNode;
struct GNode
{
	int Ne; /*边数*/
	int Nv;/*顶点数*/
	AdjList G;/*邻接表头*/
	
};
typedef PtrToGNode LGraph;
/*边的定义*/
typedef struct ENode* PtrToGNode;
struct ENode
{
	Vertex v1, v2;
	WeightType Weight;
};
typedef PtrToGNode Edge;
/*邻接点的定义*/
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};
/*顶点表头节点*/
typedef struct Vnode
{
	PtrToAdjVNode FirstEdge;
	DataType Data;
}AdjList[MaxVertexNum];
/*初始化一个有VertexNum个顶点单没有边的图*/
LGraph CreateGraph(int VertexNum)
{
	LGraph Graph;
	Vertex V;
	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < VertexNum; V++)
	{
		Graph->G[V].FirstEdge = NULL;
	}
	return Graph;
}
/*插入边*/
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));  
	NewNode->AdjV = E->v2;
	NewNode->Weight = E->Weight;
	/*将新的节点查到表头上*/
	NewNode->Next = Graph->G[E->v1].FirstEdge;
	Graph->G[E->v1].FirstEdge = NewNode;
	/*无向图还需进行反向插入*/
	NewNode->AdjV = E->v1;
	NewNode->Weight = E->Weight;
	/*将新的节点查到表头上*/
	NewNode->Next = Graph->G[E->v2].FirstEdge;
	Graph->G[E->v2].FirstEdge = NewNode;
}
/*建立图*/
LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	scanf("%d", &Nv);
	Graph=CreateGraph(Nv);
	sancf("%d", &Graph->Ne);
	if (Graph->Ne)
		E = (Edge)malloc(sizeof(struct ENode));
	for (i = 0; i < Graph->Ne; i++)
	{
		scanf("%d %d %d", E->v1, E->v2, E->Weight);
		InsertEdge(Graph, E);
	}
	return Graph;
}