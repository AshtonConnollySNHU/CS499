// DatabaseManager.cpp contains the implementation of the DatabaseManager class, which manages the contact database using SQLite. It includes methods for initializing the database and inserting contacts. The constructor opens a connection to the specified database file, while the destructor ensures that the connection is properly closed. The initializeDatabase method creates the necessary table for storing contacts if it doesn't already exist, and the insertContact method adds new contact entries to the database.

#include "DatabaseManager.hpp"
#include "sqlite3.h"
#include <stdexcept>

using namespace std;

DatabaseManager::DatabaseManager(const string& dbFile) : db_(nullptr) {
	if (sqlite3_open(dbFile.c_str(), &db_) != SQLITE_OK) {
		throw runtime_error("Failed to open database: " + string(sqlite3_errmsg(db_)));
	}
}

DatabaseManager::~DatabaseManager() {
	if (db_) {
		sqlite3_close(db_);
	}
}

void DatabaseManager::initializeDatabase() {
		const char* createTableSQL = R"(
		CREATE TABLE IF NOT EXISTS contacts (
			id TEXT PRIMARY KEY,
			firstName TEXT NOT NULL,
			lastName TEXT NOT NULL,
			phoneNumber TEXT NOT NULL,
			address TEXT NOT NULL
		);
	)";
	char* errMsg = nullptr;
	if (sqlite3_exec(db_, createTableSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
		string error = errMsg ? errMsg : "Unknown error";
		sqlite3_free(errMsg);
		throw runtime_error("Failed to initialize database: " + error);
	}
}

void DatabaseManager::insertContact(const string& id,
	const string& firstName,
	const string& lastName,
	const string& phoneNumber,
	const string& address) {
	const char* insertSQL = "INSERT INTO contacts (id, firstName, lastName, phoneNumber, address) VALUES (?, ?, ?, ?, ?);";
	
	sqlite3_stmt* stmt;

	if (sqlite3_prepare_v2(db_, insertSQL, -1, &stmt, nullptr) != SQLITE_OK) {
		throw runtime_error("Failed to prepare statement: " + string(sqlite3_errmsg(db_)));
	}
	sqlite3_bind_text(stmt, 1, id.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, firstName.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 3, lastName.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 4, phoneNumber.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 5, address.c_str(), -1, SQLITE_TRANSIENT);

	if (sqlite3_step(stmt) != SQLITE_DONE) {
		sqlite3_finalize(stmt);
		throw runtime_error("Failed to insert contact: " + string(sqlite3_errmsg(db_)));
	}

	sqlite3_finalize(stmt);
}
