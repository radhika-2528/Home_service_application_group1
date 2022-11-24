/**************************************************************************************
*      *FILENAME          :   home_service_app.c
*
*      *DESCRIPTION       :   This file define the function that comdnsists subfunction 
*                             to perform various operation
*      
*      *REVISION HISTORY  :
*      
*
*      DATE               NAME              REASON
*
*
****************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "../include/home_service_app_header.h"
//#include "home_service_app_menu.c"
//#include "home_service_app_func1.c"
//#include "home_service_app_func2.c"

int main()
{
	customer_file_to_list();
	technician_file_to_list();
	service_file_to_list();
	int choice=0;
	//int (*option[3])()={customer_corner, technician_corner, admin};
	while(choice!=4)
	{

		//Displaying Main Menu
		system("clear");
		printf("\n1.Customer\n2.Technician\n3.Admin\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:customer_corner();
			       break;
			case 2:technician_corner();
			       break;
			case 3:admin();
			       break;
			case 4:break;
			default:printf("\nInvalid Choice\n");
				break;
		}
	}
	customer_list_to_file();
	technician_list_to_file();
	service_list_to_file();
	printf("\nThank You!\nVisit us Again!!!");
	return EXIT_SUCCESS;
}

