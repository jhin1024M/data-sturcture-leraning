
#define MaxVertexNum 100  /*z最大顶点数*/
#define INFINITY 65535 /*∞*/
typedef int Vertex;  /*顶点下标表示顶点*/
typedef int WeightType;  /*权值*/
typedef char DataType;/*顶点储存的数据类型*/
typedef struct GNode* PtrToGNode;
struct GNode
{
	int Ne; /*边数*/
	int Nv;/*顶点数*/
	WeightType G[MaxVertexNum][MaxVertexNum];/*邻接矩阵*/
	DataType Data[MaxVertexNum];/*存顶点的数据，不一定存在*/
};
typedef PtrToGNode MGraph;
/*边的定义*/
typedef struct ENode* PtrToGNode;
struct ENode
{
	Vertex v1, v2;
	WeightType Weight;
};
typedef PtrToGNode Edge;
/*初始化一个有VertexNum个顶点单没有边的图*/
MGraph CreateGraph(int VertexNum)
{
	MGraph Graph;
	Vertex V, W;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < VertexNum; V++)
	{
		for (W = 0; W < VertexNum; W++)
			Graph->G[V][W] = INFINITY;
	}
	return Graph;
}
/*插入边*/
void InsertEdge(MGraph Graph, Edge E)
{
	Graph->Data[E->v1][E->v2] = E->Weight;
	Graph->Data[E->v2][E->v1] = E->Weight;
}
/*建立图*/
MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	scanf("%d", &Nv);
	Graph=CreateGraph(Nv);
	sancf("%d", &Graph->Ne);
	if (!Graph->Ne)
		E = (Edge)malloc(sizeof(struct ENode));
	for (i = 0; i < Graph->Ne; i++)
	{
		scanf("%d %d %d", E->v1, E->v2, E->Weight);
		InsertEdge(Graph, E);
	}
	return Graph;
}