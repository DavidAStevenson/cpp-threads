#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex printMutex_;
void print(const string& s) {
    lock_guard<mutex> guard(printMutex_);
    cout << s << endl;
}

struct Foo {
    void operator()() {
        print("Executing in a thread other than main.");
    }
};

void nonMemberFunction(int n) {
    print("nonMemberFunction: " + to_string(n) + " was passed.");
}

int main() {
    cout << "Enter main." << endl;

    Foo foo;
    thread t(foo);
    t.join();

    thread t2(nonMemberFunction, 666);
    cout << "t2 joinable before join()? : " << boolalpha << t2.joinable() << endl;
    t2.join();
    cout << "t2 joinable after join()? : " << boolalpha << t2.joinable() << endl;

    cout << "Exit main." << endl;
    return 0;
}

