#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

struct node
{
	int curr_add;//结点自身地址
	int data;
	int next_add;//下一个结点地址
};

int main()
{
	int start_add, total_number, length;
	scanf("%d %d %d", &start_add, &total_number, &length);

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


	list<node> new_list;
	list<node> single;//将原链表拆分成长为length的部分链表
	for (list<node>::iterator p = l.begin(); p != l.end(); p++)
	{
		single.push_back(*p);
		if (single.size() == length||p == --l.end())
		{
			if(single.size()==length)//如果部分链长为要求逆转长度则逆转，最后不足length的不用逆转
				single.reverse();//每个部分链表逆转
			new_list.splice(new_list.end(), single);//拼接到结果链表中
			single.clear();//清空以作下次使用
		}

	}


	//修改每个节点的next_add
	list<node>::iterator p;
	for (p = new_list.begin(); p != --(new_list.end());p++)
	{
		int add = (++p)->curr_add;
		p--;
		p->next_add = add;
	}
	//最后一个结点单独处理
	p->next_add = -1;


	//输出
	for (list<node>::iterator p = new_list.begin(); p !=--(new_list.end());p++)
	{
		printf("%05d %d %05d\n", p->curr_add, p->data, p->next_add);
	}

	//最后一个结点单独输出
	printf("%05d %d %d", new_list.back().curr_add, new_list.back().data, new_list.back().next_add);

	system("pause");
	return 0;
}
