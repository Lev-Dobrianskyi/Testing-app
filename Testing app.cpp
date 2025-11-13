//make admin's menu an actual menu
//check the functionality of saving the test, everything else works fine, its just that I couldnt get the saves to work cuz of them being in different files at the same time
//You cannot get HelperFunctions to have Classes functions in it, ask the teacher on how to avoid this error. 
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include "HelperFunctions.h"
#include "Classes.h"
using namespace std;

int main() {
	if (!filesystem::exists("Administrator")) {
		filesystem::create_directory("Administrator");
	}
	if (!filesystem::exists("Users")) {
		filesystem::create_directory("Users");
	}
	char choice;
	string password;
	string login;
	while (true) {
		cout << "1 - create an admin account/ 2 - create a user account/ 3 - login as admin/ 4 - login as user/ anything else - exit" << endl;
		cin >> choice;
		switch (choice) {
		case '1':
			if (!filesystem::is_empty("Administrator")) {
				cout << "An administrator account already exists, if you proceed you will DELETE the previous account and create a new one, to proceed you have to prove you are the owner of the previous account" << endl;
				cout << "What is the name of the previous admin?" << endl;
				cin >> login;
				cout << "What is the password of the account?" << endl;
				cin >> password;
				if (Admin(login, password).Login() == true) {
					filesystem::remove("Administrator/" + login + ".txt");
					cout << "Deletion succesfull!" << endl;
					cout << "What is the name of the new admin?" << endl;
					cin >> login;
					cout << "What is the password of the new admin?" << endl;
					cin >> password;
					Admin(login, password).signUp();
				}
				else {
					cout << "The name or password did not match, quit deletion of the administrator account" << endl;
					break;
				}
			}
			else {
				cout << "What is the name of the admin account?" << endl;
				cin >> login;
				cout << "What is the password of the admin account?" << endl;
				cin >> password;
				Admin(login, password).signUp();
				break;
			}
			break;
		case '2':
			cout << "What is the name of the account?" << endl;
			cin >> login;
			cout << "What is the password of the account?" << endl;
			cin >> password;
			User(login, password).signUp();
			break;
		case '3':
			cout << "What is the name of the admin?" << endl;
			cin >> login;
			cout << "What is the password of the account?" << endl;
			cin >> password;
			if (Admin(login, password).Login() == true) {
				Admin(login, password).menu();
			}
			break;
		case '4':
			cout << "What is the name of the account?" << endl;
			cin >> login;
			cout << "What is the password of the account?" << endl;
			cin >> password;
			if (User(login, password).Login() == true) {
				User(login, password).menu();
			}
			break;
		default:
			return 0;
		}
	}
}
