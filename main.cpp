#include <iostream>
#include <cstdlib>
#include <vector>
#include "SongClass.h"
using namespace std;

int songId = 1;

const int numOfCommands{ 8 };


void DeleteSong(Song song, vector<Song>& songs) {

	auto el = remove(songs.begin(), songs.end(), song);
	songs.erase(el, songs.end());

}


Song GetSong(int id, vector<Song> songs) {

	for (auto& el : songs) if (el.id == id) return el;

}


void ShowAllSongs(vector<Song> songs) {

	cout << "Current Songs in Library: " << endl;

	for (int i{}; i < songs.size(); ++i) {
		cout << "Song " << i + 1 << endl;
		cout << "ID --->      " << songs[i].id << endl;
		cout << "Name --->    " << songs[i].name << endl;
		cout << "Author --->  " << songs[i].author << endl;
		cout << "Address ---> " << songs[i].address << endl;
	}
}

Song CreateSongInstance(string name, string author, string addr) {
	cout << "Name: ";
	cin >> name;
	cout << "Author: ";
	cin >> author;
	cout << "Address: ";
	cin >> addr;

	Song song(songId, name, author, addr);

	songId++;

	return song;
}


void ShowCommands(const string(&arr)[numOfCommands]) {
	cout << "The valid commands are: " << endl;

	for (auto el : arr) cout << "--->" << el << endl;
}


int mapCommand(string command, const string (&arr)[numOfCommands]) {

	for (int i{}; i < numOfCommands; ++i) if (arr[i] == command) return i + 1;

}


int checkForValidCommand(string command, const string (&arr)[numOfCommands]) {

	for (auto el : arr) if (el == command) return 1;

	return 0;

}


int main() {

	cout << "1. Create Playlist." << endl;
	cout << "2. Create Song" << endl;
	cout << "3. Add Song to Playlist." << endl;
	cout << "4. Show all playlists" << endl;
	cout << "5. Show all songs" << endl;
	cout << "6. Delete Song" << endl;
	cout << "7. Help" << endl;
	cout << "8. End" << endl;

	string command;
	const string validCommands[numOfCommands] = { "CreatePlaylist", "CreateSong", "AddSong", "ShowAllPlaylists", "ShowAllSongs", "DeleteSong", "Help", "End"};
	vector<Song> songs;

	string name, author, address;

	while (true) {
		cin >> command;

		if (!checkForValidCommand(command, validCommands)) {
			cout << "Invalid command! Try again!" << endl;
			continue;
		}
		int mappedCommand = mapCommand(command, validCommands);

		switch (mappedCommand) {
		case 1:
			cout << "The current command is: " << command << endl;
			break;
		case 2:
		{

			Song song = CreateSongInstance(name, author, address);

			songs.push_back(song);

			break;

		}
		case 3:
			cout << "The current command is: " << command << endl;
			break;
		case 4:
			cout << "The current command is: " << command << endl;
			break;
		case 5:
			ShowAllSongs(songs);

			break;
		case 6:
			int id;

			if (songs.size() > 0) {
				do {
					cout << "Song ID: ";
					cin >> id;
				} while (id >= songId || id < songs[0].id);

				Song song = GetSong(id, songs);

				DeleteSong(song, songs);

			}
			else cout << "You have no Songs in your Library!" << endl;

			break;
		case 7:
			ShowCommands(validCommands);

			break;
		case 8:
			exit(0);
			break;
		}
	}

}