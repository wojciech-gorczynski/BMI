#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
/**
Personal_data struct
This structure contains all the data of each person on the list
*/

struct Personal_data
{
	std::string m_name; /*!< person's name */
	int m_age; /*!< person's age */
	double m_height; /*!< person's height */
	double m_weight; /*!< person's weight */
	double m_bmiRate; /*!< person's bmi rate */
	std::string countBmi();
	//Personal_data * next; /*!< a pointer typed of Personal_data */
	std::shared_ptr<Personal_data>next;
	///a default constructor whichs sets "next" pointer on the NULL value
	Personal_data()
	{
		next = nullptr;
	};
};

/**
List struct
This structure contains all the methods user need to operate the list
There is also a pointer of type Personal_data named "first_person"
*/
struct List
{
	//Personal_data *m_firstPerson; /*!<a pointer typed of Personal_data  */
	std::shared_ptr<Personal_data>m_firstPerson;
	/** a function which adds new person to the list 
	@param name parameter passes name do the function
	@param age parameter passes age do the function
	@param heigth parameter passes height do the function
	@param weight parameter passes weight do the function
	*/
	void Add_person(std::string name, int age, double height, double weight);
	/** a function which deletes chosen person from to the list 
	@param nr parameter passes ID of the person which is chosen to be deleted
	*/
	void Del_person(int nr);
	/**a function which shows all persons added to the list so far
	*/
	void Show_list();
	///a default constructor whichs sets "first_person" pointer on the NULL value
	List(){ m_firstPerson = nullptr; };
};
std::string&checkIfCorrectName(std::string &name);
int checkIfCorrectAge();
double checkIfCorrectHeight();
double checkIfCorrectWeight();
void Menu();
