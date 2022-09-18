#pragma once

#include <string>
#include <cstdint>

#include "bsoncxx/builder/stream/document.hpp"
#include "bsoncxx/json.hpp"
#include "bsoncxx/oid.hpp"
#include "mongocxx/client.hpp"
#include "mongocxx/database.hpp"
#include "mongocxx/uri.hpp"

namespace server 
{
constexpr char kMongoDbUri[] ="mongodb://0.0.0.0:27017";
constexpr char kDatabaseName[] = "files_db";
constexpr char kCollectionName[] = "files0";

class MongoDbHandler {
  public:
    MongoDbHandler()
    : uri(mongocxx::uri(kMongoDbUri)),
      client(mongocxx::client(uri)),
      db(client[kDatabaseName]) {}

    bool AddFile(const std::string &file_name,
                 const std::string &content) {
        mongocxx::collection collection = db[kCollectionName];
        auto builder = bsoncxx::builder::stream::document{};

        bsoncxx::document::value doc_to_add = 
            builder << "fileName" << file_name
                    << "content" << content << bsoncxx::builder::stream::finalize;
        collection.insert_one(doc_to_add.view());
        return true;
                     }
                
    bool UpdateFile(const std::string &file_id) {
        return true;
    }

    bool RemoveFile(const std::string &file_id) {
        return true;
    }
  private: 
    mongocxx::uri uri;
    mongocxx::client client;
    mongocxx::database db;
};
}