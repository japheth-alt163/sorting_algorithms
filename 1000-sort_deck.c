#include "deck.h"
#include <stdlib.h>
#include <string.h>

int compare_values(const char *value1, const char *value2) {
    static const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    for (int i = 0; i < 13; i++) {
        if (strcmp(value1, values[i]) == 0) {
            return i;
        }
        if (strcmp(value2, values[i]) == 0) {
            return -i;
        }
    }

    return 0;
}

void swap_nodes(deck_node_t **node1, deck_node_t **node2) {
    deck_node_t *temp1 = *node1;
    deck_node_t *temp2 = *node2;
    deck_node_t *temp;

    temp = temp1->prev;
    temp1->prev = temp2->prev;
    temp2->prev = temp;
    temp = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp;

    if (temp1->prev) {
        temp1->prev->next = temp1;
    } else {
        *node1 = temp1;
    }

    if (temp2->prev) {
        temp2->prev->next = temp2;
    } else {
        *node2 = temp2;
    }

    if (temp1->next) {
        temp1->next->prev = temp1;
    }

    if (temp2->next) {
        temp2->next->prev = temp2;
    }
}

deck_node_t *partition_deck(deck_node_t **head, deck_node_t *tail) {
    deck_node_t *pivot = tail;
    deck_node_t *i = *head;

    for (deck_node_t *j = *head; j != tail; j = j->next) {
        if (compare_cards(j->card, pivot->card) < 0) {
            swap_nodes(&i, &j);
            i = i->next;
        }
    }

    swap_nodes(&i, &tail);

    return i;
}

void qsort_deck(deck_node_t **head, deck_node_t *tail) {
    if (*head && *head != tail && (*head)->next != tail) {
        deck_node_t *pivot = partition_deck(head, tail);
        qsort_deck(head, pivot);
        qsort_deck(&(pivot->next), tail);
    }
}

void sort_deck(deck_node_t **deck) {
    qsort_deck(deck, NULL);
}
