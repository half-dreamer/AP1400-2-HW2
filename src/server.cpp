#include "server.h"
#include "client.h"
#include <random>

using std::make_pair;
using std::make_shared;
using std::pair;


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
std::shared_ptr<Client> Server::get_client(std::string id)
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
bool Server::parse_trx(std::string trx, std::string sender, std::string receiver, double value)
{
    return false;
}
bool Server::add_pending_trx(std::string trx, std::string signature)
{
    return false;
}
size_t Server::mine()
{
    return 0;
}