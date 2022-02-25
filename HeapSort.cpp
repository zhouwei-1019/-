#include <stdio.h>

void HeapAdjust(int array[],int k,int length){		//将以k为根的子数调整为大根堆 
	array[0]=array[k];							//把array[0]暂时存为子树的根节点 
	for(int i=2*k;i<=length;i*=2){			//沿着k节点的较大的子节点向下筛选 
		if(i<length && 	array[i]<array[i+1])
			i++;							//取k节点较大的子节点的下标 
		if(array[0]>=array[i])
			break; 							//筛选结束 
		else{
			array[k]=array[i];				//将array[i]调整到父节点上 
			k=i; 							//修改k值，以便继续向下筛选 
		} 
	}
	array[k] = array[0]; 					//被筛选出来节点的值放入最终位置 
} 

void BuildMaxHeap(int array[],int length){		//初始化大根堆 
	for (int i=length/2;i>0;i--)  			//从后往前调整所有非叶子节点
		HeapAdjust(array,i,length);
}

void swap(int *a, int *b){			//两元素互换位置 
	int temp;			
	temp = *a;
	*a = *b;
	*b = temp;
}   

void HeapSort(int array[],int length){
	BuildMaxHeap(array,length);			//调用初始建大根堆函数 
	for(int i=length;i>1;i--){			//遍历n-1趟交换和建堆过程 
		swap(&array[i],&array[1]);		//调用函数使堆顶元素和堆底元素互换位置 
		HeapAdjust(array,1,i-1); 		//除去最后一个堆底元素后，把剩余的待排序元素整理成堆 
	} 	
}

int main() {
    int array[] = {-1, 47, 38, 65, 97, 76, 13, 27, 49, 13, 66};      //数组的0号下标位置作为空位，-1不代表数组中的元素 
    int length = sizeof(array)/sizeof(array[0]);	  	//求出数组长度		 
	printf("原数据顺序： \n"); 
	for(int i=1;i<length;i++){
		printf("%d ",array[i]);      	//遍历输出 
	} 
    printf("\n");
    printf("排序后数据顺序：\n");    
    HeapSort(array,length-1);				//调用函数 
    for (int i =1; i < length; i++) {
        printf("%d ", array[i]);		//遍历输出	
    }
    return 0;
}
