#ifndef patient
#define patient

#define String 20

/*1- Structure of Node */
typedef struct Node_type node;
//typedef struct Test test;
struct Node_type{
    u8 name [50];
	u8 id [15];
	u8 age ;
	s8 gender ;
	s8 p_slots[String];
	u8 day ;
	u8 period;
    node *next;
};

/*Functions Prototypes :- */

void Add_Node ();
void Edit_Node();
u8 search_Node (u8* ID  );
node* Get_Node (u8* ID);
void Rsrv_Slot(void);
void Cncl_Rsrv (void);
void Display_Patient ( );
void Diplay_Day_Rsrv ();


#endif
