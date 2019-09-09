#include "Database.h"

using namespace std;

int main() {

	Database datab;
	cout << "DATABASE TERMINAL -- DataManager 2019" << endl << endl;
	while (true) {
		datab.GetCommand();
	}

	cout << endl;
	system("pause");
	return 0;
}