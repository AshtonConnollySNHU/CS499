// ContactTest.cpp 
// Uses Gtest instead of JUnit

#include <gtest/gtest.h>
#include "Contact.hpp"

// Remove or comment out the following line if sqlite3 is not required for your tests
// #include <sqlite3.h>
TEST(ContactTest, FirstNameTruncatesToTwenty) {
	Contact c("TheAmazingLegendaryDominic", "lastName", "1234567890", "Address");
	EXPECT_LE(c.getFirstName().length(), 20u);
}

TEST(ContactTest, LastNameTruncatesToTwenty) {
	Contact c("firstName", "TheAmazingLegendaryFantasticButler", "1234567890", "Address");
	EXPECT_LE(c.getLastName().length(), 20u);
}

TEST(ContactTest, PhoneNumberGoesToZerosWhenInvalid) {
		Contact c("firstName", "lastName", "545454545454545454545454", "Address");
		EXPECT_EQ(c.getPhoneNumber(), "0000000000");
}

TEST(ContactTest, AddressTruncatesToFifty) {
	Contact c("firstName", "lastName", "1234567890", "This address is way too long and should be truncated to fit the limit Brooklyn New York United States of America.");
	EXPECT_LE(c.getAddress().length(), 50u);
}

TEST(ContactTest, NullishStringBecomeNULL) {
	Contact c("", "", "", "");
	EXPECT_EQ(c.getFirstName(), "NULL");
	EXPECT_EQ(c.getLastName(), "NULL");
	EXPECT_EQ(c.getPhoneNumber(), "0000000000");
	EXPECT_EQ(c.getAddress(), "NULL");
}
