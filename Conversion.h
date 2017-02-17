#pragma once

#include <string>
#include <vector>

class Conversion
{
	
protected:
	int TOT_INPT = 0;
	std::string INITIAL;
	std::vector <char> ARR_STO;
	std::vector<std::string> Storage;
	
public:
	
	Conversion();
	Conversion(std::string);
	~Conversion();
	void DET_STATE(std::string&);
	int BIN_COVERSION();
	int OCT_CONVERSION();
	std::string HEX_CONVERSION();
	int DECI_CONVERSION();
	int Conversion::TOTAL_AMOUNT();
	void Conversion::PRINT_RESULT();
	std::string FIN_RESULT(int,int,int,std::string);
};