#include "../code/include/csapp.h"

int main()
{
	unsigned int n = 0;
	scanf("%d", &n);
	int* array = NULL;
	array = (int*)Malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &array[i]);
	}
	Free(array);
	return 0;
}