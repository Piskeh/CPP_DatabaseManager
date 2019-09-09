#include "Database.h"

using namespace std;

void Database::SaveDatabase(string name) {

	fstream file(name, ios::out | ios::binary | ios::beg);
	
	if (table.size() > 0) {
		file.write((char*)& table[0], table.size() * sizeof(table));
	}
	else {
		cout << "Exception: must have data to save" << endl << endl;
	}

	file.close();
}

// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------

void Database::Help() {

	cout << endl << "POSSIBLE COMMANDS: " << endl;
	cout << "add STRING <--> where string is text data to be appended to database" << endl;
	cout << "display <--> print current database" << endl;
	cout << "save <--> saves current database as .bin file" << endl;
	cout << "find STRING <--> searches current database for string" << endl;
	cout << "display << INTEGER <--> display values at index" << endl;
	cout << "display < OR > INTEGER <--> displays smaller OR larger than given integer " << endl << endl;

}

// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------

void Database::DisplayDataAt(int loc) {
	cout << table.at(loc) << endl;
}

// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------

void Database::GetCommand() {
	
	string stri;
	getline(cin, stri);
	istringstream stream(stri);

	vector<string> vec;

	do {
		string word;
		stream >> word;
		vec.push_back(word);

	} while (stream);


	if (vec[0] == "find") {
		Find(vec[1]);
	} else 



	// CHECK THE DATABASE
	if (vec[0] == "display") {
		if (vec[1] == ">") {
			Check(stoi(vec[2]), true);
		}
		else if (vec[1] == "<") {
			Check(stoi(vec[2]), false);
		}
	} else

	// SAVE THE DATABASE
	if (vec[0] == "save") {
		if (vec[1] != "") {
			SaveDatabase(vec[1]);
		}
		else {
			cout << "Exception: must provide a save name" << endl << endl;
		}
	} else 

	// DISPLAY HELP
	if (vec[0] == "help") {
		Help();
	} else 

	// DISPLAY DATA AT SPECIFIC INDEX
	if (vec[0] == "display") {
		if (vec[1] == "<<") {
			try {

				DisplayDataAt(stoi(vec[2]));
			}
			catch (exception& e) {
				cout << "Exception: the index could not be understood";
			}
		}
	// DISPLAY DATA AT ALL INDEXES IF NO INDEX SPECIFIED
		else {
			if (vec[1] != ">" && vec[1] != "<") {
				DisplayData();
			}
		}
		
	} else

	// ADD DATA TO DATABASE
	if (vec[0] == "add") {
		if (vec[1] != "") {
			for (int i = 1; i < vec.size(); i++) {
				AddData(vec[i]);
			}
		}
		else {
			cout << "Exception: no data found to add to database" << endl << endl;
		}
	
	}
	// NO COMMAND COULD BE UNDERSTOOD
	else {
		cout << "COMMAND NOT FOUND" << endl << endl;
	}
}

// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------

void Database::DisplayData() {
	if (table.size() > 0) {
		cout << endl << "Data Layout: " << endl;
		for (int i = 0; i < table.size()-1; i++) {
			cout << table[i] << " at table location " << i << endl;
			if (i == table.size()-2) {
				cout << endl;
			}
		}
	}
	else {
		cout << "Exception: no data in table to display" << endl << endl;
	}
}

// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------

void Database::AddData(string data) {
	table.push_back(data);
}

// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------

void Database::Check(int check, bool greaterThan) {
	for (int i = 0; i < table.size(); i++) {
		if (!greaterThan) {
			if (check > table.at(i).size() && i+1 < table.size()) {
				cout << "Found match " << table.at(i) << " at location " << i << endl;
			}
		}
		else {
			if (check < table.at(i).size() && i+1 < table.size()) {
				cout << "Found match " << table.at(i) << " at location " << i << endl;
			}
		}
	}
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------

void Database::Find(string str2) {
	string str1;
	bool found = false;
	for (int i = 0; i < table.size(); i++) {
		str1 = table.at(i);
		if (str1.find(str2) != string::npos) {
			cout << "Found match " << table.at(i) << " at location " << i << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Could not locate " << "'" << str2 << "' in database." << endl;
	}
	
}

// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------