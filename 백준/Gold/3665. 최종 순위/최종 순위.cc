#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int n, m;
	for(int i = 0; i < T; i++)
	{
		cin >> n;
		vector<int> prev_rank(n);
		for(int j = 0; j < n; j++)
			cin >> prev_rank[j];

		vector<vector<int> > graph(n + 1);
		vector<int> indegree(n + 1, 0);
		for(int j = 0; j < n; j++) {
			for(int k = j + 1; k < n; k++)
				graph[prev_rank[j]].push_back(prev_rank[k]);
			indegree[prev_rank[j]] = j;
		}

		cin >> m;
		for(int j = 0; j < m; j++) {
			int t1, t2;
			cin >> t1 >> t2;
			if (find(graph[t1].begin(), graph[t1].end(), t2) == graph[t1].end()) {
				graph[t1].push_back(t2);
				graph[t2].erase(remove(graph[t2].begin(), graph[t2].end(), t1), graph[t2].end());
				indegree[t1] -= 1;
				indegree[t2] += 1;
			} else {
				graph[t2].push_back(t1);
				graph[t1].erase(remove(graph[t1].begin(), graph[t1].end(), t2), graph[t1].end());
				indegree[t1] += 1;
				indegree[t2] -= 1;
			}
		}

		queue<int> Q;
		for(int j = 1; j <= n; j++)
			if (indegree[j] == 0)
				Q.push(j);
		if (Q.size() > 1) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		int visit_cnt = 1;
		vector<int> cur_rank;
		while (!Q.empty())
		{
			int t = Q.front();
			cur_rank.push_back(t);
			Q.pop();

			vector<int> zero;
			for(int j = 0; j < graph[t].size(); j++) {
				indegree[graph[t][j]] -= 1;
				if (indegree[graph[t][j]] == 0)
					zero.push_back(graph[t][j]);
			}
			if (zero.size() == 1) {
				Q.push(zero[0]);
				visit_cnt += 1;
			} else {
				if (zero.size() > 1)
					cout << "?\n";
				break;
			}
		}
		if (visit_cnt != n) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for(int j = 0; j < cur_rank.size(); j++)
			cout << cur_rank[j] << ' ';
		cout << '\n';
	}

	return 0;
}