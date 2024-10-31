#include "functions.h"

int songId = 1;
int playlistId = 1;


void AddSongToPlaylist(Song song, Playlist& playlist) {

	playlist.songs.push_back(song);

}


Playlist GetPlaylist(int id, vector<Playlist> playlists) {

	for (auto el : playlists) if (el.id == id) return el;

}


void ShowAllPlaylists(vector<Playlist> playlists) {

	if (playlists.size() > 0) {
		for (int i{}; i < playlists.size(); ++i) {
			cout << "Playlist: " << i + 1 << endl;
			cout << "---" << "ID:    " << playlists[i].id << endl;
			cout << "---" << "Name:  " << playlists[i].name << endl;
			cout << "---" << "Songs: ";
			if (playlists[i].songs.size() > 0) {
				for (auto el : playlists[i].songs) cout << el.name << ", ";
			}
			else cout << "This Playlist has no Songs." << endl;
		}
	}
	else cout << "You have no Playlists!" << endl;

}


Playlist CreatePlaylist(string name) {

	cout << "Playlist Name: ";
	cin >> name;

	Playlist playlist(playlistId, name);
	playlistId++;

	return playlist;

}


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