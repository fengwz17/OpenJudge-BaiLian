/*
#����
��������������ݣ�һ������b���Ӧһ������
��һ�а�����������w��h(1 <= w, h <= 75)���ֱ��ʾ���ΰ�Ŀ�Ⱥͳ���
����h�У�ÿ�а���w���ַ�����ʾ���ΰ��ϵ���Ϸ��Ƭ�ֲ���X��ʾ����ط���һ����Ϸ��Ƭ���ո��ʾ����ط�û�п�Ƭ
֮��ÿ�а���4��������x1, y1, x2, y2(1 <= x1, x2 <= w, 1 <= y1, y2 <= h)����������Ƭ�ھ��ΰ��ϵ�λ�ã����ΰ����Ͻ���(1, 1)
���뱣֤��������Ϸ��Ƭ������λ���ǲ���ͬ��
���һ������4��0, ��ʾ����������ݵĽ���
���һ���ϸ���w = h = 0, ��ô��ʾ���е����������

#���
��ÿһ�����ΰ�, ���һ�� ��Board #n:��, n���������ݵı��
��ÿһ����Ҫ���Ե���Ϸ��Ƭ���һ��.��һ�еĿ�ͷ�� ��Pair m : ��, ����m�ǲ��Կ�Ƭ�ı�ţ���ÿ�����ΰ�, ��Ŷ���1��ʼ��
�����������, �ҵ�������������Ƭ������·���а����߶������ٵ�·��, ��� ��k segments.��
k���ҵ�������·���а������߶ε���Ŀ
�����������, ��� ��impossible.��
ÿ������֮�����һ������

#��������
5 4
XXXXX
X   X
XXX X
XXX
2 3 5 3
1 3 4 4
2 3 3 4
0 0 0 0
0 0

#�������
Board #1:
Pair1: 4 segments
Pair2 : 3 segments
Pair3 : impossible

�������������
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
# define MAXIN 75

using namespace std;

char board[MAXIN + 2][MAXIN + 2];
int minstep, w, h, to[4][2] = { {0,1},{1,0},{0,0},{1,1} };
bool mark[MAXIN + 2][MAXIN + 2];

void Search(int now_x, int now_y, int end_x, int end_y, int step, int f)
{
	if (step > minstep)
		return;
	if (now_x == end_x && now_y == end_y)
	{
		if (minstep > step)
			minstep = step;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int x = now_x + to[i][0];
		int y = now_y + to[i][1];
		if ((x > -1) && (x < w + 2) && (y > -1) && (y < h + 2)
			&& (((board[y][x] == ' ') && (mark[y][x] == false)) ||
			((x == end_x) && (y == end_y) && (board[y][x] == 'X'))))
		{
			mark[y][x] = true;
			if (f == i) Search(x, y, end_x, end_y, step, i);
			else Search(x, y, end_x, end_y, step + 1, i);
			mark[y][x] = false;
		}
	}
}

int main()
{
	int Boardnum = 0;
	while (cin >> w >> h)
	{
		if (w == 0 && h == 0)
			break;
		Boardnum++;
		cout << "Board #: " << Boardnum << endl;
		int i, j;
		for (i = 0; i < MAXIN + 2; i++)
			board[0][i] = board[i][0] = ' ';
		for (i = 1; i <= h; i++)
		{
			getchar();
			for (j = 1; j <= w; j++)
				board[i][j] = getchar();
		}

		for (i = 0; i <= w; i++)
			board[h + 1][i + 1] = ' ';
		for (i = 0; i <= h; i++)
			board[i + 1][w + 1] = ' ';
		for (i = 0; i <= w; i++)
		{
			for (j = 0; j <= h; j++)
				cout << board[i][j];
			cout << board[i][h+1] << endl;
		}
				
		int begin_x, begin_y, end_x, end_y, count = 0;
		while (cin >> begin_x >> begin_y >> end_x >> end_y && begin_x > 0)
		{
			count++;
			minstep = 100000;
			memset(mark, false, sizeof(mark));
			Search(begin_x, begin_y, end_x, end_y, 0, -1);
			if (minstep < 100000)
				cout << "Pair " << count << ": " << minstep << " segments" << endl;
			else
				cout << "Pair " << count << ": impossible" << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}






