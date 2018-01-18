#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include "BMI.h"


/**
Add new person to the list
This method adds new person to the end of the one way list
*/

void List::Add_person(std::string _name, int _age, double _height, double _weight)
{
	std::shared_ptr<Personal_data>person=std::make_shared<Personal_data>();
	person->m_name = _name; 
	person->m_age = _age;
	person->m_height = _height;
	person->m_weight = _weight;
	person->m_bmiRate = (_weight / ((_height*_height)*0.0001));

	if (m_firstPerson == NULL)
	{
		m_firstPerson = person;
	}

	else
	{
		std::shared_ptr<Personal_data>temp = m_firstPerson;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = person;
		person->next = NULL;
	}
}

/**
Delete person function
This method delets chosen person
At first,user passes the parameter with a chosen integer value of person he'd like to delete
from the list
If this is a first person on the list,the "if" statement just switch "first_person" to the
"first_person"+1
If this is not a first person on the list,the "while" loop searches for a person "nr-1"
When it is found,the function overwrite *temp pointer from "nr" into "nr+1"
If it was last person on a list,the last pointer takes value 0
*/

void List::Del_person(int nr)
{
	std::shared_ptr<Personal_data>temp = m_firstPerson;
	if (nr == 1)
	{
		m_firstPerson = temp->next;
	}

	if (nr >= 2)
	{
		int a = 1; 
		while (temp)
		{
			if (a + 1 == nr)
			{
				break;
			}
			temp = temp->next;
			a++;
		}
		if (temp->next->next == 0)
			temp->next = 0;
		else
			temp->next = temp->next->next;
	}
}

/**
The show list function
This method shows all the persons that are on the list
At first there is a "temp" pointer built which is set on "first_person",and integer variable "counter"
Then there is a "while" loop,which shows next persons(at the end of every loop,the "temp" pointer is 
set to the next person as long,as there is data).Also the counter variable (which is an ID of
every person) is incremented after every loop.
*/


void List::Show_list()
{
	std::shared_ptr<Personal_data>temp = m_firstPerson;
	 int counter = 1;
	while (temp)
	{
		std::cout << counter << std::endl;
		std::cout << "||Name: " << temp->m_name << std::endl;
		std::cout << "||Age: " << temp->m_age<<std::endl;
		std::cout << "||Weight: " << temp->m_weight << std::endl;
		std::cout << "||Height: " << temp->m_height<< std::endl;
		std::cout << "||BMI index: " << std::setprecision(4)<< temp->m_bmiRate << std::endl;
		std::cout << "||Overall: " << temp->countBmi()<< std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		temp = temp->next;
		counter++;
	}
}

/**
The count BMI function
This method returns string with a result of each person's BMI rate
*/


std::string Personal_data::countBmi()
{
	if (m_bmiRate >18.5&&m_bmiRate < 25)
	{
		return "healthy weight";
	}
	else if (m_bmiRate>25)
	{
		return "overweight";
	}
	else
	{
		return "underweight";
	}
}

/**
This method allows user to choose an option from the several available variants which are 
After calling each case variant(except variant 4),function goes back to main menu
*/


std::string&checkIfCorrectName(std::string &name)
{
	std::cout << "Enter name: " << '\n';
	bool check = true;
	int lenght = 0;
	while (check) {
		std::cin >> name;
		lenght = name.length();
		for (int letter = 0; letter < lenght; ++letter) {
			if (!isalpha(name[letter])) {
				std::cout << "Name must consist only from the letters" << '\n';
				break;
			}
			else if (letter == (lenght - 1)) {
				check = false;
			}

		}
		}
	return name;
	}

int checkIfCorrectAge()
{
	int value;
	std::cout << "Enter age" << '\n';
	while (!(std::cin >> value) || value < 1 || value >130) {
		std::cout << "The age You have entered is not correct.Put an age between 1 and 130" << '\n';
		std::cin.clear();
		std::cin.sync();
		std::cin.ignore(INT_MAX, '\n');
	}
	return value;
}

double checkIfCorrectHeight()
{
	double value;
	std::cout << "Enter height" << '\n';
	while (!(std::cin >> value) || value < 1 || value >250) {
		std::cout << "The value You have entered is not correct.Put a height between 1 and 250" << '\n';
		std::cin.clear();
		std::cin.sync();
		std::cin.ignore(INT_MAX, '\n');
	}
	return value;
}

double checkIfCorrectWeight()
{
	double value;
	std::cout << "Enter weight" << '\n';
	while (!(std::cin >> value) || value < 1 || value >250) {
		std::cout << "The value You have entered is not correct.Put a weight between 1 and 250" << '\n';
		std::cin.clear();
		std::cin.sync();
		std::cin.ignore(INT_MAX, '\n');
	}
	return value;
}


void Menu()
{
		int choice=0; /*!< variable used to make a choice in a switch statement */
		std::shared_ptr<List>person=std::make_shared<List>();
		do
		{
			system("cls");
			std::cout << "Body Mass Index Calculator" << std::endl;
			std::cout << "Choose option: " << std::endl;
			std::cout << "1.Add person" << std::endl;
			std::cout << "2.Delete person" << std::endl;
			std::cout << "3.Show list" << std::endl;
			std::cout << "4.End" << std::endl;
			std::cin >> choice;
	switch (choice)
	{
	case 1 :
	{
	std::string name;
	int age;
	double height; 
	double weight; 
	name = checkIfCorrectName(name);
	age = checkIfCorrectAge();
	height = checkIfCorrectHeight();
	weight = checkIfCorrectWeight();
	person->Add_person(name, age, height, weight);
	break;
	}
	case 2 :
	{
				int nr; /*!< a variable used to pass the ID of a person which is chosen do be delete*/
				std::cout << "Put ID You would like to remove from the list" << std::endl;
				std::cin >> nr;
				person->Del_person(nr);
				break;
	}
	case 3 :
	{
				person->Show_list();
				system("pause");
				break;
	}
	default:
	{
			   if (choice != 4){
				   std::cout << "choose correct option from the list" << std::endl;
				   system("pause");
				   break;
			   }

	}
	}
		} while (choice != 4);
}