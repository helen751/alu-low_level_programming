#include "dog.h"
#include <stdlib.h>

/**
 * copy_string - creates a copy of a string
 * @source: string to copy
 *
 * Return: pointer to the copy, or NULL on failure
 */
char *copy_string(char *source)
{
	char *copy;
	int length;
	int i;

	length = 0;
	while (source[length] != '\0')
		length++;

	copy = malloc(sizeof(char) * (length + 1));
	if (copy == 0)
		return (0);

	for (i = 0; i <= length; i++)
		copy[i] = source[i];

	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	if (name == 0 || owner == 0)
		return (0);

	dog = malloc(sizeof(dog_t));
	if (dog == 0)
		return (0);

	dog->name = copy_string(name);
	if (dog->name == 0)
	{
		free(dog);
		return (0);
	}

	dog->owner = copy_string(owner);
	if (dog->owner == 0)
	{
		free(dog->name);
		free(dog);
		return (0);
	}

	dog->age = age;
	return (dog);
}
