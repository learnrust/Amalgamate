// https://www.codeproject.com/Questions/5072866/Error-when-casting-an-integer-to-a-pointer-to-an-i

#include<stdio.h>

int main()
{
        int num = 10;
        int *pi = &num;
        //pi = &num is also valid
        printf("%d\n",*pi);
        //Typecasting
        //pi = num;
        //Will show an error because you can't convert a integer to a 'pointer to the data type integer' However, it is possible to typecast
        //pi = (int *)num;
	pi = &num;
        printf("After typecasting : %d\n",*pi);


}
