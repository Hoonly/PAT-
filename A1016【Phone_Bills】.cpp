#include<iostream>
#include<cstring>
#include<algorithm>
#include<iterator>
#include<string.h>
#include<vector>
using namespace std;

struct bill
{
	char name[21];
	int month;
	int day;
	int hour;
	int minute;
	char state[10];
};

bool cmp(bill a, bill b)
{
	if (strcmp(a.name,b.name)!=0)
		return strcmp(a.name, b.name) < 0;
	else if (a.day != b.day)
		return a.day < b.day;
	else if (a.hour != b.hour)
		return a.hour < b.hour;
	else
		return a.minute < b.minute;
}

int main()
{
	vector<bill> record;

	int charge[24];//每个小时的收费
	int oneday_charge=0;//一整天收费(美分)
	for (int i = 0; i < 24; i++)
	{
		scanf("%d", &charge[i]);
		oneday_charge += charge[i] * 60;
	}
		
	

	int N;
	cin >> N;//N条记录

	for (int i = 0; i<N; i++)
	{
		bill tmp;
		scanf("%s %d:%d:%d:%d %s", tmp.name, &tmp.month, &tmp.day, &tmp.hour, &tmp.minute,tmp.state);
		record.push_back(tmp);
	}
	stable_sort(record.begin(), record.end(), cmp);

	//找出匹配的on-line off-line
	vector<bill> check;
	for (int i=0;i<record.size()-1;i++)
	{
		bill first = record[i];
		bill second = record[i+1];
		if (strcmp(first.name, second.name) == 0 && strcmp(first.state, "on-line") == 0 && strcmp(second.state, "off-line") == 0)
		{
			check.push_back(first);
			check.push_back(second);
		}
	}

	
	bill b;
	strcpy(b.name, "NULL");
	check.push_back(b);//扩容一位为了打印最后一个人，无实际意义
	
	char *name = check[0].name;
	int index = 0;
	for (int i = 0; i < check.size(); i++)
	{
		if (strcmp(check[i].name, name) == 0)//如果是同一个人,继续往后找属于这个人的记录
		{
			continue;
		}
		else//直到遇到下一个人，把上一个人的全部账单打印出来
		{
			double amount=0;//单条记录账单
			double total_amount=0;//总记录账单
			printf("%s %02d\n",check[i-1].name,check[i-1].month);
			for (int j = index; j < i-1; j+=2)
			{
				printf("%02d:%02d:%02d ", check[j].day, check[j].hour, check[j].minute);
				printf("%02d:%02d:%02d ", check[j+1].day, check[j+1].hour, check[j+1].minute);
				int total_day = check[j + 1].day - check[j].day - 1;
				int online_minute = 24 * 60 - (check[j].hour * 60 + check[j].minute);
				int offline_minute = check[j + 1].hour * 60 + check[j + 1].minute;
				int total_minute = total_day * 24 * 60 + online_minute + offline_minute;
				printf("%d ", total_minute);

				if (check[j].day==check[j+1].day)//如果在同一天内
				{
					if (check[j].hour == check[j + 1].hour)//如果在同一小时内
					{
						amount = (check[j + 1].minute - check[j].minute)*charge[check[j].hour];
					}
					else
					{
						int amount1 = charge[check[j].hour] * (60 - check[j].minute);
						int amount2 = charge[check[j + 1].hour] * (check[j + 1].minute);
						if (check[j + 1].hour == check[j].hour + 1)//如果在相邻小时内
						{
							amount = amount1 + amount2;
						}
						else
						{
							for (int k = check[j].hour + 1; k < check[j + 1].hour; k++)
							{
								amount += charge[k] * 60;
							}
							amount = amount + amount1 + amount2;
						}
						
					}
				}
				else//不在同一天内
				{
					int amount1 = charge[check[j].hour] * (60 - check[j].minute);
					int amount2 = charge[check[j + 1].hour] * (check[j + 1].minute);
					for (int k = check[j].hour + 1; k < 24; k++)
					{
						amount1 += charge[k] * 60;
					}
					for (int k = 0; k < check[j+1].hour; k++)
					{
						amount2 += charge[k] * 60;
					}
					amount = amount1 + amount2 + oneday_charge * total_day;
				}
				total_amount += amount/100;
				printf("$%.2f\n", amount / 100);
				amount = 0;

			}
			name = check[i].name;
			index = i;
			printf("Total amount: $%.2f\n", total_amount);
		}
	}

	return 0;


}
