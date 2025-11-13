#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include "HelperFunctions.h"/////////////////////////////////////////
using namespace std;

class Template {
protected:
	string login;
	string password;
public:
	virtual string get_password() = 0;
	virtual void menu() = 0;
};

class User : public Template {
private:
	string login;
	string password;
public:
	User(string _login = "", string _password = "") {
		this->login = _login;
		this->password = _password;
	}

	string get_password() override {
		ifstream file("Users/" + login + "/password.txt");
		if (file.is_open()) {
			string filePassword;
			string line;
			while (getline(file, line)) {
				filePassword += line;
			}
			return get_hash_pass(filePassword);
		}
		return "";
	}

	vector<int> getGrades() {
		ifstream file("Users/" + login + "/grades.txt");
		vector<int> grades;
		if (file.is_open()) {
			string grade;
			while (getline(file, grade, ',')) {
				if (grade != "")
					grades.push_back(stoi(grade));
			}
		}
		return grades;
	}

	void saveTestGrade(int grade) {
		bool isEmpty = false;
		if (filesystem::exists("Users/" + login + "/grades.txt") && filesystem::is_empty("Users/" + login + "/grades.txt") == true) {
			isEmpty = true;
		}

		ofstream file("Users/" + login + "/grades.txt", ios::app);
		if (!file.is_open()) {
			return;
		}
		if (isEmpty == false) {
			file << ",";
		}
		file << grade;
	}

	void getAllGradeData() {
		vector<int> previousDataSaved = getGrades();
		int totalGrade = 0;
		cout << "All of the grades:" << endl;
		for (int i = 0; i < previousDataSaved.size(); i++) {
			totalGrade += previousDataSaved[i];
			cout << previousDataSaved[i];
			if (i < previousDataSaved.size() - 1) {
				cout << ", ";
			}
		}
		if (previousDataSaved.size() != 0) {
			cout << "\nAverage grade = " << round(totalGrade * 10.0 / previousDataSaved.size()) / 10 << endl;
		}
		else {
			cout << "The average grade cannot be calculated due to the lack of grades" << endl;
		}
	}

	void saveTest(int question, int typeOfTest, int grade) {
		ofstream file("Users/" + login + "/savedTestQuestion.txt");
		if (file.is_open()) {
			file << question;
		}
		ofstream file2("Users/" + login + "/savedTestType.txt");
		if (file2.is_open()) {
			file2 << typeOfTest;
		}
		ofstream file3("Users/" + login + "/savedTestGrade.txt");
		if (file3.is_open()) {
			file3 << grade;
		}
	}

	int getTestQuestion() {
		string question = "";
		ifstream file("Users/" + login + "/savedTestQuestion.txt");
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				question += line;
			}
		}
		cout << "question saved was: " << question << endl;
		return stoi(question);
	}

	int getTestType() {
		string test = "";
		ifstream file("Users/" + login + "/savedTestType.txt");
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				test += line;
			}
		}
		cout << "test saved was: " << test << endl;
		return stoi(test);
	}

	int getTestGrade() {
		string grade = "";
		ifstream file("Users/" + login + "/savedTestGrade.txt");
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				grade += line;
			}
		}
		cout << "grade saved was: " << grade << endl;
		return stoi(grade);
	}

	void menu() override {
		char choice;
		int grade;
		int question;
		int test;
		while (true) {
			cout << "1 - Do a mathematics test/ 2 - See all grades/ 3 - Load the saved test/ anything else - exit" << endl;
			cin >> choice;
			switch (choice) {
			case '1':
				cout << "Which one do you want to do? 1 - Discrete mathematics/ 2 - Mathematical analysis" << endl;
				cin >> choice;
				switch (choice) {
				case '1':
					grade = discMathTest(0, 0);
					if (grade > 12) {
						return;
					}
					else {
						saveTestGrade(grade);
					}
					break;
				case '2':
					grade = mathAnalyzeTest(0, 0);
					if (grade > 12) {
						return;
					}
					else {
						saveTestGrade(grade);
					}
					break;
				}
				break;
			case '2':
				getAllGradeData();
				break;
			case '3':
				question = getTestQuestion();
				test = getTestType();
				grade = getTestGrade();
				switch (test) {
				case 1:
					discMathTest(question, grade);
					break;
				}
				case 2:
					mathAnalyzeTest(question, grade);
					break;
			default:
				return;
			}
		}
	}

	bool signUp() {
		if (!filesystem::exists("Users/" + login)) {
			filesystem::create_directory("Users/" + login);
		}
		if (!filesystem::exists("Users/" + login + "/password.txt")) {

			ofstream file("Users/" + login + "/password.txt");

			if (file.is_open()) {
				if (password != "") {
					file << make_hash_pass(password);
					cout << "User account created!" << endl;
					return true;
				}
				else {
					cout << "Password cannot be nothing!" << endl;
					return false;
				}
			}
			else {
				cout << "File couldnt be created" << endl;
				return false;
			}
		}
		else {
			cout << "Such user already exists!" << endl;
		}
	}

	bool Login() {
		ifstream file("Users/" + login + "/password.txt");
		if (file.is_open()) {
			string line;
			if (password == get_password()) {
				cout << "Login successfull!" << endl;
				return true;
			}
			else {
				cout << "Password is wrong!" << endl;
				return false;
			}
		}
		else {
			cout << "Such user was not found!" << endl;
			return false;
		}
	}
};

class Admin : public Template {
private:
	string login;
	string password;
public:

	Admin(string _login = "", string _password = "") {
		this->login = _login;
		this->password = _password;
	}

	string get_password() override {
		ifstream file("Administrator/" + login + ".txt");
		if (file.is_open()) {
			string filePassword;
			string line;
			while (getline(file, line)) {
				filePassword += line;
			}
			return get_hash_pass(filePassword);
		}
		return "";
	}

	void menu() override {
		char choice;
		cout << "1 - edit user accounts/ 2 - see test results " << /* to see test specific results - add 2 new files with them saving grades only for their specific test*/"/ 3 - edit a test" << endl;
		switch (choice) {
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		default:
			return;
		}
	}

	bool signUp() {
		ofstream file("Administrator/" + login + ".txt");

		if (file.is_open()) {
			if (password != "") {
				file << make_hash_pass(password);
				cout << "Admin account created!" << endl;
				return true;
			}
			else {
				cout << "Password cannot be nothing!" << endl;
				return false;
			}
		}
		else {
			cout << "File couldnt be created" << endl;
			return false;
		}
	}

	bool Login() {
		ifstream file("Administrator/" + login + ".txt");
		if (file.is_open()) {
			string line;
			if (password == get_password()) {
				cout << "Login successfull!" << endl;
				return true;
			}
			else {
				cout << "Password is wrong!" << endl;
				return false;
			}
		}
		else {
			cout << "Such admin was not found!" << endl;
			return false;
		}
	}
};
