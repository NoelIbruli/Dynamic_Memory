/*
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
------------------------------------------------------
Workshop 2 part 1
Module: Car
Filename : Car.h
Version 1
Student	Noel Ibruli
Seneca ID : 117745216
Seneca Email : nibruli@myseneca.ca
Date : 1 / 27 / 22 (MM / DD / YY)
------------------------------------------------------
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#define MAX_PLATE 9
#define MAX_SIZE 61

namespace sdds {

	struct Car
	{
		// holds the license plate in an array
		char license_plate[MAX_PLATE];
		// points to the array in beginning 
		char* make_and_model;
		// holds the time in military format
		int time;
	};

	void VBPLE_Title();
	void initialize(int allocSize);
	void deallocate(Car& C);
	bool read(Car& C);
	void print(const Car& C);
	void record(const Car& C);
	void endOfDay();
}

#endif	