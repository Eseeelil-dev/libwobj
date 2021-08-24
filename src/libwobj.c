#include "libwobj.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef LIBWOBJ_DEBUG
#pragma message "LIBWOBJ_DEBUG is set. Debugging output is enabled"
#define	LOG(comment) printf(__FILE__ ":%d " comment "\n", __LINE__);
#else
#define LOG(comment) void(0);
#endif

#define MAX_OBJECTS 8

static void * object_table[MAX_OBJECTS] = { 0 };

static void wobj_load_file(FILE* pfile);

int wobj_load_from_file(const char *filename)
{
	int iobj_index;

	for (iobj_index = 0; iobj_index < MAX_OBJECTS; iobj_index++) {
		if (object_table[iobj_index] == 0) {
			break;
		}
	}
	
	if (iobj_index == MAX_OBJECTS) {
		LOG("Object table is full");
		return -1;
	}

	FILE * pfile = fopen(filename, "r");
	if (!pfile) {
		LOG("Failed to open file");
		return -1;
	}

	wobj_load_file(pfile);

	fclose(pfile);

	return iobj_index;
}

void wobj_load_file(FILE* pfile)
{
	char buff[4096];
	int ret;

	ret = fread(buff, sizeof(char), 4096, pfile);
	if (ret != 0) {
		if (ret == 4096) {
			ret -= 1;
		}
		buff[ret] = '\0';
		printf("Output:\n%s\n", buff);
	} else {
		if (ferror(pfile) != 0) {
			LOG("Reading file error");
		}
	}
}

void wobj_free(int handle)
{

}

