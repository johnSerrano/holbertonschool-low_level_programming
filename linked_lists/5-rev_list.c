#include "list.h"
#include <stdlib.h>
void rev_list(List **list) {
  List *slow = *list;
  List *next;
  List *base;

  next = slow->next;
  /* this is going to be the end of the list */
  slow->next = NULL;

  /* point each element to the one that points to it */
  while (next != NULL) {

    /*
        ... <- [           ] xx [    ] -> [    ] -> [    ] -> ...
                  ^     ^          ^
                slow, base       next
     */

    base = next;
    /*
        ... <- [    ] xx [          ] -> [    ] -> [    ] -> ...
                  ^         ^     ^
                slow      base, next
     */

    next = base->next;
    /*
        ... <- [    ] xx [    ] -> [    ] -> [    ] -> ...
                  ^         ^         ^
                slow      base      next
    */

    base->next = slow;
    /*                **
        ... <- [    ] <- [    ] xx [    ] -> [    ] -> ...
                  ^   **    ^         ^
                slow      base      next
     */

    slow=base;
    /*
        ... <- [    ] <- [           ] xx [    ] -> [    ] -> ...
                            ^     ^          ^
                          slow, base       next
     */
  }

  /* point list to the new start */
  *list = slow;

}
