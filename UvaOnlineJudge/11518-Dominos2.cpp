#include <bits/stdc++.h>

using namespace std;

bool vis[10001];
int counter = 0;

void dfs(int domino, vector <int> list[]){
	counter++;
	vis[domino] = true;
	for(auto i : list[domino]){
		if(!vis[i]){
			dfs(i, list);
		}
	}
}

void makeFalse(int size){
	for(int i = 0; i <= size; i++){
		vis[i] = false;
	}
}

int main(){
	int numberOfTestCases, i, j, n, m , l, x, y, z;
	cin >> numberOfTestCases;
	for(i = 0; i < numberOfTestCases; i++){
		cin >> n >> m >> l;
		makeFalse(n);
		vector <int> adjList[n + 1];
		for(j = 0; j < m; j++){
			cin >> x >> y;
			adjList[x].push_back(y);
		}
		for(j = 0; j < l; j++){
			cin >> z;
			if(!vis[z]){
				dfs(z, adjList);
			}
		}
		cout << counter << '\n';
		counter = 0;
	}
}
