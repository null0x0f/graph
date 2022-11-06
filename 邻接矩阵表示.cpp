#include<iostream>
#define maxsize 100
#define INF 65555
using namespace std;
template<class T>
class Mgraph
{
protected:
	T arc[maxsize][maxsize];//��ž���Ķ�ά����
	//�����
	int vertex[maxsize];//�洢�ڵ����
	char vername[maxsize];//�洢�ڵ�����
	int e;//����
	int n;//������
	bool visited[maxsize];//��¼��û�б�����
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
	//������
	void create()
	{
		int i, j, k, w;
		cout << "��������ͱ���";
		cin >> n>> e;
		cout << "�����붥����Ϣ" << endl;
		for (i = 0; i < n; i++)
		{
			vertex[i] = i;//�洢���
			cin>>vername[i];//���붥������
		}
		/*for (k = 0; k < e; k++)
		{
			cout << "������ߵ��±�i��j��Ȩw";
			cin >> i >> j >> w;
			if (i > n - 1 || j > n - 1)
			{
				cout << "�������" << endl;
			}
			else
			{
				//arc[j][i] = arc[i][j] = w;//����ͼ
				arc[i][j] = w;//����ͼ
			}
		}*/
		//���Ҷ��㽨��
		char x, y;
		for (k = 0; k < e; k++)
		{
			cout << "�������������Ȩ";
			cin >> x >> y >> w;
			i = located(x);
			j = located(y);
			arc[i][j] = w;
		}
	}
	//���ض���������λ��
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
	//���Ӷ���
	void insertvex(char ch)
	{
		vertex[n] =n;
		vername[n] = ch;
		n++;
	}
	void deleteVex(char ch)
	{
		int i,j,k;
		//����Ѱ�Ҷ���λ��
		i = located(ch);
		if (i == -1)
		{
			cout << "�������" << endl;
		}
		for (j = i; j < n - 1; j++)
			vername[j] = vername[j + 1];//����
		//arc�����a�������ȫ���0���Ժ�������ҵ�0��������������Ѿ���ɾ��



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
	//����ĳ����
	void insertedge(int i,int j,int w)
	{
		arc[i][j] = w;
		e++;
	}
	//ɾ��ĳ����
	void deleteEdge(int i,int j)
	{
		arc[i][j] = INF;
		e--;
	}
	//���ص�һ���ڽӶ���
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
		cout << "�ڽӾ���" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%4d",arc[i][j]);
			}
			cout << endl;
		}
	}
	//������ȱ���
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
	//������ȱ���
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