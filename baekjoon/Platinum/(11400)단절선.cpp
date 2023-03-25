/**
 * baekjoon - 11400
 * 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100001

using namespace std;

int V, E;
vector<int> Edge[MAX];
int visited[MAX];
vector<pair<int, int> > answer;

int DFS(int Parent, int Start, int Order) {
	int res = Order;
	visited[Start] = Order; // DFS 탐색 순서 지정

	for (int i = 0; i < Edge[Start].size(); i++) {
		int Next = Edge[Start][i]; // 다음 정점
		if (Parent == Next) {
			continue;
		}
		if (visited[Next] == 0) { // 다음 정점이 아직 탐색되지 않은 정점일 때
			int Next_Order = DFS(Start, Next, Order + 1); // 다음 정점의 방문 번호를 찾고
			if (Next_Order > visited[Start]) {
				/*
					현재 정점에서, 아직 방문하지 않은 정점의 방문 순서가 현재 정점의 순서보다 뒤라면
					현재 Edge는 단절선이 된다.(visited[Next] > visited[Start])
				*/
				answer.push_back(make_pair(min(Start, Next), max(Start, Next)));
			}
			res = min(res, Next_Order);
		}
		else {
			res = min(res, visited[Next]);
			continue;
		}
	}

	return res;
}

void Input() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B;
		cin >> A >> B;
		Edge[A].push_back(B);
		Edge[B].push_back(A);
	}
}

void Settings() {
	for (int i = 1; i <= V; i++) {
		sort(Edge[i].begin(), Edge[i].end());
	}
	for (int i = 1; i <= V; i++) {
		if (visited[i] == 0) {
			DFS(0, i, 1);
		}
	}
}

void Find_Answer() {
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		int S = answer[i].first;
		int E = answer[i].second;
		cout << S << " " << E << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}