#include <iostream>
#include <map>
#include <vector>

using namespace std;

class ConsistentHashing {
private:
    int size = 0;
    vector<string> servers;
    map<int, string> ring;
    const int KEY = 23, MOD = 1e9 + 7;
public:
    long get_hash(string str);
    string get_server(string data);
    void add(string server_name);
    void remove(string server_name);
    int get_size() {
        return size;
    }
};