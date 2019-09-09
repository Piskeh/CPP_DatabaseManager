#ifndef DATAB_H
#define DATAB_H

#include <iostream>
#include <vector>
#include "Database.h"
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Database {
public:
	void DisplayData();
	void DisplayDataAt(int loc);
	void AddData(string data);
	void GetCommand();
	void Check(int, bool);
	void Find(string);
	void Key();
	vector<string> table;
	void Help();
private:
	void SaveDatabase(string name);
};

#endif