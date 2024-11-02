
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <Windows.h>
#include "PlaylistClass.h"
#include "SongClass.h"
using namespace std;

const int numOfCommands{ 11 };

extern int songId;
extern int playlistId;

void RemoveSongFromPlaylist(Song song, Playlist& playlist);
void PlayPlaylist(Playlist& playlist);
void AddSongToPlaylist(Song song, Playlist& playlist);
Playlist& GetPlaylist(int id, vector<Playlist>& playlists);
void ShowAllPlaylists(vector<Playlist> playlists);
Playlist CreatePlaylist(string name);
void PlaySong(string addr);
void DeleteSong(Song song, vector<Song>& songs);
Song GetSong(int id, vector<Song> songs);
void ShowAllSongs(vector<Song> songs);
Song CreateSongInstance(string name, string author, string addr);
void ShowCommands(const string(&arr)[numOfCommands]);
int mapCommand(string command, const string(&arr)[numOfCommands]);
int checkForValidCommand(string command, const string(&arr)[numOfCommands]);

#endif
