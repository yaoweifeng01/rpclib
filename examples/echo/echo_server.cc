#include "rpc/server.h"


void foo() {
    //std::cout << "foo was called!" << std::endl;
}

int main() {
    int port = 8765;
    rpc::server srv1(port++);
    rpc::server srv2(port++);
    rpc::server srv3(port++);
    rpc::server srv4(port++);
    rpc::server srv5(port++);
    rpc::server srv6(port++);
    rpc::server srv7(port++);
    rpc::server srv8(port++);

    srv1.bind("echo", [](std::string const& s) {

        return ("heloworld:" + s);
    });

    srv1.bind("add", [](int a, int b) {
            return a + b;
        });
    srv1.bind("add1", [](int a, int b) {
            return a + b;
        });
    srv2.bind("add2", [](int a, int b) {
        return a + b;
    });
    srv3.bind("add3", [](int a, int b) {
        return a + b;
    });
    srv4.bind("add4", [](int a, int b) {
        return a + b;
    });
    srv5.bind("add5", [](int a, int b) {
        return a + b;
    });
    srv6.bind("add6", [](int a, int b) {
        return a + b;
    });
    srv7.bind("add7", [](int a, int b) {
        return a + b;
    });
    srv8.bind("add8", [](int a, int b) {
        return a + b;
    });

    srv1.bind("foo", &foo);

    srv1.run();
    srv2.run();
    srv3.run();
    srv4.run();
    srv5.run();
    srv6.run();
    srv7.run();
    srv8.run();
    return 0;
}
