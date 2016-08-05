#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int ntree_insert(NTree **tree, char **parents, char *data);
void print_ntree(NTree *);
void print_tree_recurse(NTree *tree, int tabs);
int get_words(char *str, char seperator);
int get_word_len(char *fast, char seperator);
char **string_split(char *ptr, char seperator);

int main() {
  /*test insert*/
  NTree *tree = NULL;
  ntree_insert(&tree, NULL, "/");

  ntree_insert(&tree, string_split("/", ' '), "home");
  ntree_insert(&tree, string_split("/", ' '), "opt");
  ntree_insert(&tree, string_split("/ home", ' '), "john");
  ntree_insert(&tree, string_split("/ home", ' '), "sys");
  ntree_insert(&tree, string_split("/ home john", ' '), "other");
  ntree_insert(&tree, string_split("/ opt", ' '), "bin");
  ntree_print(tree);
  return 0;
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
