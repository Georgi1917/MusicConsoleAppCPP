
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <Windows.h>
#include "SongClass.h"
using namespace std;

const int numOfCommands{ 9 };
extern int songId;

void PlaySong(string addr);
void DeleteSong(Song song, vector<Song>& songs);
Song GetSong(int id, vector<Song> songs);
void ShowAllSongs(vector<Song> songs);
Song CreateSongInstance(string name, string author, string addr);
void ShowCommands(const string(&arr)[numOfCommands]);
int mapCommand(string command, const string(&arr)[numOfCommands]);
int checkForValidCommand(string command, const string(&arr)[numOfCommands]);

#endif
