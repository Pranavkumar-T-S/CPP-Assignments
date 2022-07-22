#include<regex>
#include<iostream>
#include<fstream>
#include "login.h"
using namespace std;
     
bool validateEmail(string e) {
	regex p("^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$");
	cout << regex_match(e, p);
	return (regex_match(e, p) ? true : false);
}

string encryptPassword(string message) {
	// encypting message using ceaser cipher
	for (int i = 0; i < message.size(); i++)
		message[i] += 3;
	return message;
}

Users::Users() {
	std::ifstream fin;
	fin.open("users_database.bin", std::ios_base::binary);
	if (!this->userslist.ParseFromIstream(&fin)) {
		cerr << "Failed to parse address book." << endl;
	}
	fin.close();
}

void Users::writeData() {
	std::ofstream fout;
	fout.open("users_database.bin", std::ios_base::binary);
	if (!userslist.SerializeToOstream(&fout)) {
		cerr << "Failed to write address book." << endl;
	}
	fout.close();
}

void Users::addUser() {
	users::User* newUser = this->userslist.add_users();
	std::string username, password, email, location, name, mobile;
	while (true) {

		std::cout << endl << "Enter Username: ";
		std::cin.ignore();
		getline(std::cin, username);
		if (this->findUserbyUsername(username) == -1) {
			newUser->set_username(username);
			break;
		}
		else {
			std::cout << "Username already exists try a new name..." << endl;
		}
	}

	std::cout << "enter password: ";
	//cin.ignore();
	getline(std::cin >> ws, password);
	newUser->set_password(encryptPassword(password));

	cout << "Enter your name (blank for none): ";
	//cin.ignore();
	std::getline(cin, name);
	if (!name.empty())
		newUser->set_name(name);

	while (true) {
		cout << "Enter your email address (blank for none): ";
		std::getline(cin, email);
		if (!email.empty()) {
			if (validateEmail(email)) {
				newUser->set_email(email);
				break;
			}
			else
				std::cout << "Not a valid email. Try again..." << endl;
		}
		else
			break;
	}

	cout << "Enter your mobile number (blank for none): ";
	std::getline(cin, mobile);
	if (!mobile.empty())
		newUser->set_mobile(mobile);

	cout << "Enter your location (blank for none): ";
	getline(cin, location);
	if (!location.empty())
		newUser->set_location(location);

}

void Users::printUserInfo() {
	for (int i = 0; i < this->userslist.users_size(); i++) {
		const users::User& user1 = this->userslist.users(i);
		std::cout << endl;
		std::cout << "Username: " << user1.username() << endl;
		std::cout << "Encrypted Password: " << user1.password() << endl;
		std::cout << "Name: " << user1.name() << endl;
		std::cout << "Email: " << user1.email() << endl;
		std::cout << "Mobile: " << user1.mobile() << endl;
		std::cout << "Location: " << user1.location() << endl;
	}
}

void Users::reset() {
	this->userslist.clear_users();
}

int Users::findUserbyUsername(string username) {
	for (int i = 0; i < this->userslist.users_size(); i++) {
		const users::User& useri = this->userslist.users(i);
		if (username == useri.username()) {
			return i;
		}
	}
	return -1;
}

string Users::signIn() {
	string username, password;
	int index;
	std::cout << "Enter your username: ";
	std::cin.ignore();
	std::getline(cin, username);
	index = this->findUserbyUsername(username);
	if (index != -1) {
		std::cout << "Enter password: ";
		std::cin >> password;
		users::User user1 = this->userslist.users(index);
		if (encryptPassword(password) == user1.password()) {
			return username;
		}
		else {
			std::cout << "Wrong password " << endl;
			return "";
		}
	}
	else {
		std::cout << "Username not found... " << endl;
		std::cout << "Try again or Create a new one " << endl;
		return "";
	}
}