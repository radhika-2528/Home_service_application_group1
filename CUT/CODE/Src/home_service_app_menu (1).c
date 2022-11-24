#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/home_service_app_header.h"

/************************************************************************************************
 *	*FUNCTION NAME	:  customer_corner
 *
 *	*DESCRIPTION	:  This function is used to performs various opertions in the 
 *	                   customer database by receiving choice from the customer.
 *
 *	*RETURNS	:  add_cust_details() function - for adding the details of the customer.
 *			   
 *			   edit_cust_details() function - for editing the details of the 
 *			   existing customer.
 *			   
 *			   view_cust_details() function - for viewing the details of the customer.
 *			   
 *			   del_cust_details() function  - for deleting the details of the customer.
 *
 *************************************************************************************************/

int customer_corner()
{
	int choice;
	while(choice!=4)
	{
		system("read a");
		system("clear");
		printf("\n1.Add Customer Details\n2.Edit Customer Details\n3.View Customer Details\n4.Delete Customer Details\n5.Go Back\n");
		printf("\nEnter your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:add_cust_details();
			       break;
			case 2:edit_cust_details();
			       break;
			case 3:view_cust_details();
			       break;
			case 4:del_cust_details();
			       break;
			case 5:return EXIT_SUCCESS;
			      // break;
			default:printf("\nInvalid Choice\n");
				continue;
		}
	}
	return EXIT_SUCCESS;
}
/*************************************************************************************************
 *      *FUNCTION NAME	: technician_corner
 *
 *	*DESCRIPTION	: This function is used to performs various opertions in the technician 
 *	                  database by receiving choice from the technician.
 *
 *	*RETURNS	:  add_tech_details() function - for adding the details of the technician.
 *			   
 *			   edit_tech_details() function - for editing the details of the existing 
 *			   technician.
 *			   
 *			   view_tech_details() function - for viewing the details of the technician.
 *			   
 *			   del_tech_details() function  - for deleting the details of the technician.
 *
 ***************************************************************************************************/

int technician_corner()
{
	int choice;
	while(choice!=4)
	{
		system("read a");
		system("clear");
		printf("\n1.Add Technician Details\n2.Edit Technician Details\n3.View Technician Details\n4.Delete Technician Details\n5.Go Back\n");
		printf("Enter your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:add_tech_details();
			       break;
			case 2:edit_tech_details();
			       break;
			case 3:view_tech_details();
			       break;
			case 4:del_tech_details();
			       break;
			case 5:return EXIT_SUCCESS;
			       //break;
			default:printf("\nInvalid Choice\n");
				continue;
		}
	}
	return EXIT_SUCCESS;
}


int admin()
{
	while(1)
	{
		char admin_id[50];
		char pswd[20];
		system("read a");
		system("clear");
		printf("Enter admin_id:");
		scanf("%s",admin_id);
		printf("Enter password:");
		scanf("%s",pswd);

		if(strcmp(pswd,"admin@123")==0)
		{
			system("clear");
			int ch1=0;
			while(ch1!=4)
			{
				printf("\n1.Customer Details\n2.Technician Details\n3.Service Details\n4.Exit\n");		
				printf("Enter your choice:\n");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 1: customer_corner();
						break;
					case 2: technician_corner();
						break;
					case 3: service_corner();
						break;
					case 4: break;
					default: printf("Invalid choice\n");
						printf("choice number between 1 to 11\n:");
						continue;
				}
			}
		}
		else
		{
			printf("\nAccess Denied\n");
			continue;
		}
		break;
	}
}

/**********************************************************************************
 *      *FUNCTION NAME	:  service_corner
 *
 *	*DESCRIPTION	:  This function is used to performs various opertions in
 *	                   the service database by receiving choice from the admin.
 *
 *	*RETURNS	:  edit_records() function - for editing the details of the 
 *	                   existing customers and technicians by admin.
 *
 *			   view_records() function - for viewing the details of the 
 *			   customers and technicains by admin.
 *
 *			   del_records() function  - for deleting the details of the  
 *			   customers and technicians by admin.
 *
 *********************************************************************************/

int service_corner()
{
	int choice;
	while(choice!=3)
	{
		system("read a");
		system("clear");
		printf("\n1.Edit Records\n2.View Records\n3.Delete Records\n4.Go Back\n");
		printf("Enter your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:edit_records();
			       break;
			case 2:view_records();
			       break;
			case 3:del_records();
			       break;
			case 4:return EXIT_SUCCESS;
			       break;
			default:printf("\nInvalid Choice\n");
				continue;
		}
	}
	return EXIT_SUCCESS;
}

