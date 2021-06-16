#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countNonZeros(int *v, int len) {
    //v has &x[1] and len has 2
    int count = 0, i;
    if (len > 0) v[len-1] = 35;
    for (i=0; i<len; i++)
    if (v[i] != 0) //equivalently, if (*(v+i) != 0)
    ++count;
    return count;
}

char* strtok(char* str, const char* delim) {
    static char* tokenptr = NULL;
    static char delimtmp;
    int delimlen = strlen(delim), i;
    if (str != NULL)
    tokenptr = str;
    else
    *tokenptr++ = delimtmp;
    char *tmptoken = tokenptr;
    while (*tokenptr != '\0') {
            for (i = 0; i < delimlen; i++) {
            if (*tokenptr == delim[i]) {
                delimtmp = delim[i];
                *tokenptr = '\0';
                return tmptoken;
            }
        }
        ++tokenptr;
    }
    return NULL;
}


int main() {
    int z[3][4];
    printf("%p, %p, %p, \n", z[0], z[1], z[2]);
    //prints addresses of three rows
    printf("%p, %p, %p \n", &z[0], &z[1], &z[2]);
    //prints addresses of three rows
    printf("%p, %p \n", &z[1]+1, &z[0]+2);
    //prints identical values; z is interpreted as &z[0]
    printf("%p, %p \n", z[2]+1, &z[2][1]);
    //prints identical values
    printf("%p, %p \n", z[1], &z[1]);
    //prints identical addresses
    printf("%p, %p, %p \n", z, z+1, z+2);
    //prints z[0], z[1], z[2]
    printf("%p, %p, %p \n", &z[0], &z[0]+1, &z[0]+2);
    //prints z[0][0], z[0][1], z[0][2]
    printf("%p, %p \n", &z, &z+1);
    //prints &z, &z+1

    // double *buf[3];
    // double d0 = 8, d1[2] = {11, 12}, d2 = 10;
    // buf[0] = &d0; buf[1] = &d1[0]; buf[2] = &d2;
    // printf("%li, %li \n", sizeof(void*), sizeof(buf));
    // //prints 4, 12
    // printf("%p, %p, %p, %lf \n",
    // buf, &buf[0], d1, *buf[1]);
    int count = 3;
    double (*buf)[2] =
    (double (*)[2])malloc(count*sizeof(double [2]));
    printf("%li, %li, %li, %li \n",
    sizeof(double), sizeof(buf[0]),
    sizeof(buf[2]), sizeof(buf));
    //prints 8, 16, 16, 4 when count is 3
    free(buf);
    int x[3] = {20, 30, 0};
    int k = countNonZeros(&x[1], 2);
    printf("%d %d \n", k, x[2]); //prints 2, 35

    char input[]="CS101 is an interesting course!haha!";
    char delim[] = " !\t\n";
    char *token;
    token = strtok(input, delim);
        while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }

    int* link = NULL;
    printf("%p", link);
    //prints c, (nil)

    union {
    int a;
    double d;
    } obj;
    printf("%p, %p \n", &obj.a, &obj.d);
    //prints 0xbfa4e5b8, 0xbfa4e5b8
    obj.a = 20; obj.d = 39.45;
    printf("%d, %lf \n", obj.a, obj.d);
    //prints -1717986918, 39.450000

    int i; short s; char c; long l;
    printf("%ld, %ld, %ld, %ld\n", sizeof(i), sizeof(s), sizeof(c), sizeof(l));
    //prints 4, 2, 1, 8
    printf("%p, %p, %p, %p\n", &i, &s, &c, &l);
    //prints 0xbfdf07cc, 0xbfdf07ca, 0xbfdf07c9, 0xbfdf07d8

    unsigned int i2 = 513;
    char *q = (char*)&i2;
    printf("%d\n",q[0]);
    //prints little-endian

    int ii = 2, j = 3;
    int kk = ii++ * ++ii;
    printf("%d %d\n", kk, ii);



}