#include <iostream>

#include "mongocxx/instance.hpp"
#include "mongodb_handler.h"

int main() {
    mongocxx::instance instance;
    server::MongoDbHandler mhandler;

    mhandler.AddFile("test_file3",
                     "this is the third test");
}