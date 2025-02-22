#pragma once
#include <tgbot/tgbot.h>
#include <iostream>
#include <string>
#include "HttpAI.h"
#include <windows.h>

using namespace std;
using namespace TgBot;

class BOT: public HttpAI
{
private:
	void actions(Bot& bot, TgBot::Message::Ptr message, HttpAI& _AI);
    string utf8_encode(const wstring& wstr) {
        if (wstr.empty()) return string();
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
        string strTo(size_needed, 0);
        WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
        return strTo;
    }
public:
	void run(const string& TOKEN);
};