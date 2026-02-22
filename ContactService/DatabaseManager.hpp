// DatabaseManager.hpp contains the declaration of the DatabaseManager class, which is responsible for managing the contact database. It includes methods for adding, deleting, and updating contacts, as well as retrieving contact information. The class uses an unordered map to store contacts by their unique IDs for efficient lookups. The implementation of these methods would be found in the corresponding DatabaseManager.cpp file.

#include <string>
using namespace std;

class sqlite3; // Forward declaration of sqlite3

class DatabaseManager { // Class decloration for the database manager
public:
	explicit DatabaseManager(const string& dbFile);
	~DatabaseManager();

	void initializeDatabase();
	void insertContact(const string& id,
		const string& firstName,
		const string& lastName,
		const string& phoneNumber,
		const string& address);

private:
	sqlite3* db_; // Pointer to the SQLite database connection
};