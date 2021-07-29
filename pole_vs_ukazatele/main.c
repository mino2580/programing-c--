#include <stdio.h>
#include <stdlib.h>

void vynuluj(int* p)
{
	*p = 0;
}

void vypis(int const* p)
{
	printf("%d", *p);
}

int main()
{
	int x = 2;
	vynuluj(&x);

	printf("hodnota x je %d\n", x);

	printf("Promenna x ma hodnotu %d a je ulozena na adrese %p\n", x, &x);
	int* p1 = NULL;
	printf("Promenna p ma hodnotu %p a je ulozena na adrese %p\n", p1, &p1);
	printf("%d delka typu v pameti v bytech: d\n", sizeof(int));
	++p1;
	printf("Promenna p ma hodnotu %p a je ulozena na adrese %p\n", p1, &p1);
	p1 = p1 + 2;
	printf("Promenna p ma hodnotu %p a je ulozena na adrese %p\n", p1, &p1);
	int* p2 = NULL;
	printf("Rozdil ukazatelu %d\n", p1 - p2); // 0000000c - 00000000
	printf("Rozdil ukazatelu %d\n", p2 - p1);

	// chci na adresu ulozenou v p1 ulozit hodntou 5
	// na adresu 12 chci ulozit hodnotu 5 jako int
	// *p1 = 5;
	
	int pole[3];
	printf("sizeof(pole): %d\n", sizeof(pole));

	*(pole + 0) = 1;
	*(pole + 1) = 2;
	*(pole + 2) = 3;

	pole[0] = 3;
	pole[1] = 4;
	pole[2] = 5;
	
	int* py = pole; // &pole[0]
	*py = 6;
	++py;
	*py = 7;
	++py;
	*py = 8;

	int* const p3 = (int*)malloc(3 * sizeof(int));
	printf("sizeof(p3): %d\n", sizeof(p3));

	*(p3 + 0) = 1; // *p3 = 1;
	*(p3 + 1) = 2;
	*(p3 + 2) = 3;

	p3[0] = 4;
	p3[1] = 5;
	p3[2] = 6;

	// prepiste na 7 8 9 s pomoci operatoru ++p3;
	int* px = p3;

	*px = 7;
	++px;
	*px = 8;
	++px;
	*px = 9;

	free(p3);

	return 0;
}