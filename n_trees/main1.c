#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
void ntree_free(NTree *);
void free_str_array(char **);

int path_exists(NTree *, char **);
int ntree_insert(NTree **, char **, char *);
int get_words(char *str, char seperator);
int get_word_len(char *fast, char seperator);
char **string_split(char *ptr, char seperator);

int main(void)
{
    NTree *tree;
    char **array;

    tree = NULL;
    ntree_insert(&tree, NULL, "/");
    ntree_insert(&tree, (array = string_split("/", ',')), "home");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home", ' ')), "ubuntu");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Documents");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Download");
    free_str_array(array);
    ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Public");
    free_str_array(array);

    printf("Path=[%s], present:%d\n", "/ home", path_exists(tree, (array = string_split("/ home", ' '))));
    free_str_array(array);
    printf("Path=[%s], present:%d\n", "/ home ubuntu", path_exists(tree, (array = string_split("/ home ubuntu", ' '))));
    free_str_array(array);
    printf("Path=[%s], present:%d\n", "/ home ubuntu Download", path_exists(tree, (array = string_split("/ home ubuntu Download", ' '))));
    free_str_array(array);
    printf("Path=[%s], present:%d\n", "/ home student", path_exists(tree, (array = string_split("/ home student", ' '))));
    free_str_array(array);
    printf("Path=[%s], present:%d\n", "/ home ubuntu Public file", path_exists(tree, (array = string_split("/ home ubuntu Public file", ' '))));
    free_str_array(array);

    ntree_free(tree);
    return (0);
}

/*
 * Function that splits strings into array of strings depending on
 * seperator.
 */
char **string_split(char *ptr, char seperator)
{
	char **ret;
	char *ret_ptr;
	int count = 0;
	int word_count = 0;
	count = get_words(ptr, seperator);
	if (count == 0) {
		ret = (char **) malloc(sizeof(char *)*1);
		ret[0] = NULL;
		return ret;
	}
	ret = (char **) malloc(sizeof(char *) * (count+2));
	while (*ptr != 0) {
		while (*ptr == seperator)
			ptr++;
		count = get_word_len(ptr, seperator);
		ret[word_count] = (char *) malloc(sizeof(char) * (count + 1));
		ret_ptr = ret[word_count];
		while (*ptr != seperator && *ptr != 0) {
			*ret_ptr = *ptr;
			ret_ptr++;
			ptr++;
		}
		while (*ptr == seperator)
			ptr++;
		*ret_ptr = 0;
		word_count++;
	}
	ret[word_count] = NULL;
	return ret;
}

/*
 * gets the number of segments to break the string into
 */
int get_words(char *ptr, char seperator)
{
	int count = 0;
	while (*ptr != 0) {
		while (*ptr == seperator)
			ptr++;
		if (*ptr == 0)
			break;
		while (*ptr != seperator && *ptr != 0)
			ptr++;
		count++;
	}
	return count;
}

/*
 * gets the length of the segment starting at fast
 */
int get_word_len(char *fast, char seperator)
{
	int count = 0;
	while (*fast != seperator && *fast != 0) {
		count++;
		fast++;
	}
	return count;
}

void free_str_array(char **command)
{
	int counter = 0;
	while (command[counter] != 0) {
		free(command[counter]);
		counter++;
	}
	free(command);
}
