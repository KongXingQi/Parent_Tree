#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define MAX_TREE_SIZE 15

typedef char TElemType;

//˫�ױ�ʾ��  PT ��parent����д��   ��̬�����δ洢�ṹ �鷳��������������������������������������������������
//����ṹ�б׶�   �ر���ɾ����ʱ�� ����û�еݹ�ɾ��������֮ ��β�û��ʹ�ڵ������� ����������ѽڵ������� ���ٴ�ӡԭ���ı�����PTreeTest3�еĽṹ���
//																						ֻɾ����3�� �����ڽڵ�ļ��� �һ��Ǳ������� ����Ϊ���ٴ�ӡ��


typedef struct					//�ڵ�ṹ
{
	TElemType data;				//�ýڵ������
	int parent;					//�ýڵ�˫�׵�λ��
	int firstchild;
	int rightchild;
}PTNode;


typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];	//�ڵ�����
	int root, n;					//����λ�� �ͽڵ���
}PTree;






//����һ������
void PTreeInit(PTree* PT);

//���Լ��Ķ��幹��һ����
void PTreeCreate(PTree* PT);

//��ӡ��
void PTreePrint(PTree* PT);

//�жϴ����Ƿ�Ϊ��
bool PTreeEmpty(PTree* PT);

//�����������
int PTreeDepth(PTree* PT);

//�ҵ���������ڽڵ��е�λ��
PTNode* PTreeFind(PTree* PT, TElemType cur);

//���ص�ǰ�ڵ��ֵ
int PTreeVal(PTree* PT,int n);

//����ǰcur�ڵ㸳ֵ
void PTreeAssign(PTree* PT,TElemType cur,TElemType value);

//���ش˽ڵ��˫�ף����򷵻ؿ�
PTNode* PTreeparent(PTree* PT,TElemType cur);

//��cur�����ķ�Ҷ�ڵ㣬�򷵻��������ӣ������򣩷��򷵻ؿ�
PTNode* PTreeFristChild(PTree* PT, TElemType cur);

//��cur�����ֵܣ��򷵻��������ֵܷ��򷵻ؿ�
PTNode* PTreeRightSibling(PTree* PT, TElemType cur);

//��PTN��ǰ�ڵ�ڵ㴦		ѡ���  i  ����������
void PTreeInsertChild(PTree* PT, PTNode* PTN, int i, TElemType c);

//��PTN��ǰ�ڵ㴦			ɾ����  i ������
void PTreeDeltetChild(PTree* PT, PTNode* PTN,int i);


// ����һ����
void PTreeDestroy(PTree* PT);

//----------------------------------------------------------------------------------------
//����С����

//��ɾʱ �ҳ�λ��  ע���ҵ�����i ��ǰһ��λ�� �������������ɾ
PTNode* PTNodeFind(PTree* PT,PTNode* cur,int i);