#include "hash_tables.h"

/**
 * hash_table_set - adds or updates an element to the hash table
 * @ht: the hash table to add or update the element to
 * @key: the key of the element to add or update
 * @value: the value of the element to add or update
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node, *cur_node;

    if (ht == NULL || key == NULL || *key == '\0')
        return 0;

    index = key_index((const unsigned char *) key, ht->size);

    /* Check if the key already exists in the hash table */
    for (cur_node = ht->array[index]; cur_node != NULL; cur_node = cur_node->next)
    {
        if (strcmp(cur_node->key, key) == 0)
        {
            /* Update the value of the existing node */
            free(cur_node->value);
            cur_node->value = strdup(value);
            if (cur_node->value == NULL)
                return 0;
            return 1;
        }
    }

    /* Create a new node */
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return 0;

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    if (new_node->key == NULL || new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return 0;
    }

    /* Add the new node to the beginning of the linked list */
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return 1;
}
