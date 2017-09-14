#include "proto.h"

/*
============================================================================
 Function    : display_info
 Parameters  : none
 Return      : none
 Description : This function outputs a block header to the screen that con-
	       tains the department, class, name, EUID, and myUNT email add-
	       ress.
============================================================================
*/

void display_info()
{
	printf("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n"
	       "|         Computer Science and Engineering          |\n"
	       "|          CSCE 1040 - Computer Science II          |\n"
	       "|  Cole Dapprich  cwd0042  coledapprich@my.unt.edu  |\n"
 	       "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
}

/*
============================================================================
 Function    : new_course 
 Parameters  : struct course **c_head, struct course **c_tail
 Return      : none
 Description : This function adds a new node to the linked list of courses.
============================================================================
*/

void new_course(struct course **c_head, struct course **c_tail)
{
	// declare variables
	int ID;
	char name[50];

	// obtain user input
	printf("Enter the course ID number and the course name, separated by a space: ");
	scanf("%d%s", &ID, name);
	
	if((*c_head) == NULL) // no courses yet
	{
		(*c_head) = (struct course *) malloc(sizeof(struct course)); // allocate memory for c_head
		(*c_head)->c_next = NULL;
		(*c_tail) = (*c_head); // update c_tail
	}
	else // the list already has nodes
	{
		(*c_tail)->c_next = (struct course *) malloc(sizeof(struct course)); // allocate memory for new node
		(*c_tail) = (*c_tail)->c_next; // update c_tail
		(*c_tail)->c_next = NULL;
	}

	(*c_tail)->c_ID = ID; // assign ID to c_ID component of new node
	(*c_tail)->c_name = (char *) malloc(sizeof(char) * strlen(name) + 1); // allocate memory for c_name component of new node
	strcpy((*c_tail)->c_name, name); // assign name to c_name component of new node
}

/*
=============================================================================
 Function    : new_student
 Parameters  : struct student **s_head, struct student **s_tail
 Return      : none
 Description : This function adds a new node to the linked list of students.
=============================================================================
*/

void new_student(struct student **s_head, struct student **s_tail)
{
	// declare variables
	int ID;
	char name[50];

	// obtain user input
	printf("Enter the student ID number and the student name, separated by a space: ");
	scanf("%d%s", &ID, name);
	
	if((*s_head) == NULL) // no students yet
	{
		(*s_head) = (struct student *) malloc(sizeof(struct student)); // allocate memory for s_head
		(*s_head)->s_next = NULL;
		(*s_tail) = (*s_head); // update s_tail
	}
	else // the list already has nodes
	{
		(*s_tail)->s_next = (struct student *) malloc(sizeof(struct student)); // allocate memory for new node
		(*s_tail) = (*s_tail)->s_next; // update s_tail
		(*s_tail)->s_next = NULL;
	}

	(*s_tail)->s_ID = ID; // assign ID to s_ID component of new node
	(*s_tail)->s_name = (char *) malloc(sizeof(char) * strlen(name) + 1); // allocate memory for s_name component of new node
	strcpy((*s_tail)->s_name, name); // assign name to s_name component of new node
}

/*
============================================================================
 Function    : add_student_course
 Parameters  : struct enrollment **e_head, struct enrollment **e_tail
 Return      : none
 Description : This function adds a new node to the linked list of enroll-
	       ments.
============================================================================
*/

void add_student_course(struct enrollment **e_head, struct enrollment **e_tail)
{
	// declare variables
	int ID1, ID2;

	// obtain user input
	printf("Enter the ID number of the course you wish to add a student to: ");
	scanf("%d", &ID1);
	printf("Enter the ID number of the student you wish to add to the course: ");
	scanf("%d", &ID2);
	
	if((*e_head) == NULL) // no enrollments yet
	{
		(*e_head) = (struct enrollment *) malloc(sizeof(struct enrollment)); // allocate memory for e_head
		(*e_head)->e_next = NULL;
		(*e_tail) = (*e_head); // update e_tail
	}
	else // the list already has nodes
	{
		(*e_tail)->e_next = (struct enrollment *) malloc(sizeof(struct enrollment)); // allocate memory for new node
		(*e_tail) = (*e_tail)->e_next; // update e_tail
		(*e_tail)->e_next = NULL;
	}

	(*e_tail)->e_c_ID = ID1; // assign ID1 to e_c_ID component of new node
	(*e_tail)->e_s_ID = ID2; // assign ID2 to e_s_ID component of new node
}

/*
============================================================================
 Function    : add_grades
 Parameters  : struct grade **g_head, struct grade **g_tail
 Return      : none
 Description : This function adds a new node in the linked list of grades
	       under the selected course and student ID numbers.
============================================================================
*/

void add_grades(struct grade **g_head, struct grade **g_tail)
{
	// declare variables
	int ID1, ID2, grade = 0;

	//obtain user input
	printf("Enter the ID number of the course you wish to add grades in: ");
	scanf("%d", &ID1);
	printf("Enter the ID number of the student you wish to add grades for: ");
	scanf("%d", &ID2);

	while(grade != -1) // obtains grades until the user enters -1
	{
		if((*g_head) == NULL) // no grades yet
		{
			(*g_head) = (struct grade *) malloc(sizeof(struct grade)); // allocate memory for g_head
			(*g_head)->g_next = NULL;
			(*g_tail) = (*g_head); // update g_tail
		}
		else // the list already has nodes
		{
			(*g_tail)->g_next = (struct grade *) malloc(sizeof(struct grade)); // allocate memory for new node
			(*g_tail) = (*g_tail)->g_next; // update g_tail
			(*g_tail)->g_next = NULL;
		}
		
		(*g_tail)->g_c_ID = ID1; // assign ID1 to g_c_ID component of new node
		(*g_tail)->g_s_ID = ID2; // assign ID2 to g_s_ID component of new node
		
		printf("Enter a grade (if there are no more grades, enter -1): ");
		scanf("%d", &grade);
		if (grade > -1)
		{
			(*g_tail)->g = grade; // assign grade to g component of new node
		}
		else
		{
			(*g_tail)->g = EOF;
		}
	}
}

/*
============================================================================
 Function    : print_grades_student
 Parameters  : struct grade *g_head
 Return      : none
 Description : This function prints all grades that are associated with a
	       chosen course and student.
============================================================================
*/

void print_grades_student(struct grade *g_head)
{
	//declare variables
	int ID1, ID2;
	struct grade *walk = NULL;

	//obtain user input
	printf("Enter the ID number of the course you wish to print grades from: ");
	scanf("%d", &ID1);
	printf("Enter the ID number of the student whose grades you wish to print: ");
	scanf("%d", &ID2);
	printf ("The grades for Student #%d in Course #%d are:\n\n", ID2, ID1);

	walk = g_head; // assigns placeholder to first node
	while (walk != NULL)
	{
		if (walk->g_c_ID == ID1) // walk matches the selected course
		{
			if (walk->g_s_ID == ID2) // walk matches the selected student
			{
				if (walk->g != EOF)
				{	
					printf("%d\n", walk->g); // print the grade
				}
			}
		}
		walk = walk->g_next; // update the loop
	}
	printf("\n---End of list--\n");
}

/*
============================================================================
 Function    : print_students_course
 Parameters  : struct enrollment *e_head
 Return      : none
 Description : This function prints out all student IDs that are associated
	       with a chosen course.
============================================================================
*/

void print_students_course(struct enrollment *e_head)
{
	//declare variables
	int ID;
	struct enrollment *walk = NULL;

	//obtain user input
	printf("Enter the ID number of the course you wish to print students from: ");
	scanf("%d", &ID);
	printf ("The students enrolled in Course #%d are:\n\n", ID);

	walk = e_head; // assigns placeholder to first node
	while (walk != NULL)
	{
		if (walk->e_c_ID == ID) // walk matches the selected course
		{
			printf("%d\n", walk->e_s_ID); // print the student ID
		}
		walk = walk->e_next; // update the loop
	}
	printf("\n---End of list---\n");
}

/*
============================================================================
 Function    : student_avg
 Parameters  : struct grade *g_head
 Return      : a double representing the average of all a student's grades
	       in a course
 Description : This function adds together all the grades that match the de-
	       sired course and student ID numbers, then finds the average.
============================================================================
*/

double student_avg(struct grade *g_head)
{	
	//declare variables
	int ID1, ID2, sum = 0;
	double result, count = 0;
	struct grade *walk = NULL;

	//obtain user input
	printf("Enter the ID number of the student whose grades you wish to average: ");
	scanf("%d", &ID1);
	printf("Enter the ID number of the course you would like to calculate the average for: ");
	scanf("%d", &ID2);

	walk = g_head; // assigns placeholder to first node
	while (walk != NULL)
	{
		if (walk->g_c_ID == ID2) // walk matches the selected course
		{
			if (walk->g_s_ID == ID1) // walk matches the selected student
			{
				if (walk->g != EOF)
				{
					sum += walk->g; // add the matching grade to sum
					count++;        // update count
				}
			}
		}
		walk = walk->g_next; // update the loop
	}

	result = sum / count; // calculate average

	return result;
}

/*
============================================================================
 Function    : print_courses 
 Parameters  : struct course *c_head
 Return      : none
 Description : This function prints all the nodes in the linked list of
	       courses.
============================================================================
*/

void print_courses(struct course * c_head)
{
	// declare variables
	struct course *walk = NULL;
	
	printf("********** Courses: *****\nID:\t\t   Name: \n\n");
	walk = c_head; // assigns placeholder to first node
	while (walk != NULL) // walks through the list until it reaches a node with no data
	{
		printf("%4d %20s\n", walk->c_ID, walk->c_name); // prints out the contents of each node
		walk = walk->c_next;
	}
	printf("\n---End of list---\n");
}

/*
============================================================================
 Function    : print_students_all 
 Parameters  : struct student *s_head
 Return      : none
 Description : This function prints all the nodes in the linked list of stu-
	       dents.
============================================================================
*/

void print_students_all(struct student *s_head)
{
	// declare variables
	struct student *walk = NULL;
	
	printf("********** Students: *****\nID:\t\t   Name: \n\n");
	walk = s_head; // assigns placeholder to first node
	while (walk != NULL) // walks through the list until it reaches a node with no data
	{
		printf("%4d %20s\n", walk->s_ID, walk->s_name); // prints out the contents of each node
		walk = walk->s_next;
	}
	printf("\n---End of list---\n");
}

/*
============================================================================
 Function    : course_avg
 Parameters  : struct grade *g_head
 Return      : a double representing the average of all grades in a course
 Description : This function adds together all the grades that match the de-
	       sired course ID number, then calculates the average.
============================================================================
*/

double course_avg(struct grade *g_head)
{	
	//declare variables
	int ID, sum = 0;
	double result, count = 0;
	struct grade *walk = NULL;

	//obtain user input
	printf("Enter the ID number of the course you would like to calculate the average for: ");
	scanf("%d", &ID);

	walk = g_head; // assigns placeholder to first node
	while (walk != NULL)
	{
		if (walk->g_c_ID == ID) // walk matches the selected course
		{	
			if (walk->g != EOF)
			{
				sum += walk->g; // add the matching grade to sum
				count++;        // update count
			}
		}
		walk = walk->g_next; // update the loop
	}

	result = sum / count; // calculate average

	return result;
}

/*
============================================================================
 Function    : save
 Parameters  : struct course *c_head, struct course *c_tail, struct student
	       *s_head, struct student *s_tail, struct enrollment *e_head,
	       struct enrollment *e_tail, struct grade *g_head, struct grade
	       *g_tail
 Return      : none
 Description : This function writes all the nodes from the 4 linked lists to
	       a .txt file
============================================================================
*/

void save(struct course *c_head, struct course *c_tail, struct student *s_head, struct student *s_tail, struct enrollment *e_head, struct enrollment *e_tail, struct grade *g_head, struct grade *g_tail)
{
	// declare variables
	struct course *c_walk = NULL;
	struct student *s_walk = NULL;
	struct enrollment *e_walk = NULL;
	struct grade *g_walk = NULL;
	FILE *toFile;
	char f_name[20];

	//obtain input
	printf("Enter the name of the file you wish to write to, including the extension: ");
	scanf("%s", f_name);

	// open file
	toFile = fopen(f_name, "w");

	if (toFile == NULL)
	{
		printf("ERROR: Unable to open file: %s", f_name);
		exit(1);
	}

	// write courses
	c_walk = c_head; // assigns placeholder to first node
	while (c_walk != NULL) // walks through the list until it reaches a node with no data
	{
		fprintf(toFile, "%4d %20s\n", c_walk->c_ID, c_walk->c_name); // writes the contents of each node
		c_walk = c_walk->c_next;
	}
	
	// write students
	s_walk = s_head; // assigns placeholder to first node
	while (s_walk != NULL) // walks through the list until it reaches a node with no data
	{
		fprintf(toFile, "%4d %20s\n", s_walk->s_ID, s_walk->s_name); // writes the contents of each node
		s_walk = s_walk->s_next;
	}	
	
	// write enrollments
	e_walk = e_head; // assigns placeholder to first node
	while (e_walk != NULL) // walks through the list until it reaches a node with no data
	{
		fprintf(toFile, "%4d %4d\n", e_walk->e_c_ID, e_walk->e_s_ID); // writes the contents of each node
		e_walk = e_walk->e_next;
	}	

	// write grades
	g_walk = g_head; // assigns placeholder to first node
	while (g_walk != NULL) // walks through the list until it reaches a node with no data
	{
		fprintf(toFile, "%4d %4d %3d\n", g_walk->g_c_ID, g_walk->g_s_ID, g_walk->g); // writes the contents of each node
		g_walk = g_walk->g_next;
	}
	
	//close file
	fclose(toFile);
}

/*
============================================================================
 Function    : load
 Parameters  : struct course *c_head, struct course *c_tail, struct student
	       *s_head, struct student *s_tail, struct enrollment *e_head,
	       struct enrollment *e_tail, struct grade *g_head, struct grade
	       *g_tail
 Return      : none
 Description : This function scans all the nodes from the 4 linked lists
	       from a .txt file, then assigns them to the appropriate vari-
	       able.
============================================================================
*/

void load(struct course **c_head, struct course **c_tail, struct student **s_head, struct student **s_tail, struct enrollment **e_head, struct enrollment **e_tail, struct grade **g_head, struct grade **g_tail)
{
	//couldn't figure this one out
	return;
}
