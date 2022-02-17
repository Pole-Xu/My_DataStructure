 #include<stdio.h> 
 #include<stdlib.h>
 
 
 /* define */
 #define  LIST_INIT_SIZE  	5
 #define  LIST_EXTRA_SIZE 	1 

#define  ERROR  			-1
#define  SUCCESS    		 0

/* ˳���Ԫ�����Ͷ��� */
typedef int ElemType;

/* ���Ա�ṹ */ 
typedef struct{
	ElemType * elem;
	int length;
	int listsize;
	
}SqList; 


int InitList(SqList *L);

int GetElem(SqList *L, int position, ElemType *elem);
 
int ListInsert(SqList *L,int position,ElemType elem);

int ListTraverse(SqList *L); 
