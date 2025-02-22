#include "BOT.h"

void BOT::run(const string& TOKEN) {
    Bot bot(TOKEN);
    HttpAI _AI;

    bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
        });

    bot.getEvents().onAnyMessage([&bot, &_AI, this](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (!StringTools::startsWith(message->text, "/start")) {
            actions(bot, message, _AI);
        }
        });
    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            longPoll.start();
        }
    }
    catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
}

void BOT::actions(Bot& bot, TgBot::Message::Ptr message, HttpAI& _AI) {
    bot.getApi().sendMessage(message->chat->id, utf8_encode(L"Îáğîáêà..."));
    string req = _AI.SendMessageAi(message->text.c_str());
    bot.getApi().sendMessage(message->chat->id, req);
}