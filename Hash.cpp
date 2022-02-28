#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define P 7				
typedef struct HashNode {
	ElemType data;
	HashNode* link;
}HashNode;

typedef HashNode* HashTable[P];//表里存的是个地址，这是个HashNode*类型的数组,如HashTable[i] 表示指向第一个结点的地址

//初始化Hash表
void InitHashTable(HashTable& ht) {
	for (int i = 0; i < P; i++) {
		ht[i] = NULL;
	}
}

//构造Hash函数，使用除留余数法
int Hash(ElemType key) {
	return key % P;
}


//插入数据，使用拉链法解决碰撞问题
void InsertHashTable(HashTable& ht, ElemType x) {
	int index = Hash(x);

	HashNode* s = (HashNode*)malloc(sizeof(HashNode));
	s -> data = x;

	//头插法插入
	s -> link = ht[index];		//数组里存的是原来结点的地址
	ht[index] = s;
}

//打印输出
void PrintHashTable(HashTable& ht) {
	for (int i = 0; i < P; i++) {
		printf("%d: ", i);
		HashNode* p = ht[i];
		while (p != NULL) {
			printf("%d-->", p->data);
			p = p->link;
		}
		printf(".\n");
	}
}

void main() {
	HashTable ht;
	InitHashTable(ht);
	int array[] = { 1,8,15,22,29,36,43,44,17,28 };
	int arraylength = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i <arraylength; i++){
		InsertHashTable(ht, array[i]);		//依次插入Hash表
	}
	PrintHashTable(ht);			//输出Hash表
}
