#pragma once
#include <iostream>
using namespace std;

class clsPerson 
{
private:
	string _FirstName;
	string _LastName;
	string _Phone;
	string _Email;
public:

	//parameterize Constructor 
	clsPerson(string FirstName ,string LastName,string Email ,string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Phone = Phone;
		_Email = Email;
	}

	// Set Property
	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	// Get Property
	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = setFirstName)) string FirstName;

	// Set Property
	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	// Get Property
	string GetLastName()
	{
		return _LastName;
	}

	__declspec(property(get = GetLastName, put = setLastName)) string LastName;

	// Set Property
	void setPhone(string Phone)
	{
		_Phone = Phone;
	}
	// Get Property
	string GetPhone()
	{
		return _Phone;
	}

	__declspec(property(get = GetPhone, put = setPhone)) string Phone;

	// Set Property
	void setEmail(string Email)
	{
		_Email = Email;
	}
	// Get Property
	string GetEmail()
	{
		return _Email;
	}

	string FullName()
	{
		return _FirstName +" "+ _LastName;
	}

	__declspec(property(get = GetEmail, put = setEmail)) string Email;

	
};

