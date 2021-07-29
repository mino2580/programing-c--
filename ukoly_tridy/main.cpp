#include <stdlib.h>
 
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
 
using namespace std;

class Obdelnik1
{
    int m;
    int n;
public:
    Obdelnik1(int m, int n){
        this->m = m;
        this->n = n;
    }
    int VratObsah(){
        return m * n;
    }
};

void Vypis(Obdelnik1 o){
    printf("Obsah je %d\n", o.VratObsah());
}

/**************************************************************/
class Komp_cislo
{
	int re;
	int im;
public:
	Komp_cislo(int re, int im){
		this->re = re;
		this->im = im;
	}
	int GetRe(){
		return re;
	}
	int GetIm(){
		return im;
	}
	double VratAbsHodnotu(){
		return pow(pow(re, 2) + pow(im, 2), 0.5);
	}	
};
/********************************************************************/
class Obdelnik
{
	int a;
	int b;
public:
	Obdelnik(int a, int b){
		this->a = a;
		this->b = b;
	}
	
	int VypocitejObvod() {
		return 2*(a + b);
	}
	
	int VypocitejObsah() {
		return a*b;
	}
};
/*********************************************************************/
class Zasobnik
{
private:
    int kapacita;
    int *data;
    int pocet;
    
public:
    Zasobnik(int kapacita)
    {
        this->kapacita = kapacita;
        //data = new int[kapacita];
        data = (int*) malloc (kapacita);
        pocet=0;
        
    }        
    void tlac(int nevim){   
        data++;
        if(pocet<kapacita){
        *data = nevim;
        pocet++;
        }
        else
            printf("\nNeni misto blbe.");
        
    }
     
    int pop(){   
      if(pocet>0)
        {
        int dat = *data;
        data--;
        pocet--;
        return dat;
        }
        else
        {
            printf("\nNic nemam. Nemame nic na zasobniku.");
            return -1;
        }
        /*pocet++;
        if(pocet!=kapacita){
            data++;
        
        
        }*/
    }
    
};


int main(void)
{
	// Deklarujte třídu reprezentující obdelník s následujícími podrobnostmi:
//vytvořte konstruktor s délkou a šírkou obdelníka,
//vytvořte členské funkce pro výpočet obsahu a obvodu,
//dále definujte pole obdelníků a vytvořte kód, který vypíše rozměry největšího obdelníku v poli.*/
	
	/*int velikost = 4;
	
	Obdelnik o1(2,4);
	Obdelnik o2(2,5);
	Obdelnik o3(3,5);
	Obdelnik o4(6,5);
	Obdelnik pole[4] = {o1, o2, o3, o4};
	
	int index_nejvetsi = 0;
	int nejvetsiObsah = pole[0].VypocitejObsah();
	
	for (int i = 1; i < velikost; i++)
	{
		int aktObsah = pole[i].VypocitejObsah();
		if (aktObsah > nejvetsiObsah)
		{
			nejvetsiObsah = aktObsah;
			index_nejvetsi = i;
		}
	}
	
	std::cout << "Nejvetsi obsah obdelniku má obdelnik na pozici " << index_nejvetsi + 1 << " a to je " << nejvetsiObsah << std::endl;
	*/
//Deklarujte třídu reprezentující komplexní číslo s následujícími podrobnostmi:
//členské proměnné (reálná a imaginární část) budou public,
//vytvořte konstruktor s reálnou i imaginární složkou,
//vytvořte funkci pro změnu hodnoty reálné a imaginární složky
//vytvořte členskou funkci, která vrátí absolutní hodnotu komplexního čísla. Řešení
//definujte pole komplexních čísel na zásobníku,
//najděte komplexní číslo s největší absolutní hodnotou a vypište jeho komplexní a reálnou část. */
/*
	int velikost = 4;
	
	Komp_cislo k1(2,4);
	Komp_cislo k2(2,5);
	Komp_cislo k3(3,5);
	Komp_cislo k4(6,5);
	
	Komp_cislo pole[4] = {k1, k2, k3, k4};
	
	int index_nejvetsi = 0;
	int nejvetsiAbsHodnota = pole[0].VratAbsHodnotu();
	cout<<nejvetsiAbsHodnota<<endl;
	for (int i = 1; i<velikost; i++)
	{
		int aktAbsHodnota = pole[i].VratAbsHodnotu();
		if (aktAbsHodnota > nejvetsiAbsHodnota)
		{
			nejvetsiAbsHodnota = aktAbsHodnota;
			index_nejvetsi = i;
		}
	}
	
	 cout << "Nejvetsi absolutni hodnotu ma komplecni cislo re = "<< pole[index_nejvetsi].GetRe() << " a im = "<< pole[index_nejvetsi].GetIm() <<" a je v poli na pozici " << index_nejvetsi + 1 <<   endl;
// Takto neee!!! -> std::cout << "Nejvetsi absolutni hodnotu ma komplecni cislo re = "<< pole[index_nejvetsi].re << " a im = "<< pole[index_nejvetsi].im <<" a je v poli na pozici " << index_nejvetsi + 1 <<  std::endl;
*/

//Deklarujte třídu reprezetující zásobník s následujícími funkcemi:
//konstruktor s kapacitou zásobníku,
//funkci pro vložení nového prvku (push),
//funkci která vrátí hodnotu posledního prvku a odebere ho ze zásobníku (pop).*/
Zasobnik z(5);
    z.tlac(4);
    z.tlac(5);
    z.tlac(8);
    z.tlac(2);
    z.tlac(1);
    printf("\n");
    printf("Pop - %d \n",z.pop());
    z.tlac(12);
    printf("\n");
    printf("Pop - %d \n",z.pop());
    printf("Pop - %d \n",z.pop());
    printf("Pop - %d \n",z.pop());
    printf("Pop - %d \n",z.pop());
    printf("Pop - %d \n",z.pop());
    printf("Pop - %d \n",z.pop());
    z.tlac(25);
    printf("Pop - %d \n",z.pop());
    
    
 
	return 0;
}