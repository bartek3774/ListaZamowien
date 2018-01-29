#pragma once
#include "Admin.h"
class User: private Admin
{
public:
	User(SingIn log);
	void startPage();
	User();
	~User();
};

