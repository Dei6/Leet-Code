#include <stdio.h>
#include <math.h>
//暴力法
int maxSubSum1(int arry[], int count){
    int max = 0;
    for (int i = 0; i < count; i++)//起始指针
    {   for (int j = 1; j < count; j++)//结尾指针
        {   int temp = 0; //跳出作用体，将temp归0
            for (int m = i; m <= j; m++)//将起始指针与结尾指针之间的数遍历相加(真正作用体)
            {
                temp += arry[m];
                if (temp >= max)
                {
                    max = temp;
                }
            }
        }       
    }
    return max;
}

//动态规划
int maxSubSum2(int arry[], int count){
    int max = arry[0];
    int subMax = arry[0];
    for (int i = 1; i < count; i++)
    {
        if (subMax > 0)
        {
            subMax += arry[i]; //subMax对当前的数有增益效果，因此加上当前的数（上车）
        }else////一旦subMax小于0，一定是执行上一轮后（车尾）加上了一个非常大的负数，导致整体为负数，一个老鼠坏了一锅汤
        {
            subMax = arry[i];//直接跳过之前的（因为有老鼠屎所以把前面的都丢掉），将subMax的值设置为当前元素的值
        }
        max = subMax>max? subMax:max;
    }
    return max;
}


int main(){
    int arry[] = {-2,1,-3,4,-1,2,1,-5,4};
    int count = sizeof(arry)/sizeof(arry[0]);

    int result1 = maxSubSum1(arry,count);
    printf("%d \n",result1);

    int result2 = maxSubSum2(arry,count);
    printf("%d \n",result2);
}