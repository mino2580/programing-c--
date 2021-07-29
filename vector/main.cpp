#include <string>
#include <iostream>
#include <array>
#include <sstream>    
#include <vector>



int main(int argc, char **argv)
{
	/*
std::string retezec1 = "ahoj";
std::string retezec2 = " jak se mas";

std::cout << "retezec1 ma " << retezec1.length() << " znaky" << std::endl;

std::string retezec3 = retezec1 + retezec2;

std::cout << retezec3 << std::endl;
*/
/*******************************************************************/
/*
int n=4;
std::array<int, 3> pole1={};
std::array<int, 3> pole2 = { 4,5,6 };
std::array<int, 3> pole3 = { 1,2,3 };
int pocetPrvku = pole3.size();
for (int i = 0; i < pocetPrvku; i++)
{
int prvek = pole3[i];
std::cout << prvek << std::endl;

}

for (int i = 0; i < pocetPrvku; i++)
{
int prvek = pole2[i];
std::cout << prvek << std::endl;
}


for (int i = 0; i < pocetPrvku; i++)
{
int prvek = pole1[i];
std::cout << prvek << std::endl;
}
*/
/**********************************************************************/
std::vector<int> pole1;
std::vector<int> pole2 = { 1,2,3 };
std::vector<int> pole3{ 1,2,3 };
pole3.push_back(4);
//pole3.push_back(5); // vloží prvek na konec 
 int posledni = pole3.back(); // hodnota posledního prvku
 pole3.pop_back(); // odstraní poslední prvek
// pole3.insert(pole3.begin() + 1, 4); // vloží prvek na druhou pozici
 pole3.erase(pole3.begin() + 3); // odstraní třetí prvek
for (int i = 0; i < pole3.size(); i++)
{
std::cout << pole3[i] << std::endl;
}
std::cout<<"posledni "<<posledni<<std::endl;



	return 0;
}
