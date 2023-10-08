#include <iostream>
#include <exception>
#include <string>
#include <system_error>

using namespace std;

// string AskTimeServer() {
// 	int a = 7;
// 	if (a == 5)
// 		throw system_error();
//     else if ( a == 8 ) 
//         throw runtime_error("Something went wrong");
// 	return "00:00:09";
// }

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
        }  catch (system_error& ex) {
            return last_fetched_time;
        }
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

// int main() {
//     TimeServer ts;
//     try {
//         cout << ts.GetCurrentTime() << endl;
//     } catch (exception& e) {
//         cout << "Exception got: " << e.what() << endl;
//     }
//     return 0;
// }