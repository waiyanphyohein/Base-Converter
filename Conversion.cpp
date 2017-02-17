#include "Conversion.h"
#include <iostream>	
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <sstream>
#include <istream>


Conversion::Conversion() 
{
	std::cout << "Class initialized." << std::endl;
	bool IS_CONTINUE = true;
	std::string CON_D = "";
	INITIAL = "";
	while (IS_CONTINUE) 
	{

		do
		{		
			std::cout << "Enter any value to convert:" << std::endl;
			std::getline(std::cin, INITIAL);

		} while (INITIAL.empty());

		INITIAL.erase(remove(INITIAL.begin(), INITIAL.end(), ' '), INITIAL.end());
		DET_STATE(INITIAL);
		
		std::cout << "Would you like to input another value? If so, Enter Yes(Y);otherwise, No(N)." << std::endl;
		std::getline(std::cin, CON_D);

		if (CON_D == "yes" || CON_D == "YES" || CON_D == "Yes" || CON_D == "Y")
		{
			IS_CONTINUE = true;
		}
		else if (CON_D == "No" || CON_D == "NO"||CON_D == "No"|| CON_D == "N") 
		{
			IS_CONTINUE = false;
		}

		else
		{
			std::cout << "Error Input: Invalid INPUT.Exiting the program.\n";
			system("pause");
			exit(1);
		}

		INITIAL = "";
		CON_D = "";
	}
		PRINT_RESULT();
		//Default Constructor without any input but will ask for the input and do the calculation.
}

Conversion::Conversion(std::string INPUT): INITIAL(INPUT)
{
	std::cout << "Class Initialized." << std::endl;	
	INITIAL.erase(remove(INITIAL.begin(), INITIAL.end(), ' '), INITIAL.end());
	DET_STATE(INITIAL);
	PRINT_RESULT();
	std::cout << "Would you like to input another value? If so, Enter Yes(Y);otherwise, No(N).\n" << std::endl;
	// Constructor with string input
}

Conversion::~Conversion() 
{
	std::cout << "Program has been terminated." << std::endl;
	//Destructor
}
void Conversion::DET_STATE(std::string &INPUT) 
{

	for (int i = 0; i < INITIAL.length(); i++)
	{		
		ARR_STO.push_back(INITIAL[i]);
	}

	std::string DETERM ;
	
	std::cout << "In order to avoid further confusion during our conversion, it is advised that the user should specify the base of an integer of the input to give out the best result." << std::endl;
	std::cout << "Enter Oct for Octo base, Deci for decimal base, Hexa for Hexa_Decimal base, Bin for Binary base." << std::endl;
	std::getline(std::cin, DETERM);
	
	if (DETERM.compare("Oct")==0)
	{	
		std::cout << "OCTO CONVERSION Initialized.\n";
		OCT_CONVERSION();
	}
	else if (DETERM.compare("Deci") == 0)
	{
		std::cout << "Decimal CONVERSION Initialized.\n";
		DECI_CONVERSION();
	}
	else if (DETERM.compare("Hexa") == 0)
	{
		std::cout << "Hexadecimal CONVERSION Initialized.\n";
		HEX_CONVERSION();
	}
	else if (DETERM.compare("Bin") == 0)
	{
		std::cout << "Binary CONVERSION Initialized.\n";
		BIN_COVERSION();
	}
	else
	{
		std::cerr << "Error: Invalid Type Input."<<std::endl;
	}
	//A function that will ask user for input type and do the conversion.
}

int Conversion::DECI_CONVERSION()
{
	int temp = 0;
	int Ini = 0;
	std::vector <int> remainder;
	remainder.clear();
	int Octotemp = 0;
	int Binarytemp = 0;
	std::string Hexatemp = "";

	for (int i = 0; i < ARR_STO.size(); i++)
	{
		if (isdigit(ARR_STO[i]) && (ARR_STO[i]-'0') <= 9)
		{
			temp += pow(10, ARR_STO.size()- (i+1)) * (ARR_STO[i] - '0');
			
		}
		else
		{
			std::cout << "Error Message: Invalid Input.Type should be numeric.";
			system("pause");
			exit(1); // Program will be terminated.
		}
	}
	
	Ini = temp;
	
	//OCTO BASE

	while (temp != 0)
	{
		remainder.push_back(temp % 8);
		temp = temp / 8;		
	}
	for (int i = 0; i < remainder.size(); i++)
	{
		Octotemp += (pow(10, i) * remainder[i]);	
	}
	//std::cout << Octotemp<<std::endl;
	remainder.clear();
	//OCTO BASE

	//BINARY BASE

	temp = Ini;
	
	while (temp != 0)
	{
		remainder.push_back(temp % 2);		
		temp = temp / 2;
	}
	for (int i = 0; i < remainder.size(); i++)
	{
		Binarytemp += (pow(10, i)*remainder[i]);		
	}
	remainder.clear();
	//Binary Base
	
	// Hexa-Decimal
	
	temp = Ini;
	
	while (temp != 0)
	{
		remainder.push_back(temp % 16);
		temp = temp / 16;
	}
	for (int i = 0; i < remainder.size()+1; i++)
	{
		if (remainder.back() >= 10)
		{
			switch (remainder.back())
			{
			case 10:
				Hexatemp += "A";
				remainder.pop_back();
				break;
			case 11:
				Hexatemp += "B";
				remainder.pop_back();
				break;
			case 12:
				Hexatemp += "C";
				remainder.pop_back();
				break;
			case 13:
				Hexatemp += "D";
				remainder.pop_back();
				break;
			case 14:
				Hexatemp += "E";
				remainder.pop_back();
				break;
			case 15:
				Hexatemp += "F";
				remainder.pop_back();
				break;
			default: std::cout << "Error Occurred at Line 169.\n";
				break;
			}
		}
		else if (remainder.back() < 10)
		{
			Hexatemp += std::to_string((int)remainder.back());		
			remainder.pop_back();
		}
		else
		{
			std::cout << "Error: Invalid Argument at Line 181.\n";
			exit(1);
		}
	}


	//Hexa-Decimal	
	ARR_STO.clear();
	Storage.push_back(FIN_RESULT(Octotemp, Ini, Binarytemp, Hexatemp));
	std::cout << "Conversion Complete." << std::endl;
	return Ini;
}

int Conversion::BIN_COVERSION()
{
	int temp = 0;
	int Decimaltemp = 0;
	std::vector <int> remainder;
	int Octotemp = 0;
	int Ini = 0;
	std::string Hexatemp = "";

	for (int i = 0; i < ARR_STO.size(); i++)
	{
		if (isdigit(ARR_STO[i]) && (ARR_STO[i]-'2')<2)
		{
			temp += pow(10, ARR_STO.size() - (i + 1)) * (int)(ARR_STO[i]-'0');
		}
		else
		{
			std::cout << "Error Message: Invalid Input.Type should be numeric.";
			system("pause");
			exit(1); // Program will be terminated.
		}
		
	}
	Ini = temp; // Binary State.
	

	// Decimal Base 

	for (int i = 0; i < ARR_STO.size(); i++)
	{
		Decimaltemp += pow(2, ARR_STO.size() - (i + 1)) * (int)(ARR_STO[i] - '0');	
	}
	temp = Decimaltemp;
	
	//Decimal Bases

	//Octo Base

	while (temp != 0)
	{
		remainder.push_back(temp % 8);
		temp = temp / 8;
	}
	for (int i = 0; i < remainder.size(); i++)
	{
		Octotemp += (pow(10, i) * remainder[i]);
		
	}
	remainder.clear();

	temp = Decimaltemp;
	//Octo Base
	
	// HexaDecimal Base
		
	while (temp != 0)
	{
		remainder.push_back(temp % 16);
		temp = temp / 16;
	}

	for (int i = 0; i < remainder.size()+1; i++)
	{
		if (remainder.back() >= 10)
		{
			switch (remainder.back())
			{
			case 10:
				Hexatemp += "A";
				remainder.pop_back();
				break; 
			case 11:
				Hexatemp += "B";
				remainder.pop_back();
				break;
			case 12:
				Hexatemp += "C";
				remainder.pop_back();
				break;
			case 13:
				Hexatemp += "D";
				remainder.pop_back();
				break;
			case 14:
				Hexatemp += "E";
				remainder.pop_back();
				break;
			case 15:
				Hexatemp += "F";
				remainder.pop_back();
				break;
			default: std::cout << "Error Occurred at Line 274.\n";
				break;
			}
		}
		else if (remainder.back() < 10)
		{
			Hexatemp += std::to_string(remainder.back());
			remainder.pop_back();
		}
		else
		{
			std::cout << "Error: Invalid Argument at Line 181.\n";
			system("pause");
			exit(1);
		}
	}
	remainder.clear();
	//Hexa-Decimal	
	ARR_STO.clear();
	Storage.push_back(FIN_RESULT(Octotemp, Decimaltemp, Ini, Hexatemp));
	std::cout << "Conversion Complete." << std::endl;
	return Ini;
}

std::string Conversion::HEX_CONVERSION() 
{
	std::string Ini = "";
	unsigned long long int temp = 0,Decimaltemp = 0,Binarytemp = 0;
	int Octotemp = 0;
	std::vector<int> Remainder;
	
	//Hexadecimal Base

	for (int i = 0; i < ARR_STO.size(); i++)
	{
		if (isdigit(ARR_STO[i]) || (isalpha(ARR_STO[i]) && (ARR_STO[i] <= 'F'||ARR_STO[i] >= 'A')))
		{
			if (isdigit(ARR_STO[i]))
			{
				Ini += ARR_STO[i];
			}
			else if (isalpha(ARR_STO[i]) )
			{
				int tempSto = 0;
				tempSto = ARR_STO[i] - 55;

				switch (tempSto)
				{
				case 10:
					Ini += "A";
					break;
				case 11: 
					Ini += "B";
					break;
				case 12:
					Ini += "C";
					break;
				case 13:
					Ini += "D";
					break;
				case 14:
					Ini += "E";
					break;
				case 15:
					Ini += "F";
					break;
				default: std::cout << "Error Occurred at Line 337.\n";
					exit(1);
					
				}

			}
		}
		else
		{
			std::cerr << "Invalidity Error: Please enter the value correctly.";
			system("pause");
			exit(1);
		}

	}

	//Hexadecimal Base

	//Decimal Base

	for (int i = 0; i < Ini.size();i++)
	{
		if (Ini[i] - '0' <= 9)
			temp += pow(16, Ini.size() - (i + 1))*(int)(ARR_STO[i] - '0');
		else if (Ini[i] - '0' > 9)
			temp += pow(16, Ini.size() - (i + 1))*((int)ARR_STO[i] - 55);
	}
	Decimaltemp = temp;
	
	//Decimal Base

	// Binary Base
	
	
	while (temp != 0)
	{
		Remainder.push_back(temp % 2);
		temp = temp / 2;
	}
	for (int i = 0; i < Remainder.size(); i++)
	{
		Binarytemp += (pow(10,i) * Remainder[i]);
	}
	
	// Binary Base

	// Octo Base

	temp = Decimaltemp;
	Remainder.clear();
	
	while (temp != 0)
	{
		Remainder.push_back(temp % 8);
		temp = temp / 8;
	}
	for (int i  = 0; i < Remainder.size();i++)
	{
		Octotemp += (pow(10, i) * Remainder[i]);
		
	}
	
	ARR_STO.clear();

	// Octo BaseStorage.push_back(FIN_RESULT(Octotemp, Decimaltemp, Ini, Hexatemp));0
	Storage.push_back(FIN_RESULT(Octotemp, Decimaltemp, Binarytemp, Ini));

	std::cout << "Conversion Complete." << std::endl;
	return Ini; 
}

	

int Conversion::OCT_CONVERSION()
{

	int temp = 0;
	int Decimaltemp = 0;
	std::vector <int> remainder;
	int Ini= 0;
	int Binarytemp = 0;
	std::string Hexatemp = "";

	for (int i = 0; i < ARR_STO.size(); i++)
	{
		if (isdigit(ARR_STO[i]) && (ARR_STO[i] - '0') < 8 )
		{
			temp += pow(10, ARR_STO.size() - (i + 1)) * (int)(ARR_STO[i] - '0');
		}
		else
		{
			std::cout << "Error Message: Invalid Input.Type should be numeric.";
			system("pause");
			exit(1); // Program will be terminated.
		}

	}
	Ini = temp;

	// Decimal Base 

	for (int i = 0; i < ARR_STO.size(); i++)
	{
		Decimaltemp += pow(8, ARR_STO.size() - (i + 1)) * (int)(ARR_STO[i] - '0');
	}
	temp = Decimaltemp;

	//Decimal Bases

	//Binary Base

	while (temp != 0)
	{
		remainder.push_back(temp % 2);
		temp = temp / 2;
	}
	for (int i = 0; i < remainder.size(); i++)
	{
		Binarytemp += (pow(10, i)*remainder[i]);
	}

	//Binary Base
	temp = Decimaltemp;

	//Hexadecimal Base
	remainder.clear();
	while (temp != 0)
	{
		remainder.push_back(temp % 16);
		temp = temp / 16;
	}
	for (int i = 0; i < remainder.size()+1; i++)
	{
		if (remainder.back() >= 10)
		{
			switch (remainder.back())
			{
			case 10:
				Hexatemp += "A";
				break;
			case 11:
				Hexatemp += "B";
				break;
			case 12:
				Hexatemp += "C";
				break;
			case 13:
				Hexatemp += "D";
				break;
			case 14:
				Hexatemp += "E";
				break;
			case 15:
				Hexatemp += "F";
				break;
			default: std::cout << "Error Occurred at Line 489.\n";
				break;
			}
		}
		else if (remainder.back()< 10)
		{
			Hexatemp += std::to_string((int)remainder.back());
			remainder.pop_back();
		}
		else
		{
			std::cout << "Error: Invalid Argument at Line 500.\n";
			exit(1);
		}
	}

	//Hexadecimal Base
	ARR_STO.clear();
	Storage.push_back(FIN_RESULT(Ini, Decimaltemp, Binarytemp, Hexatemp));
	std::cout << "Conversion Complete." << std::endl;
	return Ini;
}

void Conversion::PRINT_RESULT()
{
	for (int i = 0; i< Storage.size();i++)
	{
		std::cout << "Printing the result:\n";
		std::cout << Storage[i] << std::endl;
	}
}


std::string Conversion:: FIN_RESULT(int Octo,int Decimal,int Binary,std::string Hexa)
{
	TOT_INPT++;
	std::stringstream buffer;
	buffer 
		<< TOT_INPT<<") Decimal Value: " << Decimal << "\n"
		<< "   Octo Value: " << Octo << "\n"
		<< "   Binary Value: " << Binary << "\n"
		<< "   Hexa-decimal Value: " << Hexa << "\n";
	return buffer.str();
}

int Conversion::TOTAL_AMOUNT()
{
	return TOT_INPT;
}