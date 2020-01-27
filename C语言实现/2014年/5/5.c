#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10000

typedef struct LNode Node;
struct LNode
{
    int hashValue;
    int lenghth;
    char *ch;
};

int hash(char *s);
int cmp(const void* a, const void* b);

int main(int argc, char *argv[])
{
    FILE *fin = fopen("5.c", "r");
    FILE *fout = fopen("test_log", "w");                              //用于测试
//    FILE *fout = fopen("fout_log", "w");
    char s[MAXSIZE + 1];
    int n = atoi(argv[1]);

    Node *data = (Node *)malloc(n * sizeof(Node));                      //申请n长的结构体数组

    for(int i = 0; i < n; i++)
    {
        fgets(s, MAXSIZE, fin);                                         //不可使用fprintf()，因文件行可能只输入一个空格，fget()函数会读取'\n'
        if(s[strlen(s) - 1] == '\n')                                    //换行符不计入字符串
            s[strlen(s) - 1] = 0;
        data[i].hashValue = hash(s);
        data[i].lenghth = strlen(s);
        data[i].ch = (char *)malloc((strlen(s) + 1) * sizeof(char));    //申请存字符行的空间，长度加一存放'\0'
        strcpy(data[i].ch, s);                                          //存入刚申请的空间内
    }
    qsort(data, n, sizeof(Node), cmp);

    for(int i = 0; i < n; i++)
    {
        fprintf(fout, "%d\t%d\n", data[i].hashValue, data[i].lenghth);//用于测试
//        fprintf(fout, "%s\n", data[i].ch);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}

int hash(char *s)
{
    int sum = 0;                                                        //记得求和初始化时要清零！！
    while(*s)
    {
        if((*s >= '0' && *s <= '9') || (*s >= 'a' && *s <= 'z'))
            sum += *s;
        s++;
    }
    return sum % 10007;
}

int cmp(const void* a, const void* b)                                   //使用qsort()中的cmp()函数
{
    Node * m = (Node *)a;
    Node * n = (Node *)b;
    if(m->hashValue != n->hashValue)                                    //先比较hash值，从小到大，看清楚题目大小要求！！
        return m->hashValue - n->hashValue;
    else if(m->lenghth != n->lenghth)                                   //再比较字符串长度，从大到小
        return n->lenghth - m->lenghth;
    else                                                                //最后比较字典序，从大到小
        return strcmp(n->ch, m->ch);
}
