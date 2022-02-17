#include "sqlist.h"

/*
 *@brief 	: ��ʼ�����Ա� 
 *@param 	: SqList *L -> L�׵�ַ 
 *@return	: ERROR -1  SUCCESS 0
 */ 
int InitList(SqList *L){
	
	//����ָ�������ڴ� 
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(L->elem == NULL)
		return ERROR;
		
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	
	return SUCCESS;
}

/*
 *@brief 	: ��Ԫ��ָ��λ�û�ȡ 
 *@param 	: L -> L�׵�ַ 
 *			: position -> ָ����λ��	 
 *			: elem -> ��ȡ��Ԫ�ش�ŵ�ַ 
 *@return	: ERROR -1  SUCCESS 0
 */
int GetElem(SqList *L, int position, ElemType *elem){
	
	/* �б�λ�úϷ��� */ 
	if( position < 0 || position > L->length)
		return ERROR;
	
	*elem = *(L->elem + position - 1);
	
	return SUCCESS;	
} 


/*
 *@brief 	: ��Ԫ�ز��� 
 *@param 	: L -> L�׵�ַ 
 *			  position -> ����λ��
 * 			  elem -> ����Ԫ�� 
 *@return	: ERROR -1  SUCCESS 0
 */ 
int ListInsert(SqList *L,int position,ElemType elem){
	
	ElemType * newbase;
	ElemType *sp1,*sp2;
	
	/* �б���ַ�Ϸ��� */
	if(L->elem == NULL)
		return ERROR;
		
	/* �б����λ�úϷ��� */
	if( position < 0 || position > L->length+1)
		return ERROR;
	
	/* ������Ԫ���ѳ���ԭ�з�����ڴ棬�����»�ȡ�µ��ڴ� */	
	if(L->length >= L->listsize){
		newbase = (ElemType *)realloc(L->elem,(L->listsize + LIST_EXTRA_SIZE) * sizeof(ElemType));
		
		if(newbase == NULL)
			return ERROR;
			
		L->elem = newbase;
		L->listsize +=LIST_EXTRA_SIZE;
	}
	
	/* Ҫ�����λ�� */
	sp1 = L->elem + position - 1;
	
	/* �Ӻ���ǰ�ƶ� */
	for(sp2 = ( L->elem + L->length - 1); sp2 >= sp1; sp2--)
		*(sp2 + 1)= *(sp2);
		
	*sp1 = elem;
	L->length++;
	
	return SUCCESS;		 	
}


/*
 *@brief 	: ��Ԫ�ر��� 
 *@param 	: L -> L�׵�ַ 
 *@return	: ERROR -1  SUCCESS 0
 */ 
int ListTraverse(SqList *L){
	int i;
	for(i = 0; i < L->length; i++)
		printf(" %5d ",*(L->elem + i));
	printf("\n");
}
