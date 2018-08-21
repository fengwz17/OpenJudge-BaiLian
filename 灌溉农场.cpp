/*
���ũ��
��һƬ�ݳ���:��һ������ΪL (1 <= L <= 1,000,000��LΪż��)���߶Ρ� John��N (1 <= N <= 1000) ͷ��ţ�����Ųݳ��������߶γԲݣ�ÿͷţ�Ļ��Χ��һ��������(S,E)��S��E������������ͬ��ţ�Ļ��Χ�������ص���
JohnҪ�������߶��ϰ�װ��ˮͷ��Ȳݳ���ÿ����ˮͷ�������뾶����������ڣ����ڷ�Χ�� [A B ](1 <= A <= B <= 1000)��A,B����������Ҫ��
�߶��ϵ�ÿ������ǡ��λ��һ����ˮͷ��������Χ��
ÿͷ��ţ�Ļ��ΧҪλ��һ����ˮͷ��������Χ��
�κ���ˮͷ��������Χ����Խ���߶ε�����(�����0,�Ҷ���L )
���ʣ� John ������Ҫ��װ���ٸ���ˮͷ��

����
��1�У�����N��L��
��2�У�����A��B��
��3��N+2�У�ÿ����������S��E (0 <= S < E <= L) ��
��ʾĳͷţ���Χ�������յ����߶��ϵ�����(�����߶����ľ���)��

���
������Ҫ��װ�Ķ��ٸ���ˮͷ����û�з���Ҫ�����ˮͷ��װ�����������-1��

��������
2 8
1 2
6 7
3 6

�������
3
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstring>
#include<queue>

using namespace std;

const int INFINITE = 1 << 31;
const int MAXL = 1000010;
const int MAXN = 1010;
int F[MAXL];
int cowThere[MAXL]; // cowThere[i]=1��ʾi����ţ
int N, L, A, B;
struct Fx {
	int x;
	int f;
	bool operator<(const Fx & a) const { return f > a.f; }
	Fx(int xx = 0, int ff = 0) :x(xx), f(ff) {}
}; // ���ȶ��У�fֵԽСԽ����
priority_queue<Fx> qFx;

int main()
{
	cin >> N >> L;
	cin >> A >> B;
	A = A << 1; // A,B����Ϊֱ��
	B = B << 1;
	memset(cowThere, 0, sizeof(cowThere));
	for (int i = 0; i < N; i++)
	{
		int s, e;
		cin >> s >> e;
		++cowThere[s + 1]; // ��s+1�����һ����ţ��
		--cowThere[e]; // ��e���˳�һ����ţ��
	}
	int inCows = 0; // ��ʾ��ǰ��λ�ڶ���ͷ��ţ�Ļ��Χ֮��
	for (int i = 0; i <= L; i++) // ���ÿ�����Ƿ�����ţ
	{
		F[i] = INFINITE;
		inCows += cowThere[i];
		cowThere[i] = inCows > 0;
	}
	for (int i = A; i <= B; i += 2) //��ʼ������
	{
		if (!cowThere[i])
		{
			F[i] = 1;
			if (i <= B + 2 - A) //����F[i]��ʱ��Ҫȷ��������ĵ�x��x <= i - A
				qFx.push(Fx(i, 1));
		}
	}
	for (int i = B + 2; i <= L; i += 2)
	{
		if (!cowThere[i])
		{
			Fx fx;
			while (!qFx.empty())
			{
				fx = qFx.top();
				if (fx.x < i - B)
					qFx.pop();
				else
					break;
			}
			if (!qFx.empty())
				F[i] = fx.f + 1;
		}
		if (F[i - A + 2] != INFINITE) // ����������һ��+1�ɴ��¸���ĵ�
		{
			qFx.push(Fx(i - A + 2, F[i - A + 2]));
		}
	}
	if (F[L] == INFINITE)
		cout << -1 << endl;
	else
		cout << F[L] << endl;
	return 0;
}


