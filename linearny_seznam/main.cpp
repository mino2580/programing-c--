#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

template<typename T>
class LinkedList
{
private:
	class Node
	{
	public:
		T data;
		Node* next;

		Node() : next(NULL)
		{
		}
		Node(T data) : data(data)
		{
		}
		Node(T data, Node* next) : data(data), next(next)
		{
		}

	};

	Node* header;
	Node* active;
	int counter;
public:
	LinkedList() : counter(0)
	{
		header = new Node();
		active = header;
	}
	~LinkedList()
	{
		Node* uzel = header;
		do
		{
			Node* dalsi = uzel->next;
			delete uzel;
			uzel = dalsi;
		} while (uzel != NULL);
	}
	void vlozNaZacatek(T data)
	{
		Node* novyUzel = new Node(data, header->next);
		header->next = novyUzel;
		++counter;
	}

	void vlozNaZacatek(LinkedList<T>* list)
	{
		list->first();
		while (list->next())
		{
			int data = list->dataAktivniho();
			vlozNaZacatek(data);
		}
	}

	void odstranZeZacatku()
	{
		if (header->next == NULL)
		{
			return;
		}

		Node* tmp = header->next->next; // adresa druheho
		delete header->next; // smazu prvni
		header->next = tmp; // adresu druheho dam jako prvni prvek
	}

	int count()
	{
		return counter;
	}
	void first()
	{
		active = header;
	}
	bool next()
	{
		if (active->next == NULL)
		{
			return false;
		}

		active = active->next;

		return true;
	}
	T dataAktivniho()
	{
		return active->data;
	}

	void sort()
	{
		// dodelat
	}
};

void Vypis(LinkedList<int>* list)
{
	list->first();
	while (list->next())
	{
		int data = list->dataAktivniho();
		cout << data << endl;
	}
}

class Student
{
private:
	string jmeno;
	double body;
public:
	Student(string jmeno, double body)
		: jmeno(jmeno), body(body)
	{}

	string getJmeno()
	{
		return jmeno;
	}

	double getBody()
	{
		return body;
	}
};

void vypis(LinkedList<int>* list)
{
	list->first();
	while (list->next())
	{
		int data = list->dataAktivniho();
		cout << data << endl;
	}
	cout << endl;

}

template<typename T>
class Zasobnik
{
private:
	T* begin;
	T* end;
	T* active;
public:
	Zasobnik(int kapacita)
	{
		begin = new T[kapacita];
		end = begin + kapacita;
		active = begin;
	}
	~Zasobnik()
	{
		if (begin != NULL)
		{
			delete[] begin;
			begin = NULL;
		}
	}
	void push_back(T data)
	{
		if (active < end)
		{
			*active = data;
			++active;
		}
	}

	T pop_back()
	{
		T data;
		if (active > begin)
		{
			--active;
			data = *active;
		}
		return data;
	}

	int size()
	{
		int tmp = active - begin;
		return tmp;
	}
};

int main()
{
	// ukoly:
	// 1) funkce vlozNaZacatek list
	// 2) trida Zasobnik jako sablona !!!
	// 3) funkce sort - seradi spoj. seznam vzestupne
	LinkedList<int> cisla1;
	cisla1.vlozNaZacatek(1);
	cisla1.vlozNaZacatek(2);
	cisla1.vlozNaZacatek(3);
	vypis(&cisla1);

	LinkedList<int> cisla2;
	cisla2.vlozNaZacatek(5);
	cisla2.vlozNaZacatek(6);
	cisla2.vlozNaZacatek(7);
	vypis(&cisla2);


	cisla1.vlozNaZacatek(&cisla2);
	vypis(&cisla1);

	// dodelat funkci sort, ktera seradi seznam int vzestupne
	cisla1.sort();
	vypis(&cisla1);

	// Vytvorit zasobnik 
	// Predelat na sablonu
	Zasobnik<int> zasobnik(3);
	zasobnik.push_back(1); // vlozi na konec
	zasobnik.push_back(2); // vlozi na konec
	zasobnik.push_back(3); // vlozi na konec
	zasobnik.push_back(4); // nevleze se
	cout << zasobnik.size() << endl;
	int posledni = zasobnik.pop_back(); // vrati posledni vlozenou hodnotu a odstrani posledni prvek
}

