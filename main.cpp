#include <iostream>
#include <cstdlib>
#include <vector>
#include <Windows.h>
#include "SongClass.h"
#include "PlaylistClass.h"
#include "functions.h"
using namespace std;

int main() {

	cout << "1. Create Playlist." << endl;
	cout << "2. Create Song" << endl;
	cout << "3. Add Song to Playlist." << endl;
	cout << "4. Show all playlists" << endl;
	cout << "5. Show all songs" << endl;
	cout << "6. Play Song" << endl;
	cout << "7. Play Playlist" << endl;
	cout << "8. Delete Song" << endl;
	cout << "9. Help" << endl;
	cout << "10. End" << endl;

	string command;
	const string validCommands[numOfCommands] = { "CreatePlaylist", "CreateSong", "AddSongToPlaylist", "ShowAllPlaylists", "ShowAllSongs","PlaySong", "PlayPlaylist", "DeleteSong", "Help", "End"};
	vector<Song> songs;
	vector<Playlist> playlists;

	string name, author, address;

	while (true) {
		cin >> command;

		if (!checkForValidCommand(command, validCommands)) {
			cout << "Invalid command! Try again!" << endl;
			continue;
		}

		int mappedCommand = mapCommand(command, validCommands);

		switch (mappedCommand) {
		case 1: {
			string pName;

			Playlist playlist = CreatePlaylist(pName);

			playlists.push_back(playlist);

			break;
		}
		case 2:
		{

			Song song = CreateSongInstance(name, author, address);

			songs.push_back(song);

			break;

		}
		case 3: {
			if (playlists.size() > 0 && songs.size() > 0) {
				int sId, pId;

				do {
					cout << "Playlist ID: ";
					cin >> pId;
				} while (pId >= playlistId || pId < playlists[0].id);

				do {
					cout << "Song ID: ";
					cin >> sId;
				} while (sId >= songId || sId < songs[0].id);

				Playlist& playlist = GetPlaylist(pId, playlists);
				Song song = GetSong(sId, songs);

				cout << "Playlist Name: " << playlist.name << ", " << "Song Name: " << song.name << endl;

				AddSongToPlaylist(song, playlist);
			}
			else cout << "Please create Songs and Playlists first!" << endl;

			break;
		}
		case 4:
			ShowAllPlaylists(playlists);
			break;
		case 5:
			ShowAllSongs(songs);

			break;
		case 6: {
			int id;

			if (songs.size() > 0) {
				do {
					cout << "Song ID: ";
					cin >> id;
				} while (id >= songId || id < songs[0].id);

				Song song = GetSong(id, songs);

				PlaySong(song.address);

			}
			else cout << "You have no Songs in yout Library!" << endl;

			break;
			
		}

		case 7:
			cout << "The command is: " << command << endl;
			break;
			
		case 8:
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
		case 9:
			ShowCommands(validCommands);

			break;
		case 10:
			exit(0);
			break;
		}
	}

}