#include<iostream>
using namespace std;
int s[5010][5010];
int main()
{
	int N, R;
	cin >> N >> R;
	R = min(R, 5001);
	for (int i = 1; i <= N; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		s[++x][++y] += w;
	}
	for (int i = 1; i <= 5001; i++)
	{
		for (int j = 1; j <= 5001; j++)
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
	}
	int ans = 0;
	for (int i = R; i <= 5001; i++)
		for (int j = R; j <= 5001; j++)
			ans = max(ans, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]);
	cout << ans;
	return 0;
}