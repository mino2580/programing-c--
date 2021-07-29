#include <stdio.h>
 
int vrat_naj_cis_v_poli(int pole[], int delka)
{
	int  max;
	max = pole[0];
	for (int i = 0; i < delka; i++)
		if (max < pole[i])
			max = pole[i];
	return(max);
}


//vytvořte funkci, které předáte pole a ona vrátí strukturu obsahující
// nejmenší, největší a průměrný prvek.

 typedef struct {
	double mx,mn,prumer; 
 }Vrat;
 
Vrat   vrat_strukturu( int pole[], int delka)
{
	double pocet=pole[0];
	double  min,max;
	min = pole[0],max = pole[0];
	for (int i = 0; i < delka; i++){
		if (min > pole[i]) min = pole[i];
		if (max < pole[i]) max = pole[i];
	pocet+=pole[i];
	}
	double prumer=pocet/delka;
Vrat  a;
a.mx=max;
a.mn=min;
a.prumer=prumer;
return a;
}


//  funkce prohod                                                       
 
void prohod1(int a, int b,int pole[],int delka)
{
	  
	 pole[0]=b;
	 pole[5]=a;
	for (int i = 0; i < delka; i++) {
		printf(" %d ",pole[i]);
	}

		}		 

void prohod2(int  x, int   y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

/*/////////////////////////////////////////////////////////////////////*/


int main(int argc, char **argv)
{
	
//                        ukazatele a funkce                            
//vytvořte funkci, které předáte pole a ona vrátí největší prvek v poli,

int delka;
int pole[]={1,2,3,4,5,6};
delka=sizeof (pole)/sizeof (int);
int a=vrat_naj_cis_v_poli(pole,delka);
printf("najvacsie cislo v poli je %d\n",a);
 
//vytvořte funkci, které předáte pole a ona vrátí strukturu obsahující
// nejmenší, největší a průměrný prvek.
 
 Vrat  b=vrat_strukturu(pole,delka);
printf("struktura max %lf  min %lf  prumer %lf\n\n", b.mx,b.mn,b.prumer);
		
//vytvořte funkci, která prohodí hodnoty proměnných v poli (swap),
	 puts("zadane pole\n");
	for(int i=0;i<delka;i++){
		printf(" %d ",pole[i]);
	}
	puts("\n\n");
	prohod1(1,6,pole,delka);
	puts("\n\n");
	 
	return 0;
}