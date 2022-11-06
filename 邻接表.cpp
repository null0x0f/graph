#include<iostream>
#define mvnum 100
using namespace std;

//������кͻ�������
struct queuenode
{
	int data;
	queuenode* next;
};
class linkqueue
{
private:
	queuenode* front;
	queuenode* rear;
public:
	linkqueue()
	{
		front = rear = NULL;
	}
	bool isempty()
	{
		if (front == NULL)
		{
			return true;
		}
	}
	void enqueue(int p)
	{
		queuenode* q = new queuenode;
		q->data = p;
		q->next = NULL;
		if (front == NULL)
		{
			front = rear = q;
		}
		else
		{
			rear->next = q;
			rear = q;
		}
	}
	int dequeue()
	{
		int p = 0;
		if (isempty())
		{
			return -1;
		}
		queuenode* q = front;
		p = q->data;
		front = q->next;
		if (rear == q)
		{
			rear = front;
		}
		delete q;
		return p;
	}
};
//�߽��ṹ
struct Arcnode
{
	int adjvex;
	struct Arcnode* next;
	int info;
};
//����ṹ
template<class T>
struct vnode
{
	T data;
	Arcnode* first;
};
template<class T>
class ALgraph
{
private:
	vnode<int> adjvertices[mvnum];
	int vexnum, edgenum;
	bool visited[mvnum];
public:
	friend ostream& operator<<(ostream& out, ALgraph<int>& g);
	int located(int x)
	{
		for (int i = 0; i < vexnum; i++)
		{
			if (x == adjvertices[i].data)
			{
				return i;
			}
		}
		return -1;
	}
	void creategraph()
	{
		int i, j, k, w;
		Arcnode* e = NULL;
		Arcnode* q = NULL;
		cout << "�����붨�����ͱ���" << endl;
		cin >> vexnum >> edgenum;
		cout << "�����붥����Ϣ" << endl;
		for (k = 0; k < vexnum; k++)
		{
			cin >> adjvertices[k].data;//¼�붥����Ϣ
			adjvertices[k].first = NULL;//��ʼΪ��
		}
		//�����߱�
		for (k = 0; k < edgenum; k++)
		{
			int x, y;
			cout << "���������������Ϣ�ͱߵ�Ȩw";
			cin >>x>>y>>w ;
			i = located(x);
			j = located(y);
			//����ͼ
			e = new Arcnode;
			e->adjvex = j;
			e->info = w;
			e->next = adjvertices[i].first;
			adjvertices[i].first = e;
			//����ͼ
			q = new Arcnode;
			q->adjvex = i;
			q->info = w;
			q->next = adjvertices[j].first;
			adjvertices[j].first = q;
		}
	}
	/*void output()
	{
		cout << "�ڽӱ�" << endl;
		Arcnode* p;
		for (int i = 0; i < vexnum; i++)
		{
			cout << "����" << adjvertices[i].data << ": ";
			for (p = adjvertices[i].first; p; p = p->next)
				cout << p->adjvex << "(" << p->info << ")" << " ";
			cout << endl;
		}
	}*/
	void addEdge(int x,int y,T t)
	{ 
		int i = located(x);
		int j = located(y);
		if(i!=-1&&j!=-1)
		{
			Arcnode q = new Arcnode;
			q->info = t;
			q->adjvex = j;
			q->next = adjvertices[i].first;
			adjvertices[i].first = q;
			edgenum++;
		}
		else
		{
			cout << "enter error";
		}
	}
	void deleteEdge(int x, int y)
	{
		int i = located(x);
		int j = located(y);
		if (i != -1 || j != -1)
		{
			Arcnode q = adjvertices[i].first;
			Arcnode p = NULL;
			while (q != NULL && q.adjvex != j)
			{
				p = q;
				q = q.next;
			}
			if (q.adjvex == j)
			{
				if (q == adjvertices[i].first)
				{
					adjvertices[i].first = q.next;
				}
				else
				{
					p.next = q.next;
				}
				delete q;
				edgenum--;
			}
		}
		else
		{
			cout << "enter error" << endl;
		}

	}
	void deletevex(T x)
	{
		//����ͼ
		int i = located(x);
		while(adjvertices[i].first != NULL)
		{
			deleteEdge(adjvertices[i].data, adjvertices[i].first->adjvex);
			adjvertices[i].first = adjvertices[i].first->next;
		}
		vexnum--;
	}
	void addvex(T x)
	{
		adjvertices[vexnum + 1].data = x;
		adjvertices[vexnum + 1].first = NULL;
		vexnum++;
	}
	int firstadjvex(int vex)
	{
		int index = located(vex);
		if (index == -1)
		{
			return -1;
		}
		else if (adjvertices[index].first == NULL)
		{
			return -1;
		}
		else
			return adjvertices[index].first->adjvex;
	}
	int nextadjvex(int v,int u)
	{
		int index1 = located(v);
		int index2 = located(u);
		if (index1 == -1)
			return -1;
		else
		{
			Arcnode* p = adjvertices[index1].first;
			while (p && p->adjvex != index2)
			{
				p = p->next;
			}
			if (!(p->next))
			{
				return -1;
			}
			else
			{
				return p->next->adjvex;
			}
		}
	}
};
ostream& operator<<(ostream& out, ALgraph<int>& g)
{
	out << "�ڽӱ�" << endl;
	Arcnode* p;
	for (int i = 0; i < g.vexnum; i++)
	{
		out << "����" << g.adjvertices[i].data << ": ";
		for (p = g.adjvertices[i].first; p; p = p->next)
			out << p->adjvex +1<< "(" << p->info << ")" << " ";
		out << endl;
	}
	return out;
}

int main(void)
{
	ALgraph<int> g;
	g.creategraph();
	cout << g << endl;
	return 0;
}