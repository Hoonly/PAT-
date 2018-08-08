//和2015 408算法题一样，典型用hash
//需要注意的是输出删除的链表前要判断是否为空，否则测试点3会出错
#include<iostream>
#include<list>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

struct node
{
	int curr_add;//结点自身地址
	int data;
	int next_add;//下一个结点地址
};

int main()
{
	int start_add, total_number;
	scanf("%d %d", &start_add, &total_number);

	queue<node> q;
	list<node> l;
	for (int i = 0; i<total_number; i++)
	{
		node n;
		scanf("%d %d %d", &n.curr_add, &n.data, &n.next_add);
		if (n.curr_add != start_add)
			q.push(n);//把除了开始结点的其他结点全部入队
		else
			l.push_back(n);//把开始结点插到链表进行建链
	}
	//从队列里拿出结点来建链，若队头是当前链表尾结点所指下一个结点，将其加入链表并出队，否则将其出队后重新入队等待后续检查
	//这里几个注意点
	//1.当只有一个结点时，队列为空，所以进来就要判空否则死循环显示超时
	//2.有的测试用例会有无效结点，比如有两个尾结点，所以当第一次链接到nex_add=-1的尾结点时就要退出循环
	while (true)
	{
		if (q.empty()) break;
		node tmp = q.front();
		if (tmp.curr_add == l.back().next_add)
		{
			l.push_back(tmp);
			q.pop();
			if (tmp.next_add == -1)
				break;
		}
		else
		{
			q.push(tmp);
			q.pop();
		}

	}



	list<node> l1, l2;//存放结果

	int hash_table[10001] = { 0 };
	for (list<node>::iterator p = l.begin(); p != l.end(); p++)
	{
		if (hash_table[abs(p->data)] == 0)//如果之前它或它的绝对值不存在，插入链1，并设置其hash值为1，表示已出现
		{
			hash_table[abs(p->data)] = 1;
			l1.push_back(*p);
		}
		else//如果之前它或它的绝对值存在，插入链2
		{
			l2.push_back(*p);

		}
	}


	//修改每个节点的next_add
	list<node>::iterator p;
	for (p = l1.begin(); p != --(l1.end()); p++)
	{
		int add = (++p)->curr_add;
		p--;
		p->next_add = add;
	}
	//最后一个结点单独处理
	p->next_add = -1;
	for (p = l2.begin(); p != --(l2.end()); p++)
	{
		int add = (++p)->curr_add;
		p--;
		p->next_add = add;
	}
	//最后一个结点单独处理
	p->next_add = -1;



	//输出
	for (list<node>::iterator p = l1.begin(); p != --(l1.end()); p++)
	{
		printf("%05d %d %05d\n", p->curr_add, p->data, p->next_add);
	}
	//最后一个结点单独输出
	printf("%05d %d %d", l1.back().curr_add, l1.back().data, l1.back().next_add);

	if (!l2.empty())
	{
		printf("\n");
		for (list<node>::iterator p = l2.begin(); p != --(l2.end()); p++)
		{
			printf("%05d %d %05d\n", p->curr_add, p->data, p->next_add);
		}
		//最后一个结点单独输出
		printf("%05d %d %d", l2.back().curr_add, l2.back().data, l2.back().next_add);

	}

	
	system("pause");
	return 0;
}
