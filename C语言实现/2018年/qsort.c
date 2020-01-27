int cmp(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}

void swap(void *a, void *b, int size)
{
    char temp;
    int i = 0;
    while(size > 0)
    {
        temp = *((char *)a + i);
        *((char *)a + i) = *((char *)b + i);                                    //注意这里不用*size
        *((char *)b + i) = temp;
        i++;
        size--;
    }
}

void qsort(void *base, int num, int size, int (*cmp)(const void *a, const void *b))
{
    sort(base, 0, num - 1, size, cmp);
}

void sort(void *base, int left, int right, int size, int (*cmp)(const void *a, const void *b))
{
    if(left >= right)
        return ;
    char *pleft = (char *)base + left * size;
    char *pmid = (char *)base + (left + (right - left) / 2) * size;
    swap(pleft, pmid, size);                                                                    //将中间元素放置于最左边
    int last = left;                                                                            //注意last应为left而不是0
    char *plast = (char *)base + left * size;

    for(int i = left + 1; i <= right; i++)                                                      //一趟排序，将小于中间元素的元素移动至左边
    {
        char *pi = (char *)base + i * size;
        if(cmp(pi, pleft) < 0)
        {
            ++last;
            plast = base + last * size;                                                         //注意应在base的基础上算偏移，而不是pleft的基础上
            swap(plast, pi, size);
        }
    }
    swap(plast, pleft, size);                                                                   //中间元素归位
    sort(base, left, last - 1, size, cmp);
    sort(base, last + 1, right, size, cmp);
}
