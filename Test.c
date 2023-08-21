#include"PTree.h"

void TestPTree1()
{
	PTree T;
	PTreeInit(&T);

	PTreeCreate(&T);
	
	int node = 0;
	TElemType cur = 0;
	printf("请输入第几个节点:>");
	scanf("%d",&node);
	cur = PTreeVal(&T, node);
	printf("该节点修改前的值为%c\n", PTreeVal(&T, node));
	PTreeAssign(&T, cur, 'K');
	printf("该节点修改后的值为%c\n", PTreeVal(&T, node));
	cur = PTreeVal(&T, node);
	printf("该节点的双亲为:%c\n",*PTreeparent(&T,cur));
	printf("该节点的长子为:%c\n", *PTreeFristChild(&T, cur));
	printf("该节点的右兄弟为:%c\n", *PTreeRightSibling(&T, cur));

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