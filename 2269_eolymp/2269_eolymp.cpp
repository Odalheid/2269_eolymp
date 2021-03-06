#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> used;
vector<vector<int>> v;

void dfs(const int &n) {
	used[n] = true;
	for (int i = 0; i < used.size(); ++i) {
		if (v[n][i] && !used[i]) dfs(i);
	}
}

int search_unused() {
	for (int i = 0; i < used.size(); ++i) {
		if (!used[i]) return i;
	}
	return 0;
}

int main()
{
	int vertices;
	cin >> vertices;
	v.resize(vertices);
	used.resize(vertices, false);
	for (int i = 0; i < vertices; ++i) {
		vector<int> tmp(vertices);
		for (int j = 0; j < vertices; ++j) {
			cin >> tmp[j];
		}
		v[i] = tmp;
	}
	int counter = 0;
	do {
		dfs(search_unused());
		++counter;
	} while (search_unused() != 0);
	cout << counter;
    return 0;
}