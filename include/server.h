#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <map>
#include <memory>
#include <iostream>
#include <vector>
#include "client.h"


using std::cout;
using std::cin;
class Server
{
public:
	Server();
	std::shared_ptr<Client> add_client(std::string id);
	std::shared_ptr<Client> get_client(const std::string id) const;
	double get_wallet(std::string id);
	static bool parse_trx(std::string trx, std::string& sender, std::string& receiver, double& value);
	bool add_pending_trx(std::string trx, std::string signature);
	size_t mine();

	friend void show_wallets(const Server& server);
private:
	std::map<std::shared_ptr<Client>, double> clients; // pair<client, wallet>
};
   	extern std::vector<std::string> pending_trxs; 

#endif //SERVER_H