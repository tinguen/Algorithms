#include "24.h"

long ConsistentHashing::get_hash(string str) {
    long result = 0, key = 1;
    for (int i = 0; i < str.size(); i++) {
        result = (result + (str[i] * key)) % MOD;
        key = (key * KEY) % MOD;
    }
    return result;
}

string ConsistentHashing::get_server(string data) {
    if (ring.empty()) return "No servers";
    long hash = get_hash(data);
    auto it = ring.lower_bound(hash);
    if (it == ring.end()) it = ring.begin();
    return it->second;
}

void ConsistentHashing::add(string server_name) {
    size++;
    auto iter = find(servers.begin(), servers.end(), server_name);
    if (iter != servers.end()) {
        return;
    }
    servers.push_back(server_name);
    if (size == 1) {
        ring.insert(pair<int, string> (MOD, server_name));
        return;
    }
    int change = MOD / size;
    for (auto it = ring.begin(); it != ring.end(); it++) {
        int hash = it->first - change;
        string value = it->second;
        ring.erase(it);
        ring[hash] = value;
    }
    int hash_ = MOD - change;
    ring.insert(pair<int, string> (MOD, server_name));
}

void ConsistentHashing::remove(string server_name) {
    auto iter = find(servers.begin(), servers.end(), server_name);
    if (iter != servers.end()) {
        size--;
        servers.erase(iter);
    } else return;
    if (size == 0) {
        ring.clear();
        return;
    }
    int change = MOD / size;
    auto it = ring.begin();
    while (it != ring.end()) {
        if (it->second != server_name) {
            it++;
        } else {
            break;
        }
    }
    auto it_begin = ring.begin();
    while (it_begin != it) {
        int hash = it_begin->first + change;
        string value = it_begin->second;
        auto it_del = it_begin;
        ring.erase(it_del);
        ring[hash] = value;
        it_begin++;
    }
    auto it_to_del = it;
    it++;
    while (it != ring.end()) {
        int hash = it->first + change;
        string value = it->second;
        auto it_del = it;
        ring.erase(it_del);
        ring[hash] = value;
        it++;
    }
}