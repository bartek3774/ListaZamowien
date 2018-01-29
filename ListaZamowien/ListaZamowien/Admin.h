#pragma once
#include  "SingIn.h"
class Admin: public SingIn
{
public:
	Admin(SingIn log);
	void startPage();
	void startPage(int x);
	void addUser();
	int checkUser(string id);
	void removeUser();
	void printUsers();
	void addOrder();
	void printOrder();
	void printOrder(string id);
	int idGenerator();

	static void deleteRow(string path, size_t row);
	Admin();
	~Admin();
};

