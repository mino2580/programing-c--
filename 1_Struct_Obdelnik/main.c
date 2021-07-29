//Opakování C - Struktury
//Deklarujte strukturu Obdelnik reprezentující obdélník a dále definujte:
//- proměnnou x typu obdélník
//- dvě funkce pro výpočet obsahu a obvodu obdélníka:
//   první funkce bude mít jako parametr proměnnou typu struktura Obdelnik,
//   druhá funkce bude mít jako parametr ukazatel na proměnnou typu 
//   struktura Obdelnik
//-s použitím první i druhé funkce spočítejte a vypište obvod a obsah 
//   proměnné x,
//-proměnnou y typu Obdelnik a kód, který určí, zda je proměnná x větší 
//   nebo rovna (podle rozměrů) proměnné y
//-definujte pole obdélníků a inicializujte jej a spočítejte sumu obsahů,
//   průměrný obsah a vypište rozměry největšího a nejmenšího obdélníku 
//v poli
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct obdelnik {
    int a;
    int b;
};


int obvod(struct obdelnik o)
{
    return 2 * (o.a + o.b);
}

int obsah(struct obdelnik o)
{
    return o.a * o.b;
}

int main(void)
{
	struct obdelnik x = {0,0};
	
	int defined = 0;
	while(defined == 0){
		printf("Zadejte stranu a = ");
		scanf("%d", &x.a);
		if(x.a > 0){
			defined = 1;
		}
		else{
			printf("Hodnota a = (%d) -> Zadana hodnota strany a musi byt > 0 !!! Zvolte kladnou hodnotu b.\n", x.a);
		}
	}
	
	defined = 0;
	while(defined == 0){
		printf("Zadejte stranu b = ");
		scanf("%d", &x.b);
		if(x.b > 0){
			defined = 1;
		}
		else{
			printf("Hodnota b = (%d) -> Zadana hodnota strany b musi byt > 0 !!! Zvolte kladnou hodnotu b.\n", x.b);
		}
	}
    
	int obvod_x = obvod(x);
	int obsah_x = obsah(x);
	
    printf("Obvod obdelnika x = %d\n", obvod_x);
    printf("Obsah obdelnika x = %d\n", obsah_x);
    
    struct obdelnik y = {4, 6};
    
	int obvod_y = obvod(y);
	
    if (obvod_x > obvod_y){
		printf("Obdelnik x je vetsi nez y.\n");
	}
    else if (obvod_x == obvod_y){
        printf("Obdelniky x a y jsou stejne.\n");
	}
    else{
        printf("Obdelnik y je vetsi nez x.\n");
	}
        
    struct obdelnik z = {5, 3};
	
	struct obdelnik poleObdelniku[3] = {x, y, z};
    
	int obsah_akt = obsah(poleObdelniku[0]);
	int obvod_akt = obvod(poleObdelniku[0]);
    int suma = obsah_akt;
    double prumerny_obsah = obsah_akt;
    int obvod_max = obvod_akt;
    int obvod_min = obvod_akt;
	int i_min = 0;
	int i_max = 0;
    for (int i = 1; i < 3; i++)
    {
		obsah_akt = obsah(poleObdelniku[i]);
		obvod_akt = obvod(poleObdelniku[i]);
		
        suma += obsah_akt;
        prumerny_obsah += obsah_akt;
        
        if(obvod_akt > obvod_max){
			obvod_max = obvod_akt;
			i_max = i;
		}
		
		if(obvod_akt < obvod_min){
			obvod_min = obvod_akt;
			i_min = i;
		}
            
    }
    
    printf("Suma obvodu obdelniku %d\n", suma);
    printf("Prumer obsahu obdelniku %f\n", prumerny_obsah/3);
    printf("Rozmery stran nejvetsiho obdelniku: (%d, %d) \nRozmery stran nejmensiho obdelniku: (%d, %d) \n",
 poleObdelniku[i_max].a, poleObdelniku[i_max].b, poleObdelniku[i_min].a, poleObdelniku[i_min].b);

	return 0;
}
