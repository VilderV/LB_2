#include<conio.h>
#include <stdio.h>
#include<locale.h>
/// @fn void Sort(int * a, int N) �������  ������� ����������
void Sort(int * a, int N)
{    long i = 0, j = N;            
     int mass, p;
     p = a[ N/2 ];                
     do
     {
       while ( a[i] < p ) i++;
       while ( a[j] > p ) j--;
	 if (i <= j)
      { 
	mass = a[i]; a[i] = a[j]; a[j] = mass;
    i++;
	j--;
      }
     } 
	 while ( i<=j );
  if ( j > 0 ) Sort(a, j);
  if ( N > i ) Sort(a+i, N-i);
}
main()
{
	int a[10],i,n;
	char Mass[256];
    setlocale(LC_ALL,"Russian");///��������� �������� 
    printf("������� ���� � ����� � ��������� �������: ");
    gets(Mass);///���������� ������
	FILE *f;
	f=fopen(Mass,"r");
    fscanf(f,"%d",&n);
    for (i=0;i<n;i++)
	 {
		 fscanf(f,"%d",&a[i]);
	 }///������ ����� � ������ Mass
	 fclose(f);
     printf("\n ������� ���� � ����� � ��������� �������: ");
     gets(Mass);///���������� ������
     f=fopen(Mass,"w");
	 Sort(a, n);///���������� ���������� � �������
     fprintf(f,"���������� ��������������� ������ �:\n");
     for (i=0;i<n;i++)
	 {
		 fprintf(f,"%d ",a[i]);
	 }///������ ���������������� ������� � ����
     fclose(f);                           
}