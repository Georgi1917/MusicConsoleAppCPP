
#ifndef PLAYLISTCLASS_H
#define PLAYLISTCLASS_H

#include <string>
#include <vector>
#include "SongClass.h"
using namespace std;

class Playlist {
	public:
		int id;
		string name;
		vector<Song> songs;

		Playlist(const int& id, const string& n) :
			id(id), name(n) {};

		bool operator==(const Playlist& other) const {
			return id == other.id;
		}
};

#endif
