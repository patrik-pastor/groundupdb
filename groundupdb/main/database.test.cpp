//
// Created by shepherd on 24.1.23.
//

#include <groundupdb/main/database.hpp>

#include <string>
#include <filesystem>

#include <catch2/catch_test_macros.hpp>

namespace fs = std::filesystem;

TEST_CASE("database operations") {
    std::string dbname = "myemptydb";
    groundupdb::Database db = groundupdb::CreateEmpty(dbname);

    // Story:
    // [Who] As a database administrator
    // [What] I need to create a new empty database
    // [Value] So I can later store and retrieve data
    SECTION("Default settings") {
        // We know we have been successful when:
        // 1. We have a valid database reference returned
        // 2. The DB has a folder that exists on the file system
        REQUIRE(fs::is_directory(db.GetFullpath()));
        auto p = fs::directory_iterator(db.GetFullpath());
        // i.e. no contents as iterator is at the end already
        REQUIRE(p == fs::end(p));

        db.Destroy();
    }

    // Story:
    // [Who] As a database user
    // [What] I need to store and retrieve a value with a simple name
    // [Value] So I can persist data for later use
    SECTION("Basic set and get") {
        // We know we have been successful when
        // 1. The retrieved value is the same as the store value
        std::string key = "simplestring";
        std::string value = "Some highly valuable value";
        db.SetKeyValue(key, value);
        REQUIRE(value == db.GetKeyValue(key));

        db.Destroy();
    }

    // Story:
    // [Who] As a database user
    // [What] I need to create a reference to an existing database
    // [Value] So I can later store and retrieve data
    SECTION("Load an existing database") {
        groundupdb::Database db2(groundupdb::LoadDb(dbname));

        // We know we have been successful when
        // 1. We have a valid database reference returned
        // 2. The DB has a folder that exists on the file system
        REQUIRE(fs::is_directory(db2.GetFullpath()));

        // 3. The database folder is empty (no database files yet)
        auto p = fs::directory_iterator(db2.GetFullpath());
        REQUIRE(p == fs::end(p));

        db.Destroy();
    }
}