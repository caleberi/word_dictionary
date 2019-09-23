#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <error.h>

#define MAXLENGTH 46

struct word_node{
        
        char word[MAXLENGTH];
        struct word_node* left;
        struct word_node* right;
        int count;

};

typedef struct word_node word_node;

struct word_tree{
        word_node* root;
        int size;
};


typedef struct word_tree word_tree;

bool empty(word_tree*);
word_tree* create_word_tree(const char[]);
void save(word_tree*,const char[]);
bool contains(word_tree*,word_node*,const char[]);
word_node* find_node_location(word_tree*,word_node*,const char[]);
void print_word_Tree(word_node*);
