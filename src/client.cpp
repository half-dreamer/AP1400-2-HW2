#include "client.h"
#include "server.h"
#include "crypto.h"

using std::string;

/*  
    class Client:
    private:
	Server * const server;
	std::string id;
	std::string public_key;
	std::string private_key;
*/

Client::Client(string id, Server& server) : id(id), server(&server)
{
    crypto::generate_key(public_key, private_key);
}

string Client::get_id() const 
{
    return id;
}

std::string Client::get_publickey() const
{
    return public_key;
}
double Client::get_wallet()
{
    return server->get_wallet(get_id());
}
std::string Client::sign(std::string txt) const
{
    return crypto::signMessage(private_key, txt);
}
bool Client::transfer_money(std::string receiver, double value) 
{
    return true;
}
size_t Client::generate_nonce() 
{
    return 0;
}
