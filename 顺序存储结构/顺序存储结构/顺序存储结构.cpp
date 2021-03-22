// 顺序存储结构.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "pch.h"
#include <iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
typedef int status;
typedef int ElemType; //数据元素类型定义
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define LISTNUM 10

typedef struct { //顺序表（顺序结构）的定义
	ElemType * elem = NULL;
	int length;
	int listsize;
}SqList;

status InitList(SqList& L);
status DestroyList(SqList& L);
status ClearList(SqList&L);
status ListEmpty(SqList L);
status ListLength(SqList L);
status GetElem(SqList L, int i, ElemType & e);
status LocateElem(SqList L, ElemType e); //简化过
status PriorElem(SqList L, ElemType cur, ElemType&pre_e);
status NextElem(SqList L, ElemType cur, ElemType&next_e);
status ListInsert(SqList&L, int i, ElemType e);
status ListDelete(SqList&L, int i, ElemType& e);
status ListTraverse(SqList L); //简化过
status ListSave(SqList L);
status ListRead(SqList &L);
/*--------------------------------------------*/
int main(void) {
	SqList L[LISTNUM];
	int op = 1;
	int id = 0;
	int e;//数据元素的值
	int i;//数据元素的位置
	ElemType pre_e = NULL;
	ElemType next_e = NULL;
	while (op) {
		system("cls"); printf("\n\n");
		printf(" Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf(" 1. InitList     7. LocateElem\n");
		printf(" 2. DestroyList  8. PriorElem\n");
		printf(" 3. ClearList    9. NextElem \n");
		printf(" 4. ListEmpty   10. ListInsert\n");
		printf(" 5. ListLength  11. ListDelete\n");
		printf(" 6. GetElem     12. ListTraverse\n\n");
		printf("13.ListSave\n");
		printf("14.ListRead\n\n");
		printf(" 0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("请选择你要操作的线性表(1~%d)：",LISTNUM);
		scanf_s("%d", &id);
		if (id > 10 || id < 1) {
			printf("请输入正确的线性表序号！\n");
			getchar();getchar();
			continue;
		}
		id--;
		printf("请选择你的操作[0~14]:");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			if (InitList(L[id]) == OK) printf("线性表创建成功！\n");
			getchar();getchar();
			break;
		case 2:
			if (DestroyList(L[id]) == OK)printf("删除线性表成功！\n");
			else printf("删除线性表失败！\n");
			getchar();getchar();
			break;
		case 3:
			if (ClearList(L[id]) == OK)printf("清除线性表成功！\n");
			else printf("清除线性表失败！\n");
			getchar();getchar();
			break;
		case 4:
			if (ListEmpty(L[id]) == TRUE)printf("TRUE!\n");
			else printf("FALSE！\n");
			getchar();getchar();
			break;
		case 5:
			if (ListLength(L[id]))printf("求线性表数据元素个数成功！\n");
			else printf("求线性表数据元素个数失败！\n");
			getchar();getchar();
			break;
		case 6:
			if (!L[id].elem) {
				printf("该线性表不存在！\n");
				printf("获取数据元素失败！\n");
				getchar();getchar();
				break;
			}
			if (!L[id].length) {
				printf("该线性表是空表！\n");
				printf("没有可获取的数据元素！\n");
				getchar();getchar();
				break;
			}
			printf("请输入所需数据元素的位置(1~%d)：", L[id].length);
			scanf_s("%d", &i);
			if (GetElem(L[id], i, e))printf("成功获得第%d个数据元素！\n", i);
			else printf("请输入数据元素的正确位置！\n");
			getchar();getchar();
			break;
		case 7:
			if (!L[id].elem) {
				printf("该线性表不存在！\n");
				printf("查找数据元素位置失败！\n");
				getchar();getchar();
				break;
			}
			if (!L[id].length) {
				printf("该线性表是空表！\n");
				printf("没有数据元素可供查找！\n");
				getchar();getchar();
				break;
			}
			printf("请输入需要查找的数据元素数值：");
			scanf_s("%d", &e);
			if (LocateElem(L[id], e))printf("成功查到数据元素%d在该线性表中的位置！\n", e);
			else printf("查找结束！\n");
			getchar();getchar();
			break;
		case 8:
			if (!L[id].elem) {
				printf("该线性表不存在！\n");
				printf("获取数据元素前驱失败！\n");
				getchar();getchar();
				break;
			}
			if (!L[id].length) {
				printf("该线性表是空表！\n");
				printf("获取数据元素前驱失败！\n");
				getchar();getchar();
				break;
			}
			printf("请输入需要查找前驱的数据元素数值：");
			scanf_s("%d", &e);
			if (PriorElem(L[id], e, pre_e))printf("成功查到数据元素%d的前驱！\n", e);
			else printf("查找结束！\n");
			getchar();getchar();
			break;
		case 9:
			if (!L[id].elem) {
				printf("该线性表不存在！\n");
				printf("获取数据元素后继失败！\n");
				getchar();getchar();
				break;
			}
			if (!L[id].length) {
				printf("该线性表是空表！\n");
				printf("获取数据元素后继失败！\n");
				getchar();getchar();
				break;
			}
			printf("请输入需要查找后继的数据元素数值：");
			scanf_s("%d", &e);
			if (NextElem(L[id], e, next_e))printf("成功查到数据元素%d的后继！\n", e);
			else printf("查找结束！\n");
			getchar();getchar();
			break;
		case 10:
			if (!L[id].elem) {
				printf("该线性表不存在！\n");
				printf("插入数据元素失败！\n");
			}
			else {
				printf("请输入要插入的数据元素：");
				scanf_s("%d", &e);
				printf("请输入要插入的位置(1~%d)：", L[id].length + 1);
				scanf_s("%d", &i);
				if (ListInsert(L[id], i, e))printf("插入数据元素成功！\n");
				else printf("插入数据元素失败！\n");
			}
			getchar();getchar();
			break;
		case 11:
			if (!L[id].elem) {
				printf("该线性表不存在！\n");
				printf("删除数据元素失败！\n");
			}
			else {
				if (!L[id].length) {
					printf("该线性表是空表！\n");
					printf("没有可删除的数据元素！\n");
					getchar();getchar();
					break;
				}
				else {
					printf("请输入要删除的位置(1~%d)：", L[id].length);
					scanf_s("%d", &i);
					if (ListDelete(L[id], i, e))printf("删除数据元素成功！\n");
					else printf("删除数据元素失败！\n");
				}
			}
			getchar();getchar();
			break;
		case 12:
			if (ListTraverse(L[id])) printf("已遍历该线性表！\n");
			else printf("遍历失败！\n");
			getchar();getchar();
			break;
		case 13:
			if (ListSave(L[id])) printf("线性表写入文件成功！\n");
			else printf("线性表写入文件失败！\n");
			getchar();getchar();
			break;
		case 14:
			if (ListRead(L[id])) printf("线性表文件读取成功！\n");
			else printf("读取线性表文件失败！\n");
			getchar();getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
}//end of main()

/********************************************************************/
/*
函数功能：初始化表
传入参数：结构变量L的引用。
时间复杂度是O(1)。空间复杂度是O(1)。
*/
/********************************************************************/
status InitList(SqList& L) {
	if (!L.elem) {
		L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
		L.length = 0;
		L.listsize = LIST_INIT_SIZE;
		return OK;
	}
	else {
		printf("该线性表已存在！\n");
		return ERROR;
	}
}

/********************************************************************/
/*
函数功能：销毁表
传入参数：结构变量L的引用。
时间复杂度是O(1)。空间复杂度是O(1)。
*/
/********************************************************************/
status DestroyList(SqList& L) {
	if (L.elem) {
		free(L.elem);
		L.elem = NULL;
		L.length = 0;
		L.listsize = 0;
		return OK;
	}
	else {
		printf("该线性表不存在！\n");
		return ERROR;
	}
}

/********************************************************************/
/*
函数功能：清空表
传入参数：结构变量L的引用。
时间复杂度是O(n)。空间复杂度是O(1)。
*/
/********************************************************************/
status ClearList(SqList&L) {
	if (!L.elem) {
		printf("该线性表不存在！\n");
		return ERROR;
	}
	else {
		for (int i = 0;i < L.length;i++)
		{
			L.elem[i] = 0;
		}
		L.length = 0;
		return OK;
	}
}

/********************************************************************/
/*
函数功能：判定空表
传入参数：结构变量L的值。
时间复杂度是O(1)。空间复杂度是O(1)。
*/
/********************************************************************/
status ListEmpty(SqList L) {
	if (!L.elem) {
		printf("该线性表不存在！\n");
		return ERROR;
	}
	else {
		if (L.length) {
			printf("该线性表不为空! \n");
			return TRUE;
		}
		else {
			printf("该线性表为空! \n");
			return FALSE;
		}
	}
}

/********************************************************************/
/*
函数功能：求表长
传入参数：结构变量L的值。
时间复杂度是O(1)。空间复杂度是O(1)。
*/
/********************************************************************/
status ListLength(SqList L) {
	if (!L.elem) {
		printf("该线性表不存在！\n");
		return ERROR;
	}
	else {
		printf("该线性表的数据元素个数为：%d \n", L.length);
		return OK;
	}
}

/********************************************************************/
/*
函数功能：获取元素
传入参数：结构变量L的值。元素位置i，元素e的引用。
时间复杂度是O(1)。空间复杂度是O(1)。
*/
/********************************************************************/
status GetElem(SqList L, int i, ElemType & e) {
	if (i<1 || i>L.length) {
		printf("该线性表没有第%d个元素！\n", i);//考虑周全！
		return ERROR;
	}
	else {
		e = L.elem[i - 1];
		printf("该线性表第%d个元素：%d \n", i, e);
		return OK;
	}
}

/********************************************************************/
/*
函数功能：查找元素
传入参数：结构变量L的值。元素值e。
时间复杂度是O(n)。空间复杂度是O(1)。
*/
/********************************************************************/
status LocateElem(SqList L, ElemType e) {
	for (int i = 0;i < L.length;i++) {
		if (e == L.elem[i]) {
			printf("元素%d在该线性表第%d位! \n", e, i + 1);
			return OK;
		}
	}
	printf("该线性表不存在元素%d！\n", e);
	return ERROR;
}

/********************************************************************/
/*
函数功能：获得前驱
传入参数：结构变量L的值。元素值cur，元素pre_e的引用。
时间复杂度是O(n)。空间复杂度是O(1)。
*/
/********************************************************************/
status PriorElem(SqList L, ElemType cur, ElemType&pre_e) {
	for (int i = 1;i < L.length;i++) {
		if (cur == L.elem[i]) {
			pre_e = L.elem[i - 1];
			printf("元素%d的前驱是：%d \n", cur, pre_e);
			return OK;
		}
	}
	printf("元素%d的前驱不存在！\n", cur);
	return ERROR;
}

/********************************************************************/
/*
函数功能：获得后继
传入参数：结构变量L的值。元素值cur，元素next_e的引用。
时间复杂度是O(n)。空间复杂度是O(1)。
*/
/********************************************************************/
status NextElem(SqList L, ElemType cur, ElemType&next_e) {
	for (int i = 0;i < L.length - 1;i++) {
		if (cur == L.elem[i]) {
			next_e = L.elem[i + 1];
			printf("元素%d的后继是：%d \n", cur, next_e);
			return OK;
		}
	}
	printf("元素%d的后继不存在！\n", cur);
	return ERROR;
}

/********************************************************************/
/*
函数功能：插入元素
传入参数：结构变量L的引用。元素插入位置i，插入元素值e。
时间复杂度是O(n)。空间复杂度是O(1)。
*/
/********************************************************************/
status ListInsert(SqList&L, int i, ElemType e) {
	int j;
	if (i<1 || i>L.length + 1) {
		printf("请输入正确的插入位置！\n");
		return ERROR;
	}
	if (L.length >= L.listsize)    //溢出时扩充
	{
		ElemType *newbase;
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (newbase == NULL) {
			printf("内存空间不足！\n");
			return OVERFLOW;   //扩充失败
		}
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	//向后移动元素，空出第i个元素的分量elem[i-1]
	for (j = L.length - 1;j >= i - 1;j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;                   //新元素插入
	L.length++;                      //线性表长度加1
	return OK;
}

/********************************************************************/
/*
函数功能：删除元素
传入参数：结构变量L的引用。要删除的元素的位置i，删除的元素值e的引用。
时间复杂度是O(n)。空间复杂度是O(1)。
*/
/********************************************************************/
status ListDelete(SqList&L, int i, ElemType& e) {
	int j;
	if (i<1 || i>L.length) {
		printf("请输入正确的删除位置！\n");
		return ERROR;
	}
	e = L.elem[i - 1];                   //删除元素
	for (j = i - 1;j < L.length;j++)
		L.elem[j] = L.elem[j + 1];
	L.length--;                      //线性表长度减1
	return OK;
}

/********************************************************************/
/*
函数功能：遍历表
传入参数：结构变量L的值。
时间复杂度是O(n)。空间复杂度是O(1)。
*/
/********************************************************************/
status ListTraverse(SqList L) {
	if (!L.elem) {
		printf("该线性表不存在！\n");
		return ERROR;
	}
	else {
		if (!L.length) {
			printf("该线性表是空表！\n");
			return OK;
		}
		else {
			int i;
			printf("\n-----------all elements -----------------------\n");
			for (i = 0;i < L.length;i++) printf("%d ", L.elem[i]);
			printf("\n------------------ end ------------------------\n");
			return OK;
		}
	}
}

/********************************************************************/
/*
函数功能：存储表
传入参数：结构变量L的值
时间复杂度是O(n)。空间复杂度是O(1)。
*/
/********************************************************************/
status ListSave(SqList L) {
	if (!L.elem) {
		printf("该线性表不存在！\n");
		return ERROR;
	}
	else {
		FILE *fp;char road[30];
		printf("请输入文件存储路径：");
		scanf_s("%s", road, sizeof(road));
		errno_t X;
		if ((X = fopen_s(&fp, road, "w+")) != 0) {
			printf("请输入正确的存储路径！\n");
			return ERROR;
		}
		fprintf(fp, "%d\n", L.length);
		for (int i = 0;i < L.length;i++) {
			fprintf(fp, "%d\n", L.elem[i]);
		}
		fclose(fp);
		return OK;
	}
}

/********************************************************************/
/*
函数功能：读取表
传入参数：结构变量L的引用
时间复杂度是O(n)。空间复杂度是O(1)。
*/
/********************************************************************/
status ListRead(SqList &L) {
	if (!L.elem) {
		printf("该线性表不存在！\n");
		return ERROR;
	}
	else {
		FILE *fp;char road[30];
		printf("请输入文件读取路径：");
		scanf_s("%s", road, sizeof(road));
		errno_t X;
		if ((X = fopen_s(&fp, road, "r")) != 0) {
			printf("请输入正确的存储路径！\n");
			return ERROR;
		}
		
		fscanf_s(fp, "%d", &L.length);
		if (L.length >= L.listsize) {
			ElemType *newbase;
			newbase = (ElemType *)realloc(L.elem, (L.length) * sizeof(ElemType));
			if (newbase == NULL) {
				printf("内存空间不足！\n");
				return OVERFLOW;   //扩充失败
			}
			L.elem = newbase;
			L.listsize = L.length;
		}
		for (int i = 0;i < L.length;i++) {
			fscanf_s(fp, "%d", &L.elem[i]);
		}
		fclose(fp);
		return OK;
	}
}
