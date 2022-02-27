#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {			//定义数据节点的数据结构
	int data;
	struct TreeNode* lchild;		//左子节点指针
	struct TreeNode* rchild;		//右子节点指针
}TreeNode;

TreeNode* bstSearch(TreeNode* T, int data) {	//二叉搜索
	if (T) {
		if (T->data == data) {				
			return T;							//两值相等，不做处理
		}
		else if (data< T->data){				
			return bstSearch(T->lchild, data);	//data值小于父节点，递归查找左子树 
		}
		else{
			return bstSearch(T->rchild, data);  //data值大于父节点，递归查找右子树
		}
	}
	else {
		return NULL;			// 节点不存在
	}
}

void bstInsert(TreeNode** T, int data) {		//二叉树插入
	if (*T == NULL) {							//判子节点是否为空
		*T = (TreeNode*)malloc(sizeof(TreeNode));	//动态规划空间
		(*T) -> data = data;
		(*T) -> lchild = NULL;						//初始化左子树
		(*T) -> rchild = NULL;						//初始化右子树
	} 
	else if (data == (*T) -> data){
		return;							//如果两值相等，就不做处理直接返回
	}
	else if(data < (*T) -> data) {
		bstInsert(&((*T) -> lchild), data);  //data值小于父节点，递归插入左子树
	}
	else{
		bstInsert(&((*T) -> rchild), data);  //data值大于父节点，递归插入右子树
	}
}

void preOrder(TreeNode* T) {		//树的先序遍历
	if (T){
		printf("%d ", T->data); 
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
	
}

int main() {
	TreeNode* T = NULL;
	int array[] = {47, 38, 65, 97, 76, 13, 27, 49, 13, 48,66};
	int size = sizeof(array) / sizeof(array[0]);	  	//求出数组元素个数		  	
	for (int i = 0; i < size; i++) {
		bstInsert(&T, array[i]);				//循环递归插入
	}
	preOrder(T);								//输出树先序遍历
	printf("\n");
	return 0;
}
 
