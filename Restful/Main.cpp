#include <cpprest/json.h>
#include <cpprest/http_listener.h>
#include <cpprest/uri.h>
#include <cpprest/asyncrt_utils.h>

#include <stdio.h>

#include "Message.h"
#include "Server.h"

Restful::Server* server;

#ifdef TEST_CODE
int main(int argc, char** argv)
{
	web::http::uri_builder uri(U("http://localhost:1234"));
	uri.append_path(U("test"));

	server = new Restful::Server(uri.to_string());
	server->open().wait();

	std::cout << "Press ENTER to exit." << std::endl;

	std::string line;
	std::getline(std::cin, line);

	auto message = new Restful::Message();
	message->frame = 7;
	message->type = Restful::MessageType::PLAYER_CREATE;
	message->x = 22;
	message->z = 9898;
	server->send_message(message);

	std::getline(std::cin, line);

	server->close().wait();

	return 0;
}
#endif