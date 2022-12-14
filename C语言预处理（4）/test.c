#include <stdio.h>

//带副作用的宏参数

//int main()
//{
//	int a = 10;
//	int b = a + 1;   //1
//	int b = ++a;     //2
//	// 代码2就有副作用，他不仅改变了b的值，还改变了a的值
//	return 0;     
//}

////函数
//int MAX(int x, int y)
//{
//	return x > y ? x : y;
//}
//
////宏
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))

//函数和宏相比:
// 1.当有不同类型的参数时，函数只能指定某一种类型，而宏都可以(与类型无关)
// 2.函数在调用的时候，会有函数调用和返回的开销，用更多的时间，效率低
// 3.而宏在调用的时候，预处理阶段就完成了替换,没有函数调用和返回的开销，效率更高
// 4.宏能传类型，但是函数不可以
//宏相对于函数的劣势
// 1.如果宏比较长，可能会大幅度增加程序的长度（代码完全替换）
// 2.宏无法调试(替换过后我们看到的调试处代码和它所执行的代码不一样)
// 3.由于类型无关，就不够严谨（不做类型检查）
// 4.可能会带来运算符优先级的问题，导致程序出错
// （宏的参数完全替换，包括运算符，会有优先级问题，多写括号  ）


//int main()
//{
//	int a = 10;
//	int b = 11;
//	int max = MAX(a++, b++);
//	//这里相当于  int max = ((a++)>(b++)?(a++):(b++))
//	// （a++）和（b++）进行比较，是a和b进行比较（10>11）,结果false，执行b++
//	//  当执行a++和b++的比较是，两者都后加加，此时 a=11,b=12,执行b++（后加加）
//	//  b先被赋值给max,再变成了13
//	//所以不要使用带有副作用的参数
//	printf("%d\n", max);     // 12
//	printf("%d\n", a);       // 11 
//	printf("%d\n", b);       // 13 
//	return 0;
//}

////4.宏能传类型，但是函数不可以
//
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//
//int main()
//{
//	//常规：
//	int* p = (int*)malloc(10 * sizeof(int));
//	//用宏
//	int* p = MALLOC(10, int);
//	return 0;
//}

//注意：宏尽量都大写，而函数不要都大写，以免两者混淆

//#undef 可以移除一个宏定义

#define MAX 100

int main()
{
	printf("MAX = %d\n", MAX);
#undef MAX
	printf("MAX = %d\n", MAX);   //报错，MAX已被移除
	return 0;
}
