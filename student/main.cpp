#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
//Deklarujte třídu Student v namespace utb, kdy student bude mít jméno a příjmení a výsledky tří testů. Využijte std::cout a případně std::cin a třídu std::string. Dále:
//členské proměnné budou skryté (private) a k proměnným přistupujte pomocí veřejných (public) členských funkcí,
//vytvořte členskou funkci, která vrátí true, pokud student získal zápočet, to znamená že z každého ze tří testů získal alespoň 15 bodů,
//vytvořte členskou funkci, která vrátí průměr bodů ze tří testů studenta,
//definujte dynamické pole (std::vector) studentů a vložte do něj alespoň tři studenty,
//vypište jméno a příjmení studenta, který získal nejvíce bodů,
//vypište průměrný počet bodů všech studentů a vypište jméno a příjmení studenta, který má svůj průměr bodů nejbližší celkovému průměru bodů,
//vypište jména a příjmení studentů, kteří získali zápočet,
//seřaďte studenty dle získaných bodů vzestupně a vypište jména, příjmení a průměrné body všech seřazených studentů.*/
using namespace std;
 
class Student
{
private:
	string jmeno;
	string prijmeni;
	double test1;
	double test2;
	double test3;
public:
	Student(string jmeno, string prijmeni, double test1, double test2, double test3)
		: jmeno(jmeno), prijmeni(prijmeni), test1(test1), test2(test2), test3(test3)
	{
 
	}
 
	bool zapocet()
	{
		bool splnil = false;
		if ((test1 >= 15) && (test2 >= 15) && (test3 >= 15))
		{
			splnil = true;
		}
		return splnil;
	}
 
	double prumer()
	{
		double avg = (test1 + test2 + test3) / 3.0;
		return avg;
	}
 
	string getJmeno()
	{
		return jmeno;
	}
 
	string getPrijmeni()
	{
		return prijmeni;
	}
};
 
int main()
{
	vector<Student> studenti
	{
		Student("Erik", "Kral", 10, 15, 30),
		Student("Janko", "Mrkvicka", 30, 15, 30),
		Student("Milan", "Siska", 15, 15, 30)
	};
 
	double suma = 0.0;
	for (auto student : studenti)
	{
		suma += student.prumer();
	}
	double prumer = suma / studenti.size();
 
	Student nejlepsi = studenti[0];
	for (int i = 1; i < studenti.size(); i++)
	{
		Student aktualni = studenti[i];
		if (aktualni.prumer() > nejlepsi.prumer())
		{
			nejlepsi = aktualni;
		}
	}
 
	cout << nejlepsi.getJmeno() << " " << nejlepsi.getPrijmeni() << endl;
 
	// bonus, neni potreba znat
	// pomoci sort z algorithm a lambda
 
	Student max = *std::max_element(studenti.begin(), studenti.end(), [](auto s1, auto s2) -> bool { return s1.prumer() < s2.prumer(); });
 
 
	sort(studenti.begin(), studenti.end(), [](auto s1, auto s2) -> bool { return s1.prumer() > s2.prumer(); });
	for (auto student : studenti)
	{
		cout << student.getJmeno() << " " << student.getPrijmeni() << endl;
	}
}