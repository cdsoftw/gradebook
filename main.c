/*
============================================================================
 Name        : main.c
 Author      : Cole Dapprich
 Version     : 2.0
 Copyright   : 2015
 Description : This c file displays the menu and calls the functions for a
	       simple gradebook program.
============================================================================
*/

#include "proto.h"

int main ( )
{
	display_info(); // displays block header with basic info

	// variable declarations
	int choice;
	double s_avg, c_avg;

	printf("\t\tWelcome to Gradebook 2.0!\n\n");

	// create linked lists
	struct course *c_head = NULL;
	struct course *c_tail = NULL;
	struct student *s_head = NULL;
	struct student *s_tail = NULL;
	struct enrollment *e_head = NULL;
	struct enrollment *e_tail = NULL;
	struct grade *g_head = NULL;
	struct grade *g_tail = NULL;

	// print out menu, obtain choice, call appropriate function; loop if desired
	do
	{
		printf("\t\t\t***MENU***\n"
		       " 1. Add a new course\n"
		       " 2. Add a new student\n"
		       " 3. Add a student to a course\n"
		       " 4. Add grades for a student in a course\n"
		       " 5. Print a list of all grades for a student in a course\n"
		       " 6. Print a list of all students in a course\n"
		       " 7. Compute the average for a student in a course\n"
		       " 8. Print a list of all courses\n"
		       " 9. Print a list of all students\n"
		       "10. Compute the average for a course\n"
		       "11. Store Grade book (to a disk file)\n"
		       "12. Load Grade book (from a disk file)\n"
		       " 0. Exit\n\n"
		       "Enter the number of the menu option you wish to choose: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 0:
				break;
			case 1:
				new_course(&c_head, &c_tail);
				if (c_tail == NULL)
				{
					printf("We're screwed.\n"); // this excecutes every time
				}
				break;
			case 2:
				new_student(&s_head, &s_tail);
				printf("\n");
				break;
			case 3:
				add_student_course(&e_head, &e_tail);
				printf("\n");
				break;
			case 4:
				add_grades(&g_head, &g_tail);
				printf("\n");
				break;
			case 5:
				print_grades_student(g_head);
				break;
			case 6:
				print_students_course(e_head);
				break;
			case 7:
				s_avg = student_avg(g_head);
				printf("The average of all grades for the selected student in the selected course is: %f\n", s_avg);
				break;
			case 8:
				print_courses(c_head);
				break;
			case 9:
				print_students_all(s_head);
				break;
			case 10:
				c_avg = course_avg(g_head);
				printf("The average of all grades in the selected course is: %f\n", c_avg);
				break;
			case 11:
				save(c_head, c_tail, s_head, s_tail, e_head, e_tail, g_head, g_tail);
				break;
			case 12:
				load(&c_head, &c_tail, &s_head, &s_tail, &e_head, &e_tail, &g_head, &g_tail);
				break;
			default:
				printf("\n");
		}

	} while (choice != 0);

	// free grades
	struct grade *g_temp = NULL;
	g_temp = g_head;
	while (g_temp != NULL)
	{
		g_head = g_head->g_next;
		g_temp->g_c_ID = 0; // reinitialize the course ID for entering grades
		g_temp->g_s_ID = 0; // reinitialize the student ID for entering grades
		g_temp->g = 0;      // reinitialize the grade
		free(g_temp);       // return the node memory to the system
		g_temp = g_head;    // set temp to next item in the list
	}

	// free enrollments
	struct enrollment *e_temp = NULL;
	e_temp = e_head;
	while (e_temp != NULL)
	{
		e_head = e_head->e_next;
		e_temp->e_c_ID = 0; // reinitialize the course ID for creating enrollments
		e_temp->e_s_ID = 0; // reinitialize the student ID for creating enrollments
		free(e_temp);       // return the node memory to the system
		e_temp = e_head;    // set temp to next item in the list
	}

	// free students
	struct student *s_temp = NULL;
	s_temp = s_head;
	while (s_temp != NULL)
	{
		s_head = s_head->s_next;
		s_temp->s_ID = 0;	  // reinitialize the student ID
		s_temp->s_name[0] = '\0'; // reinitialize the student name string
		free(s_temp->s_name);	  // return the string memory to the system
		free(s_temp);		  // return the node memory to the system
		s_temp = s_head;	  // set temp to next item in the list
	}

	// free courses
	struct course *c_temp = NULL;
	c_temp = c_head;
	while (c_temp != NULL)
	{
		c_head = c_head->c_next;
		c_temp->c_ID = 0;	  // reinitialize the student ID
		c_temp->c_name[0] = '\0'; // reinitialize the student name string
		free(c_temp->c_name);	  // return the string memory to the system
		free(c_temp);		  // return the node memory to the system
		c_temp = c_head;	  // set temp to next item in the list
	}

	return 0;
}
