#include <stdio.h>

int ReverseInteger(int n){
	int flag = 1, temp = 0;
	unsigned long reversed = 0,max = 2147483647;
	if (n<0){
		flag = -1;
		n = -n;
	}
	for (;n>0;n=n/10){
		temp = n%10;
                reversed = reversed*10+temp; //reverse the number
	}
	if (reversed > max) //check if the number overflows
		return 0;
	else
		return (int)reversed*flag;
}

void main(void){
        int num;
        printf("Input number: ");
        scanf("%d", &num);
        printf("%d", ReverseInteger(num));
}