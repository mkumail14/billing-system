#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct students
{
    char name[50];
    char fname[50];
    int semesterno;
    int gyear;
    int password;
    char course[6][100];
};
int id,go,age,year;
int holder[10] = {0};
int agemaker(int year,int id);

struct students student[100];

void signup(){

    system("CLS");
    FILE *file;
    int i;

    file = fopen("totalid.txt", "r");
    fscanf(file, "%d", &i);
    fclose(file);

    char idFileName[30];
    sprintf(idFileName, "studentdata/%d.txt", i);

    file = fopen(idFileName, "w");
    printf("\t\t\t\t\t\t\t\t***********************************\n");
    printf("\t\t\t\t\t\t\t\t* Your Registration Number is: %d. * \n\t\t\t\t\t\t\t\t* (Remember it for future login)  *\n", i);
    printf("\t\t\t\t\t\t\t\t***********************************\n");

    printf("Enter Name: ");
    scanf("%s", student[i].name);
    fprintf(file, "Name:%s\n", student[i].name);

    printf("Enter Father Name: ");
    scanf("%s", student[i].fname);
    fprintf(file, "Father's Name:%s\n", student[i].fname);

    int date,month;

    printf("Enter DOB:\n ");

    printf("\nDate:");
    scanf("%d",&date);

    printf("\nMonth:");
    scanf("%d",&month);

    printf("\nYear:");
    scanf("%d",&year);

    fprintf(file, "Date of Birth:%d-%d-%d\n", date,month,year);
    printf("\nEnter Graduating year: ");
    scanf("%d", &student[i].gyear);

    fprintf(file, "Graduating Year:%d\n", student[i].gyear);

    fclose(file);

    agemaker(year,i);


    char passwordFileName[30];
    sprintf(passwordFileName, "studentpassword/%d.txt", i);

    file = fopen(passwordFileName, "w");

    printf("Enter Password: ");
    scanf("%d", &student[i].password);
    fprintf(file, "%d", student[i].password);

    fclose(file);

    i++;
    file = fopen("totalid.txt", "w");
    fprintf(file, "%d", i);
    fclose(file);
       printf("\t\t\t\t\t\t\t\t********************************************\n");
    printf("\t\t\t\t\t\t\t\t* Dear %s your account has been made! \n\t\t\t\t\t\t\t\t* Your Registration Number is: %d.\n\t\t\t\t\t\t\t\t* Your Password is : %d.\n",student[i-1].name,i-1,student[i-1].password);
    printf("\t\t\t\t\t\t\t\t********************************************\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t PRESS Any Number to Continue......");
    int temp;
    scanf("%d",&temp);
    system("CLS");
    main();

}


void login(){
    system("CLS");
    char passwordFileName[30];
    int pass,realpass,i=0;
    FILE* file;

    do
    {
        system("CLS");

printf("\t\t\t\t\t\t\t\t*****************************************\n");
printf("\t\t\t\t\t\t\t\t*\t\tLogin\t\t\t*\n");
printf("\t\t\t\t\t\t\t\t*****************************************\n");

        if(i!=0)
        {
            printf("\nWrong ID or Password!\n");
        }
        printf("Enter Your Id: ");
        scanf("%d", &id);

        sprintf(passwordFileName, "studentpassword/%d.txt", id);
        file = fopen(passwordFileName, "r");

        printf("Enter Your Password: ");
        scanf("%d", &pass);

        fscanf(file, "%d", &realpass);
        i++;
    }
    while(pass!=realpass);

    menu();

}

menu(){

    int choose;
    do{
        system("CLS");
 printf("\t\t\t\t\t\t\t\t*****************************************\n");
printf("\t\t\t\t\t\t\t\t********Course Registration Site*********\n");
printf("\t\t\t\t\t\t\t\t*****************************************\n");

printf("\t\t\t\t\t\t\t\t*\t\tMain Menu\t\t*\n");
printf("\t\t\t\t\t\t\t\t* 1) Register Course\t\t\t*\n");
printf("\t\t\t\t\t\t\t\t* 2) View Data\t\t\t\t*\n");
printf("\t\t\t\t\t\t\t\t* 3) Clear Data\t\t\t\t*\n");
printf("\t\t\t\t\t\t\t\t* 4) Exit\t\t\t\t*\n");
printf("\t\t\t\t\t\t\t\t*****************************************\n=");


        scanf("%d",&choose);
    }
    while(choose>4 || choose<1);

    switch(choose){
        case 1:
            system("CLS");
            courseregister();
            break;
        case 2:
            system("CLS");
            viewdata();
            break;
        case 3:
            system("CLS");
            cleardata();
            break;
    }

}

courseregister(){

    int sem,choice;
    char sem1[9][100]= {"English","Applied Physics","FOP","ITC","PST","Calculus","Lab:Applied Physics","Lab:FOP","Lab:ITC" };
    char sem2[7][100]= {"Digital Logic Design","Lab:Digital Logic Design","Object Oriented Programming Techniques","Lab:Object Oriented Programming Techniques","Communication and Presentation Skills","Statitics and Probability","Islamic Studies / Humanities"};
    char sem3[7][100]= {"Computer Organisation and Assembly Language","Lab:Computer Organisation and Assembly Language","Data Structures and Algorithms","Lab:Data Structures and Algorithms","Discrete Mathematical Structures","University Elective-1","CS Supporting-1"};
    char sem4[6][100]= {"Design and Analysis of Algorithms","Finite Automata Theory and Formal Languages","Database Systems","Lab:Database Systems","Linear Algebra","Calculus","University Elective-2"};
    char sem5[6][100]= {"Compiler Construction","CS Supporting-2","CS Supporting-3","Operating System","Operating System-Lab","Software Engineering"};
    char sem6[7][100]= {"Artificial Intelligence","Artificial Intelligence-Lab","Computer Network and Data Communication","Computer Network and Data Communication-Lab","CS Elective-1","CS Elective-2"};
    char sem7[5][100]= {"CS Elective-3","Professional Pratices","Final Year Project-1","University Elective-3","Parallel and Distributed Computing"};
    char sem8[5][100]= {"CS Elective-4","University Elective-4","Final Year Project-2","Information Security","CS Elective-5"};


    printf("COURSE MANAGEMENT SYSTEM");
    printf("\nEnter Semester number : ");
    scanf("%d",&sem);

    if(sem<=0 || sem>8){
        printf("Wrong Input");
    }
    else{
        FILE*fp;
        char filename[30];
        sprintf(filename, "studentdata/%d.txt", id);
        fp = fopen(filename, "a+");
        fprintf(fp, "\nSemester No:%d", sem);
        fclose(fp);
        int count=0,status;
        switch(sem){
            case 1:
                do{
                    do{

                        courseenroll(sem,sem1,9);
                        scanf("%d",&choice);
                        checker(choice,count);

                    }while(go==2);

                    courseselector(choice,sem1);
                    count++;
                    if(count==6){
                        printf("You Limit of enrolling courses is reached\n");
                    }
                    else{
                        printf("To Continue 1 ,To Exit 0 : ");
                        scanf("%d",&status);
                    }
                }while(count<6 && status==1);

                break;
                break;
            case 2:{
                do{

                    do{
                        courseenroll(sem,sem2,7);
                        scanf("%d",&choice);
                        checker(choice,count);
                    }while(go==2);

                    courseselector(choice,sem2);
                    count++;
                    if(count==6){
                        printf("You Limit of enrolling courses is reached\n");
                    }
                    else{
                        printf("To Continue 1 ,To Exit 0 : ");
                        scanf("%d",&status);
                    }
                }while(count<6 && status==1);
                break;
            }
            case 3:
            {
                do
                {
                    do
                    {
                        courseenroll(sem,sem3,7);
                        scanf("%d",&choice);
                        checker(choice,count);
                    }
                    while(go==2);
                    courseselector(choice,sem3);
                    count++;
                    if(count==6)
                    {
                        printf("You Limit of enrolling courses is reached\n");
                    }
                    else
                    {
                        printf("To Continue 1 ,To Exit 0 : ");
                        scanf("%d",&status);
                    }
                }
                while(count<6 && status==1);
                break;
                break;

            }
            case 4:
            {
                do
                {
                    do
                    {
                        courseenroll(sem,sem4,7);
                        scanf("%d",&choice);
                        checker(choice,count);
                    }
                    while(go==2);
                    courseselector(choice,sem4);
                    count++;
                    if(count==6)
                    {
                        printf("You Limit of enrolling courses is reached\n");
                    }
                    else
                    {
                        printf("To Continue 1 ,To Exit 0 : ");
                        scanf("%d",&status);
                    }
                }
                while(count<6 && status==1);
                break;
                break;

            }
            case 5:
            {
                do
                {
                    do
                    {
                        courseenroll(sem,sem5,7);
                        scanf("%d",&choice);
                        checker(choice,count);
                    }
                    while(go==2);
                    courseselector(choice,sem5);
                    count++;
                    if(count==6)
                    {
                        printf("You Limit of enrolling courses is reached\n");
                    }
                    else
                    {
                        printf("To Continue 1 ,To Exit 0 : ");
                        scanf("%d",&status);
                    }
                }
                while(count<6 && status==1);
                break;
                break;

            }
            case 6:
            {
                do
                {
                    do
                    {
                        courseenroll(sem,sem6,7);
                        scanf("%d",&choice);
                        checker(choice,count);
                    }
                    while(go==2);
                    courseselector(choice,sem6);
                    count++;
                    if(count==6)
                    {
                        printf("You Limit of enrolling courses is reached\n");
                    }
                    else
                    {
                        printf("To Continue 1 ,To Exit 0 : ");
                        scanf("%d",&status);
                    }
                }
                while(count<6 && status==1);
                break;
                break;

            }
            case 7:
            {
                do
                {
                    do
                    {
                        courseenroll(sem,sem7,7);
                        scanf("%d",&choice);
                        checker(choice,count);
                    }
                    while(go==2);
                    courseselector(choice,sem7);
                    count++;
                    if(count==6)
                    {
                        printf("You Limit of enrolling courses is reached\n");
                    }
                    else
                    {
                        printf("To Continue 1 ,To Exit 0 : ");
                        scanf("%d",&status);
                    }
                }
                while(count<6 && status==1);
                break;
                break;

            }
            case 8:{
                do{
                    do{
                        courseenroll(sem,sem8,7);
                        scanf("%d",&choice);
                        checker(choice,count);
                    }while(go==2);

                    courseselector(choice,sem8);
                    count++;
                    if(count==6){
                        printf("You Limit of enrolling courses is reached\n");
                    }
                    else
                    {
                        printf("To Continue 1 ,To Exit 0 : ");
                        scanf("%d",&status);
                    }
                }
                while(count<6 && status==1);
                break;
                break;

            }
        }
    }
}

int courseenroll(int semno,char arr[][100],int soa){
    FILE*file;
    char filename[30];
    arr[soa][20];
    int i;

    printf("Available Course for Semester %d\n",semno);
    for(i=0; i<soa; i++)
    {
        printf("%d . %s\n",i+1,arr[i]);
    }
    printf("Course you want to enroll : ");
}


int courseselector(int courseno,char arr[][100],int f){
    FILE*file;
    char ch;
    int  index = courseno-1;
    char filename[30];
    printf("You are finally enrolled in \"%s\"\n",arr[index]);
    sprintf(filename, "studentdata/%d.txt", id);
    file = fopen(filename, "a+");
    fprintf(file, "\nCourse : %s", arr[index]);
    fclose(file);
    f++;
    //save in file
    //save in structure variable
}

aboutus(){
    system("CLS");
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\tFOP Thory Project\t\t*\n");
    printf("\t\t\t\t* Members:\t\t\t\t*\n");
    printf("\t\t\t\t* Mohammad Kumail Asghar---------2312244*\n");
    printf("\t\t\t\t* Abdullah Waseem ---------------2312102*\n");
    printf("\t\t\t\t* Khizar Iqbal Fazil ------------2312325*\n");
    printf("\t\t\t\t* Syed Mehdi Raza Rizvi----------2312244*\n");
    printf("\t\t\t\t*\t Instructor:Mustufa Hasan\t*\n");
    printf("\t\t\t\t*****************************************\n");
}

viewdata(){
    FILE*fp;
    char filename[30],ch;
    sprintf(filename, "studentdata/%d.txt", id);
    fp = fopen(filename, "r");
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(fp);

}

cleardata(){
    FILE*fp;
    char filename[30],ch;
    sprintf(filename, "studentdata/%d.txt", id);
    fp = fopen(filename, "w");
    fclose(fp);
    printf("\nYour Data have been cleared!");
}


int checker(int choice,int count){
    int temp, a;
    temp = choice;
    for (a = 0; a < 10; a++)
    {
        if (holder[a] == temp)
        {
            go = 2;
            printf("Already Registered");
            break;
        }
        else
        {
            go = 1;
            holder[count] = choice;
            break;
        }
    }

}




int main(){
    int choose;
    do{
        system("CLS");
        printf("\t\t\t\t\t\t\t*****************************************\n");
        printf("\t\t\t\t\t\t\t*\tCourse Registration Site\t*\n");
        printf("\t\t\t\t\t\t\t*****************************************\n");

        printf("\t\t\t\t\t\t\t*\t\tMain Menu\t\t*\n");
        printf("\t\t\t\t\t\t\t* 1) Sign Up\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t* 2) Login\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t* 3) About Us\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t* 4) Exit\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t*****************************************\n");
        printf("\t\t\t\t\t\t\t=== ");
        scanf("%d",&choose);
    }while(choose>4 || choose<1);

    switch(choose){
        case 1:
            signup();
            break;

        case 2:
            login();
            break;

        case 3:
            aboutus();
            break;

        case 4:
            exit(0);

    }
    return 0;
}


int agemaker(int year,int i)
{

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentYear = tm.tm_year + 1900;
    int age = currentYear - year;
    char idFileName[30];
    FILE * file;
    sprintf(idFileName, "studentdata/%d.txt", i);

    file = fopen(idFileName, "a+");
    printf("Age:%d\n",age);
    fprintf(file, "Age:%d.", age);
    fclose(file);

    return 0;
}
