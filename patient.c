#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_typs.h"
#include "slots.h"
#include "patient.h"


#define Days 7
#define Slots 5
#define String 20

extern node* head ;
extern s8 Arr [Days][Slots] [String];

/*Functions Implementation : */

void Add_Node (  )
{

   	/****************************************************************************
	                            Create Patient Record
	*****************************************************************************/

	/*1- Create Node */
	node *new_node = (node*) malloc (sizeof(node));

	/*2-Read Values of Record */
	printf("Enter Patient Name : ");
	fflush(stdout);
	scanf("%s", &new_node->name);

  do{

	printf("Enter Patient ID (Must be 14 Numbers ): ");
	fflush(stdout);
	scanf("%s", &new_node->id);

	}while(strlen(new_node->id) != 14 );


	printf("Enter Patient Age : ");
	fflush(stdout);
	scanf("%d", &new_node->age);


GenderCheck : printf("Enter Patient Gender (F for female , M for male): ");
	          fflush(stdout);
              scanf("\n%c", &new_node->gender);

    if ( (new_node->gender == 'm')|| (new_node->gender == 'M') || (new_node->gender == 'f')||(new_node->gender == 'F'))
	{
	}
	else
	{
        printf("Invalid input , Try again \n");
		goto GenderCheck ;
	}

    strcpy(new_node->p_slots, "No Reservation"); /*initialize no reservation to each new node */
	new_node-> next = NULL ; /*Assign null to each created node */


	/****************************************************************************
	                           Node Adding Algorithm
	*****************************************************************************/
	if ( head == NULL )
	{
      /*Linked list is empty */
      head = new_node ;
	}
	else
	{

		u8 res ;
		node * last = head ;
		res = search_Node( new_node->id );

		if(res == 1 )
		{
			printf("ID is Already exist , Try again with different ID \n");
		}
		else
		{
		   while (last->next != NULL )
		   {
			  last = last->next ;   /*Loop untill reach the last node */
		   }

		   last->next = new_node ;

		}

	}


}

void Edit_Node()
{
         /************************************************************************************
                                         Edit Patient Record
          ************************************************************************************/

	u8 ID[15] ;
	u8 res ;
  /************************************** Read ID *******************************************/
  do{

	printf("Enter Patient ID (Must be 14 Numbers ): ");
	fflush(stdout);
	scanf("%s", ID);

	}while(strlen(ID) != 14 );

	/**************************** Check if exist or not ************************************/
	res = search_Node(ID);
	if ( res == 1 )
	{
		node *current = Get_Node(ID);

	u8 ans ;
	/* in case that Admins Have entered wrong values , we can edit */
	printf ("Edit list : \n"
	        "1- Edit Name \n"
			"2- Edit Age \n"
			"3- Edit Gender \n" );
EditOp : printf ("Choose operation number : ");
	     fflush(stdout);
         scanf("%d",&ans);
	     printf("================================================\n");
         switch (ans)
 	     {
		    case 1 :
		           printf("Enter New Name : ");
			       fflush(stdout);
	               scanf("%s",current->name );
                   printf("Edited Successfully \n");
                   break ;

		    case 2 :
        	   	    printf("Enter New Age : ");
				    fflush(stdout);
	                scanf("%d",&current->age );
                    printf("Edited Successfully \n");
                    break ;

		    case 3 :
	   GenderCheck : printf("Enter Patient Gender (F for female , M for male): ");
	                 fflush(stdout);
                     scanf("\n%c", &current->gender);

                     if ( (current->gender == 'm')|| (current->gender == 'M') || (current->gender == 'f')||(current->gender == 'F'))
	                 {
						 printf("Edited Successfully \n");
	                 }
	                 else
	                 {
                      printf("Invalid input , Try again \n");
		              goto GenderCheck ;
	                 }
		            break;

	        default:
		            printf("invalid Choice , Try again \n");
		            goto EditOp ;
	      }

	}
	else
	{
		printf("Patient with This ID is not exist \n");
	}

}

void Rsrv_Slot(void)
{
	/************************************************************************************************
	                                Reserve A slot with the doctor
	*************************************************************************************************/

	u8 ID[15] ;
	u8 res ,day, period ;

  /************************************** Read ID *******************************************/
  do{

	printf("Enter Patient ID (Must be 14 Numbers ): ");
	fflush(stdout);
	scanf("%s", ID);

	}while(strlen(ID) != 14 );

   /**************************** Check if exist or not ************************************/
	res = search_Node(ID);
	if ( res == 1 )
	{
		/*Read Desired slot */
		node *current = Get_Node(ID);
		printf("Enter Day Number : ");
		fflush(stdout);
		scanf("%d",&day);
		day -- ;
		printf("Enter Period Number : ");
		fflush(stdout);
		scanf("%d",&period);
		period -- ;
	/************************ Check if patient has already a slot ************************/
		if (strcmp(current->p_slots,"No Reservation")==0)
		{

	/*********************** Check if Slot is available or not *************************************/

     	      if ( strcmp(Arr[day][period],"Not Available") == 0 )
		      {
		         	printf("Sorry , Slot is not available \n");
		            fflush(stdout);
		      }
		      else
		      {

			        s8* data = Get_Slot (day,period);
			        strcpy(current-> p_slots, data );
					current->day    = day ;
					current->period = period;
			        printf("Reserve Successfully \n");
			        fflush(stdout);
		      }

		}
		else
		{
			printf("Patient already has a Reservation slot , Please cancel it firstly \n");

		}


	}
	else
	{
		printf("Patient with This ID is not exist \n");
	}

}

void Cncl_Rsrv (void)
{
	/***********************************************************************************************
	                                 Cancel A Reservation
	************************************************************************************************/

	u8 ID[15] ;
	u8 res ;

	/************************************** Read ID *******************************************/
  do{

	printf("Enter Patient ID (Must be 14 Numbers ) : ");
	fflush(stdout);
	scanf("%s", ID);

	}while(strlen(ID) != 14 );

	/**************************** Check if exist or not ************************************/
	res = search_Node(ID);
	if ( res == 1 )
	{
		/***************** Check Reservation of patient  *******************/
		node *current = Get_Node(ID);

		if (strcmp(current->p_slots,"No Reservation")==0)
		{
			printf("There is No Reservation Yet ..\n");
		}
		else
		{

			s8 data [String] ;
		    /*Steps to Correctly Cancel a patient reservation */
 			strcpy(data, current->p_slots);                        /*1- store slot*/
			strcpy(current->p_slots ,"No Reservation");            /*2- remove slot from patient record */
			Add_Slot ( current->day , current->period , data );    /*3- add to available slots */
			printf("Canceled Successfully \n");
			fflush(stdout);

		}

	}
	else
	{
		printf("Patient with This ID is not exist \n");
	}

}


u8 search_Node (  u8* ID  )
{
	node* current = head ;
    u8 flag = 0 ;

	while(current != NULL )
	{

		if ( strcmp(current->id,ID)==0 )
		{
			flag = 1 ;   /* node exist */
			break;
		}
		else
		{
			current = current-> next ; /* go to the next node */
		}
	}

	return flag ;

}

node* Get_Node (u8* ID)
{
	node* current = head ;
	while(current != NULL )
	{
		if ( strcmp(current->id,ID)==0 )
		{
			return current ; /* node exist */

		}
		else
		{
			current = current-> next ; /* go to the next node */
		}
	}
}



void Display_Patient ( )
{
	/*****************************************************************************************************
	                                    View Patient Records
	******************************************************************************************************/
	u8 ID[15] ;
	u8 res ;
	/************************************** Read ID *******************************************/
  do{

	printf("Enter Patient ID (Must be 14 Numbers ): ");
	fflush(stdout);
	scanf("%s", ID);

	}while(strlen(ID) != 14 );

	/**************************** Check if exist or not ************************************/
	res = search_Node(ID);
	if ( res == 1 )
	{
		node *current = Get_Node(ID);
		printf("====================================================\n"
		       "Patient Records are :- \n");
	    fflush(stdout);
		printf( "Name         : %s\n"
		        "ID              : %s\n"
                "Age           : %d\n"
                "Gender       : %c\n"
			  ,current->name , (current->id ), current->age , current-> gender );

		/************************ Check Reservation ************************/

		if ( strcmp(current->p_slots,"No Reservation")==0)
		{
			printf("Reservation : There is no Reservation yet \n"
			       "===================================================\n");

		}
		else
		{
			printf("Reservation : Day %d Period %d \"%s \"\n"
			       "===================================================\n"
				   ,(current->day)+1 , (current->period)+1 , current->p_slots);
		}

	}
	else
	{
		printf("There is no such ID in Database \n");

	}



}

void Diplay_Day_Rsrv ()
{
	u8 day , flag =0 ;
	node* current = head ;

do {
	printf("Enter Day Number : ");
	fflush(stdout);
    scanf("%d",&day); }while ( (day < 1) || (day > 7) );

	printf("Day %d Reservations : \n" ,day);
	day --;
	while( current != NULL )
	{
		printf("%d == %d \n" , current->day , day );
		fflush(stdout);
		/***************** Check if the patient has a reservation in that day  **************************/
		if ( current->day == day )
		{
			printf("Patient ID : %s  , Slot : Period %d \" %s \" \n", current->id , (current->period)+1 , current->p_slots );
			flag =1;

		}
		else
		{
			/*Do nothing */
		}
		current = current->next ; /* Go to the next node */

	}

	if ( flag == 0)
	{
		printf("There is no Reservation in that day \n");
	}

}
