/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (!q) {
      return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    if (!q)
      return;
    list_ele_t* next_ele = q->head;
    while (next_ele) {
      free(next_ele -> value);
      list_ele_t* cur_ele = next_ele;
      next_ele = next_ele->next;
      free(cur_ele);
    }
    /* Free queue structure */
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (!q)
      return false;
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    newh = malloc(sizeof(list_ele_t));
    if (!newh) {
      return false;
    }
    /* Don't forget to allocate space for the string and copy it */
    newh->value = (char *)malloc(strlen(s) + 1);
    if (!newh->value) {
      free(newh);
      return false;
    }
    strcpy(newh->value, s);
    newh->value[strlen(newh->value)] = '\0';

    /* What if either call to malloc returns NULL? */
    newh->next = q->head;
    q->head = newh;
  
    if (!q->tail) {
      q->tail = q->head;
    }

    q->size++;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if (!q)
      return false;
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (!newh) {
      return false;
    }

    newh->value = (char *)malloc(strlen(s) + 1);
    if (!newh->value) {
      free(newh);
      return false;
    }
    strcpy(newh->value, s);
    newh->value[strlen(newh->value)] = '\0';

    newh->next = NULL;
    if (q->tail)
      q->tail->next = newh;
    q->tail = newh;

    if (!q->head)
      q->head = q->tail;

    q->size++;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* You need to fix up this code. */
    if (!q || !(q->head))
      return false;
    
    list_ele_t *old_head = q->head;
    q->head = q->head->next;
    
    if (sp) {
      int i = 0;
      for (i = 0; i < bufsize - 1 && i < strlen(old_head->value); ++i) {
        sp[i] = old_head->value[i];
      }
      sp[i] = '\0';
    }

    free(old_head->value);
    free(old_head);
    q->size--;
  
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if (q)
      return q->size;
    else
      return 0;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    if (!q || !q->head)
      return;

    list_ele_t *last_ele = q->head;
    list_ele_t *cur_ele = q->head->next;
    list_ele_t *cp_ele = q->tail;
    q->tail = q->head;
    q->head = cp_ele;
    while (cur_ele) {
      list_ele_t *next_ele = cur_ele->next;
      cur_ele->next = last_ele;
      last_ele = cur_ele;
      cur_ele = next_ele;
    }
    q->tail->next = NULL;
}

