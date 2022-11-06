#include<iostream>
#define maxsize 100
#define INF 65555
using namespace std;
template<class T>
class Mgraph
{
protected:
	T arc[maxsize][maxsize];//存放矩阵的二维数组
	//顶点表
	int vertex[maxsize];//存储节点序号
	char vername[maxsize];//存储节点名字
	int e;//边数
	int n;//顶点数
	bool visited[maxsize];//记录有没有被访问
public:
	Mgraph()
	{
		for (int i = 0; i < maxsize; i++)
		{
			for (int j = 0; j < maxsize; j++)
			{
				arc[i][j] = INF;
			}
		}
	}
	//建立网
	void create()
	{
		int i, j, k, w;
		cout << "输入个数和边数";
		cin >> n>> e;
		cout << "请输入顶点信息" << endl;
		for (i = 0; i < n; i++)
		{
			vertex[i] = i;//存储序号
			cin>>vername[i];//输入顶点名字
		}
		/*for (k = 0; k < e; k++)
		{
			cout << "请输入边的下表i，j和权w";
			cin >> i >> j >> w;
			if (i > n - 1 || j > n - 1)
			{
				cout << "输入错误" << endl;
			}
			else
			{
				//arc[j][i] = arc[i][j] = w;//无向图
				arc[i][j] = w;//有向图
			}
		}*/
		//查找顶点建立
		char x, y;
		for (k = 0; k < e; k++)
		{
			cout << "输入两个顶点和权";
			cin >> x >> y >> w;
			i = located(x);
			j = located(y);
			arc[i][j] = w;
		}
	}
	//返回顶点在网中位置
	int located(char x)
	{
		int i = 0;
		for (i = 0; i < n; i++)
		{
			if (x == vername[i])
				return i;
		}
		return -1;
	}
	//增加顶点
	void insertvex(char ch)
	{
		vertex[n] =n;
		vername[n] = ch;
		n++;
	}
	void deleteVex(char ch)
	{
		int i,j,k;
		//遍历寻找顶点位置
		i = located(ch);
		if (i == -1)
		{
			cout << "输入错误" << endl;
		}
		for (j = i; j < n - 1; j++)
			vername[j] = vername[j + 1];//覆盖
		//arc数组把a顶点相关全变成0，以后遍历查找到0，就是这个顶点已经被删除



		for (j = i; j < n - 1; j++)
		{
			for (k = 0; k < n; k++)
			{
				arc[j][k] = arc[j + 1][k];
			}
		}
		for (j = 0; j < n-1; j++)
		{
			for (k = i; k < n-1; k++)
			{
				arc[j][k] = arc[j][k + 1];
			}
		}
			n--;
	}
	//增加某条边
	void insertedge(int i,int j,int w)
	{
		arc[i][j] = w;
		e++;
	}
	//删除某条边
	void deleteEdge(int i,int j)
	{
		arc[i][j] = INF;
		e--;
	}
	//返回第一个邻接顶点
	char firstvex(char ch)
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			if (ch == vername[i])
				break;
		}
		for (j = 0; j < n; j++)
		{
			if (arc[i][j] != INF)
			{
				break;
			}
		}
		if (j == n)
			return'\0';
		else
		{
			return vername[j];
		}
	}
	void output()
	{
		cout << "邻接矩阵" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%4d",arc[i][j]);
			}
			cout << endl;
		}
	}
	//深度优先遍历
	void DFS(char ch)
	{
		int j = 0;
		int i = located(ch);
		cout << vertex[i];
		visited[i] = true;
		for (j = 0; j < n; j++)
		{
			if ((arc[i][j] != INF) && (!visited[j]))
				DFS(vername[j]);
		}
           
	}
	//广度优先遍历
	void BFS(int v)
	{
	    for (int v = 0; v < n; ++v)
		{
			for (int w = 0; w <n; ++w)
			{
			if ((arc[v][w] != 0) && visited[w] == false)
			{
				cout << vertex[w];
			    visited[w] = true;
			}
			}
		}
	}
};


//int main(void)
//{
	//Mgraph<int> mygraph;
	//mygraph.create();
	//mygraph.output();
	// return 0;
//}