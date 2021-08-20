#include <stdio.h>
#include <string.h>
#include "std_typs.h"


#define Days 7
#define Slots 5
#define String 20

extern s8 Arr [Days][Slots] [String];
s8 data [String] ;
/*Counters*/
u8 i , j ;

/*Function Implementation */
void Creat_Slots()
{
	for ( i = 0; i < Days; i++)
    {

        for ( j = 0; j < Slots; j++)
        {
               switch (j)
			   {
				   case 0 : strcpy (Arr[i][j],"2pm to 2:30pm");
				            break;

				   case 1 : strcpy (Arr[i][j],"2:30pm to 3pm");
				            break;

				   case 2 : strcpy (Arr[i][j],"3pm to 3:30pm");
				            break;

				   case 3 :strcpy (Arr[i][j],"4pm to 4:30pm");
				            break;

				   case 4 : strcpy (Arr[i][j],"4:30pm to 5pm");
				            break;

			   }

        }
    }

}


void Add_Slot (  u8 i , u8 j , s8 * data )
{
	strcpy(Arr[i][j], data );
}


s8* Get_Slot ( u8 i , u8 j)
{
	strcpy(data,Arr[i][j]);
	strcpy(Arr[i][j], "Not Available" );
    return data ;
}

void Display_All_Slots()
{
	/*Display All Available slots */
	printf("Available Slots : \n\n");
	fflush(stdout);
	for (i=0 ; i < Days ; i++)
    {
        printf("Day %d : \n",i+1);

        for ( j = 0 ; j < Slots ; j++)
        {
		  if (strcmp(Arr[i][j],"Not Available") == 0 )
		   {
			   printf("Period %d : Not Available \n", j+1 );
			   fflush(stdout);
			   continue;
		   }
		   else
	       {
			 printf("Period %d : %s\n", j+1,Arr[i][j]);
			 fflush(stdout);

		   }


	    }
		printf("\n========================================\n");
    }

}
