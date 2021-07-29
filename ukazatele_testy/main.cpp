#include <stdio.h>
void vypis(int* pole, int n)
{
	printf("vypis pole:\n");

	for (int i = 0; i < n; i++)
	{
		printf("%d ", pole[i]);
	}

	putchar('\n');
}


int main(int argc, char **argv)
{
	/*
printf("sizeof(int):%d\n", sizeof(int)); // int zabere v paměti 4 bajty
int *a,*b,*c=0;
//printf("b:%p\n", b);
//printf("c:%p\n", c);
//printf("a:%p\n", a);
int* p = 0;
printf("p:%p\n", p); // 00000000
++p;               // zvýší adresu o 4 bajty
printf("++p:%p\n", p); // 00000004

++p; // zvýší adresu o 4 bajty
printf("%p\n", p); // 00000008
*/
//U ukazatele můžeme kromě operátoru inkremetace použít také operátory --,
// +, -, += a -=, které v následujícím příkladu vždy změní adresu 
//kam ukazatel ukazuje o násobky sizeof(int)

/*
printf("%d\n", sizeof(double)); // double zabere v paměti 8 bajtů

double* p = 0;
printf("%p\n", p); // 00000000

++p; // zvýší adresu o 8 bajtů
printf("%p\n", p); // 00000008

++p; // zvýší adresu o 8 bajtů
printf("%p\n", p); // 00000010 (16 desítkově)

 * /********************************************************/
 //printf("%d\n", sizeof(int)); // 4
/*
int* p = 0;
printf("  %p\n", p); // 00000000 v 16tkovej sustave

p = p + 1; // zvýší adresu o 2 x 4 = 8 bajtů
printf("  %d\n", p); // 00000008

++p; // sníží adresu o 4 bajty
printf("  %d\n", p); // 00000004

++p; // zvýší adresu o 3 x 4 = 12 bajtů
printf("  %d\n", p); // 00000010

p += 2; // sníží adresu o 4 x 4 = 16 bajtů
printf("  %d\n", p); // 00000000
*/

  int n = 4; // konstanta známá v době překladu

	int pole[n] = { 0 };

	vypis(pole, n);

	pole[0] = 1;
	pole[1] = 2;
	pole[2] = 3;
	pole[3] = 4;

	vypis(pole, n);

	*(pole + 0) = 5;
	*(pole + 1) = 6;
	*(pole + 2) = 7;
	*(pole + 3) = 8;

	vypis(pole, n);

	int* p = &pole[0];
	// int* p = (int*)pole;

	p[0] = 9;
	p[1] = 10;
	p[2] = 11;
	p[3] = 12;

	vypis(pole, n);

	*(p + 0) = 13;
	*(p + 1) = 14;
	*(p + 2) = 15;
	*(p + 3) = 16;

	vypis(pole, n);

	*p = 17;
	++p;
	*p = 18;
	++p;
	*p = 19;
	++p;
	*p = 20;

	// na tomto radku ukazuje ukazatel p na posledni prvek v poli

	vypis(pole, n);
 	return 0;
}
