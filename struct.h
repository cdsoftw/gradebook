#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definition of structures that represent a course, a student, an enrollment, and a grade
struct course
{
	int c_ID;
	char *c_name;
	struct course *c_next;
};

struct student
{
	int s_ID;
	char *s_name;
	struct student *s_next;
};

struct enrollment
{
	int e_c_ID;
	int e_s_ID;
	struct enrollment *e_next;
};

struct grade
{
	int g_c_ID;
	int g_s_ID;
	int g;
	struct grade *g_next;	
};
