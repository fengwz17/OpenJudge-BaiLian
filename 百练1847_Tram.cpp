// Dijkstra�㷨����Floyd�㷨�����·
// ������Ҫ�ѵ������������ 
// w��Ϊ·�����ȣ�ֱ��ָ��ʱw=0, ��Ҫ�ֶ��⶯ʱw=1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#define INF 0xffff;
using namespace std;

int map[100][100];

int main()
{
	int n, a, b;
	int k, x;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			map[i][j] = map[j][i] = INF;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> x;
			map[i][x] = j == 1 ? 0 : 1; // ��ÿ��·�ڣ���һ����ԭָ��·�ڣ�Ϊ0��֮������Ҫ����ת���ģ�ָ���·��Ϊ1
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	if ( map[a][b] == 0xffff )
		cout << "-1" << endl;
	else
		cout << map[a][b] << endl;

	return 0;
}
 
