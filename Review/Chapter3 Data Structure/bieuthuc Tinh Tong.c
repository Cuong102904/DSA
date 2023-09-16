#include <stdio.h>
#include <string.h>
#define Q 1000000007

int main() {
    char s[1000001];
    int dodai;int a=0; int tong =0;
	scanf("%[^\n]", s);
    dodai = strlen(s);
    while(a<dodai) {
       if(s[a] >= '0' && s[a] <= '9') {
        int b = a;
        int num = 0;
        while(b < dodai && s[b] >= '0' && s[b] <= '9') {
               num = (num * 10 + (s[b] - '0')) % Q;
              b++;
			  }
            tong= (tong +num) %Q;
            a = b;
        }
        else if(s[a] == '+') {
            a++;
            if(a == dodai) {
                printf("NOT_CORRECT\n");
                return 0;
            }
        }
    }
        printf("%d\n", tong);
	 return 0;
}
