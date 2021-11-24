#include <stdio.h>

BREEP_DECLARE_TYPE(std::string);

void co_listener(breep::tcp::network& network, const breep::tcp::peer& source) {
	network.send_object_to(source, std::string("Test"));
}


int main()
{
	breep::tcp::network network(1234);
	network.add_connection_listener(&co_listener);
	network.sync_awake();

	return 0;

}

