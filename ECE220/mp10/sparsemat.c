#include <stdio.h>

#ifndef SP_MAT
#define SP_MAT
#include "sparsemat.h"
#endif

#include <stdlib.h>

#ifndef ASSERT_H
#define ASSERT_H
#include <assert.h>
#endif


int main() {
    sp_tuples *test = load_tuples("withZeroes.txt");
    assert(test != NULL);
    save_tuples("output1_withZeroes.txt", test);
    return 0;
}

sp_tuples_node * allocateNode(int node_row, int node_col, double node_val) {
    sp_tuples_node *node = (sp_tuples_node*) malloc (sizeof (sp_tuples_node));
    node->row = node_row;
    node->col = node_col;
    node->value = node_val;
    node->next = NULL;
    return node;
}


sp_tuples * load_tuples(char* input_file)
{
    FILE* filename = fopen(input_file, "r");
    if (filename == NULL) return NULL;

    //* initialize "tuples_info", which stores the info of the llist *//
    sp_tuples * tuples_info = NULL;
    tuples_info = (sp_tuples*) malloc (sizeof (sp_tuples));
    tuples_info->nz = 0;
    tuples_info->tuples_head = NULL;     //* TODO *//

    //* store the rows and cols of the matrix*//
    fscanf(filename, "%d %d\n", &(tuples_info->m), &(tuples_info->n));

    double node_val;
    int node_row, node_col;
    // sp_tuples_node *node = NULL, *head = NULL, *temp = NULL, *node_ptr = NULL;
    // sp_tuples_node *pre_node = NULL;   //* stores the second last node *//
    while ((fscanf(filename, "%d %d %lf\n", &node_row, &node_col, &node_val)) == 3) {
        set_tuples(tuples_info, node_row, node_col, node_val);
    }
    return tuples_info;
}


void set_tuples(sp_tuples * mat_t, int row, int col, double value)
{
    sp_tuples_node *node_ptr = NULL, *preNode = NULL;
    //* CASE 1: 0 condition *//
    if (value == 0) {
        if (mat_t->tuples_head == NULL) return; //* if it's empty *//
        for (node_ptr = mat_t->tuples_head; node_ptr != NULL; node_ptr = node_ptr->next) {
            if (node_ptr->row == row && node_ptr->col == col) { //* if found *//
                if (node_ptr == mat_t->tuples_head) {
                    mat_t->tuples_head = node_ptr->next;
                    free(node_ptr);
                } else {
                    preNode->next = node_ptr->next;
                    free(node_ptr);
                }
                mat_t->nz--;
                return;
            }
            preNode = node_ptr;
        }
        //* if not found *//
        return;
    } else {
    //* CASE 2: other values *//
        if (mat_t->tuples_head == NULL) {   //* if it's empty *//
            sp_tuples_node *node = allocateNode(row, col, value);
            mat_t->tuples_head = node;
            mat_t->nz++;
            return;
        }
        for (node_ptr = mat_t->tuples_head; node_ptr != NULL; node_ptr = node_ptr->next) {
            if (node_ptr->row == row && node_ptr->col == col) { //* if found *//
                node_ptr->value = value;
                return;
            }
            if ( (row < node_ptr->row) || 
                ((row == node_ptr->row) && (col < node_ptr->col)) ) {   //* if not found*//
                sp_tuples_node *node = allocateNode(row, col, value);
                if (node_ptr == mat_t->tuples_head) {
                    node->next = mat_t->tuples_head;
                    mat_t->tuples_head = node;
                } else {
                    node->next = node_ptr;
                    preNode->next = node;
                }
                mat_t->nz++;
                return;
            }
            preNode = node_ptr;
        }
        //* if not among the existing numbers *//
        sp_tuples_node *node = allocateNode(row, col, value);
        preNode->next = node;
        mat_t->nz++;
        return;
    }
    return;
}

double gv_tuples(sp_tuples * mat_t,int row,int col)

{
    sp_tuples_node *node_ptr;
    for (node_ptr = mat_t->tuples_head; node_ptr != NULL; node_ptr = node_ptr->next) {
        if (node_ptr->row == row && node_ptr->col == col) {
            return node_ptr->value;
        }
    }
    //* if failed, return 0*//
    return 0;
}

void save_tuples(char * file_name, sp_tuples * mat_t)
{
    FILE *outputFile = fopen(file_name, "w");
    assert(file_name != NULL);

    fprintf(outputFile, "%d %d\n", mat_t->m, mat_t->n);
    
    sp_tuples_node *node_ptr = NULL;
    for (node_ptr = mat_t->tuples_head; node_ptr != NULL; node_ptr = node_ptr->next) {
        fprintf(outputFile, "%d %d %f\n", node_ptr->row, node_ptr->col, node_ptr->value);
    }

	return;
}
