#include "client.h"
#include "server.h"

using std::string;


Client::Client(string id, Server& server) : id(id), server(&server)
{
    ;
}

string Client::get_id() 
{
    return id;
}

std::string Client::get_publickey()
{
    return public_key;
}
double Client::get_wallet()
{
    return server->get_wallet(get_id());
}
std::string Client::sign(std::string txt) 
{
    return "";
}
bool Client::transfer_money(std::string receiver, double value) 
{
    return true;
}
size_t Client::generate_nonce() 
{
    return 0;
}
