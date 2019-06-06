#include "meyers.h"


using std::cout;
using std::endl;

int main() {
	NaiveSingleton* inst = NaiveSingleton::instance(4,5);
	cout << inst->GetVolume() << " " << "\n";
	cout << inst->GetArea() << " " << "\n";
	cout << *inst;
	cout << *inst + *inst;
	delete inst;
	system("pause");
	return 0;
}
