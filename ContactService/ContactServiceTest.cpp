// ContactServiceTest.cpp
// Uses Gtest instead of JUnit

#include <gtest/gtest.h>
#include "ContactService.hpp"
#include "DatabaseManager.hpp"

using namespace std;

TEST(ContactServiceTest, AddContactIncreasesSize) {
	ContactService s;
	s.addContact("John", "Doe", "1234567890", "123 Main St");
	EXPECT_EQ(s.size(), 1u);
}

TEST(ContactServiceTest, UpdateFirstNameWorks) {
	ContactService s;
	string id = s.addContact("John", "Doe", "1234567890", "123 Main St");
	
	s.updateFirstName(id, "Jane");
	EXPECT_EQ(s.getContactorThrow(id).getFirstName(), "Jane");
}

TEST(ContactServiceTest, DeleteContactRemovesIt) {
	ContactService s;
	string id = s.addContact("John", "Doe", "1234567890", "123 Main St");

	s.deleteContact(id);
	EXPECT_EQ(s.size(), 0u);
}

TEST(ContactServiceTest, DeleteMissingThrows) {
	ContactService s;
	EXPECT_THROW(s.deleteContact("999"), NotFoundError);
}

TEST(DatabaseTest, InitializeDatabaseCreatesTable) {
	DatabaseManager db("test.db");
	EXPECT_NO_THROW(db.initializeDatabase());
}