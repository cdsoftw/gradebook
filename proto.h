#include "struct.h"

// function declarations (prototypes)
void display_info(); // prints out basic programmer info

void new_course(struct course **c_head, struct course **c_tail); // adds a node in the linked list of courses

void new_student(struct student **s_head, struct student **s_tail); // adds a node in the linked list of students

void add_student_course(struct enrollment **e_head, struct enrollment **e_tail); // adds a node in the linked list of enrollments

void add_grades(struct grade **g_head, struct grade **g_tail); // adds a node in the linked list of grades

void print_grades_student(struct grade *g_head); // prints out all grade nodes that match the desired course and student IDs

void print_students_course(struct enrollment *e_head); // prints the student IDs in every enrollment node that matches the desired course ID

double student_avg(struct grade *g_head); // adds together all grades that match the desired course and student IDs, then calculates the average

void print_courses(struct course *c_head); // prints all nodes in the linked list of courses

void print_students_all(struct student *s_head); // prints all nodes in the linked list of students

double course_avg(struct grade *g_head); // adds together all grades that match the desired course ID, then calculates the average

void save(struct course *c_head, struct course *c_tail, struct student *s_head, struct student *s_tail, struct enrollment *e_head, struct enrollment *e_tail, struct grade *g_head, struct grade *g_tail); // prints all the nodes from the 4 linked lists to a txt file

void load(struct course **c_head, struct course **c_tail, struct student **s_head, struct student **s_tail, struct enrollment **e_head, struct enrollment **e_tail, struct grade **g_head, struct grade **g_tail); // scans all the nodes from the 4 linked lists from a txt file
