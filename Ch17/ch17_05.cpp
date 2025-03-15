#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <vector>
using namespace std;

int main() {
  cout << boolalpha << true << " " << false << endl;
  cout << noboolalpha << true << " " << false << endl;

  cout << 0xFF << " " << 1024 << endl;
  cout << showbase << hex << 0xFF << " " << 1024 << dec << endl;
  cout << noshowbase << 0xFF << " " << 1024 << endl;

  cout << left << setw(10) << cout.precision() << setprecision(3) << sqrt(2.0)
       << right << endl;

  // TODO 17.5.2 17.5.3

  return 0;
}
