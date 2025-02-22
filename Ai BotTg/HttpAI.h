#pragma once
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/ssl.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <cstdlib>

namespace asio = boost::asio;
namespace beast = boost::beast;
namespace http = beast::http;
namespace ssl = asio::ssl;
using json = nlohmann::json;
using tcp = asio::ip::tcp;
using namespace std;

class HttpAI
{
public:
	string SendMessageAi(const string& message);
};

