#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//struktury opakovani C**********************************************
//Deklarovani struktury Obdelnik reprezentující obdélník 
typedef struct {
	double x ;
	double y ;
	}OBDELNIK;

//funkce pro vypocet obvodu obdelnika se vstupnymi parametramy struktury
	
	void vytiskni( OBDELNIK obdelnik,int a){//funkce parameter typu struktura obdelnik{
	 printf("obvod obdelnika %d je %.2lf \n\n",a,
	 2*(obdelnik.x+obdelnik.y));}
	 
      void vytiskni_2(OBDELNIK *a,int b){//parameter typu pointer obdelnik
	 printf("obsah obdelnika %d je %.2lf \n\n",b,
	 a->x*a->y);}
	 
	 void vytiskni_3(OBDELNIK*obdelnik_1) {
		double obsahy[3],suma,prumerny_obsah,min,max;
	 int m,n;
	 
	 for( int i=0;i<3;i++) {
			obsahy[i]=(obdelnik_1[i].x)*(obdelnik_1[i].y); 
		printf(" Obdelnik c.%d,obsah =%.2lf  \n",i,obsahy[i] );
		  // sumu obsahů, průměrný obsah 
		  suma += obsahy[i];}
		  
		 max=obsahy[0],min=obsahy[0];
		
		for( int i=0;i<3;i++){ 
		  if (max <= obsahy[i]) { //min,max
			max = obsahy[i];
			  m=i;}//pomocna premenna pre rozmery
		    
		   if (min >= obsahy[i]){
			min = obsahy[i];
			  n=i;}//pomocna premenna pre rozmery
		    }
		
		prumerny_obsah=suma/3;
		 printf(" suma=%.2lf  ,prumerny obsah =%.2lf  \n",
		 suma,prumerny_obsah );
		 printf(" nejvacsi obdelnik ma obsah=%.2lf  a rozmery sirka %.2lf ,rozmery vyska %.2lf , \n",
		 max,obdelnik_1[m].x,obdelnik_1[m].y);
		 printf(" nejmensi obdelnik ma obsah=%.2lf  a rozmery sirka %.2lf ,rozmery vyska %.2lf , \n",
		 min,obdelnik_1[n].x,obdelnik_1[n].y);
	}
//*********************************************************************
//                           komplexne cislo                           
typedef struct  {
	double re;
	double im;
}KOMPLEXNE_CISLO;

double abs_hodnota(KOMPLEXNE_CISLO k) {
	
	return sqrt( ((k.re*k.re)+(k.im*k.im)));
}
//***********************************************************************
//                           ukazatele a funkce                          
//vytvořte funkci, které předáte pole a ona vrátí největší prvek v poli  

int vrat_naj_cis_v_poli(int pole[], int delka)
{
	int  min;
	min = pole[0];
	for (int i = 0; i < delka; i++)
		if (min < pole[i])
			min = pole[i];
	return(min);
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
 void prohod1(int pole[], int delka_pole)
{
	puts("\n");
	// {1,2,3,4,5}
	for (int i = 0; i < delka_pole / 2; i++)
	{
		int pomocna = 0;
		pomocna = pole[i];
		pole[i] = pole[delka_pole - 1 - i];
		pole[delka_pole - 1 - i] = pomocna;
 
	}
	for (int i = 0; i < delka_pole ; i++) {
		printf(" %d ",pole[i]);
	}
}


int main(int argc, char** argv)
{
/*
//Deklarujte strukturu Obdelnik reprezentující obdélník (nebo kruh, čtverec atd.)
// a dále definujte:
//proměnnou x typu obdélník,
//dvě funkce pro výpočet obsahu a obvodu obdélníka:
//první funkce bude mít jako parametr proměnnou typu struktura Obdelnik,
//druhá funkce bude mít jako parametr ukazatel na proměnnou typu struktura Obdelnik
//s použitím první i druhé funkce spočítejte a vypište obvod a obsah proměnné x,
//proměnnou y typu Obdelnik a kód, který určí, zda je proměnná x větší nebo rovna (podle rozměrů) proměnné y,
//definujte pole obdélníků a inicializujte jej a spočítejte sumu obsahů,
// průměrný obsah a vypište rozměry největšího a nejmenšího obdélníku v poli
	 //                                     struktury
	OBDELNIK o,o2,o3;
	puts("\tAhoj,zdravite progam pro vypocet obdvodu a obsahu obdelnika\n");
	puts("Zadejte sirku obdelnika v metroch");
	scanf("%lf",&o.x);
	puts("Zadejte vysku obdelnika");
	scanf("%lf",&o.y);
	//  parametr funkce void obvod a obsah proměnnou typu struktura Obdelnik,
	 vytiskni(o,1);
     vytiskni_2(&o,1);
 
 OBDELNIK obdelnik_1[3];
	int i=0;
	for( i=0;i<3;i++){
	 printf("Zadejte sirku obdelnika c.%d   ",i);
	   scanf("%lf",&obdelnik_1[i].x);
	  printf("Zadejte vysku obdelnika c.%d   ",i);
	 scanf("%lf",&obdelnik_1[i].y);}
	
	 for( i=0;i<3;i++){
		printf(" Obdelnik c.%d,sirka =%.2lf,vyska =%.2lf  \n",
		i,obdelnik_1[i].x,obdelnik_1[i].y );}
		 
		vytiskni_3( obdelnik_1); 
  puts("konec");
 */
 
// *********************************************************************
/////Deklarujte strukturu komplexní číslo, definujte pole komplexních čísel, 
//napište program, který vypíše hodnoty největšího komplexního čísla 
//dle absolutní hodnoty.
/*
KOMPLEXNE_CISLO k1 = {1,2};
	KOMPLEXNE_CISLO  k2 = {3,4};
	KOMPLEXNE_CISLO  k3 = {5,6};
	KOMPLEXNE_CISLO  k4 = {7,8};
	KOMPLEXNE_CISLO  k5 = {1,10};

	KOMPLEXNE_CISLO  poleKomp_cisel[5] = {k1, k2, k3, k4, k5};

	int index_nejvetsi = 0;
	 double nej_Abs =  abs_hodnota(poleKomp_cisel[0]);
	double remax=poleKomp_cisel[0].re,imax =poleKomp_cisel[0].im;//pocatky pro max real a imag slozku
	
	
	for(int i = 0; i < sizeof(poleKomp_cisel)/sizeof(poleKomp_cisel[0]); i++){
		double akt_Abs = abs_hodnota(poleKomp_cisel[i]);
		if(akt_Abs > nej_Abs){
			index_nejvetsi = i;
			nej_Abs = akt_Abs;
		}
		
		
		 
		  if (remax <= poleKomp_cisel[i].re) { //min,max
			remax = poleKomp_cisel[i].re;
			  }//pomocna premenna pre rozmery
		   
		  if (imax <= poleKomp_cisel[i].im) { //min,max
			imax = poleKomp_cisel[i].im;
			  }
		   
	}
	
	printf("Nejvetsi komplexni cislo ma realnou slozku re = %lf a imaginarni im = %lf, pri absolutni hodnote = %f\n\n\n", poleKomp_cisel[index_nejvetsi].re, poleKomp_cisel[index_nejvetsi].im, nej_Abs);
	printf("Nejvetsi komplexni cislo ma realnou slozku re = %f a imaginarniim = %f",remax,imax);
*/

//**********************************************************************
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
	prohod1(pole,delka);
	 
	
 

	
	
	puts("\n\n");
	
	return 0;
}
