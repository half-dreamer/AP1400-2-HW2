#ifndef CLIENT_H
#define CLIENT_H

#include <memory>
#include <string>
#include <map>

using std::map;
using std::shared_ptr;

class Server;
class Client
{
public:
	Client(std::string id, Server& server);
	std::string get_id();
	std::string get_publickey();
	double get_wallet();
	std::string sign(std::string txt);
	bool transfer_money(std::string receiver, double value);
	size_t generate_nonce();
private:
	Server * const server;
	std::string id;
	std::string public_key;
	std::string private_key;
};

#endif //CLIENT_H