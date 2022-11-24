#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/home_service_app_header.h"
//#include "home_service_app_func2.c"

cust *start,*new,*ptr,*prev,*last;
tech *start1,*new1,*ptr1,*prev1,*last1;
service *start2,*new2,*ptr2,*prev2,*last2;

/***********************************************************************************************************
 *	
 *	*FUNCTION NAME  :    add_cust_details
 *	
 *	*DESCRIPTION 	:    This function is used to add customer details into the customer database by the customer.
 *
 *	*RETURNS 	:    No Returns
 *
 ************************************************************************************************************/
int add_cust_details()
{					      //adding customer details function starts here
	//cust choice;
	if((new=(cust *)calloc(1,sizeof(cust)))==NULL)
	{
		printf("\nMemory allocation failure\n");
		return EXIT_FAILURE;
	}

	printf("-------------------------Customer Registration-----------------------\n");

	while(1)
	{ 

		printf("Enter Aadhar Number:");
		scanf("%lld",&new->Aadharno);
		if(validate_aadhar(new->Aadharno))
		{
			printf("\nEnter Valid AadharNumber\n");
			continue;
		}

		if(start)
		{
			for(ptr=start;(ptr)&&ptr->Aadharno!=new->Aadharno;ptr=ptr->next);
			if((ptr)&&ptr->Aadharno==new->Aadharno)
			{
				printf("\nAadharNumber %lld already exists\n",new->Aadharno);
				continue;
			}
			else
				break;
		}
		else	
			break;
	}
	while(1)
	{
		printf("Enter Name:");
		scanf("%s",new->Cust_Name);
		if(strlen(new->Cust_Name)==0)
		{
			printf("\nThis field can't be Empty\n");
			continue;
		}

		if(strlen(new->Cust_Name)<5)
		{
			printf("\nMinimum 5 Characters required\n");
			continue;
		}
		if(alpha_valid(new->Cust_Name)==1)
		{
			printf("\nName should have only alphabets\n");
			continue;
		}
		else
			break;
	}
	while(1)
	{
		printf("\nEnter Address:");
		//fgets(new->Address,MAX-1,stdin);
		scanf("%s",new->Address);
		if(strlen(new->Address)==0)
		{
			printf("\nThis field can't be empty\n");
			continue;
		}
		else
			break;
	}
	while(1)
	{
		printf("\nEnter Contact Number:");
		scanf("%ld",&new->PhoneNo);
		//if(count_digits(new->PhoneNo) < 10 || count_digits(new->PhoneNo) > 10)
		if(validate_phoneno(new->PhoneNo))
		{
			printf("\nEnter valid Phone Number\n");
			continue;
		}
		break;
	}
	while(1)
	{
		printf("\nEnter Password:\n");
		scanf("%s",new->Password);
		if(validate_password(new->Password))
			continue;
		break;
	}
	while(1)
	{
		printf("\nEnter avail service option:\n");
		printf("\n1.Plumber\n2.Electrician\n3.AC/Freeze-Service\n4.Carpenter\n5.Electronics-Service\n");
		printf("\nEnter choice:");
		scanf("%d",&new->choice);
		if(new->choice>5)
		{
			printf("\nEnter valid service option\n");
			continue;
		}
		else
		{
			if(new->choice==1)
			{
				strcpy(new->avail_service_opt,"Plumber");
			}

			if(new->choice==2)
			{
				strcpy(new->avail_service_opt,"Electrician");
			}

			if(new->choice==3)
			{
				strcpy(new->avail_service_opt,"AC/Freeze-service");
			}
			if(new->choice==4)
			{
				strcpy(new->avail_service_opt,"Carpenter");
			}
			if(new->choice==5)
			{
				strcpy(new->avail_service_opt,"Electronics-Service");
			}
		}
		break;
	}
	if(!start)
	{
		start=new;
		new->next=NULL;
	}
	else if(new->Aadharno < start->Aadharno)
	{
		new->next=start;
		start=new;
	}
	else
	{
		for(ptr=start;(ptr)&&ptr->Aadharno<new->Aadharno;prev=ptr,ptr=ptr->next);
		prev->next=new;
		new->next=ptr;
	}
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}									//adding customer details function ends here


/**********************************************************************************************************
 *
 * 	*FUNCTION NAME : edit_cust_details
 *
 * 	*DESCRIPTION : This function is used to edit customer details into the customer database by the customer
 *
 * 	*RETURNS : No returns
 *
 *********************************************************************************************************/
int edit_cust_details()
{									//editing customer details function details starts here
	if(!start)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	long long int Aadharno;
	while(1)
	{
		printf("\nEnter Aadhar Number for editing:\n");
		scanf("%lld",&Aadharno);
		//if(count_digits(Aadharno)>12 || count_digits(Aadharno)<12)
		if(validate_aadhar(Aadharno))
		{
			printf("\nEnter valid AadharNumber\n");
			continue;
		}
		break;
	}
	for(ptr=start;(ptr)&&ptr->Aadharno!=Aadharno;ptr=ptr->next);
	if(!ptr)
	{
		printf("\nAadharno %lld not found\n",Aadharno);
		return EXIT_FAILURE;

	}
	printf("Enter new name, new phoneno,new Address and password \n");
	scanf("%s %ld  %s %s",&ptr->Cust_Name,&ptr->PhoneNo,&ptr->Address,&ptr->Password);
	printf("Enter avail service option:");

	printf("\n1.Plumber\n2.Electrician\n3.AC/Freeze-Service\n4.Carpenter\n5.Electronics-Service\n");
	printf("\nEnter choice:");
	scanf("%d",&ptr->choice);
	if(ptr->choice>5)
	{
		printf("\nEnter valid service option\n");
		//	continue;
	}
	else
	{
		if(ptr->choice==1)
		{
			strcpy(ptr->avail_service_opt,"Plumber");
		}

		if(ptr->choice==2)
		{
			strcpy(ptr->avail_service_opt,"Electrician");
		}

		if(ptr->choice==3)
		{
			strcpy(ptr->avail_service_opt,"AC/Freeze-service");
		}
		if(ptr->choice==4)
		{
			strcpy(ptr->avail_service_opt,"Carpenter");
		}
		if(ptr->choice==5)
		{
			strcpy(ptr->avail_service_opt,"Electronics-Service");
		}
	}
	return EXIT_SUCCESS;

}								//editing customer details function ends here

/************************************************************************************************************
 *
 * 	*FUNCTION : view_cust_details
 *
 * 	*DESCRIPTION : This function is used to view all customer details in the customer database
 *
 * 	*RETURNS  :  No returns
 *
 ***********************************************************************************************************/
int view_cust_details()
{								//view customer details function starts here
	if(!start)
	{
		printf("\nNo records found\n");
		return EXIT_FAILURE;
	}
	printf("\nAadharNumber       Customer_Name    Address            PhoneNumber      Avail_Service_Option         Password\n");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		printf("\n%3lld %15s %20s %15ld %15s %15s\n",ptr->Aadharno,ptr->Cust_Name,ptr->Address,ptr->PhoneNo,ptr->avail_service_opt,ptr->Password);
	}
	return EXIT_SUCCESS;
}										//view customer details function ends here

/**************************************************************************************************************************
 *
 * 	*FUNCTION NAME : del_cust_details
 *
 * 	*DESCRIPTION : This function is used to delete customer details in the customer database by the customer and admin
 *
 * 	*RETURNS : No returns
 *
 ************************************************************************************************************************/


int del_cust_details()
{				       //deleting customer details function starts here
	if(!start)
	{
		printf("\nNo record found\n");
		return EXIT_FAILURE;
	}
	long long int Aadharno;
	while(1)
	{
		printf("\nEnter the Aadhar Number for deleting:");
		scanf("%lld",&Aadharno);
		//if(count_digits(Aadharno)>12||count_digits(Aadharno)<12)
		if(validate_aadhar(Aadharno))
		{
			printf("\nEnter valid Aadhar Number");
			continue;
		}
		else
			break;

	}
	if(Aadharno==start->Aadharno)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	else
	{
		for(ptr=start;(ptr) && ptr->Aadharno!=Aadharno;prev=ptr,ptr=ptr->next);
		if(!ptr)
		{
			printf("\nAadhar number %lld is not found\n",Aadharno);
			return EXIT_FAILURE;
		}
		prev->next=ptr->next;
		free(ptr);
	}
	return EXIT_SUCCESS;
}					//deleting customer details function ends here

//Technician Details
/*************************************************************************************************************************************
 *
 * 	*FUNCTION NAME : add_tech_details
 *
 * 	*DESCRIPTION : This function is used to add the Technician details in the technician database by the technician
 *
 * 	*RETURNS : No returns
 *
 ***********************************************************************************************************************************/
int add_tech_details()
{										//adding technician details function starts here
	if((new1=(tech *)calloc(1,sizeof(tech)))==NULL)
	{
		printf("\nMemory Allocation Failed\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		printf("\nEnter Technician Name:");
		scanf("%s",new1->Tech_Name);
		if(alpha_valid(new1->Tech_Name))
		{
			printf("\nName should contain only characters\n");
			continue;
		}
		if((strlen(new1->Tech_Name))==0)
		{
			printf("\nThis field cannot be Null\n");
			continue;
		}
		else if(strlen(new1->Tech_Name)<5)
		{
			printf("\nMinimum 5 characters is required\n");
			continue;
		}
		else 
			break;
		break;
	}
	while(1)
	{
		printf("\nEnter Address:");
		scanf("%s",new1->Address);
		if(strlen(new1->Address)==0)
		{
			printf("\nThis field cannot be empty\n");
			continue;
		}
		else
			break;
		break;
	}
	while(1)
	{
		printf("\nEnter PhoneNumber:");
		scanf("%ld",&new1->contact_number);
		//if(count_digits(new1->contact_number)>10 || count_digits(new1->contact_number)<10)
		if(validate_phoneno(new1->contact_number))
		{
			printf("\nEnter valid Contact Number\n");
			continue;
		}
		else
			break;

		break;
	}

	while(1)
	{
		printf("\nEnter Service type:\n");
		printf("\n1.Plumber\n2.Electrician\n3.AC/Freeze-Service\n4.Carpenter\n5.Electronics-Service\n");
		printf("\nEnter choice:");
		scanf("%d",&new1->choice);
		if(new1->choice>5)
		{
			printf("\nEnter valid service type\n");
			continue;
		}
		else
		{
			if(new1->choice==1)
			{
				strcpy(new1->service_type,"Plumber");
			}

			if(new1->choice==2)
			{
				strcpy(new1->service_type,"Electrician");
			}

			if(new1->choice==3)
			{
				strcpy(new1->service_type,"AC/Freeze-service");
			}
			if(new1->choice==4)
			{
				strcpy(new1->service_type,"Carpenter");
			}
			if(new1->choice==5)
			{
				strcpy(new1->service_type,"Electronics-Service");
			}
		}
		break;
	}
	while(1)
	{
		printf("\nEnter Years of service:");
		scanf("%d",&new1->Years_of_service);
		if(new1->Years_of_service==0)
		{
			printf("\nThis field cannot be empty\n");
			continue;
		}
		break;
	}
	while(1)
	{
		printf("\nEnter cost of service:");
		scanf("%lf",&new1->cost_of_service);
		if(new1->cost_of_service==0.0)
		{
			printf("\nThis field cannot be empty\n");
			continue;
		}
		break;
	}
	while(1)
	{
		printf("\nEnter Password:");
		scanf("%s",new1->password);
		if(validate_password(new1->password))
		{
			printf("Given Password doesn't meet requirements");
			continue;
		}
		break;
	}
	if(!start1)
	{
		new1->technician_id=100;
		start1=last1=new1;
		new1->next1=NULL;
	}
	else
	{
		new1->technician_id=last1->technician_id+1;
		last1=new1;
		new1->next1=NULL;
	}
	system("read a");
	system("clear");
        return EXIT_SUCCESS;

}										//adding customer details function ends here

/*************************************************************************************************************************************
 *
 * 	*FUNCTION NAME : edit_cust_details
 *
 * 	*DESCRIPTION : This function is used to edit technician details in the technician database by the technician
 *
 * 	*RETURNS : No returns
 *
 ***********************************************************************************************************************************/
int edit_tech_details()
{                                                                           //editing technician details function starts here

	if(!start1)
	{
		printf("\nNo records found\n");
		return EXIT_FAILURE;
	}
	int technician_id;
	while(1)
	{
		printf("\nEnter the technician Id:\n");
		scanf("%d",&technician_id);
		for(ptr1=start1;(ptr1)&&ptr1->technician_id!=technician_id;ptr1=ptr1->next1);
		if(!ptr1)
		{
			printf("\nTechnician Id %d not found\n",technician_id);
			return EXIT_FAILURE;
		}
		printf("Enter new name, new contactno, new Address, new service type, new cost of service, new year of service and password\n");
		scanf("%s %ld %s %s %lf %d %s",ptr1->Tech_Name,&ptr1->contact_number,ptr->Address,ptr1->service_type,&ptr1->cost_of_service,&ptr1->Years_of_service,ptr1->password);
		printf("Enter service type:");
		printf("\n1.Plumber\n2.Electrician\n3.AC/Freeze-Service\n4.Carpenter\n5.Electrician-Service\n");
		printf("\nEnter choice:");
		scanf("%d",&ptr1->choice);
		if(ptr1->choice>5)
		{
			printf("\nEnter service type\n");
			continue;
		}
		else
		{
			if(ptr1->choice==1)
			{
				strcpy(ptr1->service_type,"Plumber");
			}

			if(ptr1->choice==2)
			{
				strcpy(ptr1->service_type,"Electrician");
			}

			if(ptr1->choice==3)
			{
				strcpy(ptr1->service_type,"AC/Freeze-service");
			}
			if(ptr1->choice==4)
			{
				strcpy(ptr1->service_type,"Carpenter");
			}
			if(ptr1->choice==5)
			{
				strcpy(ptr1->service_type,"Electronics-Service");
			}
		}
		break;
	}

	return EXIT_SUCCESS;                                           								                                                                            //editing technician details function ends here
}

/************************************************************************************************************************************
 *
 * 	*FUNCTION NAME : view_tech_details
 *
 * 	*DESCRIPTION : This function is used to view technician details in the technician database
 *
 * 	*RETURNS : No returns
 *
 *************************************************************************************************************************************/
int view_tech_details()
{										//view technician details function starts here
	if(!start1)
	{
		printf("\nNo records found\n");
		return EXIT_FAILURE;
	}
	printf("\nID    Technician_Name     Address       PhoneNumber      service_type     Years_of_service     Cost_of_service  Password\n");
	for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
	{
		printf("\n%d  %3s %15s %15ld  %15s  %15d  %15lf  %15s\n",ptr1->technician_id,ptr1->Tech_Name,ptr1->Address,ptr1->contact_number,ptr1->service_type,ptr1->Years_of_service,ptr1->cost_of_service,ptr1->password);
	}
	return EXIT_SUCCESS;

}										//view technician details function ends here

/***********************************************************************************************************************************
 *
 * 	*FUNCTION NAME : del_tech_details
 *
 * 	*DESCRIPTION : This function is used to delete technician details in the technician database by the technician
 *
 * 	*RETURNS : No returns
 *
 *********************************************************************************************************************************/

int del_tech_details()
{										//deleting technician details function starts here

	if(!start1)
	{
		printf("\nNo record found\n");
		return EXIT_FAILURE;
	}
	int technician_id;
	while(1)
	{
		printf("\nEnter the Technician Id for deleting:");
		scanf("%d",&technician_id);
		if(technician_id<100)
		{
			printf("\nEnter valid Technician Id");
			continue;
		}
		else
			break;

	}
	if(technician_id==start1->technician_id)
	{
		ptr1=start1;
		start1=start1->next1;
		free(ptr1);
	}
	else
	{
		for(ptr1=start1;(ptr1) && ptr1->technician_id!=technician_id;prev1=ptr1,ptr1=ptr1->next1);
		if(!ptr1)
		{
			printf("\nTechnician Id %d is not found\n",technician_id);
			return EXIT_FAILURE;
		}
		prev1->next1=ptr1->next1;
		free(ptr1);
	}
	return EXIT_SUCCESS;																	                                                 //deleting technician details function ends here
}

/***********************************************************************************************************************************
 *
 *	*FUNCTION NAME : edit_records
 *
 *	*DESCRIPTION : This function is used to edit the records in the service database by the admin
 *
 *	*RETURNS : No returns
 *
 **********************************************************************************************************************************/

int edit_records()
{											//editing service database starts here

	if((new2=(service *)calloc(1,sizeof(service)))==NULL)
	{
		printf("\nMemory allocation failure\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		printf("Enter Aadhar Number:");
		scanf("%lld",&new2->Aadharno);
		//if(count_digits(new2->Aadharno)<12 || count_digits(new2->Aadharno)>12)
		if(validate_aadhar(new2->Aadharno))
		{
			printf("\nEnter Valid AadharNumber\n");
			continue;
		}
		if(start2)
		{
			for(ptr2=start2;(ptr2)&&ptr2->Aadharno!=new2->Aadharno;ptr2->next2);
			if((ptr2)&&ptr2->Aadharno==new2->Aadharno)
			{
				printf("\nAadharNumber %lld already exists\n",new2->Aadharno);
				continue;
			}
			else
				break;
		}
		break;
	}



}											//editing service database ends here

/***********************************************************************************************************************************
 *
 * 	*FUNCTION : view_records
 *
 * 	*DESCRIPTION : This function is used to view the records in the service database
 *
 * 	*RETURNS : No returns
 *
 **********************************************************************************************************************************/
int view_records()
{											//viewing service database starts here

}											//viewing service database ends here

/***********************************************************************************************************************************
 *
 * 	*FUNCTION NAME : del_records
 *
 * 	*DESCRIPTION : This function is used to delete records in the service database by the admin
 * 	
 * 	*RETURNS : No returns
 *
 *********************************************************************************************************************************/
int del_records()
{										//deleting records in service database starts here

}										//deleting records in service database ends here