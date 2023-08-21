#include"PTree.h"


//创建一个空树
void PTreeInit(PTree* PT)
{
	PT->n = 0;
	PT->root = 0;
	PT->nodes->data = 0;
	PT->nodes->parent = -1;
}

//按自己的定义构造一个树
void PTreeCreate(PTree* PT)
{

	assert(PT);
	int i = 0;

	printf("请输入该树的节点数:>");
	scanf("%d", &(PT->n));
	if (PT->n > MAX_TREE_SIZE)
	{
		printf("节点数超出数组的大小\n");
		exit(-1);
	}

	for (i = 0; i < PT->n; i++)
	{
		fflush(stdin);			//清空输入缓冲区
		printf("请输入第%d个节点的数据;>", i + 1);
		scanf("%c", &(PT->nodes[i].data));
		printf("请输入第%d个节点的双亲节点数组的下标:>", i + 1);
		scanf("%d", &(PT->nodes[i].parent));
		printf("\n");
	}

	for (i = 0; i < PT->n; i++)
	{
		PT->nodes[i].firstchild = -1;
		PT->nodes[i].rightchild = -1;
	}



	int flag = -1;
	for (i = 1; i < PT->n; i++)
	{
		if ( flag == -1)
		{	
			flag = i;								//第一次  因为一个双亲只能有一个长子
			int parent = PT->nodes[i].parent;		//当前双亲的下标
			PT->nodes[parent].firstchild = i ;		// 把自己的下标 给了 双亲的长子域
		}
		else
		{
			if (PT->nodes[i].parent == PT->nodes[i - 1].parent)
			{
				PT->nodes[i - 1].rightchild = i;
			}
			else
			{
				int parent = PT->nodes[i].parent;
				PT->nodes[parent].firstchild = i;
			}
		}


	}

}

//打印树
void PTreePrint(PTree* PT)
{
	int i = 0;
	for (i = 0; i < PT->n; i++)
	{
		//如果该节点无数据 则data   = -1 自己定义的。
		if (PT->nodes[i].data != -1)
		{
			printf("%c ", PT->nodes[i].data);
		}
	}
	printf("\n");



}






//判断此树是否为空
bool PTreeEmpty(PTree* PT)
{
	return PT->n == 0;
}

//找到这个数据在节点中的位置
PTNode* PTreeFind(PTree* PT, TElemType cur)
{
	int i = 0;
	for (i = 0; i < PT->n; i++)
	{
		if (PT->nodes[i].data == cur)
		{
			return &PT->nodes[i];
		}
	}
	printf("找不到%c在树中的位置",cur);
	return NULL;
}


//返回当前节点的值
int PTreeVal(PTree* PT, int n)
{
	assert(n <= PT->n);
	return PT->nodes[n - 1].data;
}


//给当前cur节点赋值
void PTreeAssign(PTree* PT, TElemType cur, TElemType value)
{
	int i = 0;
	for (i = 0; i < PT->n; i++)
	{
		if (PT->nodes[i].data == cur)
		{
			PT->nodes[i].data = value;
		}
	}
	
}

//返回此节点的双亲，否则返回空
PTNode* PTreeparent(PTree* PT, TElemType cur)
{
	int i = 0;
	for (i = 0; i < PT->n; i++)
	{
		if (PT->nodes[i].data == cur)
		{
			return &PT->nodes[PT->nodes[i].parent];
		}
	}

	printf("找不到该节点双亲\n");
	return NULL;
}

//若cur是树的非叶节点，则返回他的左孩子（长子域）否则返回空
PTNode* PTreeFristChild(PTree* PT, TElemType cur)
{
	int i = 0;
	for (i = 0; i < PT->n; i++)
	{
		if (PT->nodes[i].data == cur)
		{
			if (PT->nodes[i].firstchild == -1)
			{
				printf("操作失败该节点为叶节点\n");
				exit(-1);
			}
			return &PT->nodes[PT->nodes[i].firstchild];

		}
	}
	
	printf("找不到该节点的长子\n");
	return NULL;
}


//若cur有右兄弟，则返回它的有兄弟否则返回空
PTNode* PTreeRightSibling(PTree* PT, TElemType cur)
{

	int i = 0;
	for (i = 0; i < PT->n; i++)
	{
		if (PT->nodes[i].data == cur)
		{
			if (PT->nodes[i].rightchild != -1)
			{
				return &PT->nodes[PT->nodes[i].rightchild]; 
			}
			else
			{
				printf("该节点没有右兄第\n");
				return NULL;
			}
		}
	}
	printf("找不到该节点在树中的位置\n");
	return NULL;
}


// 销毁一个树
void PTreeDestroy(PTree* PT)
{
	int i = (PT->n) - 1;
	for (i = (PT->n) - 1; i >= 0; i--)
	{
		PT->nodes[i].data = -1;
		PT->nodes[i].parent = -1;
		PT->nodes[i].firstchild = -1;
		PT->nodes[i].rightchild = -1;
	}

	PT->n = 0;
	PT->root = 0;
	PT = NULL;
}


//在PTN当前节点节点处 选择第  i  课子树插入
void PTreeInsertChild(PTree* PT, PTNode* PTN, int i, TElemType c)
{
	assert(PT);
	assert(PT->n < MAX_TREE_SIZE);
	//总节点的个数 正好是数组中下一个元素的下标
	//初始化
	PT->nodes[PT->n].data = c;
	PT->nodes[PT->n].firstchild = -1;
	PT->nodes[PT->n].rightchild = -1;
	PT->nodes[PT->n].parent= -1;

	PTNode* cur = PTN;
	PTNode* newnode = &PT->nodes[PT->n];
	//1.判断是否是插入长子域
	if (i == 1)
	{
		//判断该节点是否是叶子
		if (cur->firstchild != -1)
		{
			newnode->rightchild = cur->firstchild;
			newnode->parent = PT->nodes[cur->firstchild].parent;
			cur->firstchild = PT->n;
		}
		else
		{
			cur->firstchild = PT->n;
		}
	}
	else
	{
		cur = PTNodeFind(PT, cur, i);
		newnode->rightchild = cur->rightchild;
		cur->rightchild = PT->n;
		newnode->parent = cur->parent;
	}

	PT->n++;

}

//void PTNodeDel(PTNode* del)
//{
//	if (del->firstchild != -1 || del->rightchild != -1)
//	{
//
//	}
//
//}

//在PTN当前节点出			删除第  i 棵子树
void PTreeDeltetChild(PTree* PT, PTNode* PTN, int i)
{
	assert(PT);
	assert(PT->n);// 这个树不能为空
	assert(PTN->firstchild != -1);//该节点不能没有长子域


	PTNode* del = NULL;
	//是否为长子域
	if (i == 1)
	{
		// 要删除的位置为该节点的长子域
		del = &PT->nodes[PTN->firstchild];
		//判断是否有右兄弟
		if (PT->nodes[PTN->firstchild].rightchild == -1)//只有长子
		{
			PTN->firstchild = -1;
		}
		else//除了长子 还有其他
		{
			PTN->firstchild = PT->nodes[PTN->firstchild].rightchild;
		}

	}
	else
	{
		PTNode* cur = PTN;
		cur = PTNodeFind(PT, cur, i);// 找到的是删除的前一个位置
		//要删除的位置为cur的后一个位置
		del = &PT->nodes[cur->rightchild];

		cur->rightchild = del->rightchild;

	}

	del->data = -1;
	del->firstchild = -1;
	del->rightchild = -1;
	del->parent = -1;

	////删除
	//if (del->firstchild == -1)		//说明该位置为叶子
	//{
	//	del->data = -1;
	//	del->firstchild = -1;
	//	del->rightchild = -1;
	//	del->parent = -1;
	//}
	//else							//说明该位置还有分支，
	//{
	//	//需要递归删除
	//	PTNodeDel(del);
	//}






}



//
//增删时 找出位置
PTNode* PTNodeFind(PTree* PT, PTNode* cur, int i)
{
	int count = 0; // 计算第 i-1 个位置是否到了
	int flag = 0;
	for (count = 0; count < i - 1; count++)
	{
		//这个只进去1次 因为是长子
		if (cur->firstchild != -1 && flag == 0)
		{
			flag = 1;
			cur = &PT->nodes[cur->firstchild];
		}
		else
		{
			if (cur->rightchild == -1)
			{
				printf("位置不合理\n");
				exit(-1);
			}
			cur = &PT->nodes[cur->rightchild];
		}
	}
	return cur;
}