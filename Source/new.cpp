#pragma once
#include "stdafx.h"
using std::string;
#define URL L"https://web19705.meinsh.eu/authserver/Features.php"
void DoGetValppp()
{
	net::requests m_request(L"authserver", false);
	std::wstring answer = m_request.Post(false, URL, "Features.php");

	if (answer == L"FT") {

		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Build: 2.5");
		UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_MP_STRIPCLUB_PR", "CHAR_MP_STRIPCLUB_PR", 1, 8, "~w~Saphir", "~w~Server", 1, "notification", 9, 0);
		UI::_DRAW_NOTIFICATION(FALSE, FALSE);
	}
	else if (answer != L"FT")
	{
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Build: 2.5");
		UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_MP_STRIPCLUB_PR", "CHAR_MP_STRIPCLUB_PR", 1, 8, "~w~Saphir", "~w~Server", 1, "notification", 9, 0);
		UI::_DRAW_NOTIFICATION(FALSE, FALSE);
	}
}