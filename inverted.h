#ifndef INVERTED_H
#define INVERTED_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS		0
#define FAILURE		-1
#define INSERTION_FAILURE -2

typedef struct file
{
    char f_name[20];
    struct file *link;
}F_node;

typedef struct Sub
{
    int word_count;
    char filename[20];
    struct Sub *sub_link;
}S_node;

typedef struct Main
{
    char word[25];
    int file_count;
    S_node *sub_link;
    struct Main *main_link;
}M_node;

typedef struct Hashtable
{
    int index;
    M_node *H_link;
}hash;

int create_database(hash *HT, F_node *head);
void display_database(hash *HT);
void search_database(hash *HT);
void save_database(hash *HT,F_node *head);
int update_database(hash *HT,F_node **head);

int validate_files(char *argv[], F_node **head);
int insert_last(F_node **head, char *f_name);
int check_duplicates(F_node *head, char *f_name);
int print_filenames(F_node *head);
int get_index(char *word);

int insert_hashtable(hash *HT,char *word,char *file_name);
M_node* create_mnode(char *word);
S_node* create_snode(char *file_name);

#endif
