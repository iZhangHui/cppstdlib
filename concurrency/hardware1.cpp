#include <thread>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	auto hardware_threads = thread::hardware_concurrency();
	cout << "Hardware processors = " << hardware_threads << endl;
	return 0;
}