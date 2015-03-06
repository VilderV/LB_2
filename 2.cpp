#include<conio.h>
#include <stdio.h>
#include<locale.h>
/// @fn void Sort(int * a, int N) функция  быстрой сортировка
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
    setlocale(LC_ALL,"Russian");///включение русского 
    printf("Введите путь к файлу с исходными данными: ");
    gets(Mass);///считывание адреса
	FILE *f;
	f=fopen(Mass,"r");
    fscanf(f,"%d",&n);
    for (i=0;i<n;i++)
	 {
		 fscanf(f,"%d",&a[i]);
	 }///запись файла в массив Mass
	 fclose(f);
     printf("\n Введите путь к файлу с конечными данными: ");
     gets(Mass);///считывание адреса
     f=fopen(Mass,"w");
	 Sort(a, n);///применение сортировки к массиву
     fprintf(f,"Полученный отсортированный массив А:\n");
     for (i=0;i<n;i++)
	 {
		 fprintf(f,"%d ",a[i]);
	 }///печать отсортированного массива в файл
     fclose(f);                           
}