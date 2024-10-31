#include "functions.h"

int songId = 1;

void PlaySong(string addr) {

	string path = addr;
	string openCommand = "open \"" + path + "\" type mpegvideo alias mp3";

	mciSendStringA(openCommand.c_str(), NULL, 0, NULL);
	mciSendStringA("play mp3 wait", NULL, 0, NULL);

	mciSendStringA("close mp3", NULL, 0, NULL);

}


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


int mapCommand(string command, const string(&arr)[numOfCommands]) {

	for (int i{}; i < numOfCommands; ++i) if (arr[i] == command) return i + 1;

}


int checkForValidCommand(string command, const string(&arr)[numOfCommands]) {

	for (auto el : arr) if (el == command) return 1;

	return 0;

}