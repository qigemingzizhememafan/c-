#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a = 20;
//	int b = 10;
//	int c = 0;
//	c = (a-b)/2+b;
//	printf("%d",c);
//return 0;
//}
//
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char s1[100];
//	char s2[100];
//	int i = 0;
//	int j = 0;
//	gets(s1);
//	for(i=strlen(s1)-1; i>=0; i--)
//	{
//		s2[j++] = s1[i];
//	}
//	puts(s2);
//return 0;
//}
//
//3.编程实现： 
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
//请找出这个数字。（使用位运算） 
//
//#include<stdio.h>
//int main()
//{
//
//return 0;
//}
//
//
//#include <stdio.h>
//int main()
//{
//    int arr[5] = { 5, 5, 1, 2, 2 };		//0101^0101 = 0^0001 = 0001^0010 = 0011^0010 = 0001
//    int ret = arr[0];
//	    int i = 0;
//    printf("arr = %d ", arr[0]);
//	 for (i = 1; i < 5; i++)
//    {
//        ret ^= arr[i];
//        printf("%d ", arr[i]);
//    }
//    printf("\nThe number is %d\n", ret);
//    return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int i;
//	char **p;
//	char *a[]={"student","a","am","I"};
//	for(i=3;i>=0;i--)
//	{
//		p=a+i;
//		printf("%s ",*p);
//	}
//	printf("\n");
//	return 0;
//}
//

//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	char **p;
//	char *a[] = {"student","a","am","i"};
//	for(i=3; i>=0; i--)
//	{
//		p = a+i;
//		printf("%s ",*p);
//	}
//return 0;
//}

//
#include <stdio.h>
#include <string.h>

int my_strlen(char ch[])
{
	int i = 0;
	int count = 0;
	for(i=0; ch[i]!='\0'; i++)
	{
		count++;
	}
	return count;
}

void reserve_string(char *left, char *right)
{
    while(left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left ++;
        right --;
    }
}
void reserve(char ch[], int len)
{
    int i = 0;
    char *chl = ch;
    char *chr = ch;
    while(ch[i])  
    {
        if(ch[i] == ' ')
        {
            reserve_string(chl, chr - 1);  //先反转每个单词,函数的嵌套调用 tneduts a ma i
            chl = ++chr; //先给chr +1，再把ch的值赋给chl
        }
        else
        {
            chr ++;
        }
        i++;
    }
    reserve_string(ch, ch +len-1);  //再整体反转  i am a student
}
int main()
{
    char ch[] = "student a am i";
    reserve(ch , my_strlen(ch));
    printf("%s\n",ch);
    return 0;
}

