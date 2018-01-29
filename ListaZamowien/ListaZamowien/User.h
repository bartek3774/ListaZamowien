#pragma once
#include "Admin.h"
class User: private Admin
{
public:
	User(SingIn log);
	void startPage();
	void startPage(string id);
	User();
	~User();
};

