#include "stdafx.h"
#include "Admin.h"


Admin::Admin(SingIn log1)
{
	login = log1.login;
	name = log1.name;
	surname = log1.surname;
	group = log1.group;
	accountType = log1.accountType;
}

void Admin::startPage()
{
	cout << "Witaj " << SingIn::name << " " <<  SingIn::surname << endl;
	cout << "Typ konta: " << SingIn::accountType << endl;
	cout << "1. Zarzadzanie uzytkownikami\n2. Dodaj zamowienie\n3. Lista wszystkich zamowien\n4. Lista zamowien uzytkownika\n5. Usun zamowienie\n6. Wyloguj\n7. Wyjdz" << endl;
	string x;
	cin >> x;
	if (x == "1")
	{
		system("cls");
		startPage(1);
	}
	else if (x == "2")
	{
		system("cls");
		addOrder();
		startPage();
	}
	else if (x == "3")
	{
		system("cls");
		printOrder();
		startPage();
	}
	else if (x == "4")
	{
		system("cls");
		string id;
		cout << "Podaj login uzytkownika" << endl;
		cin >> id;
		if(checkUser(id))
		printOrder(id);
		else
		{
			system("cls");
			cout << "Podany uzytkownik nie istnieje" << endl;
		}
		startPage();
	}
	else if (x == "5")
	{
		system("cls");
		removeOrder();
		startPage();
	}
	else if (x == "6")
	{
		
	}
	else if (x == "7")
	{
		exit(0);
	}
	else
	{
		system("cls");
		startPage();
	}
}

void Admin::startPage(int x)
{
	if (x == 1)
	{
		cout << "1. Lista uzytkownikow\n2. Dodaj uzytkownika\n3. Usun uzytkownika\n4. Wroc" << endl;
		string x2;
		cin >> x2;
		if (x2 == "1")
		{
			system("cls");
			printUsers();
			startPage(1);
		}
		else if (x2 == "2")
		{
			system("cls");
			addUser();
			startPage(1);
		}
		else if (x2 == "3")
		{
			system("cls");
			removeUser();
			startPage(1);
		}
		else if (x2 == "4")
		{
			system("cls");
			startPage();
		}
		else
		{
			system("cls");
			startPage(1);
		}
	}
}

void Admin::addUser()
{

	string id, name, surname;

	cout << "Podaj login uzytkownika" << endl;
	cin >> id;
	if (checkUser(id))
	{
		system("cls");
		cout << "Podany uzytkownik istnieje" << endl;
		startPage(1);
	}
	cout << "Podaj imie uzytkownika" << endl;
	cin >> name;
	cout << "Podaj nazwisko uzytkownika" << endl;
	cin >> surname;

	ofstream usersFile;
	usersFile.open("users.txt", ios::app);//ID NAME SURNAME PASSWORD USER
	usersFile << id + " " + name + " " + surname + " " + id+"h" + " Uzytkownik" << endl;
	usersFile.close();
	system("cls");
	cout << "Konto utworzone" << endl;

}

int Admin::checkUser(string id)
{
	ifstream usersFile;
	usersFile.open("users.txt", ios::app);
	string loginTmp, nameTmp, surnameTmp, passwordTmp, accountTypeTmp;
	while (!usersFile.eof())
	{
		
		usersFile >> loginTmp >> nameTmp >> surnameTmp >> passwordTmp >> accountTypeTmp;
		
		if (accountTypeTmp == "Uzytkownik" && loginTmp == id)
		{
			usersFile.close();
			return 1;
		}
	}
	usersFile.close();
	return 0;
}

void Admin::removeUser()
{
	string id, x;
	cout << "Podaj numer uzytkownika" << endl;
	cin >> id;
	cout << "Czy napewno chcesz trwale usunac uzytkownika o id: " << id << " (t/n)" << endl;
	cin >> x;
	if (x == "t")
	{
		ifstream usersFile;
		usersFile.open("users.txt", ios::app);

		int i = 1;
		while (!usersFile.eof())
		{
			string loginTmp, nameTmp, surnameTmp, passwordTmp, accountTypeTmp;
			usersFile >> loginTmp >> nameTmp >> surnameTmp >> passwordTmp >> accountTypeTmp;
			if (loginTmp == id && accountTypeTmp == "Uzytkownik")
			{
				usersFile.close();
				deleteRow("users.txt", i);
				system("cls");
				cout << "Uzytkownik usuniety" << endl;
				startPage(1);
				break;
			}
			i++;
		}
		system("cls");
		cout << "Brak uzytkownika o tym id" << endl;
	}
	else
	{
		system("cls");
		cout << "Blad usuwania uzytkownika" << endl;
	}
}

void Admin::printUsers()
{
	ifstream usersFile;
	usersFile.open("users.txt", ios::app);
	cout << "Uzytkownicy" << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------" << endl;
	while (!usersFile.eof())
	{
		string loginTmp, nameTmp, surnameTmp, passwordTmp, accountTypeTmp;
		usersFile >> loginTmp >> nameTmp >> surnameTmp >> passwordTmp >> accountTypeTmp;
		if (accountTypeTmp == "Uzytkownik")
		{
			cout << loginTmp << " " << nameTmp << " " << surnameTmp << endl;
		}
	}
	usersFile.close();
	cout << "-----------------------------------------------------------------------------------------------------------" << endl << endl << endl;
}

void Admin::addOrder()
{
	int id = idGenerator();
	string login, item;
	int quantity;
	float price;
	cout << "Podaj login uzytkownika" << endl;
	cin >> login;
	int x;
	if (x = checkUser(login))
	{
		cout << "Podaj nazwe towaru" << endl;
		cin >> item;
		cout << "Podaj ilosc sztuk" << endl;
		cin >> quantity;
		cout << "Podaj cene sztuki" << endl;
		cin >> price;
		ofstream ordersFile;
		ordersFile.open("orders.txt", ios::app);//ID LOGIN ITEM QUANTITY PRICE PRICE_SUM
		ordersFile << id << " " << login + " " + item + " " << quantity << " " << price << " " << quantity * price << endl;
		ordersFile.close();
		system("cls");
		cout << "Zamowienie dodane" << endl;
	}
	else
	{
		system("cls");
		cout << "Nie ma takiego uzytkownika" << endl;
	}
}

void Admin::removeOrder()
{
	string id, x;
	cout << "Podaj numer zamowienia" << endl;
	cin >> id;
	cout << "Czy napewno chcesz trwale usunac zamowienie nr: " << id << " (t/n)" << endl;
	cin >> x;
	if (x == "t")
	{
		ifstream ordersFile;
		ordersFile.open("orders.txt", ios::app);

		int i = 1;
		while (!ordersFile.eof())
		{
			string idTmp, loginTmp, itemTmp;
			int quantityTmp;
			float priceTmp, priceSumTmp;
			ordersFile >> idTmp >> loginTmp >> itemTmp >> quantityTmp >> priceTmp >> priceSumTmp;
			if (idTmp == id)
			{
				ordersFile.close();
				deleteRow("orders.txt", i);
				system("cls");
				cout << "Zamowienie usuniete" << endl;
				startPage();
				break;
			}
			i++;
		}
		ordersFile.close();
		system("cls");
		cout << "Brak zamowienia o numerze " << id << endl;
	}
	else
	{
		system("cls");
		cout << "Blad usuwania zamowienia" << endl;
	}
}

void Admin::printOrder()
{
	ifstream ordersFile;
	ordersFile.open("orders.txt", ios::app);
	cout << "Zamowienia wszystkich uzytkownikow" << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------" << endl;
	cout << "Numer zamowienia Login Przedmiot Ilosc Cena jednostkowa Wartosc" << endl;
	float sum = 0;
	int x = 0;
	while (!ordersFile.eof())
	{
		string idTmp, loginTmp, itemTmp;
		int quantityTmp;
		float priceTmp, priceSumTmp;
		ordersFile >> idTmp >> loginTmp >> itemTmp >> quantityTmp >> priceTmp >> priceSumTmp;
		if (idTmp.length() > 1)
		{
			cout << idTmp << " " << loginTmp << " " << itemTmp << " " << quantityTmp << "szt " << priceTmp << "zl " << priceSumTmp << "zl" << endl;
			sum += priceSumTmp;
			x++;
		}
	}
	ordersFile.close();
	cout << "-----------------------------------------------------------------------------------------------------------" << endl ;
	cout << "Laczna kwota zamowien: " << sum << "zl." << endl;
	cout << "Laczna liczba zamowien: " << x << endl;
	cout << "Srednia cena zamowienia: " << roundf(((sum / x) * 100)) / 100 << endl << endl << endl;
}

void Admin::printOrder(string id)
{
	ifstream ordersFile;
	ordersFile.open("orders.txt", ios::app);
	cout << "Zamowienia uzytkownika " << id << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------" << endl;
	cout << "Numer zamowienia Login Przedmiot Ilosc Cena jednostkowa Wartosc" << endl;
	float sum = 0;
	int x = 0;
	while (!ordersFile.eof())
	{
		string idTmp, loginTmp, itemTmp;
		int quantityTmp;
		float priceTmp, priceSumTmp;
		ordersFile >> idTmp >> loginTmp >> itemTmp >> quantityTmp >> priceTmp >> priceSumTmp;
		if (idTmp.length() > 1 && loginTmp == id)
		{
			cout << idTmp << " " << loginTmp << " " << itemTmp << " " << quantityTmp << "szt " << priceTmp << "zl " << priceSumTmp << "zl" << endl;
			sum += priceSumTmp;
			x++;
		}
	}
	ordersFile.close();
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	cout << "Laczna kwota zamowien: " << sum << "zl." << endl;
	cout << "Laczna liczba zamowien: " << x << endl;
	cout << "Srednia cena zamowienia: " << roundf(((sum / x) * 100)) / 100 << endl << endl << endl;
}

int Admin::idGenerator()
{
		time_t czas;
		srand(time(&czas));
		int x = (rand() % 5000 + 1);
		return x;
}

void Admin::deleteRow(string path, size_t row)
{
	vector < string > vec;
	ifstream in(path.c_str());
	string tmp;
	while (getline(in, tmp)) 
		vec.push_back(tmp);

	in.close();
	ofstream out(path.c_str());
	for (size_t i = 0; i < vec.size(); ++i) 
	{
		if (i + 1 != row) out << vec[i] << endl;
	}
	out.close();
}

Admin::Admin()
{
}


Admin::~Admin()
{
}
