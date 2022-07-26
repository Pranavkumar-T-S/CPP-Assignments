// Notepad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "users.pb.h"
#include "login.h"
#include "project.h"


void loginMenu() {
	std::cout << std::endl;
	std::cout << "login menu" << std::endl;
	std::cout << "Select Any one of the options" << std::endl;
	std::cout << "1) Sign In" << std::endl;
	std::cout << "2) Sign Up" << std::endl;
	std::cout << "3) Close Application" << std::endl;
	std::cout << "Enter option : ";
}

void projectportalMenu() {

	std::cout << std::endl;
	std::cout << "project portal menu" << std::endl;
	std::cout << "Select Any one of the options" << std::endl;
	std::cout << "1) Print All Projects" << std::endl;
	std::cout << "2) Open Project" << std::endl;
	std::cout << "3) Create Project" << std::endl;
	std::cout << "4) Delete Project" << std::endl;
	std::cout << "5) Sign out" << std::endl;
	std::cout << "Enter option : ";
}

void projectMenu() {
	std::cout << std::endl;
	std::cout << "Select Any one of the options" << std::endl;

	std::cout << "1) Print Project Info" << std::endl;
	std::cout << "2) Print Text" << std::endl;
	std::cout << "3) Add Line" << std::endl;
	std::cout << "4) Remove Line" << std::endl;
	std::cout << "5) Update Line" << std::endl;
	std::cout << "6) Print Changes made in current version" << std::endl;
	std::cout << "7) Revert Last change made" << std::endl;
	std::cout << "8) Print Previous Versions" << std::endl;
	std::cout << "9) Revert to Previous Version" << std::endl;
	std::cout << "10) Save and exit" << std::endl;

	std::cout << "Enter option : ";
}
int main()
{
	std::cout << "Mini Notepad Application!\n";

	std::string username = "", id, optionS;
	int option;
	bool flag = true, app = true;

	std::string jsonS;
	int json;
	while (flag) {
		std::cout << "Enter 1 to use json files , 0 to use protobuf message binary files: ";
		std::cin >> jsonS;
		json = toInt(jsonS);
		if (json == 0 || json == 1) {
			break;
		}
		std::cout << "Invalid Option" << std::endl;
	}

	Users u1 = Users(json);
	while (app) {
		system("cls");
		while (username == "") {
			loginMenu();
			std::cin >> optionS;
			option = toInt(optionS);
			if (option == -1) {
				std::cout << "Invalid number " << std::endl;
				continue;
			}
			system("cls");
			switch (option) {
			case 1:
				username = u1.signIn();

				break;

			case 2:
				u1.addUser();

				break;

			case 3:
				username = "exitcase";
				app = false;
				break;

			case 4:
				u1.printUserInfo();
				break;

			default:
				std::cout << "Invalid option" << std::endl;
			}

		}

		u1.writeData();
		if (username == "")
			continue;

		if (!app) {
			break;
		}

		Projects p1(username, json);
		flag = true;

		system("cls");
		while (flag) {
			projectportalMenu();
			std::cin >> optionS;
			option = toInt(optionS);
			if (option == -1) {
				std::cout << "Invalid number ";
				continue;
			}
			system("cls");
			switch (option) {
			case 1:
				p1.printAllProjectsInfo();
				break;

			case 2:
				flag = !(p1.openProject());
				break;

			case 3:
				p1.createNewProject();

				break;

			case 4:
				std::cout << "Enter the id of project to delete: ";
				std::cin >> id;
				p1.deleteProject(id);

				break;

			case 5:
				username = "";
				flag = false;
				std::cout << "logging out" << std::endl;
				break;

			default:
				std::cout << "Invalid option" << std::endl;
			}
		}

		if (username == "")
			continue;

		flag = true;
		system("cls");

		while (flag) {
			projectMenu();
			std::cin >> optionS;
			option = toInt(optionS);
			if (option == -1) {
				std::cout << "Invalid number " << std::endl;
				continue;
			}

			system("cls");
			switch (option) {

			case 1:

				p1.printProjectInfo();
				break;

			case 2:

				p1.printText();
				break;

			case 3:

				p1.addLine();
				break;

			case 4:

				p1.removeLine();
				break;

			case 5:

				p1.updateLine();
				break;

			case 6:

				p1.printChanges();
				break;

			case 7:
				p1.revertLastChange();

				break;

			case 8:
				p1.printVersions();
				break;

			case 9:
				p1.revertbackVersion();
				break;

			case 10:
				p1.writeProject();

				flag = 0;
				break;

			default:
				std::cout << "Invalid option" << std::endl;
				break;
			}
		}
	}
}