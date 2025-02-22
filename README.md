# Oral
This bot was developed in C++ using the Boost and nlohmann/json libraries. It uses an asynchronous approach to process requests.
## Connection

To connect and use the bot, you need to download the following header files:

- `tgbot/tgbot.h`
- `boost/asio.hpp`
- `boost/beast.hpp`
- `boost/beast/ssl.hpp`
- `nlohmann/json.hpp`

Make sure that all necessary dependencies are installed and available in your development environment.

## Setting dependencies

### macOS
```sh
brew install boost jsoncpp
```

### Linux (Ubuntu/Debian)
```sh
sudo apt update
sudo apt install libboost-all-dev nlohmann-json3-dev
```

### Windows
1. Install [vcpkg](https://github.com/microsoft/vcpkg) (if not already set).
2. Run the command:
```sh
vcpkg install boost-asio boost-beast nlohmann-json
```
3. Add library paths to your project.
