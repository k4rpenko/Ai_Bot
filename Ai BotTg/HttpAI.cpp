#include "HttpAI.h"

string HttpAI::SendMessageAi(const string& message) {
    ifstream inputFILE("./appsettings.json");
    if (!inputFILE.is_open()) {
        cerr << "Can't open the appsettings.json" << endl;
        return "No response from AI.";
    }
    try {
        json config;
        inputFILE >> config;
        string apiKey = config["Token"]["Value"];
        string host = "generativelanguage.googleapis.com";
        string target = "/v1beta/models/gemini-1.5-flash:generateContent?key=" + apiKey;
        string port = "443";


        asio::io_context ioc;
        ssl::context ctx(ssl::context::tlsv12_client);
        ctx.set_default_verify_paths();

        tcp::resolver resolver(ioc);
        beast::ssl_stream<tcp::socket> stream(ioc, ctx);

        auto const results = resolver.resolve(host, port);
        asio::connect(stream.next_layer(), results.begin(), results.end());
        stream.handshake(ssl::stream_base::client);

        string json_body = R"({
            "contents": [{
                "parts": [{"text": ")" + message + R"("}]
            }]
        })";

        http::request<http::string_body> req(http::verb::post, target, 11);
        req.set(http::field::host, host);
        req.set(http::field::user_agent, "Boost.Beast HTTPS Client");
        req.set(http::field::content_type, "application/json");
        req.set(http::field::accept, "application/json");
        req.body() = json_body;
        req.prepare_payload();

        http::write(stream, req);


        beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(stream, buffer, res);

        json PARS = json::parse(beast::buffers_to_string(res.body().data()));

        if (!PARS["candidates"].empty()) {
            string text = PARS["candidates"][0]["content"]["parts"][0]["text"];
            return  text;
        }
        else {
            return  "No response from AI.";
        }

        beast::error_code ec;
        stream.shutdown(ec);
        if (ec && ec != beast::errc::not_connected) {
            throw beast::system_error{ ec };
        }
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
