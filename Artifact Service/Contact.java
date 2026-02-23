// Ashton Connolly || SNHU || Software Testing || September 23rd 2024 ||

package contact;  // Puts Contact.java into the contact package. 

import java.util.concurrent.atomic.AtomicLong;   // Imports the atomicLong function for idGenerator.


public class Contact {
	// Defines private variables all as strings. 
	private final String contactID;
	private String firstName;
	private String lastName; 
	private String number;
	private String address;
	private static AtomicLong idGenerator = new AtomicLong();
	
	// Defines the public function Contact.
	public Contact(String firstName, String lastName, String number, String Address) {
		this.contactID = String.valueOf(idGenerator.getAndIncrement()); // Creates instance of contact and will help prevent duplicate instances. 
		
		// Determines what to do with firstName input based on its length.
		if (firstName == null || firstName.isEmpty()) {
			this.firstName = "NULL";	
		}
		else if (firstName.length() > 10) {
			this.firstName = firstName.substring(0, 10);
		}
		else {
				this.firstName = firstName;
			}
		
		// Determines instances for last name based on its length. 
		if (lastName == null || lastName.isEmpty()) {
			this.lastName = "NULL";	
		}
		else if (lastName.length() > 10) {
			this.lastName = lastName.substring(0, 10);
		}
		else {
			this.lastName = lastName;
		}
		
		
		// Determines what to insert for phone number based on input and length. 
		if (number == null || number.isEmpty() || number.length() != 10) {
			this.number = "0000000000";
		}
		else {
			this.number = number;
		}
		
		// Determines what to insert for address based on input and length. 
		if (address == null || address.isEmpty()) {
			this.address = "NULL";
		}
		else if (address.length() > 30) {
			this.address = address.substring(0, 30);
		}
		else {
			this.address = address;
		}
}
	
	
	// Accessors
	public String getContactID() {
		return contactID;
	}
	
	public String getFirstName() {
		return firstName;
	}
	
	public String getLastName() {
		return lastName;
	}
	
	public String getNumber() {
		return number;
	}
	
	public String getAddress() {
		return address;
	}
	
	
	// Mutators
	public void setFirstName(String firstName) {
		if (firstName == null || firstName.isEmpty()) {
			this.firstName = "NULL";
		}
		else if (firstName.length() > 10) {
			this.firstName = firstName.substring(0, 10);
		}
		else {
			this.firstName = firstName;
		}
	}
	
	public void setLastName(String lastName) {
		if (lastName == null || lastName.isEmpty()) {
			this.lastName = "NULL";	
		}
		else if (lastName.length() > 10) {
			this.lastName = lastName.substring(0, 10);
		}
		else {
			this.lastName = lastName;
		}
	}
	
	public void setNumber(String number) {
		if (number == null || number.isEmpty() || number.length() != 10) {
			this.number = "0000000000";
		}
		else {
			this.number = number;
		}
	}
	
	public void setAddress(String address) {
		if (address == null || address.isEmpty()) {
			this.address = "NULL";
		}
		else if (address.length() > 30) {
			this.address = address.substring(0, 30);
		}
		else {
			this.address = address;
		}
		
	}
}
