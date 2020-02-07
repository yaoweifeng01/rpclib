#include "rpc/server.h"


void foo() {
    //std::cout << "foo was called!" << std::endl;
}

int main() {
    rpc::server srv(rpc::constants::DEFAULT_PORT);

    srv.bind("echo", [](std::string const& s) {

        return ("heloworld:" + s);
    });

    srv.bind("add", [](int a, int b) {
        return a + b;
    });

    srv.bind("foo", &foo);

    srv.run();
    return 0;
}
