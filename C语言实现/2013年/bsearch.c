int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/*** Linux 内核中的二分查找定义 函数形参根据题目做了相应的更改 ***/
/*
* bsearch - binary search an array of elements
* @key: pointer to item being searched for
* @base: pointer to first element to search
* @num: number of elements
* @size: size of each element
* @cmp: pointer to comparison function
*
* This function does a binary search on the given array.  The
* contents of the array should already be in ascending sorted order
* under the provided comparison function.
*
* Note that the key need not have the same type as the elements in
* the array, e.g. key could be a string and the comparison function
* could compare the string with the struct's name field.  However, if
* the key and elements in the array are of the same type, you can use
* the same comparison function for both sort() and bsearch().
*/
void *search(const void* key, const void* base, size_t num, size_t width, int(*compare)(const void* elem1, const void* elem2))
{
    size_t start = 0, end = num;
    int result;

    while(start < end)															// 若end = mid - 1 则循环判断条件为 <= 
    {
        size_t mid = start + (end - start) / 2;
        result = compare(key, base + mid * width);
        if(result < 0)
            end = mid;
        else if(result > 0)
            start = mid + 1;
        else
            return (void *)base + mid * width;
    }
    return NULL;
}
