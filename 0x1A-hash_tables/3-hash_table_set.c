#include "hash_tables.h"
/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table to add or update the key/value to
 * @key: the key. key can not be an empty string
 * @value: the value associated with the key. value must be duplicated.
 *         value can be an empty string
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node = NULL;
    hash_node_t *head = NULL;

    if (ht == NULL || key == NULL || strlen(key) == 0)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    head = ht->array[index];

    while (head != NULL)
    {
        if (strcmp(head->key, key) == 0)
        {
            free(head->value);
            head->value = strdup(value);
            if (head->value == NULL)
                return (0);
            return (1);
        }
        head = head->next;
    }

    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
