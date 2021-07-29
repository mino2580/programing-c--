#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Deklarujte třídu reprezentující obdelník s následujícími podrobnostmi:
vytvořte konstruktor s délkou a šírkou obdelníka,
vytvořte členské funkce pro výpočet obsahu a obvodu,
dále definujte pole obdelníků a vytvořte kód, který vypíše rozměry největšího obdelníku v poli.*/
class Obdelnik
{
private:
	int a;
	int b;
	
public:
	Obdelnik(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	
	int VypocitejObvod()
	{
		return 2*(a + b);
	}
	
	int VypocitejObsah()
	{
		return a*b;
	}
	
};


int main( )
{
	int velikost = 4;
	
	Obdelnik o1(2,4);
	Obdelnik o2(2,5);
	Obdelnik o3(3,5);
	Obdelnik o4(6,5);
	Obdelnik pole[4] = {o1, o2, o3, o4};
	
	int index_nejvetsi = 0;
	int nejvetsiObsah = pole[0].VypocitejObsah();
	
 for(int i=1;i<velikost;i++)
	{
		int aktObsah = pole[i].VypocitejObsah();
		if (aktObsah > nejvetsiObsah)
		{
			nejvetsiObsah = aktObsah;
			index_nejvetsi = i;
		}
	}
	
	std::cout << "Nejvetsi obsah obdelniku má obdelnik na pozici " << index_nejvetsi + 1 << " a to je " << nejvetsiObsah << std::endl;
	
	return 0;
}