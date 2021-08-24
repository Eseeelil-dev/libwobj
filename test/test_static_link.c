#include "libwobj.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i;

	i = wobj_load_from_file("test/test_file.obj");
	if (i != 0)
		exit(1);

	printf(__FILE__ ": wobj_load_from_file is return = %i\n", i);

	wobj_free(i);

	return 0;
}

