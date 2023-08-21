#include"PTree.h"

void TestPTree1()
{
	PTree T;
	PTreeInit(&T);

	PTreeCreate(&T);
	
	int node = 0;
	TElemType cur = 0;
	printf("������ڼ����ڵ�:>");
	scanf("%d",&node);
	cur = PTreeVal(&T, node);
	printf("�ýڵ��޸�ǰ��ֵΪ%c\n", PTreeVal(&T, node));
	PTreeAssign(&T, cur, 'K');
	printf("�ýڵ��޸ĺ��ֵΪ%c\n", PTreeVal(&T, node));
	cur = PTreeVal(&T, node);
	printf("�ýڵ��˫��Ϊ:%c\n",*PTreeparent(&T,cur));
	printf("�ýڵ�ĳ���Ϊ:%c\n", *PTreeFristChild(&T, cur));
	printf("�ýڵ�����ֵ�Ϊ:%c\n", *PTreeRightSibling(&T, cur));

	PTreeDestroy(&T);
}

void TestPTree2(){
	PTree T;
	PTreeInit(&T);

	PTreeCreate(&T);

	PTreePrint(&T);

	PTNode* cur = PTreeFind(&T, 'D');

	///*PTreeInsertChild(&T, cur, 1, 'K');
	//PTreeInsertChild(&T, cur, 2, 'O');
	//PTreeInsertChild(&T, cur, 3, 'N');
	//PTreeInsertChild(&T, cur, 4, 'G');
	//PTreeInsertChild(&T, cur, 3, 'K');*/
	//PTreeInsertChild(&T, cur, 3, 'K');
	//PTreePrint(&T);

	PTreeDeltetChild(&T, cur, 1);
	PTreeDeltetChild(&T, cur, 1);
	PTreeDeltetChild(&T, cur, 1);


	PTreePrint(&T);
}

void TestPTree3()
{
	PTree T;
	PTreeInit(&T);

	PTreeCreate(&T);

	PTreePrint(&T);

	PTNode* cur = PTreeFind(&T, 'D');

	PTreeDeltetChild(&T, cur, 1);
	PTreeDeltetChild(&T, cur, 1);
	PTreeDeltetChild(&T, cur, 1);

	PTreePrint(&T);

}

int main()
{
	//TestPTree1();
	//TestPTree2();
	TestPTree3();
	return 0;
}