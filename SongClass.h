
#ifndef SONGCLASS_H
#define SONGCLASS_H

#include <string>
using namespace std;

class Song {
	public:
		int id;
		string name;
		string author;
		string address;

		Song(const int& id, const string& n, const string& a, const string& addr) :
			id(id), name(n), author(a), address(addr) {}

		bool operator==(const Song& other) const {
			return id == other.id && name == other.name;
		}
};

#endif
