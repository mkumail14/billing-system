#include <stdio.h>
#include <stdlib.h>
// #include <direct.h>  // For _mkdir
//#include <Windows.h> // For RemoveDirectory

int main() {
    int a=0, b=0, c=0, d=0,e=0,f=0,g=0,h=0,j=0,K=0,l=0,p=0,m=0,q=0,r=0,id=0, quantity=0, price=0, sale=0, sold=0,totalproduct=0,i=0,profit=0,totalprofit=0,topay=0,totalitem=0,totalitemsold=0,overallprofit=0;
    char product[50], ch, cs[100];
    FILE *file;


do{
    do {
        system("CLS");
                printf("                                                                   *****************************************\n");
                printf("                                                                   ***********Sale Billing Portal***********\n");
                printf("                                                                   *****************************************\n");


        printf("                                                                   *             Main Menu                 *\n");
        printf("                                                                   * 1) Customer                           *\n");
        printf("                                                                   * 2) Product                            *\n");
        printf("                                                                   * 3) Profit                             *\n");
        printf("                                                                   * 4) Customer List                      *\n");
        printf("                                                                   * 5) About me                           *\n");
        printf("                                                                   * 6) Start/Reset                        *\n");
        printf("                                                                   * 7) Exit                               *\n");
        printf("                                                                   *****************************************\n");
        printf("                                                                   === ");
        scanf("%d", &a);
    } while (a>7 || a<1);

    if (a == 1) {
        do {

            system("CLS");
            printf("                                                                   *****************************************\n");
            printf("                                                                   *           Customer Menu               *\n");
            printf("                                                                   * 1) Show Prices                        *\n");
            printf("                                                                   * 2) Make Bill                          *\n");
            printf("                                                                   * 3) Back                               *\n");
            printf("                                                                   *****************************************\n");
            printf("                                                                   === ");
            scanf("%d", &b);
        } while (b>3 || b<1);

        if (b == 1) {
            system("CLS");
printf("*****************************************\n");
            printf("*            Price List                 *\n");
            printf("*****************************************\n");
                        file = fopen("list//pricelist", "r");
            while ((ch = fgetc(file)) != EOF) {
                printf("%c", ch);
            }
            fclose(file);

            do {
                printf("\n********************************\n\n1)Go Back\n2)Exit \n********************************\n===");
                scanf("%d", &p);
            } while (p != 1 && p != 2);
if(p==1){b=3;}else if(p==2){exit;};

        } else if (b == 2) {
            do {
                system("CLS");
                printf("****************\n* Your Total Data *\n******************\n");
                file = fopen("list//pricelist", "r");
                while ((ch = fgetc(file)) != EOF) {
                    printf("%c", ch);
                }
                fclose(file);

                printf("\n\n*********************\n* Enter Product ID*\n*********************\n===");
                scanf("%d", &id);
                char idFileName[20];
                sprintf(idFileName, "data//%d.q.txt", id);
                file = fopen(idFileName, "r");
                if (fscanf(file, "%d", &d) != 1) {
                    fprintf(stderr, "Error \n");
                }
                fclose(file);

                if (d > 0) {
                    printf("*********************\n* Enter Customer Name*\n*********************\n===");
                    scanf("%s", &cs);
                    printf("*********************\n* Enter Bought Quantity*\n*********************\n===");
                    scanf("%d", &sold);

                    d -= sold;
                    char tFileName[20];
                    sprintf(tFileName, "data//%d.q.txt", id);
                    file = fopen(tFileName, "w");
                    fprintf(file, "%d", d);
                    fclose(file);

                    file = fopen("list//customerlist", "a+");
                    fprintf(file, "\n%d)", id);
                    fprintf(file, " %s.", cs);
                    fprintf(file, "  %dpcs", sold);
                    fclose(file);

                    printf("*********************\n* Your Data has been Saved*\n*********************\n");
                }

                printf("More Data? Press 1\n");
                scanf("%d", &c);
            } while (c == 1);
            do {
                printf("\n********************************\n\n1)Go Back\n2)Exit \n********************************\n===");
                scanf("%d", &p);
            } while (p != 1 && p != 2);
if(p==1){b=3;}else if(p==2){exit;};
        }
    } else if (a == 2) {
        do {
            system("CLS");
            printf("                                                                   ****************\n                                                                   * 1)Check Data *\n                                                                   * 2)Enter Data *\n                                                                   * 3)Back       *\n                                                                   ****************\n                                                                   ===");
            scanf("%d", &b);
        } while (b>3 || b<1);

        if (b == 1) {
            system("CLS");
            printf("****************\n* Your Total Data= *\n****************\n");
            file = fopen("list//Productlist", "r");
            while ((ch = fgetc(file)) != EOF) {
                printf("%c", ch);
            }
            fclose(file);

            do {
                printf("\n********************************\nDo you Want To Clear DATA?\n1)YES\n2)NO \n********************************\n===");
                scanf("%d", &b);
            } while (b != 1 && b != 2);

            if (b == 1) {
                file = fopen("list//Productlist", "w");
                fclose(file);
                printf("Your Data Is Cleared");
            } else if (b == 2) {
                do {
                    printf("\n********************************\nDo you Want To know Quantity ?\n1)YES\n2)NO \n********************************\n===");
                    scanf("%d", &b);
                } while (b != 1 && b != 2);

                if (b == 1) {
                    printf("\n\n*********************\n* Enter Product ID*\n*********************\n===");
                    scanf("%d", &id);
                    char idFileName[20];
                    sprintf(idFileName, "data//%d.q.txt", id);
                    file = fopen(idFileName, "r");
                    if (fscanf(file, "%d", &d) != 1) {
                        fprintf(stderr, "Error \n");
                    }

                    printf("\n\n******************************************\nCurrent Quantity of Product Id=%d is %dpcs\n******************************************\n", id, d);

                    fclose(file);
                }


            }
            do {
                printf("\n********************************\n\n1)Go Back\n2)Exit \n********************************\n===");
                scanf("%d", &p);
            } while (p != 1 && p != 2);
if(p==1){b=3;}else if(p==2){exit;};

        } else if (b == 2) {
            do {
                system("CLS");
                printf("****************\n* Your Total Data *\n******************\n");
                file = fopen("list//Productlist", "r");
                while ((ch = fgetc(file)) != EOF) {
                    printf("%c", ch);
                }
                fclose(file);

                file = fopen("list//Productlist", "a+");
                printf("\n\n*********************\n* Enter Product ID*\n*********************\n===");
                scanf("%d", &id);
                fprintf(file, "\n%d)", id);
                printf("*********************\n* Enter Product Name*\n*********************\n===");
                scanf("%s", &product);
                fprintf(file, " %s.", product);
                printf("*********************\n* Enter Product Price*\n*********************\n===");
                scanf("%d", &price);
                fprintf(file, "  Rs.%d", price);

                printf("*********************\n* Enter Sale Price*\n*********************\n===");
                scanf("%d", &sale);
                fprintf(file, "  Rs.%d", sale);

                printf("*********************\n* Enter Product Quantity*\n*********************\n===");
                scanf("%d", &quantity);
                fprintf(file, "  %dpcs", quantity);
                fclose(file);

                file = fopen("list//pricelist", "a+");
                fprintf(file, "\n%d)", id);
                fprintf(file, " %s.", product);
                fprintf(file, "  Rs.%d", sale);
                fclose(file);

                // Create separate file for quantity
                char tquantityFileName[20];
                sprintf(tquantityFileName, "data//%d.tq.txt", id);
                file = fopen(tquantityFileName, "w");
                fprintf(file, "%d", quantity);
                fclose(file);

                // Create separate file for quantity
                char quantityFileName[20];
                sprintf(quantityFileName, "data//%d.q.txt", id);
                file = fopen(quantityFileName, "w");
                fprintf(file, "%d", quantity);
                fclose(file);

                // Create separate file for price
                char priceFileName[20];
                sprintf(priceFileName, "data//%d.price.txt", id);
                file = fopen(priceFileName, "w");
                fprintf(file, "%d", price);
                fclose(file);

                char saleFileName[20];
                sprintf(saleFileName, "data//%d.sale.txt", id);
                file = fopen(saleFileName, "w");
                fprintf(file, "%d", sale);
                fclose(file);

                printf("*********************\n* Your Data has been Saved*\n*********************\n");

                printf("More Data? Press 1\n");
                scanf("%d", &c);
            } while (c == 1);
       do {
                printf("\n********************************\n\n1)Go Back\n2)Exit \n********************************\n===");
                scanf("%d", &p);
            } while (p != 1 && p != 2);
if(p==1){b=3;}else if(p==2){exit;};


        }else if(b==3){ b=3;}



    }else if(a==3){
         system("CLS");
        printf("*****************************************\n");
            printf("*            Price List                 *\n");
            printf("*****************************************\n");
                        file = fopen("list//pricelist", "r");
            while ((ch = fgetc(file)) != EOF) {
                printf("%c", ch);
            }
            fclose(file);
        b=0;

    printf("\n*********************\n*Enter Total Product*\n*********************\n===");
    scanf("%d", &totalproduct);
      file = fopen("list//Bill.txt", "w");
fclose(file);

    for (id = 1; id <= totalproduct; id++) {
        printf("\n\n%d)", id);
          file = fopen("list//Bill.txt", "a+");
                fprintf(file,"\n\n%d)", id);

fclose(file);

        char ppFileName[20];
        sprintf(ppFileName, "data//%d.q.txt", id);
        file = fopen(ppFileName, "r");
        if (fscanf(file, "%d", &d) != 1) {fprintf(stderr, "Error reading data from file %s\n", ppFileName);}
            fclose(file);


            l += d;

            printf("    Left: %d", d);
            file = fopen("list//Bill.txt", "a+");
    fprintf(file,"Left: %d", d);
fclose(file);





            char tFileName[20];
            sprintf(tFileName, "data//%d.tq.txt", id);
            file = fopen(tFileName, "r");
            if (fscanf(file, "%d", &f) != 1) {fprintf(stderr, "Error reading data from file %s\n", tFileName);}
                fclose(file);
            K= f - d;
            totalitemsold += K;


                totalitem += f;
                printf("    Total: %d", f);
                printf("    Sold: %d", K);
                file = fopen("list//Bill.txt", "a+");
                fprintf(file,"    Total: %d", f);
                fprintf(file,"    Sold: %d", K);
fclose(file);


                char pFileName[20];
                sprintf(pFileName, "data//%d.price.txt", id);
                file = fopen(pFileName, "r");
                if (fscanf(file, "%d", &h) != 1) {fprintf(stderr, "Error reading data from file %s\n", pFileName);}
                printf("    Price: %d", h);
                fclose(file);
                 file = fopen("list//Bill.txt", "a+");
                fprintf(file,"    Price: %d", h);
fclose(file);

                char saleFileName[20];
                sprintf(saleFileName, "data//%d.sale.txt", id);
                file = fopen(saleFileName, "r");
                if (fscanf(file, "%d", &sale) != 1) {fprintf(stderr, "Error reading data from file %s\n", saleFileName);}
                j= K * sale;
                g+=j;
                printf("    Sale Price: %d", sale);
                fclose(file);
                   file = fopen("list//Bill.txt", "a+");
                fprintf(file,"    Sale Price: %d", sale);


                profit = sale - h;
                printf("    Profit: Rs. %d", profit);
                 fprintf(file,"    Profit: Rs. %d", profit);
                totalprofit = K* profit;
                printf("    Total Profit: Rs. %d", totalprofit);
                 fprintf(file,"    Total Profit: Rs. %d", totalprofit);
                overallprofit+=totalprofit;
                fclose(file);

            }


    printf("\n\n\n****************************************");
    printf("\nTotal Product-------------%d", totalitem);
    printf("\nTotal Sold-------------%d", totalitemsold);
    printf("\nTotal Left-------------%d", l);
    printf("\nTotal Cash-------------%d", g);
    printf("\nOverall Profit-------------%d", overallprofit);
    topay=g-overallprofit;
    printf("\nTo pay-------------%d", topay);
    printf("\n****************************************\n\n\n");

file = fopen("list//Bill.txt", "a+");
    fprintf(file,"\n\n\n****************************************");
    fprintf(file,"\n\n\n****************************************");
    fprintf(file,"\nTotal Product-------------%d", totalitem);
    fprintf(file,"\nTotal Sold-------------%d", totalitemsold);
    fprintf(file,"\nTotal Left-------------%d", l);
    fprintf(file,"\nTotal Cash-------------%d", g);
    fprintf(file,"\nOverall Profit-------------%d", overallprofit);
    fprintf(file,"\nTo pay-------------%d", topay);
    fprintf(file,"\n\n\n****************************************");
fclose(file);
do {
                printf("\n********************************\n\n1)Go Back\n2)Exit \n********************************\n===");
                scanf("%d", &p);
            } while (p != 1 && p != 2);
if(p==1){b=3;}else if(p==2){exit;};



}else if(a==4){
 system("CLS");
            printf("****************\n* Customer List *\n****************\n");
            file = fopen("list//customerlist", "r");
            while ((ch = fgetc(file)) != EOF) {
                printf("%c", ch);
            }
            fclose(file);

            do {
                printf("\n********************************\nDo you Want To Clear DATA?\n1)YES\n2)NO \n********************************\n===");
                scanf("%d", &b);
            } while (b != 1 && b != 2);

            if (b == 1) {
                file = fopen("list//customerlist", "w");
                fclose(file);
                printf("Your Data Is Cleared");
            }
            do {
                printf("\n********************************\n\n1)Go Back\n2)Exit \n********************************\n===");
                scanf("%d", &p);
            } while (p != 1 && p != 2);
if(p==1){b=3;}else if(p==2){exit;};










}else if(a==5){
    system("CLS");
    for(int r=0;r<5;r++){
            printf("                                                                   *****************************************\n");
            printf("                                                                   *           ITC Project                 *\n");
            printf("                                                                   * Members:                              *\n");
            printf("                                                                   * Mohammad Kumail Asghar---------2312244*\n");
            printf("                                                                   * Syed Mehdi Raza Rizvi----------2312244*\n");
                        printf("                                                                   * Instructor:                           *\n");
                        printf("                                                                   * Mohammad Ali Fatmi                    *\n");
            printf("                                                                   *****************************************\n");
    }

            do {
                printf("\n********************************\n\n1)Go Back\n2)Exit \n********************************\n===");
                scanf("%d", &p);
            } while (p != 1 && p != 2);
if(p==1){b=3;}else if(p==2){exit;};



             }else if(a==6){
                 int attempt,maxattempt=4,pin=786,attemptpin;

                 for(attempt=1;maxattempt>=attempt;attempt++){
                         system("CLS");
                         if(attempt>1){printf("                                                                                 Wrong Pin!              ");};
                          if(attempt==maxattempt){printf("                                                                                                Last Try!              ");};
            printf("\n                                                                   *****************************************\n");
            printf("                                                                   *              Locked!                  *\n");
            printf("                                                                   *          Kindly Enter Pin             *\n");
            printf("                                                                   *****************************************\n");
            printf("                                                                   === ");
            scanf("%d",&attemptpin);
            if(attemptpin==pin){attempt=10;};

                 }
 if(attemptpin==pin){
                            printf("                                                                   *************Access Granted!**************\n");
                    printf("                                                                   *****************************************\n");
            }else {printf("                                                                   ******************Blocked!**************\n");
                    printf("                                                                   *****************************************\n");
                    exit(0);
};
                system("CLS");

                printf("Do you really want to?If 'Yes' Press 1\n\n===");
                scanf("%d",&m);
if(m==1){



printf("\n\n");

const wchar_t *directoryPath = L"C:\\Users\\mkuma\\Documents\\C programs\\salebillingportal\\list";
if(RemoveDirectoryW(directoryPath)==1){q=1;};
directoryPath = L"C:\\Users\\mkuma\\Documents\\C programs\\salebillingportal\\data";
if(RemoveDirectoryW(directoryPath)==1){r=1;};
 if(q==1 || r==1){printf("Data and Directory Cleared!");}else{printf("Error in Clearing Data and Directory!");}
printf("\n\n");

 char folderpath[100];

sprintf(folderpath, "C:\\Users\\mkuma\\Documents\\C programs\\salebillingportal\\list");
    if(_mkdir(folderpath)==1){g=1;};
    sprintf(folderpath, "C:\\Users\\mkuma\\Documents\\C programs\\salebillingportal\\data");
    if(_mkdir(folderpath)==1){h=1;};
     if(h==1 || g==1){printf("New Directory Created!");}else{printf("Error Creating New Directory!");}

printf("\n\n");

}

             }   else if(a==7){     exit(0);
}
}while(b==3);

}
