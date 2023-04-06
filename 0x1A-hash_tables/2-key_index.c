#include "hash_tables.h"

/**
 * key_index - gets the index of a key in a hash table array
 * @key: the key
 * @size: the size of the hash table array
 *
 * Return: the index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash_val;

    hash_val = hash_djb2(key);
    return (hash_val % size);
}

