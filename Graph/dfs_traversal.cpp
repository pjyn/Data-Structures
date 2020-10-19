# include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<int>*adj;
	
	public:
		Graph(int v){
			this->v = v;
			adj = new list<int>[v];
		}
		void DFS(int v);		//make all node unvisited..
		void DFSUtil(int v, bool visited[]);	//visited, print & traverse.
		void addEdge(int v, int w);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])		
{
	visited[v] = true;
	cout<< v <<" ";
	
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end();i++)
	{
		if(!visited[*i])
		{
			DFSUtil(*i,visited);
		}
	}
}

void Graph::DFS(int v)
{
	bool *visited = new bool[v];
	for(int i = 0;i<v;i++)
	{
		visited[i] = false;
	}
	DFSUtil(v,visited);
}

int main()
{
	Graph a(6);
	a.addEdge(0,1);
	a.addEdge(0,2);
	a.addEdge(1,2);
	a.addEdge(2,0);
	a.addEdge(2,3);
	a.addEdge(3,3);
	a.addEdge(4,2);
	a.addEdge(4,3);
	a.addEdge(5,4);
	cout<<"Following is:\n";
	a.DFS(4);
	return 0;
}
