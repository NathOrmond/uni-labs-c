#include <stdio.h>

int main() {
    int a;
    int *pa = &a;

    a = 12; 

    printf("a val : %d\n", a);
    printf("a loc : %p\n", &a);

    printf("pa val : %d\n", *pa);
    printf("pa loc : %p\n", pa);

    return 0;
}
