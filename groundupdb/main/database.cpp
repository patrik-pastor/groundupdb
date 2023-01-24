//
// Created by shepherd on 24.1.23.
//

#include <groundupdb/main/database.hpp>

#include <string>
#include <filesystem>
#include <fstream>

namespace groundupdb {
Database::Database(std::string const& name, std::string const& fullpath) : name_(name), fullpath_(fullpath) {}

std::string const& Database::GetFullpath() const {
    return fullpath_;
}

void Database::SetKeyValue(std::string const& key, std::string const& value) {
    std::ofstream os;
    os.open(fullpath_ + "/" + key + "_string.kv", std::ios::out | std::ios::trunc);
    os << value;
    os.close();
}

std::string Database::GetKeyValue(std::string const& key) const {
    std::ifstream is(fullpath_ + "/" + key + "_string.kv");
    std::string value;
    is.seekg(0, std::ios::end);
    value.reserve(is.tellg());
    is.seekg(0, std::ios::beg);
    value.assign(std::istreambuf_iterator(is), std::istreambuf_iterator<char>());
    return value;
}

void Database::Destroy() {
    if (std::filesystem::exists(fullpath_)) {
        std::filesystem::remove_all(fullpath_);
    }
}

Database CreateEmpty(std::string const& dbname) {
    std::string basedir = ".groundupdb";
    if (!std::filesystem::exists(basedir)) {
        std::filesystem::create_directory(basedir);
    }
    std::string dbfolder = basedir + "/" + dbname;
    if (!std::filesystem::exists(dbfolder)) {
        std::filesystem::create_directory(dbfolder);
    }
    return {dbname, dbfolder};
}

Database LoadDb(std::string const& dbname) {
    std::string dbfolder = ".groundupdb/" + dbname;
    return {dbname, dbfolder};
}

} // groundupdb