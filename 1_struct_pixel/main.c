#include <stdio.h>
#include <stdlib.h>
//Deklarujte strukturu Pixel a dále:
//definujte pole pixelů a inicializujte jej,
//vypište počet černých pixelů v poli pixelů,
//vypište hodnoty barevných složek (red, green, blue) nejtmavšího pixelu.

struct pixel {
    int red;
    int green;
    int blue;
};

double luminance(struct pixel p)
{
	return p.red*0.3 + p.green*0.59 + p.blue*0.11;
}

int main(void)
{
	struct pixel p1 = {0, 0, 0};
	struct pixel p2 = {1, 0, 0};
	struct pixel p3 = {0, 56, 0};
	struct pixel p4 = {0, 0, 90};
	struct pixel p5 = {200, 200, 200};

	struct pixel polePixelu[5] = {p1, p2, p3, p4, p5};

	int pocetCernych = 0;
	int nejtmavsi = 0;
	double hodnotaNejtmavsi = 2;
	
	for(int i = 0; i < sizeof(polePixelu)/sizeof(polePixelu[0]); i++){
		if(polePixelu[i].red == 0 && polePixelu[i].green == 0 && polePixelu[i].blue == 0){
			pocetCernych += 1;
		}
		double l = luminance(polePixelu[i]);
		if(l < hodnotaNejtmavsi){
			hodnotaNejtmavsi = l;
			nejtmavsi = i;
		}
	}
	
	printf("\n\nPocet cernych pixelu v poli je %d\n", pocetCernych);
	printf("Slozky nejtmavsiho pixelu v poli jsou R = %d, G = %d, B = %d\n\n\n", polePixelu[nejtmavsi].red, polePixelu[nejtmavsi].green, polePixelu[nejtmavsi].blue);
	return 0;
}