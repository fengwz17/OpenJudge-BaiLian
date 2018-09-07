// �鲢��������Ҫ����ԣ�i < j && x[i] > 2 * x[j]
// ע�����ֱ�Ӵ���������ԸĵĻ�������x[i] > x[j] && x[i] <= 2 * x[j]������������������ֱ��������x[i+1]��x[j]�ıȽ�
// �������ֱ������������һ��ѭ�����Ƚ�i+1��mid���ƺ��п��ܳ�ʱ��Ӧ������������ֿ�
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;

int num = 0;
int x[200001];
int temp[200001];
long long icount;

void merge(int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int point = 0;
	//for (int t = left; t <= mid; ++t)
	//{
		//cout << "from left to mid is " << x[t] << " ";
	//}
	//for (int t = mid+1; t <= right; ++t)
	//{
		//cout << "from mid+1 to right is " << x[t] << " ";
	//}
	//cout << endl;

	// ����һ��ѭ��ֻ����
	while (i <= mid && j <= right)
	{
		if (x[i] <= 2 * x[j])
			i++;
		else
		{
			j++;
			icount += mid - i + 1;
		}
	}

	// �ٺ�����һ�����򣬲�������ע����ʱҪ��ǰ���i,j��ԭ
	i = left;
	j = mid + 1;

	while(i <= mid && j <= right)
	{
		if (x[i] <= x[j])
		{
			temp[point++] = x[i++];
		}
		else
		{
			temp[point++] = x[j++];
			//icount += mid - i + 1;
			//cout << endl;
			//cout << "mid is " << mid << endl;
			//cout << "i is " << i << endl;
			//cout << "j is " << j << endl;
			//cout << "xi is " << x[i] << endl;
			//cout << "xj is " << x[j-1] << endl;
			//cout << "icount is " << icount << endl;
		}
	}

	while (i <= mid)
	{
		temp[point++] = x[i++];
	}
	while (j <= right)
	{
		temp[point++] = x[j++];
	}
	for (int t = 0; t < point; t++)
	{
		x[t + left] = temp[t];
	}
	//for (int t = 0; t < point; ++t)
	//{
		//cout << x[t + left] << ' ';
	//}
	//cout << endl;
	//cout << icount << endl;
	//cout << endl;
	/*
	while (i <= mid || j <= right)
	{
		if (j > right || (i <= mid && x[i] <= x[j]))
			temp[point++] = x[i++];
		else
		{
			temp[point++] = x[j++];
			icount += mid - i + 1;
		}
	}
	for (int t = 0; t < point; t++)
	{
		x[t + left] = temp[t];
	}
	*/
}

void merge_sort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main()
{
	cin >> num;
	icount = 0;
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < num; ++i)
	{
		scanf("%d", &x[i]);
	}
	merge_sort(0, num - 1);

	printf("%lld\n", icount);
	
	
	return 0;
}