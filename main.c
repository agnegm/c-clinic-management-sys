#include <stdio.h>
#include "std_typs.h"
#include "slots.h"
#include "patient.h"


#define Days 7
#define Slots 5
#define String 20
/*Create a head pointer to hold the linked list */
node *head = NULL ;

/*Create Array that hold all slots per week */
s8 Arr [Days] [Slots] [String];
s8* temp ;


void main (void){

		/*Create 3d Dynamic Array to hold Slots */

		Creat_Slots();


	   /* User interface */
	       u8 ans , i , ExitFlag = 0, PasswordFlag = 0 , AdminOpFlag = 0 , UserOpFlag = 0 ;
	       s32 pass ;
MainMenu : printf("===============================================================\n"
                  "Welcome to our Clinic Management System , please choose System mode :-\n"
                  "1-Admin Mode\n"
	              "2-User Mode\n"
	              "3-Exit\n"
		          "===============================================================\n");

           while ( ExitFlag != 1 )
           {

	         printf ("Enter Your choice : ");
             fflush(stdout);
	         scanf("%d", &ans );
	         switch (ans)
	         {
		       case 1 : /*Admin Mode Case */
				        for ( i = 3 ; i > 0 ; i-- ) /*This loop Read the password */
				       {
			              printf("Please Enter Password : ");
				          fflush(stdout);
					      scanf("%d",&pass);

				          if ( pass == 1234 )
				          {
			                   printf("\nCorrect password , Welcome to Admin Mode :) \n");
			                   fflush(stdout);
				               PasswordFlag = 1 ;
				               break ;
				          }
				          else
				          {
					        if (i == 1)
					        {
							break; /* Last check end*/
					        }
				  	        printf("\nIncorrect password , Tty again (Remaining attemps : %d )\n", i-1 );
					        fflush(stdout);
				          }
				       }

				        if (PasswordFlag == 1 ) /*password is correct */
				        {

						  /*Features of Admin mode */
				          printf("===============================================================\n"
				                 "please select an operation :- \n"
						         "1-Add new patient record\n"
					             "2-Edit patient record\n"
				                 "3-Reserve a slot with doctor\n"
					             "4-Cancel Reservation\n"
					             "5-Return to the main menu\n"
						         "===============================================================\n");
						  fflush(stdout);
                          while ( AdminOpFlag != 1 )
					      {
						 	 printf("Enter operation Number : ");
							 fflush(stdout);
					         scanf("%d",&ans);
					         switch (ans)
					         {
						        case 1 : /*Add new patient record feature */
							             printf("===============================================================\n");
										 Add_Node();
										 printf("===============================================================\n");
							             printf("Do you want to do another operation ?\n"
											     "1-Yes \n"
											     "2-No\n");
								          fflush(stdout);
							  AddCheck :  printf("Enter your Answer : ");
							              fflush(stdout);
							              scanf ("%d" , &ans);
										  switch (ans)
									      {
										    case 1 :  /*Yes case */
											        printf("===============================================================\n");
													fflush(stdout);
											        break ;

									        case 2 : /* No Case */
											         AdminOpFlag = 1 ;
												     ExitFlag = 1;
												     break ;

									      default: /*Invalid Entry case */
											       printf("invalid Choice , Try again \n"
												          "===============================================================\n");
												   fflush(stdout);
											       goto AddCheck ;
										 }
										break ;

							   case 2 :  /*Edit Case */
							              printf("===============================================================\n");
							              Edit_Node();
										  printf("===============================================================\n");
							              printf("Do you want to do another operation ?\n"
											   "1-Yes \n"
											   "2-No\n");
							         	  fflush(stdout);
						   	 EditCheck :  printf("Enter your Answer : ");
							              fflush(stdout);
							              scanf ("%d" , &ans);
									      switch (ans)
										  {
											 case 1 : /*Yes Case */
											          break ;

											 case 2 : /*No Case */
											          AdminOpFlag = 1 ;
													  ExitFlag = 1;
													  break ;

											default:  /*Invalid Entry Case */
											          printf("invalid Choice , Try again \n ");
													  fflush(stdout);
													  goto EditCheck ;
										  }
										break ;

							   case 3 : /*Reserve a slot with a doctor Case */
							            printf("===============================================================\n");
							            Display_All_Slots();
										Rsrv_Slot();
										printf("===============================================================\n");
										printf("Do you want to do another operation ?\n"
											   "1-Yes \n"
											   "2-No\n");
										fflush(stdout);
						 ReserveCheck : printf("Enter your Answer : ");
							            fflush(stdout);
						                scanf ("%d" , &ans);
										switch (ans)
										{
											case 1 : /*Yes Case*/
											         break ;

											case 2 : /*No Case*/
											         AdminOpFlag = 1 ;
													 ExitFlag = 1;
													 break ;

											default: /*Invalid Entry Case*/
											         printf("invalid Choice , Try again \n");
													 fflush(stdout);
													 goto ReserveCheck ;
										}
										break ;


							   case 4 : /*Cancel patient Reservation*/
							            printf("===============================================================\n");
										Cncl_Rsrv();
							            printf("===============================================================\n");
										printf("Do you want to do another operation ?\n"
											   "1-Yes \n"
											   "2-No\n");
									    fflush(stdout);
						  CancelCheck : printf("Enter your Answer : ");
							            fflush(stdout);
						                scanf ("%d" , &ans);
									    switch (ans)
									    {
											case 1 : /*Yes Case */
											         break ;

											case 2 : /*No Case */
											         AdminOpFlag = 1 ;
													 ExitFlag = 1;
													 break ;

											default: /*Invalid Entry Case */
											         printf("invalid Choice , Try again \n");
													 fflush(stdout);
													 goto CancelCheck;
									    }
									    break ;

							   case 5 : /*Return to the main menu case */
							            printf("===============================================================\n"
									           "Return to the main menu\n");
									    fflush(stdout);
									    goto MainMenu ;
									    break ;

							   default: /*Invalid Entry Case*/
							            printf("===============================================================\n"
										       "Invalid Choice, Try again \n");
										fflush(stdout);

			                }

						 }
				}
				else /*Password is incorrect*/
				{
				  printf ("Invalid Password , Exiting ...... ");
				  ExitFlag = 1 ;
		    	}
				 break;

		case 2 : /*User Mode Features */
		         printf( "=================================================\n"
				         "Welcome to User Mode ,Please select an operation :- \n"
				         "1-View patient record \n"
                         "2-View today reservation\n"
                         "3-Return to Main Menu\n"	);

				 while(UserOpFlag !=1 ) /*Read  option*/
				 {
	 UserModeMenu : printf( "=================================================\n"
						    "Enter Number of Operation : ");
				    fflush(stdout);
					scanf("%d", &ans);
          			switch (ans)
                    {

					   case 1 :/*View patient record Case */
					           printf( "=================================================\n");
						  	   Display_Patient();
							   printf( "=================================================\n"
							           "Do you want to do another operation ?\n"
									   "1-Yes \n"
									   "2-No\n");
			 ViewRecordCheck : printf("=================================================\n"
				                      "Enter your Answer : ");
							   fflush(stdout);
							   scanf ("%d" , &ans);
							   switch (ans)
							   {
								   case 1 : /*Yes Case */
											break ;

								   case 2 : /*No Case */
											UserOpFlag = 1 ; /*Exit User Mode */
	 										ExitFlag = 1;    /*Exit program */
										    break ;

								   default:  /*Invalid Entry Case */
											 printf("invalid Choice , Try again \n ");
										     fflush(stdout);
											 goto ViewRecordCheck ;
								}
					           break;

					   case 2 :/*View today reservation */
				               printf("=================================================\n");
		                       Diplay_Day_Rsrv ();
                               printf( "=================================================\n"
							           "Do you want to do another operation ?\n"
									   "1-Yes \n"
									   "2-No\n");
	         ViewReserveCheck : printf("=================================================\n"
				                       "Enter your Answer : ");
							    fflush(stdout);
							    scanf ("%d" , &ans);
							    switch (ans)
							    {
								    case 1 : /*Yes Case */
									         break ;

								    case 2 : /*No Case */
											 UserOpFlag = 1 ; /*Exit User Mode */
	 										 ExitFlag = 1;    /*Exit program */
										     break ;

								    default:  /*Invalid Entry Case */
											  printf("invalid Choice , Try again \n ");
										      fflush(stdout);
											  goto ViewReserveCheck ;
								}
					           break;

					   case 3 :/*Return to Main Menu Case */
					            printf("===============================================================\n"
									           "Return to the main menu\n");
							    fflush(stdout);
							    goto MainMenu ;
							    break ;



					   default: printf("Invalid Choice , Try Again\n" );

				    }
				 }

		         break;


	    case 3 : /*Exiting from the program Case */
		         printf("Exiting ......\n");
		         ExitFlag = 1 ;
	             break ;

	    default: /*Invalid Entry Case*/
		         printf("Invalid Choice , Try Again\n" );


	  }
   }
}
