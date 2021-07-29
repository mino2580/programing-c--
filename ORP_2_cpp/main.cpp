#include <iostream>
#include <string>
#include <sstream>  
 #include <vector>

  //using namespace std;

 
int main()
{
//Pro ošetření chyb slouží členské funkce good()
//která vrátí true, pokud se vše povedlo, 
//fail() vrátí true pokud došlo k chybě při parsování 
// a bad() vrátí true pokud došlo k chybě systému nezávisle 
// na vstupu uživatele.
/* 
int n = 0;
std::cout << "Zadej hodnotu n:" << std::endl;
std::cin >> n;
if (std::cin.good()){
	std::cout << "Zadal jsi hodnotu: " << n << std::endl;}

else if (std::cin.fail()){
std::cout << "Zadal jsi neplatnou hodnotu" << std::endl;
std::cin.clear();} // reset chyb

else if (std::cin.bad()){
std::cout << "IO stream corrupted";
return -1;}
*/
//Pro práci s řetězci používáme v C++ třídu std::string.
// Můžeme například slučovat řetězce pomocí přetíženého operátoru +.
/*
std::string retezec1 = "ahoj";
std::string retezec2 = " jak se mas";

std::cout << "retezec1 ma " << retezec1.length() << " znaky" << std::endl;

std::string retezec3 = retezec1 + retezec2;//spajanie retazcov

std::cout << retezec3 << std::endl;
*/
/*
std::stringstream ss;

int x = 100;
ss << "cislo x ma hodnotu " << x; 
std::string retezec = ss.str(); 
*/
//Protože obyčejné pole v C++ neobsahuje informaci o své délce, 
//doporučuje se pro pole s pevnou délkou používat třídu std::array.
// V reálném kódu ale budeme nejčastěji používat dynamické pole.

/*
std::array<int, 3> pole1;
std::array<int, 3> pole2 = { 1,2,3 };
std::array<int, 3> pole3 = { 1,2,3 };
int pocetPrvku = pole3.size();
for (int i = 0; i < pocetPrvku; i++)
{
int prvek = pole3[i];
std::cout << prvek << std::endl;
}
*/
//Třída std::vector představuje dynamické pole.
// Můžeme mimo jiné vkládat, číst a odstraňovat prvky na libovolné pozici. 

      std::vector<int> marks = {50, 47, 60};
    marks = {50, 47, 60};
    std::cout << "length of array : " << marks.size() << std::endl;
    return 0;
}
