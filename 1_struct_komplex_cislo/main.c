#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Deklarujte strukturu komplexní číslo, definujte pole komplexních čísel,
// napište program, který vypíše hodnoty největšího komplexního čísla
// dle absolutní hodnoty.
struct komp_cislo {
    double re;
    double im;
};

double abs_hodnota(struct komp_cislo k)
{
	return pow(pow(k.re, 2) + pow(k.im, 2), 0.5);
}

int main(void)
{
	struct komp_cislo k1 = {0.9, -90};
	struct komp_cislo k2 = {10, 110};
	struct komp_cislo k3 = {-0.9, 5.9};
	struct komp_cislo k4 = {0, 0};
	struct komp_cislo k5 = {111, 200};

	struct komp_cislo poleKomp_cisel[5] = {k1, k2, k3, k4, k5};

	int index_nejvetsi = 0;
	double nej_Abs = abs_hodnota(poleKomp_cisel[0]);
	
	for(int i = 1; i < sizeof(poleKomp_cisel)/sizeof(poleKomp_cisel[0]); i++){
		double akt_Abs = abs_hodnota(poleKomp_cisel[i]);
		if(akt_Abs > nej_Abs){
			index_nejvetsi = i;
			nej_Abs = akt_Abs;
		}
	}
	
	printf("Nejvetsi komplexni cislo ma realnou sloyku re = %f a imaginarni im = %f, pri absolutni hodnote = %f\n\n\n", poleKomp_cisel[index_nejvetsi].re, poleKomp_cisel[index_nejvetsi].im, nej_Abs);
	return 0;
}