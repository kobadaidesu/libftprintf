#include <stdio.h>

int main(void)
{
    char *str = "aiuesdfsdfo";
    unsigned long long n = (unsigned long long)str;
    int a;
    int b;

    a = printf("%llu\n", n);
    b = printf("%p\n", n);
    return 0;
}