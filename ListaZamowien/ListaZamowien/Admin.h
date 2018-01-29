#pragma once
#include  "SingIn.h"
class Admin: public SingIn
{
public:
	Admin(SingIn log);
	void startPage();
	void startPage(int x);

	static void deleteRow(string path, size_t row);
	Admin();
	~Admin();
};

