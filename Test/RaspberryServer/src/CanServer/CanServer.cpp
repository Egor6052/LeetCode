
#include "../../lib/CanServer.h"

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <net/if.h>
#include <unistd.h>
#include <cstring>

void CanServer::init(size_t threads = 1) {
    auto opts = Http::Endpoint::options()
                .threads(threads)
                .flags(Tcp::Options::InstallSignalHandler);
    httpEndpoint->init(opts);
    setupRoutes();
}

void CanServer::start() {
    httpEndpoint->setHandler(router.handler());
    httpEndpoint->serve();
}
