#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define MAX_TREE_SIZE 15

typedef char TElemType;

//双亲表示法  PT 是parent的缩写。   静态的树形存储结构 麻烦！！！！！！！！！！！！！！！！！！！！！！！！！
//这个结构有弊端   特别是删除的时候 首先没有递归删除整个分之 其次并没有使节点数减少 ，因我如果把节点数减少 会少打印原来的比如在PTreeTest3中的结构如此
//																						只删除了3个 但由于节点的减少 且还是遍历数组 所以为减少打印的


typedef struct					//节点结构
{
	TElemType data;				//该节点的数据
	int parent;					//该节点双亲的位置
	int firstchild;
	int rightchild;
}PTNode;


typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];	//节点数组
	int root, n;					//根的位置 和节点数
}PTree;






//构造一个空树
void PTreeInit(PTree* PT);

//按自己的定义构造一个树
void PTreeCreate(PTree* PT);

//打印树
void PTreePrint(PTree* PT);

//判断此树是否为空
bool PTreeEmpty(PTree* PT);

//返回树的深度
int PTreeDepth(PTree* PT);

//找到这个数据在节点中的位置
PTNode* PTreeFind(PTree* PT, TElemType cur);

//返回当前节点的值
int PTreeVal(PTree* PT,int n);

//给当前cur节点赋值
void PTreeAssign(PTree* PT,TElemType cur,TElemType value);

//返回此节点的双亲，否则返回空
PTNode* PTreeparent(PTree* PT,TElemType cur);

//若cur是树的非叶节点，则返回他的左孩子（长子域）否则返回空
PTNode* PTreeFristChild(PTree* PT, TElemType cur);

//若cur有右兄弟，则返回它的有兄弟否则返回空
PTNode* PTreeRightSibling(PTree* PT, TElemType cur);

//在PTN当前节点节点处		选择第  i  棵子树插入
void PTreeInsertChild(PTree* PT, PTNode* PTN, int i, TElemType c);

//在PTN当前节点处			删除第  i 棵子树
void PTreeDeltetChild(PTree* PT, PTNode* PTN,int i);


// 销毁一个树
void PTreeDestroy(PTree* PT);

//----------------------------------------------------------------------------------------
//公用小函数

//增删时 找出位置  注意找到的是i 的前一个位置 这样方便进行增删
PTNode* PTNodeFind(PTree* PT,PTNode* cur,int i);