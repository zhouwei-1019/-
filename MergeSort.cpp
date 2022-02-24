#include <stdio.h>
#include <stdlib.h>

void Merge(int array[], int low, int mid, int high, int size) {
    int i,j,k;
    int *arrayB=(int *)malloc(size*sizeof(int));			//定义一个辅助动态规划数组
	for(k=low;k<=high;k++){
		arrayB[k]=array[k];							//将原有的数据复制到辅助数组中 
	} 
	for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){         //i下标指向左半部分的第一个元素，j下标指向右半部分的第一个元素，k下标指向原来数组的第一个下标
		if (arrayB[i]<arrayB[j])
			array[k]=arrayB[i++];   //当两个元素相等时，优先赋值下标小的元素，以保持算法的稳定性
		else							        //将两者中的较小值复制到原数组中 
			array[k]=arrayB[j++];
	}
	while(i<=mid)
		array[k++]=arrayB[i++];	  //左半部分的序列已经排序完成，依次把右半部分剩余的元素赋值到原数组中
	while(j<=high)
		array[k++]=arrayB[j++];	  //右半部分的序列已经排序完成，依次把左半部分剩余的元素赋值到原数组中
}

void MergeSort(int array[], int low , int high,int size) {
    if(low<high){
    	int mid=(low+high)/2;  					//从中间划分
		MergeSort(array,low,mid,size); 				//调用自身对数组左边递归排序 
		MergeSort(array,mid+1,high,size);			//调用自身对数组右边递归排序
		Merge(array,low,mid,high,size); 				//归并 
	}
}

int main() {
    int array[] = {47, 38, 65, 97, 76, 13, 27, 49, 13, 48};
    int size = sizeof(array) / sizeof(array[0]);	  	//求出数组中元素的个数		 
	int i;
	int low=0,high=size-1;    				//设置两个变量分别对应数组的低位下标、高位下标
	printf("原数据顺序： \n"); 
	for(i=0;i<size;i++){
		printf("%d ",array[i]);      //遍历输出 
	} 
    printf("\n");
    printf("排序后数据顺序：\n");   
    MergeSort(array,low,high,size);		//调用函数 
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);		//遍历输出	
    }
    return 0;
}
