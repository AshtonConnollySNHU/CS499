# CS499
## Computer Science Capstone ePortfolio
## Ashton Connolly || Southern New Hampshire University


### Overview

This ePortfolio showcases an upgraded version of a Contact Service Application I had made during my time at SNHU. Specifically, I made the original Contact Service Application for my **CS320: Software Testing, Automation, and Quality** Course. Throughout my time in **CS499** I refactored, redesigned, and upgraded the program to demonstrate the following capabilities:
- *Software Design / Engineering*
- *Understanding of Multiple code languages*
- *Algorithim / data structures*
- *Databases*
- *Secure Coding*
- *Professional Communication*

 ### Table Of Contents

 1. Self-Assessment
 2. Code Review
 3. Software Design Enhancement
 4. Algorithmic / Data Structure Enhancements
 5. Database Enhancement
 6. Security Considerations
 7. Course Outcome Alignment
 8. One Last Reflection

### 1. Self-Assessment

Throughout my time in SNHU's Computer Science Program, I gained many unique software development skills that are needed in our world of modern computing. I have learned how to code in multiple languages, build web-pages, program AI, Design enviornments in a 3D space, work with databases, and many other such skills. For my project in this course, I touched on the three primary skills that were requested from the different development capstones. These different capstones allowed me to demonstrate my capability to:

- Code in different languages / Translate code between different languages
- Build secure and highly performative data structures
- implement secure hash algorithm functionality
- Build a database for persistent data storage post runtime
- Automated Testing Through GoogleTest

My original program was designed in Java and contained very limited functionality to demonstrate code capability that stay within test parameters. This new project is meant to demonstrate code that is more scalable, maintainable, functionable, and secure. 

### 2. Code Review

In my initial code review I examined my original Java version of the Contact Service Application. In this review I found some key issues:

- The app used an incremental ID system (going from 0 to 1, 2, 3 ...)
- Contacts were stored in a linear array list (makes contact search take longer)
- No database
- Contacts were not secured

After my code review I decided to make three major components with the alloted time I had: 
1. Convert the program from Java to a more performative and compatible C++
2. Replace incremental IDs with Hashes / Change array list to a Hash table
3. Build a new database into the system for persistence

### 3. Software Design Enhancement (Java -> C++)

My original artifact was written in Java which allowed for the use of JUnit testing that was originally found within that system. However for a more enhanced version of this project I decided to move the program over from Java to C++. This change allowed me to improve memory control that could be used if needed. Furthermore, I was able to implement stronger architectural seperation between components through a definitive service layer, data layer, and function layer. Lastly, this change was implemented to improve the speed and performance of the program as it works faster in C++ as opposed to Java.

### 4. Algorithm / Data Structure Enhancement

My original artifact used incremental IDs and an array list for the sake of functionality. When this program was first made it was developed solely to understand easy testing functionality. In a real world contact service however, this implementation can cause collisions, insecurity, bugs, and slow performance. For my enhanced version, I used SHA-256 hashing through Windows CNG bcrypt and two new HashUtil files. This allowed for the ID to be made through the generation of a 64-character hexadecimal as opposed to a small digit that can be copied. Furthermore, I changed the Array list function to an unordered map / hash-based container that could retrieve these hashes faster to speed up the program. I was able to do this while perserving test functionality by removing hard coded test assumptions for id and also changing JUnit testing to GoogleTest for language compatibility. 

### 5. Database Enhancement

The original version of this application only stored contacts in memory. This means that memory was not persistent and could not be accessed after runtime. To get this program closer to real world functionality, I made a new database system using SQLite using the amalgamation source. I then implemented a brand new DatabaseManager class and created initialization logic. Lastly, I had to make sure that it was capable of working with the hash IDs that I had just implemented previously. Lastly, my new database was implemented in a manner that was seperated from logic, mitigated SQL execution, and contained the proper exception handling. 

### 6. Security Considerations

Majority of the security upgrades done to this project were done so through the implementation of the brand new Hash system. C++ is often cited as less secure than java, but the memory allocation is an improvement especially considering the lack of memory this program had initially. However, through the use of SHA-256 hashing and Windows CNG most of the contact service functionality is secured from encapsulation attacks or predictable ids that can be guessed by attackers. 

### 7. Course Outcome Alignment

This capstone course helped me demonstrate my skills and progress in the following computer science program outcomes:

- ##### **Collaborative Environment Strategies**
  *I demonstrated my code review process, narrated my progress through documentations to my instructor, and followed milestone feedback provided from my instructor.*

- ##### **Professional Communication**
  *I structured my milestone narratives to best communicate my outcomes, troubles, and future goals for the project.*

- ##### **Design Tradeoffs**
  *I traded low storage sequential IDs for secure Hash IDs, simplistic linear listing for faster hash-based structure, and traded Java's security for performance and control.*

- ##### **Tool Implementation**
  *I implemented SQLite, CMake, GoogleTest, and Windows CNG to enhance the functionality of this program.*

- ##### **Secure Coding Mindset**
  *I implemented secure ID hash generation that reduced predictability or collision risks. I also kept the database layer seperate and still maintained defensive error testing / handling within the program.*

### 7. One Last Reflection

To me this project is more than just improvements on an earlier assignment. Rather they are a repressentation of how I approach software development today. Instead of keeping the program successful at passing tests with some extra functionality, I aimed to improve this project in every aspect that mattered. I gave this project higher security, scalability potential, maintainablity, and better overall performance. In my time at SNHU I have learned that coding is a lot more adjacent to writing. When you go back to read an old paper there are always improvements to be made. An essay never exists in a concrete *Perfect* form. Code is very much the same. In the world of Computer programming, enhancements can always be made and security must always needs to be changed. 
