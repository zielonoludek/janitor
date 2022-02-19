#include <iostream>
#include <string>
#include <vector>
#include <locale>

std::string addNote()
{
	std::string rooms[10]{ "Lobby", "Office 1", "Office 2", "Server room 1", "Server room 2", "Kitchen", "Toilet", "Boardroom", "Storeroom", "Janitor's room" };
	std::string room = "";
	std::string newNote;
	int num = 0;

	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << "   " << rooms[i] << std::endl;
	}
	std::cout << std::endl << "Where is something to be repaired, enter room's number : ";

	do
	{
		std::locale loc;
		std::getline(std::cin, room);

		if (std::isdigit(room[0],loc))
		{
			num = stoi(room);
		}
		if (num < 1 || num > 10)
		{
			std::cout << "Enter a proper value : ";
		}
	} while (num < 1 || num > 10);

	std::cout << "You chose :  " << rooms[num - 1] << std::endl << std::endl;

	std::cout << "Write note to save : ";
	std::getline(std::cin, newNote);
	newNote = rooms[num - 1] + "  :  " + newNote;
	
	return newNote;
}

void delNote(std::vector <std::string> &notepad)
{
	if (notepad.empty() == false) 
	{
		std::string number;
		const int WRONG_VALUE = -100;
		int num = WRONG_VALUE;
		std::cout << "Choose the note to delete. Write a number. " << std::endl;
		std::cout << "If you don't want to delete any note, write N" << std::endl;
		
		do
		{
			std::locale loc;
			std::getline(std::cin, number);
			int num = WRONG_VALUE;
			if (number[0] == 'N') 
			{
				break;
			}
			if (std::isdigit(number[0],loc))
			{
				num = stoi(number);
			}
			if (num <= 0 || num > notepad.size())
			{
				std::cout << "Enter a proper value : ";
			}
		} while (num <= 0 || num > notepad.size());

		if (num != WRONG_VALUE)
		{
			notepad.erase(notepad.begin() + num - 1);
		}
	}
}

void viewAll(std::vector <std::string> &notepad)
{
	if (notepad.empty()) {
		std::cout << "You don't have any notes" << std::endl;
	}
	else {
		std::cout << "My notes: " << std::endl;
		for (int i = 0; i < notepad.size(); i++)
		{
			std::cout << i + 1 << ".  " << notepad[i] << std::endl;
		}
		std::cout << std::endl;
	}
}

void menu()
{
	std::cout << std::endl;
	std::cout << "		MENU		" << std::endl;
	std::cout << "1.	Add note" << std::endl;
	std::cout << "2.	Delete note" << std::endl;
	std::cout << "3.	My notes" << std::endl;
	std::cout << "4.	Exit" << std::endl << std::endl ;
}

int main()
{
	bool run = true; 
	std::vector <std::string> notepad;
	
	while (run)
	{
		menu();
		std::string choice;
		std::getline(std::cin, choice);
		std::cout << std::endl;
		if (choice[0] == '1')
		{
			notepad.push_back(addNote());
		}
		if (choice[0] == '2')
		{
			viewAll(notepad);
			delNote(notepad);
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