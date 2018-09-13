// ��ȫ��������
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
using namespace std;
 
int N;

int paycount[5000]; // ֧��i��ʱ��ʹ��Ǯ�ҵ���������ʼΪi��1Ԫ
int value[5000] = { 0 }; // ��ʾ��ֵ

int main()
{
	cin >> N;
	while (N--) {
		for (int i = 0; i < 6; ++i)
		{
			cin >> value[i];
		}
		memset(paycount, 50, sizeof(paycount));
		paycount[0] = 0;
		for (int i = 0; i < 6; ++i)
			for (int j = value[i]; j <= 5000; ++j)
				paycount[j] = min(paycount[j], paycount[j - value[i]] + 1);

		// ���㣬����Ҫ��4Ԫ���ȸ�5Ԫ�ټ�һԪ������value����һԪ
		for (int i = 0; i < 6; ++i)
			for (int j = 5000 - value[i]; j >= 0; j--)
				paycount[j] = min(paycount[j], paycount[j + value[i]] + 1);

		double sum = 0;
		int imax = 0;
		for (int i = 1; i <= 100; ++i)
		{
			sum += paycount[i];
			imax = max(imax, paycount[i]);
		}
		cout << fixed << setprecision(2) << sum / 100 << " " << imax << endl;
		//for (int i = 0; i < 6; ++i)
			//cout << value[i] << " ";
	}
	return 0;

}