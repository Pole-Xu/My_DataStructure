/*
 * ████████ 算法2.1 ████████
 *
 * A=A∪B
 *
 * 计算La与Lb的并集并返回。
 */

#include "sqlist.h"


int main(void){
	ElemType list_a[5] = {3,23,1,5,6};
	ElemType list_b[8] = {21,1,31,5,1,7,0,12};
	
	SqList L1,L2;
	int i;
	
	//初始化L1
	if(!InitList(&L1)){
		for( i = 1; i <= 5; i++)
			if(!ListInsert(&L1,i,list_a[i-1])); 
			else{
				printf("L1 Insert fail!\n");
				return ERROR;
			}
			
	}
	else 
		printf("L1 Initial fail!\n");		
	ListTraverse(&L1);
	
	//初始化L2
	if(!InitList(&L2)){
		for( i = 1; i <= 8; i++)
			ListInsert(&L2,i,list_b[i-1]);
	}
	else 
		printf("L2 Initial fail!\n");		
	ListTraverse(&L2);
	
	//合并 L1 L2
	
	if(UnionList(&L1,&L2))
		printf("List Union fail!\n");
	ListTraverse(&L1);	
		
	return 0;
}

