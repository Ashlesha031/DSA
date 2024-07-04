#include<iostream>
#include<vector>
using namespace std;

#define V 6
#define INF 99

int selectMinVertex(vector<int>& value, vector<bool>& processed) {
	int minimum = INF;
	int vertex;
	for (int i = 0; i < V; i++) {
		if (!processed[i] && value[i] < minimum) {
			minimum = value[i];
			vertex = i;
		}
	}
	return vertex;
}

void dijkstra(int graph[V][V]) {
	int parent[V];
	vector<int> value(V, INF);
	vector<bool> processed(V, false);

	parent[0] = -1;
	value[0] = 0;

	for (int i = 0; i < V - 1; i++) {
		int U = selectMinVertex(value, processed);
		processed[U] = true;

		for (int j = 0; j < V; j++) {
			if (graph[U][j] != 0 && !processed[j] && value[U] != INF && (value[U] + graph[U][j] < value[j])) {
				value[j] = value[U] + graph[U][j];
				parent[j] = U;
			}
		}
	}

	for (int i = 1; i < V; i++) {
		cout << "u -> v : " << parent[i] << " -> " << i << " wt = " << graph[parent[i]][i] << endl;
	}
}

int main() {
	int graph[V][V] = { {0, 1, 4, 0, 0, 0},
						{1, 0, 4, 2, 7, 0},
						{4, 4, 0, 3, 5, 0},
						{0, 2, 3, 0, 4, 6},
						{0, 7, 5, 4, 0, 7},
						{0, 0, 0, 6, 7, 0} };

	dijkstra(graph);
	return 0;
}
