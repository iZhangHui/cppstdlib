#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>

using namespace std;

void doSomething(int num, char c)
{
    try {
        // random-number generator (use c as seed to get different sequences)
        default_random_engine dre(42*c);
        uniform_int_distribution<int> id(10, 1000);
        for (int i = 0; i < num; ++i) {
            this_thread::sleep_for(chrono::milliseconds(id(dre)));
            cout.put(c).flush();
        }
    // make sure no exception leaves the thread and terminates the program
    } catch (const exception& e) {
        cerr << "THREAD-EXCEPTION (thread "
             << this_thread::get_id() << "): " << e.what() << endl;
    } catch (...) {
        cerr << "THREAD-EXCEPTION (thread "
             << this_thread::get_id() << ")" << endl;
    }
}

int main()
{
    thread t1(doSomething, 5, '.');
    thread t2(doSomething, 5, '+');
    thread t3(doSomething, 5, '*');

    cout << "t3 ID:       " << t3.get_id() << endl;
    cout << "main ID:     " << this_thread::get_id() << endl;
    cout << "nothread ID: " << thread::id() << endl;

    t1.join();
    t2.join();
    t3.join();

}

