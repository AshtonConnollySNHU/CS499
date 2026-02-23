

package contact; // Asserts that the class is in the contact package. 

import java.util.ArrayList; // imports array functionality from java utility. 





public class ContactService {
	public ArrayList<Contact> contactList = new ArrayList<Contact>(); // Creates a new array which will store all contact information. 
	
	// Inserts each contact "instance" into the list until no instances are left. 
	public void displayContactList() {
		for (int i = 0; i < contactList.size(); i++) {
			System.out.println("\t Contact ID: " + contactList.get(i).getContactID());
			System.out.println("\t First Name: " + contactList.get(i).getFirstName());
			System.out.println("\t Last Name: " + contactList.get(i).getLastName());
			System.out.println("\t Phone Number: " + contactList.get(i).getNumber());
			System.out.println("\t Address: " + contactList.get(i).getAddress()+ "\n");
		}
	}
	// Creates a function to add contacts. 
	public void addContact(String firstName, String lastName, String number, String address) {
		Contact contact = new Contact(firstName, lastName, number, address);
		contactList.add(contact);
		
	}
	// Creates a function to delete contacts. 
	public void deleteContact(String contactID) {
		for (int i = 0; i < contactList.size(); i++) {
			if (contactList.get(i).getContactID().equals(contactID)) {
				contactList.remove(i);
				break;
			}
			if (i == contactList.size() - 1) {
				System.out.println("Contact ID: " + contactID + "not found."); // Reports if the complier cannot find the contactID searched for by the user. 
			}
		}
	}
	// Updates the first name of a contact. 
	public void updateFirstName(String updatedString, String contactID) {
		for (int i = 0; i < contactList.size(); i++) {
			if (contactList.get(i).getContactID().equals(contactID)) {
				contactList.get(i).setFirstName(updatedString);
				break;
			}
			if (i == contactList.size() - 1) {
				System.out.println("Contact ID: " + contactID + "not found.");
			}
		}
	}
	// Updates the last name of a contact. 
	public void updateLastName(String updatedString, String contactID) {
		for (int i = 0; i < contactList.size(); i++) { 
			if (contactList.get(i).getContactID().equals(contactID)) {
				contactList.get(i).setLastName(updatedString);
				break;
			}
			if (i == contactList.size() - 1) {
				System.out.println("Contact ID: " + contactID + " not found.");
			}
		}
	}
	// Updates the number of a contact. 
	public void updateNumber(String updatedString, String contactID) {
		for (int i = 0; i < contactList.size(); i++) {
			if (contactList.get(i).getContactID().equals(contactID)) {
				contactList.get(i).setNumber(updatedString);
				break;
			}
			if (i == contactList.size() - 1) {
				System.out.println("Contact ID: " + contactID + " not found.");
			}
		}
	}
	// Updates the address of a contact. 
	public void updateAddress(String updatedString, String contactID) {
		for (int i = 0; i < contactList.size(); i++) {
			if (contactList.get(i).getContactID().equals(contactID)) {
				contactList.get(i).setAddress(updatedString);
				break;
			}
			if (i == contactList.size() - 1) {
				System.out.println("Contact ID: " + contactID + " not found.");
			}
		}
	}
}
