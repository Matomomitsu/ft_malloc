#include <stdlib.h>

int main(){
	void *teste = malloc(1);
	if (teste == NULL)
		return 1;
	return 2;
}
