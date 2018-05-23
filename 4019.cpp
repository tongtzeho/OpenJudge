#include <stdio.h>
#include <stdlib.h>

int Index[7][12];
int main()
{
int w;
while(scanf("%d",&w)!=EOF)
{
switch(w)
{
case 1:printf("9 12\n");break;
case 2:printf("6\n");break;
case 3:printf("3 11\n");break;
case 4:printf("2 8\n");break;
case 5:printf("5\n");break;
case 6:printf("10\n");break;
case 7:printf("1 4 7\n");break;
}
}
}