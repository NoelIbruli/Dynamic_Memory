/*
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
------------------------------------------------------
Workshop 2 part 1
Module: Car
Filename : Car.cpp
Version 1
Student	Noel Ibruli
Seneca ID : 117745216
Seneca Email : nibruli@myseneca.ca
Date : 1 / 27 / 22 (MM / DD / YY)
------------------------------------------------------
*/

// Disclaimer: I do not use the namespace std. Reason being 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "cStrTools.h"
#include "Car.h"

namespace sdds {

	// this pointer will hold a dynamic array of Car structures (the Car Pointer) 
	Car* car_ptr;
	// expansion memory
	int allocation_size;
	// number of cars currently in the dynamic array pointed by car_ptr
	int num_of_cars;
	// holds the current allocation size of the array. max numbers that we can hold before expanding it
	int car_array_size;

	// prints a message
	void VBPLE_Title()
	{
		std::cout << "Vehicle Border Passing Log Entry\n";
		std::cout << "Enter the data in the following format:\n";
		std::cout << "Make and model,LicensePlate,MilitaryTime<ENTER>\n";
		std::cout << "Exit the program by entering the following:\n";
		std::cout << "X,<ENTER>\n";
	}

	// initialize the values of the four file-scoped variables
	void initialize(int allocSize)
	{
		num_of_cars = 0;
		car_array_size = allocSize;
		allocation_size = allocSize;
		car_ptr = new Car[allocation_size];
	}

	// deletes allocated memory pointed by the make_and_model pointer in the Car struct and sets it to nullptr
	void deallocate(Car& C)
	{
		delete[] C.make_and_model;
		C.make_and_model = nullptr;
	}

	// reads the information of car passing the border in a comma seperated format from the console
	// dynamically holds the make and model in make_and_model pointer of the Car struct
	// returns true if a car is red, returns false if X is entered instead
	bool read(Car& C)
	{
		
		bool flag = false;
		// holds make and model
		char cString[MAX_SIZE];

		// read the make and model
		read(cString, MAX_SIZE - 1, ',');

		if (cString[0] != 'X')
		{
			flag = true;
			// dynamic array is assigned the size of the old array (from the console) + null byte char
			C.make_and_model = new char[strLen(cString) + 1];
			// copy the make and model to the dyamic array
			strCpy(C.make_and_model, cString);
			// reads license plate
			read(C.license_plate, MAX_PLATE - 1, ',');
			// read time
			std::cin >> C.time;
		}
		else
		{
			exit(0);
		}
		return flag;
	}

	// records the passage of the array (make and model, time and license plate)by adding its information to the car array
	void record(const Car& C)
	{
		Car* temp_ptr = nullptr;

		if (num_of_cars == car_array_size)
		{
			// dynamically allocating new memory 
			temp_ptr = new Car[car_array_size + allocation_size];
			// copy values from the old array to new array
			for (int i = 0; i < car_array_size; i++)
			{
				temp_ptr[i] = car_ptr[i];
			}
			delete[] car_ptr;
			// car pointer points to new array
			car_ptr = temp_ptr;
			// car_array_size assigned to the size of the new array
			car_array_size += allocation_size;	
		}
		car_ptr[num_of_cars] = C;
		num_of_cars++;
	}

	void print(const Car& C)
	{
		std::cout << C.time << ": " << C.make_and_model << "," << C.license_plate << std::endl;
	}

	void endOfDay()
	{
		for (int i = 0; i < car_array_size; i++)
		{
			print(car_ptr[i]);
			deallocate(car_ptr[i]);
		}
		delete[] car_ptr;
		car_ptr = nullptr;
	}
}