#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct BiTNode
{
	int data;
	BiTNode *lchild, *rchild;
	BiTNode(int value)//给定根节点值得构造函数
	{
		this->data = value;
		this->lchild = NULL;
		this->rchild = NULL;
	}
};

//构造二叉树
BiTNode* create_post_in(int *post, int *in, int n)
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (*post != *(in + k))//在中序序列找到根节点（前序第一个元素）
		k++;
	BiTNode* root = new BiTNode(*post);//创建根节点
	root->rchild = create_post_in(post - 1, in + k + 1, n - k - 1);//创建右子树
	root->lchild = create_post_in(post - n + k, in, k);//创建左子树
	return root;
}

int main()
{
	int N;
	scanf("%d", &N);
	int *a = new int[N];//post_oder
	int *b = new int[N];//in_oder
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &b[i]);
	int *post = a + N - 1;
	int *in = b;
	BiTNode* result = create_post_in(post, in, N);

	vector<int> v;

  //层次遍历输出
	queue<BiTNode*> q;
	BiTNode* p;
	q.push(result);//根节点入队
	while (!q.empty())
	{
		p = q.front();
		v.push_back(p->data);
		q.pop();
		if (p->lchild != NULL)
			q.push(p->lchild);
		if (p->rchild != NULL)
			q.push(p->rchild);
	}

	for (int i = 0; i < v.size(); i++)
	{
		printf("%d", v[i]);
		if (i != v.size() - 1)
			printf(" ");
	}

	return 0;
}
