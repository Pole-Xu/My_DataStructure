#include "sqlist.h"

/*
 *@brief 	: 初始化线性表 
 *@param 	: SqList *L -> L首地址 
 *@return	: ERROR -1  SUCCESS 0
 */ 
int InitList(SqList *L){
	
	//分配指定容量内存 
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(L->elem == NULL)
		return ERROR;
		
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	
	return SUCCESS;
}

/*
 *@brief 	: 表元素指定位置获取 
 *@param 	: L -> L首地址 
 *			: position -> 指定的位置	 
 *			: elem -> 获取的元素存放地址 
 *@return	: ERROR -1  SUCCESS 0
 */
int GetElem(SqList *L, int position, ElemType *elem){
	
	/* 判别位置合法性 */ 
	if( position < 0 || position > L->length)
		return ERROR;
	
	*elem = *(L->elem + position - 1);
	
	return SUCCESS;	
} 


/*
 *@brief 	: 表单元素插入 
 *@param 	: L -> L首地址 
 *			  position -> 插入位置
 * 			  elem -> 插入元素 
 *@return	: ERROR -1  SUCCESS 0
 */ 
int ListInsert(SqList *L,int position,ElemType elem){
	
	ElemType * newbase;
	ElemType *sp1,*sp2;
	
	/* 判别表地址合法性 */
	if(L->elem == NULL)
		return ERROR;
		
	/* 判别插入位置合法性 */
	if( position < 0 || position > L->length+1)
		return ERROR;
	
	/* 所插入元素已超出原有分配的内存，需重新获取新的内存 */	
	if(L->length >= L->listsize){
		newbase = (ElemType *)realloc(L->elem,(L->listsize + LIST_EXTRA_SIZE) * sizeof(ElemType));
		
		if(newbase == NULL)
			return ERROR;
			
		L->elem = newbase;
		L->listsize +=LIST_EXTRA_SIZE;
	}
	
	/* 要插入的位置 */
	sp1 = L->elem + position - 1;
	
	/* 从后往前移动 */
	for(sp2 = ( L->elem + L->length - 1); sp2 >= sp1; sp2--)
		*(sp2 + 1)= *(sp2);
		
	*sp1 = elem;
	L->length++;
	
	return SUCCESS;		 	
}


/*
 *@brief 	: 表单元素遍历 
 *@param 	: L -> L首地址 
 *@return	: ERROR -1  SUCCESS 0
 */ 
int ListTraverse(SqList *L){
	int i;
	for(i = 0; i < L->length; i++)
		printf(" %5d ",*(L->elem + i));
	printf("\n");
}
