//* 这是我用自己的算法写的源文件，虽然代码量比原伪代码大很多 *//

#include "sparsemat.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef ASSERT_H
#define ASSERT_H
#include <assert.h>
#endif


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
    tuples_info->tuples_head = NULL;

    //* store the rows and cols of the matrix*//
    fscanf(filename, "%d %d\n", &(tuples_info->m), &(tuples_info->n));

    double node_val;
    int node_row, node_col;
    // sp_tuples_node *node = NULL, *head = NULL, *temp = NULL, *node_ptr = NULL;
    // sp_tuples_node *pre_node = NULL;   //* stores the second last node *//
    while ((fscanf(filename, "%d %d %lf\n", &node_row, &node_col, &node_val)) == 3) {
        set_tuples(tuples_info, node_row, node_col, node_val);


        // temp = NULL;    //* clear temp *//
        // //* 0-condition   (this can actually be reconstituted by other functions) *//
        // if (node_val == 0) {
        //     if (head == NULL) continue;
        //     for (temp = NULL, node_ptr = head; node_ptr != NULL; node_ptr = node_ptr->next) {
        //         if (node_row == node_ptr->row && node_col == node_ptr->col) {   //* if found *//
        //             if (temp == NULL) {
        //                 //* now node_ptr is head *//
        //                 head = node_ptr->next;
        //                 //* destroy node_ptr *//
        //                 free(node_ptr);
        //                 break;
        //             } else {
        //                 //* destroy node_ptr *//
        //                 temp->next = node_ptr->next;
        //                 free(node_ptr);
        //                 break;
        //             }
        //             tuples_info->nz--;
        //         }
        //         temp = node_ptr;    //* store the previous node *//
        //     }
        //     continue;
        // }
        // //* initialize the head *//
        // if (head == NULL) {
        //     head = (sp_tuples_node*) malloc (sizeof (sp_tuples_node));
        //     head->row = node_row;
        //     head->col = node_col;
        //     head->value = node_val;
        //     head->next = NULL;
        //     pre_node = head;
        //     tuples_info->nz++;
        //     continue;
        // }
        // //* TODO: deal with the 0 condition and repetition condition! *//
        // //* TODO: don't forget to count in tuples_info !!! *//
        // //* check repetition with the prenode *//
        // if (node_row == pre_node->row && node_col == pre_node->col) { 
        //     pre_node->value = node_val;
        //     continue;
        // }
        // //* check the order and repetition *//
        // if ( (node_row < pre_node->row) || 
        //      ((node_row == pre_node->row) && (node_col < pre_node->col)) ) {
        //     for (node_ptr = head; node_ptr != NULL; node_ptr = node_ptr->next) {    //* search for the correct position *//
        //         //* if meet a repeat node *//
        //         if (node_row == node_ptr->row && node_col == node_ptr->col) {
        //             node_ptr->value = node_val;
        //             break;
        //         }
        //         //* if firstly meet a node_ptr that has larger coordinates than node *//
        //         if ( (node_row < node_ptr->row) || 
        //              ((node_row == node_ptr->row) && (node_col < node_ptr->col)) ) {
        //             //* if node_ptr itself is head *//
        //             if (node_ptr == head) {
        //                 node = allocateNode(node_row, node_col, node_val);
        //                 node->next = node_ptr;
        //                 head = node;
        //             } else {
        //                 //* now "node" should be plugged before node_ptr, after temp *//
        //                 assert(temp != NULL);
        //                 node = allocateNode(node_row, node_col, node_val);
        //                 node->next = node_ptr;
        //                 temp->next = node;
        //             }
        //             tuples_info->nz++;
        //             break;  //* end the search *//
        //         }
        //         //* store the pre node_ptr*//
        //         temp = node_ptr;                
        //     }
        //     continue;   //* the out-of-order-node has been processed *//
        // }
        
        // //* the normal condition *//
        // node = allocateNode(node_row, node_col, node_val);
        // pre_node->next = node;
        // pre_node = node;
    }
    // tuples_info->tuples_head = head;
    return tuples_info;
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


// /*
//  * cpy_tuples -- copy the content in src into dst
//  * INPUTS:          two lists of tuples, src and dst, dst has already been allocated
//  * OUTPUTS:         dst
//  * RETURN:          None
//  * SIDE EFFECTS:    None
//  * */
// void cpy_tuples(sp_tuples * src, sp_tuples * dst) {
//     dst->m = src->m;
//     dst->n = src->n;
//     dst->nz = src->nz;
//     dst->tuples_head = NULL;

//     sp_tuples_node * node_ptr = NULL, *node = NULL, *preNode = NULL;

//     //* firstly deal with the head *//
//     node = allocateNode((src->tuples_head)->row, (src->tuples_head)->col, (src->tuples_head)->value);
//     dst->tuples_head = node;
//     preNode = node;
//     //* traverse and copy*//
//     for (node_ptr = (src->tuples_head)->next; node_ptr != NULL; node_ptr = node_ptr->next) {
//         node = allocateNode(node_ptr->row, node_ptr->col, node_ptr->value);
//         preNode->next = node;
//         preNode = node;
//     }
// }

sp_tuples * add_tuples(sp_tuples * matA, sp_tuples * matB){
    if (matA->m != matB->m || matA->n != matB->n) return NULL;

    //* initialize matC *//
    sp_tuples *matC = (sp_tuples*) malloc (sizeof (sp_tuples));
    matC->m = matA->m;
    matC->n = matA->n;
    matC->nz = 0;
    matC->tuples_head = NULL;
    // // copy matA into matC
    // cpy_tuples(matA, matC);

    sp_tuples_node *A_ptr = matA->tuples_head, *B_ptr = matB->tuples_head, *C_ptr = NULL;
    sp_tuples_node *node = NULL;
    double C_value;

    while (A_ptr != NULL && B_ptr != NULL) {
        if ( (A_ptr->row < B_ptr->row) ||
             (A_ptr->row == B_ptr->row && A_ptr->col < B_ptr->col)) {
        //* CASE 1: if A_ptr is early than B_ptr *//
            node = allocateNode(A_ptr->row, A_ptr->col, A_ptr->value);
            //* firstly take care of the head *//
            if (matC->tuples_head == NULL) {
                matC->tuples_head = node;
                C_ptr = node;
            } else {    //* if C's head has already been allocated *//
                C_ptr->next = node;
                C_ptr = node;
            }
            matC->nz++;
            A_ptr = A_ptr->next;
            continue;
        } else if ((A_ptr->row > B_ptr->row) ||
                   (A_ptr->row == B_ptr->row && A_ptr->col > B_ptr->col)) {
        //* CASE 2: if B_ptr is early than A_ptr *//
            node = allocateNode(B_ptr->row, B_ptr->col, B_ptr->value);
            //* firstly take care of the head *//
            if (matC->tuples_head == NULL) {
                matC->tuples_head = node;
                C_ptr = node;
            } else {    //* if C's head has already been allocated *//
                C_ptr->next = node;
                C_ptr = node;
            }
            matC->nz++;
            B_ptr = B_ptr->next;
            continue;
        } else if ((A_ptr->row = B_ptr->row) && (A_ptr->col = B_ptr->col)) {
        //* CASE 3: if A_ptr and B_ptr have the same coordinates *//
            C_value = A_ptr->value + B_ptr->value;
            if (C_value) {      //* if C_value != 0 *//
                node = allocateNode(A_ptr->row, A_ptr->col, C_value);
                C_ptr->next = node;
                C_ptr = node;
                matC->nz++;
                A_ptr = A_ptr->next;
                B_ptr = B_ptr->next;
                continue;
            } else {
                //* if C_value = 0 *//
                A_ptr = A_ptr->next;
                B_ptr = B_ptr->next;
                continue;
            }
        }        
    }
    //* now one of A_ptr and B_ptr has run out the tuple *//
    while (A_ptr != NULL) {
        node = allocateNode(A_ptr->row, A_ptr->col, A_ptr->value);
        //* firstly take care of the head *//
        if (matC->tuples_head == NULL) {
            matC->tuples_head = node;
            C_ptr = node;
        } else {    //* if C's head has already been allocated *//
            C_ptr->next = node;
            C_ptr = node;
        }
        matC->nz++;
        A_ptr = A_ptr->next;  
    }
    while (B_ptr != NULL) {
        node = allocateNode(B_ptr->row, B_ptr->col, B_ptr->value);
        //* firstly take care of the head *//
        if (matC->tuples_head == NULL) {
            matC->tuples_head = node;
            C_ptr = node;
        } else {    //* if C's head has already been allocated *//
            C_ptr->next = node;
            C_ptr = node;
        }
        matC->nz++;
        B_ptr = B_ptr->next;  
    }    

	return matC;
}



sp_tuples * mult_tuples(sp_tuples * matA, sp_tuples * matB){ 
    if (matA->n != matB->m) return NULL;

    //* initialize matC *//
    sp_tuples *matC = (sp_tuples*) malloc (sizeof (sp_tuples));
    matC->m = matA->m;
    matC->n = matB->n;
    matC->nz = 0;
    matC->tuples_head = NULL;
 
    // int A_row, A_col, B_row, B_col;
    double C_value;
    sp_tuples_node *A_ptr = NULL, *B_ptr = NULL;
    for (A_ptr = matA->tuples_head; A_ptr != NULL; A_ptr = A_ptr->next) {
        for (B_ptr = matB->tuples_head; B_ptr != NULL; B_ptr = B_ptr->next) {
            if (B_ptr->row != A_ptr->col) continue;
            C_value = gv_tuples(matC, A_ptr->row, B_ptr->col);
            C_value += gv_tuples(matA, A_ptr->row, A_ptr->col) * gv_tuples(matB, B_ptr->row, B_ptr->col);
            set_tuples(matC, A_ptr->row, B_ptr->col, C_value);
        }
    }

    return matC;
}


	
void destroy_tuples(sp_tuples * mat_t){
	sp_tuples_node *node_ptr = mat_t->tuples_head, *temp = NULL;
    while (node_ptr) {
        temp = node_ptr;
        node_ptr = node_ptr->next;
        free(temp);
    }
    free(mat_t);
    return;
}  






