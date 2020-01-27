//int f(int b)
//{
// int a=1;
// printf("%d", a+b); /*a为实参, b为形参*/
//}
// *this phrase of code is untested
#include <stdio.h>
#define MAX_ELEMENT 100

typedef struct _TB
{
 int Item;
 int count;
} TB;

int max_freq(int *a, int *times)
{
	TB table[MAX_ELEMENT] = { 0 };
	int tableSize = 0;
 	int find = 0;
 	int i;

 	while (a!=NULL)
 	{
  		find = 0;
  		for(i = 0; i < tableSize; i++)
  		{
   			if(table[i].Item == *a)
   			{
    			table[i].count ++;
    			find = 1;
    			break;
   			}
  		}
  		// not find in table, add new
  		if (find == 0)
  		{
   			table[i].Item = *a;
   			table[i].count++;
   			tableSize ++;
  		}
  		a++;
 	}

 	int max = 0, cnt = 0;
 	for(int j = 0; j < tableSize; j ++)
 	{
  		if (table[j].count > cnt)
  		{
   			max = table[j].Item;
   			cnt = table[j].count;
  		}
 	}
 	*times = cnt;
 	return max;
}
int main()
{
    int ans = 0, num, a[] = {1, 2, 3, 4, 0, 1, 0, 3, 3, 0, 4, 4, 0,};
    num = max_freq(a, &ans);
    printf("The number is %d.\nOccourence of number is %d.", num, ans);
    return 0;
}
