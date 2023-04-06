#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 * Return: pointer to the new hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *ht = NULL;

    /* Allocate memory for hash table structure */
    ht = malloc(sizeof(hash_table_t));
    if (ht == NULL)
        return (NULL);

    /* Allocate memory for the array */
    ht->array = malloc(sizeof(hash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    /* Set size and initialize array elements to NULL */
    ht->size = size;
    for (unsigned long int i = 0; i < size; i++)
        ht->array[i] = NULL;

    return (ht);
}
