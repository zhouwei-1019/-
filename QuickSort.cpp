#include <stdio.h>

int Partition(int array[],int low,int high){
	int pivot = array[low];					//将数组的第一个元素作为基准元素 
	while(low<high){						//用low、high来搜索基准元素的位置 
		while(low<high && array[high]>=pivot){
			--high; 
		}
		array[low]=array[high];				//比基准元素小的赋值到左子表 
		while(low<high && array[low	]<=pivot){
			++low; 
		}
		array[high]=array[low];				//比基准元素大的赋值到右子表
	}			
	array[low]=pivot;						//将基准元素放到最终位置
	return low; 							//返回基准元素的最终下标
}

void QuickSort(int array[],int low,int high){
	if (low<high){								//递归跳出条件 
		int pivotpos = Partition(array,low,high); //用基准元素划分左右子表
		QuickSort(array,low,pivotpos-1);			//递归调用划分左子表	
		QuickSort(array,pivotpos+1,high);			//递归调用划分右子表 
	}
}

int main() {
    int array[] = {47, 38, 65, 97, 76, 13, 27, 49, 13, 48,66};
    int size = sizeof(array) / sizeof(array[0]);	  	//求出数组元素个数		 
	int i;
	int low=0,high=size-1;    				//设置两个变量分别对应数组的低位下标、高位下标
	printf("原数据顺序： \n"); 
	for(i=0;i<size;i++){
		printf("%d ",array[i]);      //遍历输出 
	} 
    printf("\n");
    printf("排序后数据顺序：\n");    
    QuickSort(array,low,high);		//调用函数 
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);		//遍历输出	
    }
    return 0;
}
