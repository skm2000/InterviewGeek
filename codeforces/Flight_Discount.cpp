#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	//in[i] contains flights from city i
	//out[i] contains flights to city i
	vector<pair<int, int>> in[100000], out[100000];
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		out[a - 1].push_back({b - 1, c});
		in[b - 1].push_back({a - 1, c});
	}
	priority_queue<pair<long long, int>> q; //(-price, city)
	bool visited[100000]{};

	//find the price to go from city 1 to all other cities
	long long dist1[100000];
	fill(dist1, dist1 + n, 1e18);
	dist1[0] = 0;
	q.push({0, 0});
	while (!q.empty())
	{
		int a = q.top().second;
		q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto i : out[a])
		{
			int b = i.first, w = i.second;
			if (dist1[a] + w < dist1[b])
			{
				dist1[b] = dist1[a] + w;
				q.push({-dist1[b], b});
			}
		}
	}

	//find the price to go from each city to city n
	long long distn[100000];
	fill(distn, distn + n, 1e18);
	fill(visited, visited + n, false);
	distn[n - 1] = 0;
	q.push({0, n - 1});
	while (!q.empty())
	{
		int a = q.top().second;
		q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto i : in[a])
		{
			int b = i.first, w = i.second;
			if (distn[a] + w < distn[b])
			{
				distn[b] = distn[a] + w;
				q.push({-distn[b], b});
			}
		}
	}

	//take the minimum cost after using the coupon over all pairs of cities
	long long cost = dist1[n - 1];
	for (int a = 0; a < n; a++)
	{
		for (auto i : out[a])
		{
			int b = i.first, w = i.second;
			cost = min(cost, dist1[a] + distn[b] + w / 2);
		}
	}
	cout << cost << endl;
	return 0;
}