#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "../include/home_service_app_header.h"

extern cust *start,*new,*ptr,*prev,*last;
extern tech *start1,*new1,*ptr1,*prev1,*last1;
extern service *start2,*new2,*ptr2,*prev2,*last2;

/*int count_digits(long int num)
{
	int count=0;
	if(isdigit(num))
	{
		while(num!=0)
		{
			num=num/10;
			count++;
		}
		return count;
	}
}*/

int validate_aadhar(long long int num)
{

                        if(num < 100000000000|| num >999999999999)                         
			{
                                printf("\nInvalid Length.Length should only of 12 digits.\n");
                                return 1;
                        }

                        return 0;

}

int validate_phoneno(long int num)
{

                        if(num < 1000000000|| num >9999999999) 
			{
                                printf("\nInvalid Length.Length should only of 10 digits.\n");
                                return 1;
                        }

                        return 0;
}

int alpha_valid(char *s)
{
	for(char *p=s;(*p);p++)
	{
		if(!isalpha(*p))
			return 1;
	}
	return 0;
}
int validate_password(char *str)
{
	char *ptr = str;

	int c_count = 0 , s_count = 0 , i_count = 0;
	while(*ptr !='\0')
	{
		if(*ptr >= 'A' && *ptr <= 'Z')
		{
			c_count = 1;
		}
		else if(*ptr >= 'a' && *ptr <= 'z')
		{
			s_count = 1;
		}
		else if(*ptr >= 48 && *ptr <= 57 )
		{
			i_count = 1;
		}
		else
		{
			return 0;
		}

		ptr++;
	}

	if(c_count &&s_count &&i_count)
	return 1;
	else
	return 0;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : customer_file_to_list
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the customer file to the list.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int customer_file_to_list()		//customer file to list function starts here...
{
	FILE *pc;
	cust_temp c1;
	if((pc=fopen("../data/customer.dat","rb"))==NULL)
	{
		printf("\n File is not found\n");
		return EXIT_FAILURE;
	}
	fread(&c1,sizeof(cust_temp),1,pc);
	while(!feof(pc))
	{
		if((new=(cust *)calloc(1,sizeof(cust)))==NULL)
		{
			printf("\n Memory Allocation Failed \n");
			return EXIT_FAILURE;
		}
		new->Aadharno=c1.Aadharno;
		strcpy(new->Cust_Name,c1.Cust_Name);
		strcpy(new->Address,c1.Address);
		new->PhoneNo=c1.PhoneNo;
		strcpy(new->avail_service_opt,c1.avail_service_opt);
		strcpy(new->Password,c1.Password);
		if(!start)
		{
			start = last = new;
			new->next=NULL;
		}
		else
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
		fread(&c1,sizeof(cust_temp),1,pc);
	}
	fclose(pc);
//	free(new);
	return EXIT_SUCCESS;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : customer_list_to_file
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the customer list to the file.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int customer_list_to_file() 		//customer list to file function starts here...
{
	cust_temp c2;
	if(!start)
	{

		printf("\n The list is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *pc1;
	if((pc1=fopen("../data/customer.dat","wb"))==NULL)
	{
		printf("\nFile is Not Found\n");
		return EXIT_FAILURE;
	}
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		c2.Aadharno=ptr->Aadharno;
		strcpy(c2.Cust_Name,ptr->Cust_Name);
		strcpy(c2.Address,ptr->Address);
		c2.PhoneNo=ptr->PhoneNo;
		strcpy(c2.avail_service_opt,ptr->avail_service_opt);
		strcpy(c2.Password,ptr->Password);
		fwrite(&c2,sizeof(cust_temp),1,pc1);
	}
	for(ptr=start;(ptr);prev=ptr,ptr=ptr->next)
	{
		free(prev);
	}
	free(prev);
	fclose(pc1);
	return EXIT_SUCCESS;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : technician_file_to_list
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the technician file to the list.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int technician_file_to_list()		//technician file to list function start here...
{
	FILE *pt;
	tech_temp t1;
	if((pt=fopen("../data/technician.dat","rb"))==NULL)
	{
		printf("\n File is not found\n");
		return EXIT_FAILURE;
	}
	fread(&t1,sizeof(tech_temp),1,pt);
	while(!feof(pt))
	{
		if((new1=(tech *)calloc(1,sizeof(tech)))==NULL)
		{
			printf("\n Memory Allocation Failed \n");
			return EXIT_FAILURE;
		}
		strcpy(new1->Tech_Name,t1.Tech_Name);
		strcpy(new1->Address,t1.Address);
		new1->Years_of_service=t1.Years_of_service;
		new1->cost_of_service=t1.cost_of_service;
		new1->contact_number=t1.contact_number;
		new1->technician_id=t1.technician_id;
		strcpy(new1->service_type,t1.service_type);
		strcpy(new1->password,t1.password);
		if(!start1)
		{
			start1 = last1 = new1;
			new1->next1=NULL;
		}
		else
		{
			last1->next1=new1;
			last1=new1;
			new1->next1=NULL;
		}
		fread(&t1,sizeof(tech_temp),1,pt);
	}
	//free(new1);
	fclose(pt);
	return EXIT_SUCCESS;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : technician_list_to_file
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the technician list to the file.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int technician_list_to_file()		//technician list to file function start here...
{
	tech_temp t2;
	if(!start1)
	{

		printf("\n The list is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *pt1;
	if((pt1=fopen("../data/technician.dat","wb"))==NULL)
	{
		printf("\nFile is Not Found\n");
		return EXIT_FAILURE;
	}
	for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
	{
		strcpy(t2.Tech_Name,ptr1->Tech_Name);
		strcpy(t2.Address,ptr1->Address);
		t2.Years_of_service=ptr1->Years_of_service;
		t2.cost_of_service=ptr1->cost_of_service;
		t2.contact_number=ptr1->contact_number;
		t2.technician_id=ptr1->technician_id;
		strcpy(t2.service_type,ptr1->service_type);
		strcpy(t2.password,ptr1->password);
		fwrite(&t2,sizeof(tech_temp),1,pt1);
	}
	for(ptr1=start1;(ptr1);prev1=ptr1,ptr1=ptr1->next1)
	{
		free(prev1);
	}
	free(prev1);
	fclose(pt1);
	return EXIT_SUCCESS;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : service_file_to_list
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the service file to the list.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int service_file_to_list()		//service file to list function starts here...
{
	FILE *ps;
	service_temp s1;
	if((ps=fopen("../data/service.dat","rb"))==NULL)
	{
		printf("\n File is not found\n");
		return EXIT_FAILURE;
	}
	fread(&s1,sizeof(service_temp),1,ps);
	while(!feof(ps))
	{
		if((new2=(service *)calloc(1,sizeof(service)))==NULL)
		{
			printf("\n Memory Allocation Failed \n");
			return EXIT_FAILURE;
		}
		new2->service_no=s1.service_no;
		new2->Aadharno=s1.Aadharno;
		strcpy(new2->service_type,s1.service_type);
		new2->technician_id=s1.technician_id;
		new2->cost_of_service=s1.cost_of_service;
		new2->service_status=s1.service_status;
		if(!start2)
		{
			start2 = last2 = new2;
			new2->next2=NULL;
		}
		else
		{
			last2->next2=new2;
			last2=new2;
			new2->next2=NULL;
		}
		fread(&s1,sizeof(service_temp),1,ps);
	}
	//free(new2);
	fclose(ps);
	return EXIT_SUCCESS;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : service_list_to_file
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the service list to the file.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int service_list_to_file()		//service list to file function start here...
{
	service_temp s2;
	if(!start2)
	{

		printf("\n The list is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *ps1;
	if((ps1=fopen("../data/service.dat","wb"))==NULL)
	{
		printf("\nFile is Not Found\n");
		return EXIT_FAILURE;
	}
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
	{
		s2.service_no=ptr2->service_no;
		s2.Aadharno=ptr2->Aadharno;
		strcpy(s2.service_type,ptr2->service_type);
		s2.technician_id=ptr2->technician_id;
		s2.cost_of_service=ptr2->cost_of_service;
		s2.service_status=ptr2->service_status;
		fwrite(&s2,sizeof(service_temp),1,ps1);
	}
	for(ptr2=start2;(ptr2);prev2=ptr2,ptr2=ptr2->next2)
	{
		free(prev2);
	}
	free(prev2);
	fclose(ps1);
	return EXIT_SUCCESS;
}
