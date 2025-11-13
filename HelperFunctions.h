#pragma once
#include <iostream>
#include <string>
#include "Classes.h"///////////////////////////////
using namespace std;

string make_hash_pass(string passw) {
	string hex_pass = "";
	for (char symb : passw) {
		hex_pass += symb + 13;
	}
	return hex_pass;
}
string get_hash_pass(string passw) {
	string hex_pass = "";
	for (char symb : passw) {
		hex_pass += symb - 13;
	}
	return hex_pass;
}

int discMathTest(int question, int grade) {
	char choice;
	cout << "\nThis test will have 6 questions in total, each question answered correctly will award 2 points. If you wish to exit this test and then continue on later, you can by answering 'D' on the question (the question will not be counted as answered 'D'), you cannot save 2 tests at the same time." << endl;
	for (int i = question; i < 6; i++) {
		switch (i) {
		case 1:
			cout << "1. What is the difference between a set and a subset? A - A subset contains all possible sets. B - A subset contains some or all elements of another set. C - A subset is always larger than the set." << endl;
			cin >> choice;
			if (toupper(choice) == 'B') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 1, grade);
			}
			break;
		case 2:
			cout << "2. How many elements does the power set of a 3-element set have? A - 6 B - 8 C - 9" << endl;
			cin >> choice;
			if (toupper(choice) == 'B') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 1, grade);
			}
			break;
		case 3:
			cout << "3. What is a truth table used for? A - To test the validity of logical expressions. B - To calculate probabilities. C - To store data in tables." << endl;
			cin >> choice;
			if (toupper(choice) == 'A') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 1, grade);
			}
			break;
		case 4:
			cout << "4. Define a graph in discrete mathematics. A - A structure made of vertices and edges. B - A chart used to display data. C - A list of numbers in order." << endl;
			cin >> choice;
			if (toupper(choice) == 'A') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 1, grade);
			}
			break;
		case 5:
			cout << "5. What is the degree of a vertex in a graph? A - The number of edges connected to it. B - Its position in the list of vertices. C - The number of loops only." << endl;
			cin >> choice;
			if (toupper(choice) == 'A') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 1, grade);
			}
			break;
		case 6:
			cout << "6. What does the symbol '^' mean in logic expressions? A - OR B - AND C - NOT" << endl;
			cin >> choice;
			if (toupper(choice) == 'B') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 1, grade);
			}
			break;
		default:
			break;
		}
	}
	cout << "Are you sure you want to submit your test for review? Answer 'A' if you want to finish your test, answer anything else if you want to exit (the test will not be saved and it will not be graded)" << endl;
	cin >> choice;
	if (toupper(choice) == 'A') {
		cout << "\nYou got " << grade / 2 << " questions correct, which means " << (round(grade * 1000 / 12) / 10) << "% of questions were answered correctly!" << endl;

		if (grade == 0) {
			grade = 1; // мінімальна оцінка = 1 в моїй школі
		}

		cout << "\nThe final grade being: " << grade << endl;

		return grade;
	}
	else {
		return 999;
	}
}

int mathAnalyzeTest(int question, int grade) {
	char choice;
	cout << "\nThis test will have 6 questions in total, each question answered correctly will award 2 points. If you wish to exit this test and then continue on later, you can by answering 'D' on the question (the question will not be counted as answered 'D'), you cannot save 2 tests at the same time." << endl;
	for (int i = question; i < 6; i++) {
		switch (i) {
		case 1:
			cout << "1. What is the limit of a function? A - The value the function approaches as x approaches some point. B - The maximum value of a function. C - The derivative of a function." << endl;
			cin >> choice;
			if (toupper(choice) == 'A') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 2, grade);
			}
			break;
		case 2:
			cout << "2. Define the derivative of a function. A - The area under the curve. B - The rate of change of the function. C - The average value of the function." << endl;
			cin >> choice;
			if (toupper(choice) == 'B') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 2, grade);
			}
			break;
		case 3:
			cout << "3. What is the integral of a constant function f(x) = c? A - cx+C B - c^2+C C - 0" << endl;
			cin >> choice;
			if (toupper(choice) == 'A') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 2, grade);
			}
			break;
		case 4:
			cout << "4. What is the difference between a continuous and a discontinuous function? A - Continuous functions have no breaks or jumps. B - Discontinuous functions are always linear. C - Continuous functions have sudden jumps." << endl;
			cin >> choice;
			if (toupper(choice) == 'A') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 2, grade);
			}
			break;
		case 5:
			cout << "5. What does the notation f′(x) represent? A - The limit of the function. B - The derivative of the function. C - The integral of the function." << endl;
			cin >> choice;
			if (toupper(choice) == 'B') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 2, grade);
			}
			break;
		case 6:
			cout << "6. What is the area under a curve used to represent in calculus? A - The integral of a function. B - The slope of a tangent line. C - The average rate of change." << endl;
			cin >> choice;
			if (toupper(choice) == 'A') {
				grade += 2;
			}
			else if (toupper(choice) == 'D') {
				User().saveTest(i, 2, grade);
			}
			break;
		default:
			break;
		}
	}
	cout << "Are you sure you want to submit your test for review? Answer 'A' if you want to finish your test, answer anything else if you want to exit (the test will not be saved and it will not be graded)" << endl;
	cin >> choice;
	if (toupper(choice) == 'A') {
		cout << "\nYou got " << grade / 2 << " questions correct, which means " << (round(grade * 1000 / 12) / 10) << "% of questions were answered correctly!" << endl;

		if (grade == 0) {
			grade = 1; // мінімальна оцінка = 1 в моїй школі
		}

		cout << "\nThe final grade being: " << grade << endl;

		return grade;
	}
	else {
		return 999;
	}
