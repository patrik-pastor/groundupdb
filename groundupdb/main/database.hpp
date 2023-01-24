//
// Created by shepherd on 24.1.23.
//

#ifndef GROUNDUPDB_MAIN_DATABASE_HPP_
#define GROUNDUPDB_MAIN_DATABASE_HPP_

#include <string>

namespace groundupdb {

class Database {
public:
    Database(std::string const& name, std::string const& fullpath);

    std::string const& GetFullpath() const;

    void SetKeyValue(const std::string& key, const std::string& value);

    std::string GetKeyValue(const std::string& key) const;

    void Destroy();

private:
    std::string name_;
    std::string fullpath_;
};

Database CreateEmpty(const std::string& dbname);

} // groundupdb

#endif //GROUNDUPDB_MAIN_DATABASE_HPP_
