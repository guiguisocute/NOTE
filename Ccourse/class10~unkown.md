### 函数
引入：
> 上黄老师的C语言实验课，每次都要写好几坨代码，每次展示的时候都要不停地注释和反注释，这实在是太麻烦了，有什么办法可以化简这个过程吗？

直接用返回值为`void`的函数进行 **“封装”** 直接调用就行：

比如随便从我的作业里面复制三个代码：

```c
#include<stdio.h>
#include<stdlib.h>

int main(){
    int t; int apple[10];
    for(int i = 0; i < 10; i++){
        scanf("%d",&apple[i]);
    }
    scanf("%d",&t); t += 30;

    int count = 0;
    for(int i = 0; i < 10; i++){
        if(apple[i] <= t){
            count++;
        }
      
    }
        printf("%d\n",count);  

        system("pause");
        return 0;

//本应该注释掉
   int kwh;
    scanf("%d",&kwh);

    if(kwh >= 150){
    printf("%.1f",kwh >= 400 ? 150 * 0.4463 + 250 * 0.4663 + (kwh - 400) * 0.5663 : 150 * 0.4463 + (kwh - 150) * 0.4663);
    }else{
        printf("%.1f",kwh * 0.4463);
    }
    system("pause");
    return 0;

//下面这段也是
  int x;
    scanf("%d",&x);
    if(x % 2 == 0 && x > 4 && x <= 12 ){
        printf("1 ");
    }
    else{
        printf("0 ");
    }
    if (x % 2 == 0 || (x > 4 && x <= 12)) {
        printf("1 ");
    } 
    else {
        printf("0 ");
    }
    if ((x % 2 == 0) ^ (x > 4 && x <= 12)) {
        printf("1 ");
    }
    else {
        printf("0 ");
    }
    if(!(x % 2 == 0 || (x > 4 && x <= 12))){
        printf("1 ");
    }
    else{
        printf("0 ");
    }
}
```

现在，我们把这三段完全不一样的代码给分类封装好一个个的“盒子”，但因为盒子里面完全就是机械地执行代码，所有的语句都在“盒子”里就已经定义执行好了，所以其应该被定义为`无参函数`（小括号里面没有东西） 。而且它们没有返回值需求所以也定义成`void` *（`main`函数返回`int`比较特殊,属于一种约定俗成的规定）*。

可以直接进行封装：
```c
void box1();
```
函数定义 =（函数声明————→函数实现）
函数实现就和调用变量参数一样不用在写个变量类型一样了显得你很弱智。。。。