package test; // Establishes that this class is in the test package. 

import org.junit.jupiter.api.Test; // Imports Junit test functionality. 


import contact.Contact; // Imports the Contact class from the contact package. 

import org.junit.jupiter.api.DisplayName;        // imports display name functionality. 
import static org.junit.jupiter.api.Assertions.*; // Imports assertions. 

public class ContactTest {
	
	// Tests 1 - 4 do test runs with data too long to be held by the contact class. 
	@Test
	@DisplayName("Contact ID cannot have more than 10 characters")
	void testContactIDWithMoreThanTenCharacters() {
		Contact contact = new Contact("FirstName", "LastName", "PhoneNumbr", "Address");
		if (contact.getContactID().length() > 10) {
			fail("Contact ID has more than 10 characters.");
		}
	}

	@Test
	@DisplayName("Contact First Name cannot have more than 10 characters")
	void testContactFirstNameWithMoreThanTenCharacters() {
		Contact contact = new Contact("TheLegendaryDominic", "LastName", "PhoneNumbr", "Address");
		if (contact.getFirstName().length() > 10) {
			fail("First Name has more than 10 characters.");
		}
	}

	@Test
	@DisplayName("Contact Last Name cannot have more than 10 characters")
	void testContactLastNameWithMoreThanTenCharacters() {
		Contact contact = new Contact("FirstName", "TheAmazingButler", "PhoneNumbr", "Address");
		if (contact.getLastName().length() > 10) {
			fail("Last Name has more than 10 characters.");
		}
	}

	@Test
	@DisplayName("Contact phone number is exactly 10 characters")
	void testContactNumberWithMoreThanTenCharacters() {
		Contact contact = new Contact("FirstName", "LastName", "5454545454545454", "Address");
		if (contact.getNumber().length() != 10) {
			fail("Phone number length does not equal 10.");
		}
	}

	@Test
	@DisplayName("Contact address cannot have more than 30 characters")
	void testContactAddressWithMoreThanThirtyCharacters() {
		Contact contact = new Contact("FirstName", "LastName", "PhoneNumbr",
				"387 42nd Street Brooklyn New York United States of America");
		if (contact.getAddress().length() > 30) {
			fail("Address has more than 30 characters.");
		}
	}

	// Tests 5- 8 test what happens when data is missing from a section of the contact class. 
	@Test
	@DisplayName("Contact First Name shall not be null")
	void testContactFirstNameNotNull() {
		Contact contact = new Contact(null, "LastName", "PhoneNumbr", "Address");
		assertNotNull(contact.getFirstName(), "First name was null.");
	}

	@Test
	@DisplayName("Contact Last Name shall not be null")
	void testContactLastNameNotNull() {
		Contact contact = new Contact("FirstName", null, "PhoneNumbr", "Address");
		assertNotNull(contact.getLastName(), "Last name was null.");
	}

	@Test
	@DisplayName("Contact Phone Number shall not be null")
	void testContactPhoneNotNull() {
		Contact contact = new Contact("FirstName", "LastName", null, "Address");
		assertNotNull(contact.getNumber(), "Phone number was null.");
	}

	@Test
	@DisplayName("Contact Address shall not be null")
	void testContactAddressNotNull() {
		Contact contact = new Contact("FirstName", "LastName", "PhoneNumbr", null);
		assertNotNull(contact.getAddress(), "Address was null.");
	}

}
