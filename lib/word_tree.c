#include "word_tree.h"
//  check to see whether  the tree is empty
bool empty(word_tree* t){
        return t->size == 0;
}

//  check to see whether  the tree contains  the provided word
bool contains(word_tree* t,word_node* root,const char word[]){
        //@TODO: implement  contain method
        clock_t start,finish;
        start = clock();
        if(strcmp(word,root->word) != 0 ){
                        
                if (strcmp(word,root->word) < 0)
                {
                        if(root->left == NULL){
                        finish = clock();
                        printf(" \t saving finished :%.2f \n",(double)((finish-start)/CLOCKS_PER_SEC));
                        return false;
                        }else{
                                if(strcmp(word,root->word) == 0){
                                        return true;
                                }
                                root= root->left;
                                contains(t,root,word);
                        }
                }
                else if(strcmp(word,root->word) >  0){
                        if(root->right == NULL){
                        finish = clock();
                        printf(" \t saving finished :%.2f \n",(double)((finish-start)/CLOCKS_PER_SEC));
                        return false;
                        }else{
                                if(strcmp(word,root->word) == 0){
                                        return true;
                                }
                                root = root->right;
                                contains(t,root,word);
                        }
                }
        }else
        {
                finish = clock();
                printf(" \t saving finished :%.2f \n",(double)((finish-start)/CLOCKS_PER_SEC));
                return true;
        }
};

// returns the  memory location of the word in the word_tree
word_node* find_node_location(word_tree* t,word_node* root,const char word[]){
        if(strcmp(word,root->word)== 0){
                
                return root;
        }
        else if(strcmp(word,root->word)< 0)
        {
        
                if(strcmp(word,root->word)== 0){
                        
                        return root;
                }
                root= root->left;
                find_node_location(t,root,word);
        }
        else if(strcmp(word,root->word)> 0){
                
                if(strcmp(word,root->word)== 0){
                        return root;
                }
                root = root->right;
                find_node_location(t,root,word);
        }
        else{
                return NULL;
        }
}

// builds a tree scaffold to insert more word_node 
word_tree* create_word_tree( const char root_word[]){

        word_node* tn = (word_node*)malloc(sizeof(word_node));
        strcpy(tn->word,root_word);
        tn->left = tn->right = NULL;
        tn->count = 1;

        word_tree* t = (word_tree*)malloc(sizeof(word_tree));
        t->root= tn;
        t->size++;
        return t;
}

/*
        * @params takes in a pointer to a tree and takes a word 
        * 
*/
void save(word_tree* t,const char word[]){
        clock_t start,finish;
        start = clock();
        word_node* tn = (word_node*)malloc(sizeof(word_node));
        strcpy(tn->word,word);
        tn->left = tn->right = NULL;
        if(empty(t)){
                perror("Empty tree without root");
        }
        
        if(!contains(t,t->root,word))
        { 
                // means it is new and set it occurences to 0;
                tn->count = 0; 

        }
        else{
                word_node* found_location = find_node_location(t,t->root,word);
                found_location->count++;
                return;
        }

        word_node* root = t->root;
        while (true)
        {
                
                if(strcmp(word,root->word) < 0){
                        if(root->left == NULL){
                                root->left = tn;
                                root->left->count++;
                                t->size++;
                                return;
                        }
                        else
                        {
                                root = root->left;
                        }
                }else if (strcmp(word,root->word) > 0){
                        if(root->right == NULL){
                                root->right = tn;
                                root->right->count++;
                                t->size++;
                                return;
                        }
                        else
                        {
                                root = root->right;
                        }
                }
                else
                {
                        break;
                }
                
        }
        finish = clock();
        printf(" \t saving finished :%.2f \n",(double)((finish-start)/CLOCKS_PER_SEC));
}





// // display all the words and their corresponding number of occurence
void print_word_Tree(word_node* root)
{
        clock_t start,finish;
        start = clock();
        if(root==NULL)
        {
                return;
        }
        print_word_Tree(root->left);
        printf("\t %s :==:  %d \n",root->word,root->count);
        print_word_Tree(root->right);
        finish = clock();
        printf(" \t printing finished :%f \n",(double)((finish-start)/CLOCKS_PER_SEC));
}

