#include <string>
#include <vector>

using namespace std;

#define _ID(name, line) name ## line
#define _LINE(line) _ID(_var_, line)
#define UNIQ_ID _LINE(__LINE__)


int main() {
    int UNIQ_ID = 0;
    string UNIQ_ID = "hello";
    vector<string> UNIQ_ID = {"hello", "world"};
    vector<int> UNIQ_ID = {1, 2, 3, 4};
}