#include "server.h"
#include "client.h"
#include <random>
#include <regex>

using std::make_pair;
using std::make_shared;
using std::pair;
using std::logic_error;
using std::runtime_error;

/*  
class Server: 
    private:
	std::map<std::shared_ptr<Client>, double> clients; // pair<client, wallet>
*/

 void show_wallets(const  Server& server)
 {
 	std::cout << std::string(20, '*') << std::endl;
 	for(const auto& client: server.clients)
 		std::cout << client.first->get_id() <<  " : "  << client.second << std::endl;
 	std::cout << std::string(20, '*') << std::endl;
 }

Server::Server()
{
    clients = map<shared_ptr<Client>, double>{};
}
std::shared_ptr<Client> Server::add_client(std::string id)
{
    if (get_client(id) != nullptr) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1000, 9999);
        int randNum = dis(gen);
        id += std::to_string(randNum);
    }
    shared_ptr addedClient = make_shared<Client>(id, *this);
    clients.insert(make_pair(addedClient, 5));
    return addedClient;
}
std::shared_ptr<Client> Server::get_client(const std::string id) const
{
    // actually using auto is better
    for (pair<shared_ptr<Client>, double> rollPair : clients) {
        if ((*rollPair.first).get_id() == id) {
            return rollPair.first;
        }
    }
    return nullptr;
}
double Server::get_wallet(std::string id)
{
    for (auto map : clients) {
        if (map.first->get_id() == id){
            return map.second;
        }
    }
    return 0;
}
bool Server::parse_trx(std::string trx, std::string& sender, std::string& receiver, double& value)
{
    // well, this function really helps me to learn regex and static member function !
    // barvo!
    std::regex pattern("([a-zA-Z]+)-([a-zA-Z]+)-([\\d.]+)");
    std::smatch matches;
    if (!std::regex_match(trx, matches, pattern)) {
        throw runtime_error("input trx is not valid!");
    }
    sender = matches[1];
    receiver = matches[2];
    value = std::stod(matches[3]);
    return true;
}
bool Server::add_pending_trx(std::string trx, std::string signature)
{
    return false;
}
size_t Server::mine()
{
    return 0;
}