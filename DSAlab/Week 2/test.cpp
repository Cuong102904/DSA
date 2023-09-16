#include <iostream>
#include<cmath>
#include<windows.h>
#define PI 3.1415926535898
using namespace std;
//tinh phuyong trinh bac nhat

void bacnhat(float a,float b)
{
  if (a==0 && b==0)
  {
    cout<<"phuong trinh vo so nghiem"<<endl;
  }
  else if (a==0 && b!=0)
  {
    cout<<"phuong trinh vo nghiem"<<endl;
  }
  else
  {
    cout<<"phuong trinh co nghiem x= "<<-b/a<<endl;
  }
}

//tinh phuyong trinh bac 2
void bachai(float a,float b,float c)
{
  float d,x1,x2;
  if(a==0)
  {
    cout<<"phuong trinh vo nghiem"<<endl;
  }
  else
  {
    d=b * b-4 *a *c;
    if(d<0)
   {
     cout<<"phuong trinh vo nghem"<<endl;
   }
   else if(d==0)
   {
     cout<<"phuong trinh co nghiem kep x1=x2="<<-b/(2*a)<<endl;
   } 
   else
   {
     x1=(-b-sqrt(d))/(2*a);
     x2=(-b+sqrt(d))/(2*a);
     cout<<"phuong trinh co 2 ngiem phan biet:"<<endl;
     cout<<"x1="<<x1<<endl;
     cout<<"x2="<<x2<<endl;
   }
  }
}

// tinh phuong trinh bac 3
void bacba(float a, float b, float c, float d)
{
  float dt,k,x1,x2,x3,x;
  if(a==0)
  {
    cout<<"Phuong trinh vo nghiem"<<endl;
  }
  dt=pow(b,2)-3*a*c;//delta=b*b-3*a*c
  k=(9*a*b*c-2*pow(b,3)-27*pow(a,2)*d)/(2*sqrt(pow(fabs(dt),3)));
  if(dt>0)
  {
    if(fabs(k)<=1)
    {
      x1=(2*sqrt(dt)*cos(acos(k)/3)-b)/(3*a);
      x2=(2*sqrt(dt)*cos(acos(k)/3-(2*PI/3))-b)/(3*a);
      x3=(2*sqrt(dt)*cos(acos(k)/3+(2*PI/3))-b)/(3*a);
      cout<<"phuong trinh co 3 nghiem phan biet:"<<endl;
      cout<<"x1="<<x1<<endl;
      cout<<"x2="<<x2<<endl;
      cout<<"x3="<<x3<<endl;
    }
    if(fabs(k)>1)
    {
      x=((sqrt(dt)*fabs(k))/(3*a*k))*(pow((fabs(k)+sqrt(pow(k,2)-1)),1.0/3)+pow((fabs(k)-sqrt(pow(k,2)-1)),1.0/3))-(b/(3*a));
      cout<<"Phuong trinh co 1 ngiem duy nhat la:"<<x<<endl;
    }
   }
  else if(dt==0)
  {
    x=(-b-pow(-(pow(b,3)-27*a*a*d),1.0/3))/(3*a);//do ham pow khong dung doi so am nen ta phai doi dau.Ct goc:x=(-b+pow(pow(b,3)-27*a*a*d),1.0/3))/(3*a)
    cout<<"Phuong trinh co nghiem boi:"<<x<<endl;
  }
  else
  {
    x=(sqrt(fabs(dt))/(3*a))*(pow((k+sqrt(k*k+1)),1.0/3)-pow(-(k-sqrt(k*k+1)),1.0/3))-(b/(3*a));
    cout<<"phuong trinh co 1 nghiem duy nhat:"<<x<<endl;
  }
}
int main()
{
  float a,b,c,d;
  int chon;
  cout<<"1.Phuong trinh bac nhat:ax+b=0"<<endl;
  cout<<"2.Phuong trinh bac hai:ax^2+bx+c=0"<<endl;
  cout<<"3.Phuong trinh bac hai:ax^3+bx^2+cx+d=0"<<endl;
  cout<<"Hay chon dang phuong trinh bang cach an so tuong ung:";
  cin>>chon;
  switch(chon)
  {
    case 1: //Chon 1 de giai phuong trinh bac 1
    {
      cout<<"Ban da chon phuong trinh bac 1:"<<endl;
      cout<<"nhap a,b:"<<endl;
      cin>>a>>b;
      bacnhat(a,b);
      break;
    }
    case 2: //Chon 2 de giai phuong trinh bac 2
    {
      cout<<"Ban da chon phuong trinh bac 2:"<<endl;
      cout<<"nhap a,b,c:"<<endl;
      cin>>a>>b>>c;
      bachai(a,b,c);
      break;
    }
    case 3: //Chon3 de giai phuong trinh bac 3
    {
      cout<<"Ban da chon phuong trinh bac 3:"<<endl;
      cout<<"nhap a,b,c,d"<<endl;
      cin>>a>>b>>c>>d;
      bacba(a,b,c,d);
      break;
    }
  }
  system("pause");
  return 0;
}
