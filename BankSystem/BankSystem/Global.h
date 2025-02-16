#pragma once
#include <iostream>
#include "clsUser.h"
clsUser CurrentUser = clsUser::Find("", "");
bool ChackIsLocked()
{
	fstream MyFile;
	MyFile.open("IsLocked.txt", ios::in);
	string Lien = "";
	getline(MyFile, Lien);
	return (Lien == "1");
}
void SaveLockedToFile(bool Locked)
{
	fstream MyFile;
	MyFile.open("IsLocked.txt", ios::out);
	if (Locked == true)
		MyFile << "1";
	else
		MyFile << "0";
}
bool Locked = ChackIsLocked();