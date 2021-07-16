#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	uint32_t sale = 0;
	scanf("%" SCNu32, &sale);
	printf("sale = %" PRIu32 "\n", sale);
	printf("UINT32_MAX = %#" PRIx32 "\n", UINT32_MAX);
	return 0;
}