#pragma once
#include "stdafx.h"
using std::string;
/*
#define URL L"https://BLDR-black.de/authserver/authserver.php"

wstring s2ws(const std::string& str)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}

bool is_user_authed(std::string username, std::string password)
{
	char hwid[4096];
	// total physical memory
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	sprintf_s(hwid, "%I64i", statex.ullTotalPhys / 1024);

	// volume information
	TCHAR volumename[MAX_PATH + 1] = { 0 };
	TCHAR filesystemname[MAX_PATH + 1] = { 0 };
	DWORD serialnumber = 0, maxcomponentlen = 0, filesystemflags = 0;
	GetVolumeInformation(_T("C:\\"), volumename, ARRAYSIZE(volumename), &serialnumber, &maxcomponentlen, &filesystemflags, filesystemname, ARRAYSIZE(filesystemname));
	sprintf_s(hwid, "%s%li%ws%li", hwid, serialnumber, filesystemname, maxcomponentlen);

	// computer name
	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	GetComputerName(computerName, &size);
	sprintf_s(hwid, "%s%ws", hwid, computerName);

	net::requests m_request(L"galaxy-five", false);
	std::wstring answer = m_request.Post(false, URL, "username=%s&password=%s&hwid=%s", username.c_str(), password.c_str(), (sw::sha512::calculate(hwid)).c_str());
	if (answer == L"Try again!") {
		answer = m_request.Post(false, URL, "username=%s&password=%s&hwid=%s", username.c_str(), password.c_str(), (sw::sha512::calculate(hwid)).c_str());
	}
	return answer != L"Access granted!" ? false : true;
}//only this nothing else  */