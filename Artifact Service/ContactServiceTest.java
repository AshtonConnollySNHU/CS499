package test;  // Asserts that the ContactServiceTest is in the test package. 

import org.junit.jupiter.api.Test;            // Adds JUnit test function
import org.junit.jupiter.api.TestMethodOrder; // Adds test method order function

import static org.junit.jupiter.api.Assertions.*; // Adds assertions

import java.util.ArrayList;                       // Adds the array functionality
import org.junit.jupiter.api.DisplayName;         // Adds display names
import org.junit.jupiter.api.MethodOrderer.OrderAnnotation; // Adds order annotation to test method order. 

import contact.Contact;                           // Imports the Contact class from the contact package. 
import contact.ContactService;                    // Imports the ContactService class from the contact package. 

import org.junit.jupiter.api.Order;               // Allows use for @order. 

@TestMethodOrder(MethodOrderer.OrderAnnotation.class)

public class ContactServiceTest {
// Runs all possible test cases to ensure the functionality of the system is solid. 
	@Test
	@DisplayName("Test to Update First Name.")
	@Order(1)
	void testUpdateFirstName() {
		ContactService service = new ContactService();
		service.addContact("John", "Doe", "9999999999", "123 Test Street");
		service.updateFirstName("Jane", "9");
		service.displayContactList();
		assertEquals("Jane", service.getContact("6").getFirstName(), "First name was not updated.");
	}

	@Test
	@DisplayName("Test to Update Last Name.")
	@Order(2)
	void testUpdateLastName() {
		ContactService service = new ContactService();
		service.addContact("John", "Doe", "9999999999", "123 Test Street");
		service.updateLastName("Smith", "12");
		service.displayContactList();
		assertEquals("Smith", service.getContact("12").getLastName(), "Last name was not updated.");
	}

	@Test
	@DisplayName("Test to update phone number.")
	@Order(3)
	void testUpdatePhoneNumber() {
		ContactService service = new ContactService();
		service.addContact("John", "Doe", "9999999999", "123 Test Street");
		service.updateNumber("7816190422", "18");
		service.displayContactList();
		assertEquals("7816190422", service.getContact("18").getNumber(), "Phone number was not updated.");
	}

	@Test
	@DisplayName("Test to update address.")
	@Order(4)
	void testUpdateAddress() {
		ContactService service = new ContactService();
		service.addContact("John", "Doe", "9999999999", "123 Test Street");
		service.updateAddress("54 Ronald Drive", "3");
		service.displayContactList();
		assertEquals("54 Ronald Drive", service.getContact("3").getAddress(), "Address was not updated.");
	}

	@Test
	@DisplayName("Test to ensure that service correctly deletes contacts.")
	@Order(5)
	void testDeleteContact() {
		ContactService service = new ContactService();
		service.addContact("John", "Doe", "9999999999", "123 Test Street");
		service.deleteContact("14");
		ArrayList<Contact> contactListEmpty = new ArrayList<Contact>();
		service.displayContactList();
		assertEquals(service.contactList, contactListEmpty, "The contact was not deleted.");
	}

	@Test
	@DisplayName("Test to ensure that service can add a contact.")
	@Order(6)
	void testAddContact() {
		ContactService service = new ContactService();
		service.addContact("John", "Doe", "9999999999", "123 Test Street");
		service.displayContactList();
		assertNotNull(service.getContact("0"), "Contact was not added correctly.");
	}

}
