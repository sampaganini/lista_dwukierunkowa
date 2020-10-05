
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"



int main()
{


    int value;
    int index;
    struct doubly_linked_list_t* lista;

    lista = dll_create();

    if (lista == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    int check;
    int choose;

    int blad;

    for (;;)
    {

        printf("Co chcesz zrobic: ");
        check = scanf("%d", &choose);
        if (check != 1)
        {
            dll_clear(lista);
            free(lista);
            printf("Incorrect input");
            return 1;
        }
        if (choose < 0 || choose > 14)
        {
            printf("Incorrect input data\n");
            continue;
        }


        if (choose == 0)
        {
            dll_clear(lista);
            free(lista);
            return 0;

        }
        ////////////////////////////////////////////////////////////////////////////////////////////////
        if (choose == 1)
        {
            printf("Podaj element: ");

            check = scanf("%d", &value);

            if (check != 1)
            {
                dll_clear(lista);
                free(lista);

                printf("Incorrect input");
                return 1;
            }

            blad = dll_push_back(lista, value);

            if (blad == 2)
            {

                dll_clear(lista);

                free(lista);
                printf("Failed to allocate memory");
                return 8;
            }

        }
        //////////////////////////////////////////////////////////////////////////////////////
        if (choose == 2)
        {
            check = dll_is_empty(lista);

            if (check == 1)
            {
                printf("List is empty\n");
                continue;
            }
            int value2 = dll_pop_back(lista, NULL);

            printf("%d\n", value2);


        }
        /////////////////////////////////////////////////////////////////////////////////////////
        if (choose == 3)
        {

            printf("Podaj element?? ");
            check = scanf("%d", &value);
            if (check != 1)
            {
                dll_clear(lista);
                free(lista);
                printf("Incorrect input");
                return 1;
            }

            blad = dll_push_front(lista, value);

            if (blad == 2)
            {
                dll_clear(lista);
                free(lista);
                printf("Failed to allocate memory");
                return 8;
            }

        }

        /////////////////////////////////////////////////////////////////////////////////////////////////
        if (choose == 4)
        {
            check = dll_is_empty(lista);
            if (check == 1)
            {
                printf("List is empty\n");
                continue;
            }

            printf("%d\n", dll_pop_front(lista, NULL));

            continue;
        }
        ////////////////////////////////////////////////////////////////////////////////////
        if (choose == 5)
        {

            printf("Podaj element????");
            check = scanf("%d", &value);
            if (check != 1)
            {
                printf("Incorrect input");
                dll_clear(lista);
                free(lista);
                return 1;
            }

            printf("Podaj indexxx: ");
            check = scanf("%d", &index);
            if (check != 1)
            {
                dll_clear(lista);

                free(lista);
                printf("Incorrect input");
                return 1;
            }

            int blad3 = dll_insert(lista, index, value);
            if (blad3 == 2)
            {

                dll_clear(lista);
                free(lista);
                printf("Failed to allocate memory");
                return 8;
            }
            if (blad3 == 1)
            {
                printf("Index out of range\n");
            }

        }

        //////////////////////////////////////////////////////////////////////
        if (choose == 6)
        {
            int blad2;
            check = dll_is_empty(lista);
            if (check == 1)
            {
                printf("List is empty\n");
                continue;
            }

            printf("Podaj indexxxxx: ");
            check = scanf("%d", &index);
            if (check != 1)
            {
                dll_clear(lista);

                free(lista);
                printf("Incorrect input");
                return 1;
            }

            value = dll_remove(lista, index, &blad2);

            if (blad2 == 1)
            {
                printf("Index out of range\n");
            }
            else
                printf("%d\n", value);

        }
        //////////////////////////////////////////////////////////////////////////////////
        if (choose == 7)
        {
            check = dll_is_empty(lista);
            if (check == 1)
            {
                printf("List is empty\n");
                continue;
            }
            int me = dll_back(lista, NULL);
            printf("%d\n", me);

        }


        /////////////////////////////////////////////////////////////////////////////////////
        if (choose == 8)
        {
            check = dll_is_empty(lista);
            if (check == 1)
            {
                printf("List is empty\n");
                continue;
            }

            printf("%d\n", dll_front(lista, NULL));



        }

        //////////////////////////////////////////////////////////////////////////////////////////

        if (choose == 9)
        {
            printf("%d\n", dll_is_empty(lista));
        }



        ///////////////////////////////////////////////////////////////////////////////////////////////////

        if (choose == 10)
        {
            printf("%d\n", dll_size(lista));
        }

        ////////////////////////////////////////////////////////////////////////////////////
        if (choose == 11)
        {
            dll_clear(lista);

        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (choose == 12)
        {
            check = dll_is_empty(lista);


            if (check == 1)
            {
                printf("List is empty\n");
                continue;
            }

            printf("Podaj indexxxxxxx: ");
            check = scanf("%d", &index);
            if (check != 1)
            {
                dll_clear(lista);

                free(lista);
                printf("Incorrect input");
                return 1;
            }

            value = dll_at(lista, index, &blad);

            if (blad == 1)
            {
                printf("Index out of range\n");
                continue;
            }

            printf("%d\n", value);
        }


        ///////////////////////////////////////////////////////////////////////////////////////
        if (choose == 13)
        {
            check = dll_is_empty(lista);
            if (check == 1)
            {
                printf("List is empty\n");
                continue;
            }

            dll_display(lista);
            printf("\n");


        }

        if (choose == 14)
        {
            check = dll_is_empty(lista);
            if (check == 1)
            {
                printf("List is empty\n");
                continue;
            }

            dll_display_reverse(lista);
            printf("\n");


        }

    }

    return 0;

}
