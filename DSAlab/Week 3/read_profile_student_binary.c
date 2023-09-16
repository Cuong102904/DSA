#include <stdio.h>
#include <string.h>

typedef struct Profile
{
    char name[20];
    int age;
    char phone[10];
} Profile;

Profile Students[1000];
int n;

void Addprofile()
{
    Profile p;
    printf("Enter the name: ");
    scanf("%s", p.name);
    printf("Enter the age: ");
    scanf("%d", &p.age);
    printf("Enter the phone: ");
    scanf("%s", p.phone);
    n++;
    Students[n - 1] = p;
}

void Storeprofile()
{
    char filename[50];
    printf("Enter the filename for storing: ");
    scanf("%s", filename);
    FILE *f = fopen(filename, "wb");
    int nbItemsWrite = fwrite(Students, sizeof(Profile), n, f);
    printf("Write successfully %d items\n", nbItemsWrite);
    fclose(f);
}
void Loadprofile()
{
    char filename[50];
    printf("Enter filename for loading data: ");
    scanf("%s", filename);
    FILE *f = fopen(filename, "rb");
    n = 0;
    Profile p;

    while (!feof(f))
    {
        int sz = fread(&p, sizeof(Profile), 1, f);
        if (sz == 0)
            break;
        printf("Read successfully %d items", sz);
        n++;
        Students[n - 1] = p;
    }
    fclose(f);
}
void Viewprofile()
{
    for (int i = 0; i < n; i++)
    {
        printf("name = %s, age = %d, phone = %s", Students->name, Students->age, Students->phone);
    }
}
int main()
{
    int n = 0;
    char cmd[50];

    while (1)
    {
        printf("moi nhap cau lenh: ");
        scanf("%s", &cmd);
        if (strcmp(cmd, "quit") == 0)
            break;
        else if (strcmp(cmd, "add") == 0)
        {
            Addprofile();
        }
        else if (strcmp(cmd, "store") == 0)
        {
            Storeprofile();
        }
        else if (strcmp(cmd, "load") == 0)
        {
            Loadprofile();
        }
        else if (strcmp(cmd, "view") == 0)
        {
            Viewprofile();
        }
    }

    return 0;
}