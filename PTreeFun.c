#include"PTree.h"


//����һ������
void PTreeInit(PTree* PT)
{
	PT->n = 0;
	PT->root = 0;
	PT->nodes->data = 0;
	PT->nodes->parent = -1;
}

//���Լ��Ķ��幹��һ����
void PTreeCreate(PTree* PT)
{

	assert(PT);
	int i = 0;

	printf("����������Ľڵ���:>");
	scanf("%d", &(PT->n));
	if (PT->n > MAX_TREE_SIZE)
	{
		printf("�ڵ�����������Ĵ�С\n");
		exit(-1);
	}

	for (i = 0; i < PT->n; i++)
	{
		fflush(stdin);			//������뻺����
		printf("�������%d���ڵ������;>", i + 1);
		scanf("%c", &(PT->nodes[i].data));
		printf("�������%d���ڵ��˫�׽ڵ�������±�:>", i + 1);
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
			flag = i;								//��һ��  ��Ϊһ��˫��ֻ����һ������
			int parent = PT->nodes[i].parent;		//��ǰ˫�׵��±�
			PT->nodes[parent].firstchild = i ;		// ���Լ����±� ���� ˫�׵ĳ�����
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

//��ӡ��
void PTreePrint(PTree* PT)
{
	int i = 0;
	for (i = 0; i < PT->n; i++)
	{
		//����ýڵ������� ��data   = -1 �Լ�����ġ�
		if (PT->nodes[i].data != -1)
		{
			printf("%c ", PT->nodes[i].data);
		}
	}
	printf("\n");



}






//�жϴ����Ƿ�Ϊ��
bool PTreeEmpty(PTree* PT)
{
	return PT->n == 0;
}

//�ҵ���������ڽڵ��е�λ��
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
	printf("�Ҳ���%c�����е�λ��",cur);
	return NULL;
}


//���ص�ǰ�ڵ��ֵ
int PTreeVal(PTree* PT, int n)
{
	assert(n <= PT->n);
	return PT->nodes[n - 1].data;
}


//����ǰcur�ڵ㸳ֵ
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

//���ش˽ڵ��˫�ף����򷵻ؿ�
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

	printf("�Ҳ����ýڵ�˫��\n");
	return NULL;
}

//��cur�����ķ�Ҷ�ڵ㣬�򷵻��������ӣ������򣩷��򷵻ؿ�
PTNode* PTreeFristChild(PTree* PT, TElemType cur)
{
	int i = 0;
	for (i = 0; i < PT->n; i++)
	{
		if (PT->nodes[i].data == cur)
		{
			if (PT->nodes[i].firstchild == -1)
			{
				printf("����ʧ�ܸýڵ�ΪҶ�ڵ�\n");
				exit(-1);
			}
			return &PT->nodes[PT->nodes[i].firstchild];

		}
	}
	
	printf("�Ҳ����ýڵ�ĳ���\n");
	return NULL;
}


//��cur�����ֵܣ��򷵻��������ֵܷ��򷵻ؿ�
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
				printf("�ýڵ�û�����ֵ�\n");
				return NULL;
			}
		}
	}
	printf("�Ҳ����ýڵ������е�λ��\n");
	return NULL;
}


// ����һ����
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


//��PTN��ǰ�ڵ�ڵ㴦 ѡ���  i  ����������
void PTreeInsertChild(PTree* PT, PTNode* PTN, int i, TElemType c)
{
	assert(PT);
	assert(PT->n < MAX_TREE_SIZE);
	//�ܽڵ�ĸ��� ��������������һ��Ԫ�ص��±�
	//��ʼ��
	PT->nodes[PT->n].data = c;
	PT->nodes[PT->n].firstchild = -1;
	PT->nodes[PT->n].rightchild = -1;
	PT->nodes[PT->n].parent= -1;

	PTNode* cur = PTN;
	PTNode* newnode = &PT->nodes[PT->n];
	//1.�ж��Ƿ��ǲ��볤����
	if (i == 1)
	{
		//�жϸýڵ��Ƿ���Ҷ��
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

//��PTN��ǰ�ڵ��			ɾ����  i ������
void PTreeDeltetChild(PTree* PT, PTNode* PTN, int i)
{
	assert(PT);
	assert(PT->n);// ���������Ϊ��
	assert(PTN->firstchild != -1);//�ýڵ㲻��û�г�����


	PTNode* del = NULL;
	//�Ƿ�Ϊ������
	if (i == 1)
	{
		// Ҫɾ����λ��Ϊ�ýڵ�ĳ�����
		del = &PT->nodes[PTN->firstchild];
		//�ж��Ƿ������ֵ�
		if (PT->nodes[PTN->firstchild].rightchild == -1)//ֻ�г���
		{
			PTN->firstchild = -1;
		}
		else//���˳��� ��������
		{
			PTN->firstchild = PT->nodes[PTN->firstchild].rightchild;
		}

	}
	else
	{
		PTNode* cur = PTN;
		cur = PTNodeFind(PT, cur, i);// �ҵ�����ɾ����ǰһ��λ��
		//Ҫɾ����λ��Ϊcur�ĺ�һ��λ��
		del = &PT->nodes[cur->rightchild];

		cur->rightchild = del->rightchild;

	}

	del->data = -1;
	del->firstchild = -1;
	del->rightchild = -1;
	del->parent = -1;

	////ɾ��
	//if (del->firstchild == -1)		//˵����λ��ΪҶ��
	//{
	//	del->data = -1;
	//	del->firstchild = -1;
	//	del->rightchild = -1;
	//	del->parent = -1;
	//}
	//else							//˵����λ�û��з�֧��
	//{
	//	//��Ҫ�ݹ�ɾ��
	//	PTNodeDel(del);
	//}






}



//
//��ɾʱ �ҳ�λ��
PTNode* PTNodeFind(PTree* PT, PTNode* cur, int i)
{
	int count = 0; // ����� i-1 ��λ���Ƿ���
	int flag = 0;
	for (count = 0; count < i - 1; count++)
	{
		//���ֻ��ȥ1�� ��Ϊ�ǳ���
		if (cur->firstchild != -1 && flag == 0)
		{
			flag = 1;
			cur = &PT->nodes[cur->firstchild];
		}
		else
		{
			if (cur->rightchild == -1)
			{
				printf("λ�ò�����\n");
				exit(-1);
			}
			cur = &PT->nodes[cur->rightchild];
		}
	}
	return cur;
}