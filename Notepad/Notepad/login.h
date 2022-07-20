
#include "users.pb.h"

bool validateEmail(std::string);

std::string encryptPassword(std::string);

class Users {
	users::Users userslist;

public:
	Users();

	void writeData();

	void addUser();

	void printUserInfo();

	void reset();

	int findUserbyUsername(std::string);

	std::string signIn();
};
