#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees a dog and its allocated strings
 * @d: pointer to the dog to free
 */
void free_dog(dog_t *d)
{
	if (d == 0)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}
