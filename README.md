# C867-ScriptingAndProgrammingApplications
Final exam for C867 course

You are hired as a contractor to help a university migrate an existing student system to a new platform using C++ language. Since the application already exists, its requirements exist as well. You are responsible for implementing the part of the system based on these requirements. A list of data is provided as part of these requirements. This part of the system is responsible for reading and manipulating the provided data. 

You will write a program containing five classes (Student, SecurityStudent, NetworkStudent, SoftwareStudent, and Roster). The program will maintain a current roster of students within a given course. Student data for the program includes studentID, first name, last name, email address, age, an array of the number of days to complete each course, and degree. The program will read a list of five students and use function calls to manipulate data. While parsing the list of data, the program should create student objects using the appropriate subclasses indicated by the degree program. The entire student list will be stored in one array of students called classRosterArray. Specific data-related output will be directed to the console.

STUDENT STRING DATA:

const string studentData[] =
 {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
 "A5,Bethany,Carpio,bcarpio@my.wgu.edu,29,
 20,50,42,SOFTWARE"
