#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//vytvořte program pro součet a násobení matic s proměnnými rozměry s 
//využitím pole ukazatelů a alokací paměti na haldě pomocí funkce malloc
 
struct vysledky {
	int min;
	int max;
	double prum;
	};

int nejvetsiVPoli(int p[], int velikost){
	
	int index = 0;
	int max = p[0];
	for(int i = 1; i < velikost; i++){
		if (p[i] > max){
			max = p[i];
			index = i;
		}
	}
	return index;
}

int generuj(){
	return rand() % 10;
}

struct vysledky minMaxPrum(int p[], int velikost){
	
	int minC = p[0];
	int maxC = p[0];
	double prum = p[0];
	struct vysledky vys= {minC, maxC, prum};
	for(int i = 1; i < velikost; i++){
		prum += p[i];
		if (p[i] > maxC){
			maxC = p[i];
		}
		if (p[i] < minC){
			minC = p[i];
		}
	}
	vys.min = minC;
	vys.max = maxC;
	vys.prum = prum;
	return vys;
}

void swapDve(int p[], int i1, int i2){
	
	int pom = p[i1];
	p[i1] = p[i2];
	p[i2] = pom;
}

int main(void)
{
	int pole[10] = {9, 8, 1, 0, -9, 7, 8, 10, 111, -9};
	
	int index_nejvetsiho = nejvetsiVPoli(pole, 10);
	
	printf("Nejvetsi cislo v poli je %d a je na pozici %d\n\n\n", pole[index_nejvetsiho], index_nejvetsiho + 1);
	
	struct vysledky v = minMaxPrum(pole, 10);
	printf("Nejvetsi cislo v poli je %d, nejmensi je %d a prumerne cislo je %.2f\n\n\n", v.max, v.min, v.prum);
	
	int a = 0;
	int b = 1;
	swapDve(pole, a, b);
	printf("Byly prohozene hodnoty na pozicich %d a %d\n\n\n", a, b);
	
	int m = 2;
	int n = 3;
	
	int ** matice1 = NULL;
	int ** matice2 = NULL;
	int ** matice3 = NULL;
	int ** soucet = NULL;
	int ** nasobek = NULL;
	
	matice1 = malloc(m * sizeof(int *));
	matice2 = malloc(m * sizeof(int *));
	matice3 = malloc(n * sizeof(int *));
	
	for(int i = 0; i < m; i++)
	{
		matice1[i] = malloc(n * sizeof(int));
		matice2[i] = malloc(n * sizeof(int));
	}
	
	for(int i = 0; i < n; i++)
	{
		matice3[i] = malloc(m * sizeof(int));
	}
	
	
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			int cislo1 = generuj();
			int cislo2 = generuj();
			matice1[i][j] = cislo1;
			matice2[i][j] = cislo2;
		}
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int cislo = generuj();
			matice3[i][j] = cislo;
		}
	}
	
	printf("Nova Matice 1:\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("%d,", matice1[i][j]);
		}
		printf("\n");
	}
	
	
	printf("Nova Matice 2:\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("%d,", matice2[i][j]);
		}
		printf("\n");
	}
	
	printf("sucet matic 1 a 2:\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("%d,",  matice1[i][j] + matice2[i][j]);
		}
		printf("\n");
	}
	
	printf("Nova Matice 3:\n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("%d,", matice3[i][j]);
		}
		printf("\n");
	}
	
	printf("Soucin matic 1 a 3:\n");
	for (int x = 0; x < m; x++){
		for (int i = 0; i < m; i++){
			int suma = 0;
			for (int j = 0; j < n; j++){
				suma += (matice1[x][j] * matice3[j][i]);
				//printf("i %d, j %d, j %d, i %d, m1 %d, m2 %d\n", i, j, j, i, matice1[i][j], matice3[j][i]);
			}
			printf("%d, ", suma);
		}
		printf("\n");
	}
}
