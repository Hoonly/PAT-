#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct testee
{
	char registration[13];
	int score;
	int location_number;
	int local_rank;
	int final_rank;
}t[30001];

bool cmp(testee a, testee b)
{
	if (a.score != b.score)//分数不同按分数由大到小排序
		return a.score>b.score;
	else//分数相同按学号由小到大排序
		return strcmp(a.registration,b.registration)<0;
}

int main()
{

	int N;//考点数
	scanf("%d", &N);

	int K;//每个考点人数

	
	int total_count = 0;//考生总数
	for (int i = 0; i<N; i++)
	{
		scanf("%d", &K);
		for (int j = 0; j<K; j++)
		{
			t[total_count].location_number = i + 1;
			scanf("%s%d", t[total_count].registration, &(t[total_count].score));
			total_count++;
		}

		//单个考点排序
		sort(&t[total_count - K], &t[total_count], cmp);
		//单个考点排名
		int begin = total_count - K;
		t[begin].local_rank = 1;
		for (int m = begin + 1; m<total_count; m++)
		{
			if (t[m].score == t[m - 1].score)
				t[m].local_rank = t[m - 1].local_rank;
			else
				t[m].local_rank = m - begin + 1;
		}
	}

	printf("%d\n", total_count);

	//所有考生排序
	sort(t, t + total_count, cmp);
	//所有考生排名
	t[0].final_rank = 1;
	for (int i = 1; i<total_count; i++)
	{
		if (t[i].score == t[i - 1].score)
			t[i].final_rank = t[i - 1].final_rank;
		else
			t[i].final_rank = i + 1;
	}


	for (int i = 0; i<total_count; i++)
	{
		printf("%s %d %d %d\n", t[i].registration, t[i].final_rank, t[i].location_number, t[i].local_rank);
	}

	return 0;
}