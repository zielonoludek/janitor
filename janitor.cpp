#include <iostream>
#include <string>
#include <vector>

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
		std::getline(std::cin, room);
		if (std::isdigit(room[0]))
		{
			num = stoul(room);
		}
		if (num < 1 || num > 10)
		{
			std::cout << "Enter the proper value : ";
		}
	} while (num < 1 || num > 10);
	std::cout << "You chose :  " << rooms[num - 1] << std::endl << std::endl;

	std::cout << "Write the note, you want to be written down : ";
	std::getline(std::cin, newNote);
	return newNote, rooms[num - 1];
}

void delNote(std::vector <std::string> Vroom, std::vector <std::string> notepad)
{

}

int main()
{

	std::vector <std::string> Vroom;
	std::vector <std::string> notepad;
	notepad.push_back(addNote());

	for (int i = 0; i < notepad.size(); i++)
	{
		std::cout << 'x';
		std::cout << notepad[i];
	}

	return 0;

}