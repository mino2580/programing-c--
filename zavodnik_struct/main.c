#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct zavodnik {
	int hod;
	int min;
	int sek;
	int cislo;
};

double vypocitejCas(struct zavodnik z){
	
	return z.hod + (z.min*0.01) + (z.sek*0.0001);
	
}

int porovnejCasy(double c, struct zavodnik zav){
	
	double cas = vypocitejCas(zav);
	if (cas < c){
		return 1;
	}
	else{
		return 0;
	}
}

int main(void)
{
	struct zavodnik z1 = {1, 3, 9, 76};
	struct zavodnik z2 = {10, 58, 11, 198};
	struct zavodnik z3 = {0, 37, 45, 19};
	struct zavodnik z4 = {0, 0, 59, 1};
	struct zavodnik z5 = {8, 7, 6, 200};

	struct zavodnik poleZavodniku[5] = {z1, z2, z3, z4, z5};

	int index_nejrychlejsi = 0;
	double nejrychlejsiCas = vypocitejCas(poleZavodniku[0]);
	
	for(int i = 1; i < sizeof(poleZavodniku)/sizeof(poleZavodniku[0]); i++){
		int jeNeni = porovnejCasy(nejrychlejsiCas, poleZavodniku[i]);
		if(jeNeni == 1){
			index_nejrychlejsi = i;
			nejrychlejsiCas = vypocitejCas(poleZavodniku[i]);
		}
	}
	
	printf("Nejrychlejsi zavodnik je závodník s číslem %d a měl čas %d:%d:%d.\n\n\n", poleZavodniku[index_nejrychlejsi].cislo, poleZavodniku[index_nejrychlejsi].hod, poleZavodniku[index_nejrychlejsi].min, poleZavodniku[index_nejrychlejsi].sek);
	return 0;
}