/*có n người được gán số hiệu từ 1 đến n. Phần tử K[i][j] của mảng K[1..n][1..n] là 1
nếu người i biết người j và là 0 nếu ngược lại. (Ta có giả thiết K[i][i]=1 với mọi i và nếu người i biết người j thì không nhát thiết
người j cũng phải biết người i)
Một người được gọi là đặc biệt nếu  như ngoại trừ chinhs mình, anh ta không biết ai cả nhưng tất cả mọi người để biết anh ta */

#include <stdio.h>

// O(n^2) chưa tìm được cách biến O(n)

void nhap(int arr[][100], int k, int check[])
{
    for (int i = 1; i <= k; i++)
    {
        check[i] = 1;
        for (int j = 1; j <= k; j++)
        {
            printf("arr[%d][%d]= ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

int main()
{
    int arr[100][100];
    int check[100];
    int k;
    printf("moi nhap phan tu: ");
    scanf("%d", &k);
    nhap(arr, k, check);

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (arr[i][j] == 1 && i != j)
            {
                check[i] = 0;
                break;
            }
        }
        if (check[i])
        {
            printf("%d la nguoi dac biet\n", i);
        }
    }
    return 0;
}
