#ifndef HOME_SERVICE_APP_HEADER_H
#define HOME_SERVICE_APP_HEADER_H
#define MAX 100

typedef struct Customer
{
	char Cust_Name[MAX];
	char Address[MAX];
	long long int Aadharno;
	long int PhoneNo;
	char avail_service_opt[MAX];
	char Password[MAX];
	int choice;
	struct Customer *next;
}cust;

//Temporary Structure for Customer
typedef struct Cust_temp
{
	char Cust_Name[MAX];
	char Address[MAX];
	long long int Aadharno;
	long int PhoneNo;
	char avail_service_opt[MAX];
	char Password[MAX];
}cust_temp;

typedef struct Technician
{
	char Tech_Name[MAX];
	int technician_id;
	char Address[MAX];
	int Years_of_service;
	double cost_of_service;
	long int contact_number;
	char password[MAX];
	int choice;
	char service_type[MAX];
	struct Technician *next1;
}tech;

//Temporary Structure for technician
typedef struct Tech_temp
{
	char Tech_Name[MAX];
	int technician_id;
	char Address[MAX];
	int Years_of_service;
	double cost_of_service;
	long int contact_number;
	char password[MAX];
	int choice;
	char service_type[MAX];
}tech_temp;

typedef struct Service
{
	int service_no;
	long long int Aadharno;
	char service_type[MAX];
	int technician_id;
	double cost_of_service;
	int service_status;
	struct Service *next2;
}service;

//Temporary Structure for Service
typedef struct Service_temp 
{
	int service_no;
	long long int Aadharno;
	char service_type[MAX];
	int technician_id;
	double cost_of_service;
	int service_status;
}service_temp;


int customer_corner();
int technician_corner();
int admin();


int customers_menu();
int technician_menu();
int reports_menu();

//Operations performed on Customer database
int add_cust_details();
int edit_cust_details();
int view_cust_details();
int do_transaction();


int admin_add_cust_details();
int admin_edit_cust_details();
int admin_view_cust_details();
int admin_del_cust_details();
//Operations performed on Technician database
int add_tech_details();
int edit_tech_details();
int view_tech_details();

int admin_add_tech_details();
int admin_edit_tech_details();
int admin_view_tech_details();
int admin_del_tech_details();

//Operations performed on Service database
int technician_report();
int completed_services();
//int del_records();

//prototype for validation functions
int alpha_valid(char *s);
//int count_digits(long int num);
int validate_aadhar(long long int num);
int validate_phoneno(long int num);
int validate_password(char *str);
int customer_file_to_list();
int technician_file_to_list();
int service_file_to_list();
int customer_list_to_file();
int technician_list_to_file();
int service_list_to_file();

#endif
