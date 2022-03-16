#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <locale>
#include <map>

void addNote(std::map<std::string, std::vector <std::string>> &notepad)
{
	std::string newNote;
	std::string place;
	std::locale loc;
	std::cout << std::endl << "Where is something to repair? \n";
	std::getline(std::cin, place);
	std::cout << std::endl << "Note:  ";
	std::getline(std::cin, newNote);

	if (newNote != "") {
		int help = 0;
		for (auto i = notepad.begin(); i != notepad.end(); ++i) {
			if (place == i->first) {
				i->second.push_back(newNote);
				help = 1;
			}
		}
		if (help == 0) {
			std::vector <std::string> nVec;
			nVec.push_back(newNote);
			notepad.insert(std::pair <std::string, std::vector<std::string>>(place, nVec));
		}
	}
}

void delNote(std::map<std::string, std::vector <std::string>>& notepad)
{
	if (notepad.empty() == false){
		std::string number;
		const int WRONG_VALUE = -100;
		int num = WRONG_VALUE;
		std::cout << "Choose the note to delete. Write a number. " << std::endl << "If you don't want to delete any note, write N" << std::endl;

		do{
			std::locale loc;
			int num = WRONG_VALUE;
			std::getline(std::cin, number);
			if (number[0] == 'N')
			{
				break;
			}
			else if (std::isdigit(number[0], loc))
			{
				num = stoi(number.substr(0,6));
			}
			if (num < 0 || num > notepad.size())
			{
				std::cout << "Enter a proper value : ";
			}
		} while (num <= 0 || num > notepad.size());
		
		if (num != WRONG_VALUE)
		{
			//notepad.erase(notepad.begin() + num - 1);
		}
	}
}


void viewAll(std::map<std::string, std::vector <std::string>>& notepad)
{
	if (notepad.empty()) {
		std::cout << "You don't have any notes" << std::endl;
	}
	else {
		std::map< std::string, std::vector <std::string >>::iterator itr;
		for (itr = notepad.begin(); itr != notepad.end(); ++itr) {
			std::cout << itr->first << '\t';
			for (auto n : itr->second) {
				std::cout << '\t' << n;
			}
			std::cout << std::endl;
		}
	}
}

void menu()
{
	std::cout << std::endl<< "		MENU		" << std::endl;
	std::cout << "1.	Add note" << std::endl;
	std::cout << "2.	Delete note" << std::endl;
	std::cout << "3.	My notes" << std::endl;
	std::cout << "4.	Exit" << std::endl << std::endl ;
}

int main()
{
	bool run = true;
	std::map<std::string, std::vector <std::string>> notepad;

	while (run)
	{
		menu();
		std::string choice;
		std::getline(std::cin, choice);
		std::cout << std::endl;
		if (choice[0] == '1')
		{
			addNote(notepad);
		}
		if (choice[0] == '3')
		{
			viewAll(notepad);
		}
		if (choice[0] == '4')
		{
			run = false;
		}
	}
	return 0;

}