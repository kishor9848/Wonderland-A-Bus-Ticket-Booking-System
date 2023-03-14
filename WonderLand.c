#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int main()
{
    user_main_menu();

}
int numcheak()
{
    int cheaked;
    while(scanf("%d",&cheaked) != 1)
    {

        while(getchar() != '\n');
    }

    return cheaked;
}

int user_main_menu()
{

    int sign_choice;


    do
    {
        system("cls");
        system("Color 30");
        printf("\n\n\n\n");
        printf("=======================================  Welcome To Wonderland Ticket Booking  =========================================\n");
        printf("========================================================================================================================\n");
        printf("\n\n");
        printf("                                             1. Sign In\n\n");
        printf("                                             2. Sign Up");
        printf("\n\n\n                  Enter your Choice (1/2):  ");

        sign_choice = numcheak();
    }
    while(sign_choice>2 ||sign_choice<1);


    if(sign_choice!=1)
        goto info_review_change_label;


user_jump: //////////////////////////////////////////////////////////////////////////////////////////////////////                                                                                  log in

    system("cls");
    system("Color 30");
    int join;
    char logid[50],logpass[50],logid1[50],logpass1[50];


    printf("\n\n\n\n");
    printf("===========================================  Welcome To Wonderland  ====================================================\n");
    printf("========================================================================================================================\n");
    printf("\n\n");
    printf("                                        Enter Your User ID:  ");
    scanf("%s", &logid);
    char user_part[300];
    int flag60=0;
    int f_f_flag=0;

    FILE *user_fp =fopen("User ID.txt","r");
    if(!user_fp)
    {
        printf("error:could not find the file");
        exit(0);
    }

    while(fgets(user_part,300,user_fp)!=NULL)
    {
        fgets(user_part,300,user_fp);
        if(strstr(user_part,logid)!=NULL)
            flag60=1;
    }
    if(flag60!=1)
        f_f_flag=1;


    printf("\n\n");
    printf("                                        Enter Your Password:  ");
    scanf("%s",&logpass);
    char user_po[300];   ////// check
    int flag50=0;
    int f_l_flag=0;

    FILE *user_fpl =fopen("Password.txt","r");
    if(!user_fpl)
    {
        printf("error:could not find the file");
        exit(0);
    }

    while(fgets(user_po,300,user_fpl)!=NULL)
    {
        fgets(user_po,300,user_fpl);
        if(strstr(user_po,logpass)!=NULL)
            flag50=1;
    }
    if(flag50!=1)
        f_l_flag=1;

    printf("\n\n");

    if(f_l_flag==0 && f_f_flag==0)
    {
        system("Color 3E");

        printf("                                        (^_^) Log In Successful! (^_^)\n");
        printf("\n\n");
        printf("========================================================================================================================\n");
        printf("\n\n");
        printf("                                          Why Still Waiting! Press Enter To Start Your Journey  .................. \n");
        getch();
        main_menu();
    }


    else if(f_l_flag==1 && f_f_flag==0)
    {
        system("Color 34");

        printf("\n\n                                        ('-')  Wrong Password!  ('.')");
        printf("\n\n");
        printf("========================================================================================================================\n\n\n\n");
        printf("                                                     Press Enter To Try Again .............................");
        getch();
        goto user_jump;
    }


    else if(f_l_flag==0 && f_f_flag==1)
    {
        system("Color 34");

        printf("\n\n                                        ('-')  Wrong User ID!  ('.')");
        printf("\n\n");
        printf("========================================================================================================================\n\n\n\n");
        printf("                                                     Press Enter To Try Again .............................");
        getch();
        goto user_jump;
    }
    else
    {
        system("Color 34");

        printf("                                    ('.') Sorry, Incorrect User ID & Password! ('.') \n");
        printf("\n\n");
        printf("========================================================================================================================\n");
        printf("\n\n");




        printf("                                  Did you not joined our family ?? \n");
        printf("\n\n");
        printf("                                 1=>>  I just need to try again.\n");
        printf("                                 2=>>  No, wanna join.\n");
        printf("\n");
        printf("                     Enter your choice (1/2):   ");
        do
        {
            join =numcheak();

        }
        while(join>2 ||join<1);

    }
    if(join==1)
        goto user_jump;


    char user_fullname[50],user_logemail[50],user_loguserid[50],user_loguserpass[50];
    int  user_idnumber;
info_review_change_label:

    system("cls");
    system("Color 70");
    printf("\n\n\n");
    printf("================   ID Set Up  ==========================================================================================\n\n\n");


    fflush(stdin);
    printf("  1. Enter your Full Name:  ");
    gets(user_fullname);


    printf("\n\n  2. Enter your Phone Number:  ");
    do
    {
        user_idnumber =numcheak();

    }
    while(user_idnumber<01300000000);


    printf("\n\n  3. Enter your User ID:  ");
    scanf("%s", &user_loguserid);


    printf("\n\n  4. Enter your Password:  ");
    scanf("%s", &user_loguserpass);


    printf("\n\n  5. Enter your Email:  ");
    scanf("%s", &user_logemail);

    int review_info;

    do
    {
        system("cls");
        system("Color 60");

        printf("\n\n");
        printf("================   Review You Information  =============================================================================\n\n\n");
        printf("  1. Your Name :%s",user_fullname);
        printf("\n  2. Your Number :%d", user_idnumber);
        printf("\n  3. User ID :%s", user_loguserid);
        printf("\n  4. Password :%s", user_loguserpass);
        printf("\n  5. Email :%s", user_logemail);
        printf("\n\n========================================================================================================================\n\n\n");
        printf("\n\n");
        printf("\n\n");

        printf("                                    Do you want to change your Info ? ");
        printf("\n\n                                    1. Yes. Done Some Mistake. ");
        printf("\n\n                                    2. No. Confirm This. ");
        printf("\n\n            Select your choice(1/2): ");
        do
        {
            review_info =numcheak();

        }
        while(review_info>2 ||review_info<1);
    }
    while(review_info>3);
    if(review_info==1)
        goto info_review_change_label;
    else
    {
        FILE *fp_user_info; /// user write

        fp_user_info=fopen("User ID.txt","a");

        fprintf(fp_user_info,"%s\t",user_loguserid);
        fclose(fp_user_info);

        FILE *fp_pass_info; //pass write

        fp_pass_info=fopen("Password.txt","a");

        fprintf(fp_pass_info,"%s\t",user_loguserpass);
        fclose(fp_pass_info);

        FILE *fp_userinfo_info; ///user info write

        fp_userinfo_info=fopen("User Info.txt","a");

        fprintf(fp_userinfo_info,"\n%s\t\t%d\t\t%s",user_fullname,user_idnumber,user_logemail);
        fclose(fp_userinfo_info);

        goto user_jump;
    }
}










void about()
{
    system("cls");
    system("Color 1d");
    printf("\n\n\n\n");
    printf("=======================================  Wonderland Bus Ticket Booking C Program =======================================\n");
    printf("========================================================================================================================\n");
    printf("\n\n");
    printf("                            This Is An Imaginary Bus Ticket Booking Program Created By Shourav Deb.");
    printf("\n\n\n                                   *  Here You Can Book A Ticket In A Snip For Your Destination.");
    printf("\n                                    *  You Can Recover Booked Ticket In-case Of Real One Lost. \n");
    printf("                                      *  Also, You Submit a Request To Cancel You Booking. \n");
    printf("                                        *  Additionally Can Calculate The Fair Cost.");
    printf("\n\n");
    printf("\n\n\n\n");
    printf("                                                                        >>>> [ Talk To Me: heyneeddev@gmail.com ] <<<<");
//    Author Info                                                                                                                                                                                                                                      Copyright © 2022 by Shourav Dev. All Rights Reserved.
    printf("\n\n");
    printf("\n\n");
    printf("");
    printf("\n\n");
    printf("                                                     Press Enter To Go Menu. .............................");
    getch();
    main_menu();


}




void ticketrecover()
{
    system("cls");
    system("Color 30");
    char bkashticket[50];
    printf("\n\n\n");
    printf("================   Ticket Recover   ===================================================================================\n\n\n");

    printf("\n\n\n");
    printf("    ==>> Enter Your Transaction ID Used For During Payment.");
    printf("\n\n\n    =}} ");
    scanf("%s",bkashticket);




    char bk[50];
    char chadd[60]=" no TxID Ticket.txt";


    strcpy(bk, bkashticket);
    strcat(bk, chadd);


    char fstr[500];
    FILE *fp;
    fp = fopen(bk, "r");
    if(fp==NULL)
    {
        system("Color 1C");
        printf("\n\n\n\n  >>>>>  No Ticket Has Been Booked Using This TxID. Come Back After Booking Any ....................");
        getch();
        main_menu();
    }
    else
    {
        system("cls");
        system("Color 30");
        fscanf(fp, "%[^\0]", fstr);
        printf("%s", fstr);
    }


    getch();
    main_menu();
}









////////////////////////////////////////////////////////////////          Menu Point          //////////////////////////////////////////////////////////////////////                                                                                                                                                                                                                                     Copyright © 2022 by Shourav Dev. All Rights Reserved.



int main_menu()
{
    int x;



    do
    {
        system("cls");
        system("Color 1B");
        printf("\n\n\n");
        printf("============================================          Main Menu          ============================================\n\n\n");
        printf("\n\n");
        printf("                                             (1)==> Book A Ticket.");
        printf("\n\n");
        printf("                                             (2)==> Recover Booked Ticket.");
        printf("\n\n");
        printf("                                             (3)==> Request Booking Cancellation.");
        printf("\n\n");
        printf("                                             (4)==> Calculate Journey Cost.");
        printf("\n\n");
        printf("                                             (5)==> About Us.");
        printf("\n\n");
        printf("                                             (6)==> Log Out.");
        printf("\n\n\n");
        printf("                   Enter your choice (1-6): ");
        do
        {
            x =numcheak();

        }
        while(x>6 ||x<1);


        switch(x)
        {
        case 1:
            book(); ///for booking a seat
            break;
        case 2: ///go to about
            ticketrecover();
            break;
        case 3:
            cancel(); ///for canceling a booking
            break;
        case 4:
            calculate (); ///for calculating bus cost
            break;
        case 5: ///go to about
            about();
            break;
        case 6: ///go to first page
            user_main_menu();
            break;
        }

        system("cls");
        getch();
    }

    while(x > 5);


    return 0;

}
char *readFile(char *filename)
{
    FILE *f = fopen(filename, "rt");
    assert(f);
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buffer = (char *) malloc(length + 1);
    buffer[length] = '\0';
    fread(buffer, 1, length, f);
    fclose(f);
    return buffer;
}




void book() //////////////////////////////////////////////////////////////////////////////////////////////////////////////////  booking
{
    int pick,x,y;
    int price;
    char get_on[40]="",off_point[40]="",tic_time[40]="",tic_ac[40]="";

    price=0;
    system("Color F");
    do
    {
        system("cls");
        system("Color 1B");
        printf("\n\n\n");
        printf("=============== Journey Start's ========================================================================================\n\n\n");
        printf("\n\n\n");
        printf("            (i)==>\tFrom Where You Want To Start Your Journey ?");
        printf("\n\n");
        printf("                        1.Dhaka.");
        printf("\n");
        printf("                        2.Chattogram.");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("    Enter your choice (1/2): ");
        do
        {
            pick =numcheak();

        }
        while(pick>2 ||pick<1);


    }
    while(pick>2);


    if(pick==1)
    {
        strcpy(get_on,"Dhaka");
        do
        {
            system("cls");
            system("Color 1B");
            printf("\n\n\n");
            printf("=============== Destination ============================================================================================\n\n\n");
            printf("\n\n\n");
            printf("            (ii)==>\tWhere You Want To Get Off ?");
            printf("\n\n");
            printf("                        1.Feni.");
            printf("\n");
            printf("                        2.Sitakund.");
            printf("\n");
            printf("                        3.Chattogram.");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("    Enter your choice (1/2/3): ");
            do
            {
                x =numcheak();

            }
            while(x>3 ||x<1);
        }
        while (x>3);
        if(x==1)
        {
            price=price+300;
            strcpy(off_point,"Feni");
        }
        else if(x==2)
        {
            strcpy(off_point,"Sitakund");
            price=price+400;
        }
        else
        {
            strcpy(off_point,"Chattogram");
            price=price+500;
        }

    }
    else if(pick==2)
    {
        strcpy(get_on,"Chattogram");
        do
        {
            system("cls");
            system("Color 1B");
            printf("\n\n\n");
            printf("=============== Destination ============================================================================================\n\n\n");
            printf("\n\n\n");
            printf("           (ii)==>\tWhere You Want To Get Off ?");
            printf("\n\n");
            printf("                        1.Sitakund.");
            printf("\n");
            printf("                        2.Feni.");
            printf("\n");
            printf("                        3.Dhaka.");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("    Enter your choice (1/2/3): ");
            do
            {
                y =numcheak();

            }
            while(y>3 ||y<1);
        }
        while (y>3);
        if(y==1)
        {
            strcpy(off_point,"Sitakund");
            price=price+300;
        }
        else if(y==2)
        {
            price=price+400;
            strcpy(off_point,"Feni");
        }
        else
        {
            strcpy(off_point,"Dhaka");
            price=price+500;
        }

    }


    int z;
    do
    {
        system("cls");
        system("Color 1B");
        printf("\n\n\n");
        printf("============== Time For Ride ===========================================================================================\n\n\n");
        printf("\n\n\n");
        printf("        (iii)==>\tWhich Time You Want To Enjoy Your Ride ?");
        printf("\n\n");
        printf("                        1.Day Time. (Departure at sharp 12 PM)");
        printf("\n");
        printf("                        2.Night Time. (Departure at sharp 12 PM)");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("    Enter your choice (1/2): ");
        do
        {
            z =numcheak();

        }
        while(z>2 ||z<1);
    }
    while(z>2);

    if(z==1)
    {
        printf("");
        strcpy(tic_time,"Day_Shift_[Sharp_at_12_P.M.].");
    }
    else
    {
        printf("");
        strcpy(tic_time,"Night_Shift_[Sharp_at_12_A.M.].");
    }


    int w;                    ///  AC / Non AC
    do
    {
        system("cls");
        system("Color 1B");
        printf("\n\n\n");
        printf("================ AC / Non AC ===========================================================================================\n\n\n");
        printf("\n\n\n");
        printf("        (iv)==>\t\tWhich Ride Do You Want To Enjoy ?");
        printf("\n\n");
        printf("                        1.AC.");
        printf("\n");
        printf("                        2.Non AC.");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("    Enter your choice (1/2): ");
        do
        {
            w =numcheak();

        }
        while(w>2 ||w<1);
    }
    while(w>2);

    if(w==1)
    {
        price=price+700;
        strcpy(tic_ac,"Full_AC_Bus.");
    }
    else
    {
        price=price+100;
        strcpy(tic_ac,"Non-AC_Bus.");
    }

    int total;
jump_to_book:
total1:
    system("cls");
    system("Color 1B");
    printf("\n\n\n");
    printf("=============== Journey Partner's ======================================================================================\n\n\n");
    printf("\n\n\n        (v)==>\tHow Many Ticket You Want To Book: ");
    do
    {
        total =numcheak();

        if(total<6)
    {
        price=price*total;
    }
    else
    {
        printf("\n\n       ('.') Sorry, One person can book total 5 seats at a time.");
        printf("\n\n                                     If you want to book full bus please contact us physically.");
        printf("\n\n                                                           Otherwise, press enter to select again.   ..................");
        getch();
        goto total1;

    }

    }
    while(total>5 || total<1);



    printf("\n\n\n\n\n                            {'-'}    Press Enter To Book Seats ....................");
    getch();


// Bus sit list

    if(w==1 && z==1 && pick==2) // AC_Day_C_Dhaka
    {
        system("cls");
        char copy[2];
        int m=0;
        printf("\t       Chattogram To Dhaka (AC Service)\n");
        printf("\t   --------------------------------------\n\n");
        FILE *file;
        file=fopen("AC_Day_C_Dhaka.txt","r");
        while(!feof(file))
        {
            fscanf(file,"%s",copy);
            printf("\t%s",copy);
            m++;
            if(m==4 || m==8 || m== 12 || m==16 || m== 20 || m==24 || m== 28 || m==32 || m== 36)
                printf("\n");
        }
        fclose(file);
    }

    else if(w==1 && z==1 && pick==1) // AC_Day_Dhaka_C
    {
        system("cls");
        char copy[2];
        int m=0;
        printf("\t       Dhaka To Chattogram (AC Service)\n");
        printf("\t     -----------------------------------\n\n");
        FILE *file;
        file=fopen("AC_Day_Dhaka_C.txt","r");
        while(!feof(file))
        {
            fscanf(file,"%s",copy);
            printf("\t%s",copy);
            m++;
            if(m==4 || m==8 || m== 12 || m==16 || m== 20 || m==24 || m== 28 || m==32 || m== 36)
                printf("\n");
            else
                printf("\t");
        }
        fclose(file);
    }

    else if(w==1 && z==2 && pick==2) // AC_Night_C_Dhaka
    {
        system("cls");
        char copy[2];
        int m=0;
        printf("\t       Chattogram To Dhaka (AC Service)\n");
        printf("\t   --------------------------------------\n\n");
        FILE *file;
        file=fopen("AC_Night_C_Dhaka.txt","r");
        while(!feof(file))
        {
            fscanf(file,"%s",copy);
            printf("\t%s",copy);
            m++;
            if(m==4 || m==8 || m== 12 || m==16 || m== 20 || m==24 || m== 28 || m==32 || m== 36)
                printf("\n");
        }
        fclose(file);
    }

    else if(w==1 && z==2 && pick==1) // AC_Night_Dhaka_C
    {
        system("cls");
        char copy[2];
        int m=0;
        printf("\t       Dhaka To Chattogram (AC Service)\n");
        printf("\t   --------------------------------------\n\n");
        FILE *file;
        file=fopen("AC_Night_Dhaka_C.txt","r");
        while(!feof(file))
        {
            fscanf(file,"%s",copy);
            printf("\t%s",copy);
            m++;
            if(m==4 || m==8 || m== 12 || m==16 || m== 20 || m==24 || m== 28 || m==32 || m== 36)
                printf("\n");
        }
        fclose(file);
    }

    else if(w==2 && z==1 && pick==2) // Non AC_Day_C_Dhaka
    {
        system("cls");
        char copy[2];
        int m=0;
        printf("\t        Chattogram To Dhaka\n");
        printf("\t   ----------------------------\n\n");
        FILE *file;
        file=fopen("Non AC_Day_C_Dhaka.txt","r");
        while(!feof(file))
        {
            fscanf(file,"%s",copy);
            printf("\t%s",copy);
            m++;
            if(m==4 || m==8 || m== 12 || m==16 || m== 20 || m==24 || m== 28 || m==32 || m== 36)
                printf("\n");
        }
        fclose(file);
    }

    else if(w==2 && z==1 && pick==1) // Non AC_Day_Dhaka_C
    {
        system("cls");
        char copy[2];
        int m=0;
        printf("\t       Dhaka To Chattogram\n");
        printf("\t   ----------------------------\n\n");
        FILE *file;
        file=fopen("Non AC_Day_Dhaka_C.txt","r");
        while(!feof(file))
        {
            fscanf(file,"%s",copy);
            printf("\t%s",copy);
            m++;
            if(m==4 || m==8 || m== 12 || m==16 || m== 20 || m==24 || m== 28 || m==32 || m== 36)
                printf("\n");
        }
        fclose(file);
    }

    else if(w==2 && z==2 && pick==2) // Non AC_Night_C_Dhaka
    {
        system("cls");
        char copy[2];
        int m=0;
        printf("\t        Chattogram To Dhaka\n");
        printf("\t   ----------------------------\n\n");
        FILE *file;
        file=fopen("Non AC_Night_C_Dhaka.txt","r");
        while(!feof(file))
        {
            fscanf(file,"%s",copy);
            printf("\t%s",copy);
            m++;
            if(m==4 || m==8 || m== 12 || m==16 || m== 20 || m==24 || m== 28 || m==32 || m== 36)
                printf("\n");
        }
        fclose(file);
    }


    else if(w==2 && z==2 && pick==1) // Non AC_Night_Dhaka_C
    {
        system("cls");
        char copy[2];
        int m=0;
        printf("\t       Dhaka To Chattogram\n");
        printf("\t   ----------------------------\n\n");
        FILE *file;
        file=fopen("Non AC_Night_Dhaka_C.txt","r");
        while(!feof(file))
        {
            fscanf(file,"%s",copy);
            printf("\t%s",copy);
            m++;
            if(m==4 || m==8 || m== 12 || m==16 || m== 20 || m==24 || m== 28 || m==32 || m== 36)
                printf("\n");
        }
        fclose(file);
    }

//bus sit list done
    system("Color 1B");
    printf("\n\n\n");
    int a[6];
    printf("\n\n## Enter your sit numbers _ (Don't Enter The Booked Seat Number / Incorrect Seat Number / Same Seat Number.)\n");
    printf("                                                          Otherwise, we will cancel those. \n");
    for(int i=1; i<total+1; i++ )
    {
        printf("\n  >> Number %d ticket: ",i );
        do
        {
            a[i] =numcheak();
            if(a[i]>=60 || a[i]<21 ||  a[i] == 50 || a[i] == 40 || a[i] == 30)
                printf("\n\t\tIncorrect Input!\n\n");

        }
        while(a[i]>=60 || a[i]<21 ||  a[i] == 50 || a[i] == 40 || a[i] == 30);
    }


    system("cls");
    system("Color 70");
    char dummy[10],fullname_detail[50],email_detail[50];
    int number_detail=0;


    printf("\n\n\n");
    printf("=============== Enter Your Details =================================================================================\n\n\n");
    printf("\n");
    gets(dummy);
    printf("       Full Name: ");
    gets(fullname_detail);
    printf("\n\n       Contact Number : ");
    do
    {
        number_detail =numcheak();

    }
    while(number_detail<01300000000);
    printf("\n\n       Email Address: ");
    scanf("%s",&email_detail);

    system("cls");
    system("Color 60");
    printf("\n\n\n");
    printf("=============== Review Your Details ===================================================================================\n\n\n");
    printf("\n\n      Name: ");
    puts(fullname_detail);
    printf("\n      Contact Number : %d.",number_detail);
    printf("\n\n      Email Address: %s.",email_detail);
    printf("\n\n      Total Seats: %d [Seat no ( ",total);
    for(int i=1; i<total+1; i++ )
        printf("%d ",a[i]);
    printf(")].");
    printf("\n\n\n=======================================================================================================================\n\n\n");


    printf("\n\n                           [^_^] Press enter after your review .................");
    getch();

    int rdetail;
    do
    {
        system("cls");
        system("Color 1B");
        printf("\n\n\n");
        printf("================ Wanna Change / Unchange ===============================================================================\n\n\n");
        printf("\n\n\n");
        printf("        (^_^)\tDo You Want To Change Your Details ?");
        printf("\n\n");
        printf("                        1.I Want To Resubmit. (^~^)");
        printf("\n");
        printf("                        2.No, Confirm It. (^-^)");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("    Enter your choice (1/2): ");
        do
        {
            rdetail =numcheak();

        }
        while(rdetail>2 || rdetail<1);
    }
    while(rdetail>2);

    if(rdetail==1)
        goto jump_to_book;



    printf("\n\n\n\n          [^_^]   That's nice. Then press enter to confirm with payment .................");
    getch();

fake:
    system("cls");
    system("Color 1F");
    char bkash[50];

    printf("\n\n\n");
    printf("================   Payment   ==========================================================================================\n\n\n");

    printf("\n\n\n");
    printf("    ==>> Send %d tk to 01700000000 using Bkash. After Payment Enter Your Transaction ID (It will show aside of TrxID).",price);
    printf("\n\n\n    =}} ");
    scanf("%s",&bkash);


    /// Cheak Transaction ID
    char part[300];
    int flag=0;

    FILE *fp =fopen("Transaction ID.txt","r");
    if(!fp)
    {
        printf("error:could not find the file");
        exit(0);
    }

    while(fgets(part,300,fp)!=NULL)
    {
        fgets(part,300,fp);
        if(strstr(part,bkash)!=NULL)
            flag=1;
    }
    if(flag==1)
        goto match;
    else
    {
        system("Color 1C");
        printf("\n\n\t\t [*_*] It seems to be a forgery transaction ID. Press enter to try with valid TrxID ................");
        getch();
        goto fake;
    }







match:
    //working
    system ("cls");


    system("Color  12");
    printf("Please wait,Processing your booking.");

    for(int load=0; load<101; load++)
    {
        printf("\n\n\n");
        printf(" ['.'] Please wait, Processing your booking >>>>>>\n\n");
        printf("            %d %% Completed ...",load);
        if(load<100)
            system ("cls");
    }

    system("Color 1E");
    printf("\n\n\n");
    printf("\t\t\t\t\t [^-^] Press Enter To Get Your Ticket ...........");
    getch();

    ///   Ticket

    system("cls");

    system("Color  1A");
    printf("\n\n\n");
    printf("==========================================        Ticket        ======================================================\n\n\n");

    printf("                                                 %s To %s\n",get_on,off_point);
    printf("                                         ______________________________");

    printf("\n\n                           Name: ");
    puts(fullname_detail);
    printf("\n                           Contact Number : %d. \t\t         Email Address: %s.",number_detail,email_detail);
    printf("\n\n                           Departure Time : %s \t Bus Type: %s     ",tic_time,tic_ac);
    printf("\n\n\n                          Paid: %d                         \t Total Seats: %d [Seat no( ",price,total);
    for(int i=1; i<total+1; i++ )
        printf("%d ",a[i]);
    printf(")].");
    printf("\n\n\n====================================================================================================================\n\n\n");

    printf("                            [^_^]  Enjoy Your Journey  [^_^]\n\n");
    printf("                                                [____] Take A Screen Shot Of The Ticket  [____]");

    printf("\n\n                                                           Press Enter To Go Main Menu .................");
    getch();


    char bus_type[10]="";




    char bk[50];
    char chadd[60]=" no TxID Ticket.txt";


    strcpy(bk, bkash);
    strcat(bk, chadd);

    FILE *file3;
    file3=fopen(bk,"w");

    fprintf(file3, "\n\n\n==========================================        Ticket        ======================================================\n\n\n");

    fprintf(file3, "                                                 %s To %s\n",get_on,off_point);
    fprintf(file3, "                                         ______________________________");

    fprintf(file3, "\n\n                           Name: ");
    fputs(file3, fullname_detail);
    fprintf(file3, "\n                           Contact Number : %d. \t\t         Email Address: %s.",number_detail,email_detail);
    fprintf(file3, "\n\n                           Departure Time : %s \t Bus Type: %s     ",tic_time,tic_ac);
    fprintf(file3, "\n\n\n                          Paid: %d                         \t Total Seats: %d [Seat no( ",price,total);
    for(int i=1; i<total+1; i++ )
        fprintf(file3, "%d ",a[i]);
    fprintf(file3, ")].");
    fprintf(file3, "\n\n\n====================================================================================================================\n\n\n");

    fprintf(file3, "                            [^_^]  Enjoy Your Journey  [^_^]\n\n");
    fclose(file3);
/// File input
    if(w==1 && z==1 && pick==2) // AC_Day_C_Dhaka
        strcpy(bus_type,"[1]");
    else if(w==1 && z==1 && pick==1) // AC_Day_Dhaka_C
        strcpy(bus_type,"[2]");
    else if(w==1 && z==2 && pick==2) // AC_Night_C_Dhaka
        strcpy(bus_type,"[3]");
    else if(w==1 && z==2 && pick==1) // AC_Night_Dhaka_C
        strcpy(bus_type,"[4]");
    else if(w==2 && z==1 && pick==2) // Non AC_Day_C_Dhaka
        strcpy(bus_type,"[5]");
    else if(w==2 && z==1 && pick==1) // Non AC_Day_Dhaka_C
        strcpy(bus_type,"[6]");
    else if(w==2 && z==2 && pick==2) // Non AC_Night_C_Dhaka
        strcpy(bus_type,"[7]");
    else if(w==2 && z==2 && pick==1) // Non AC_Night_Dhaka_C
        strcpy(bus_type,"[8]");






    FILE *file;

    file=fopen("Ticket Details.txt","a");

    fprintf(file,"\n%s\t%s\t%d\t%s\t%d\t%s",bkash,bus_type,total,fullname_detail,number_detail,email_detail);
    fclose(file);





    FILE *fp2;
    fp2=fopen("Ticket Details.txt","a");
    fprintf(file,"\t");
    for(int i=1; i<total+1; i++)
        fprintf(file,"%d, ",a[i]);

    fclose(file);






    if(strcmp(bus_type, "[1]") == 0)
    {
        for(int i=1; i<total+1; i++)
        {

            char *content = readFile("AC_Day_C_Dhaka.txt");

            char c[20];
            sprintf(c, "%d", a[i]);
            char d[] = "XX";
            char f[] = "AC_Day_C_Dhaka.txt";

            Replace(content, c, d, f);
        }
    }

    if(strcmp(bus_type, "[2]") == 0)
    {
        for(int i=1; i<total+1; i++)
        {

            char *content = readFile("AC_Day_Dhaka_C.txt");

            char c[20];
            sprintf(c, "%d", a[i]);
            char d[] = "XX";
            char f[] = "AC_Day_Dhaka_C.txt";

            Replace(content, c, d, f);
        }
    }

    if(strcmp(bus_type, "[3]") == 0)
    {
        for(int i=1; i<total+1; i++)
        {

            char *content = readFile("AC_Night_C_Dhaka.txt");

            char c[20];
            sprintf(c, "%d", a[i]);
            char d[] = "XX";
            char f[] = "AC_Night_C_Dhaka.txt";

            Replace(content, c, d, f);
        }
    }

    if(strcmp(bus_type, "[4]") == 0)
    {
        for(int i=1; i<total+1; i++)
        {

            char *content = readFile("AC_Night_Dhaka_C.txt");

            char c[20];
            sprintf(c, "%d", a[i]);
            char d[] = "XX";
            char f[] = "AC_Night_Dhaka_C.txt";

            Replace(content, c, d, f);
        }
    }

    if(strcmp(bus_type, "[5]") == 0)
    {
        for(int i=1; i<total+1; i++)
        {

            char *content = readFile("Non AC_Day_C_Dhaka.txt");

            char c[20];
            sprintf(c, "%d", a[i]);
            char d[] = "XX";
            char f[] = "Non AC_Day_C_Dhaka.txt";

            Replace(content, c, d, f);
        }
    }

    if(strcmp(bus_type, "[6]") == 0)
    {
        for(int i=1; i<total+1; i++)
        {

            char *content = readFile("Non AC_Day_Dhaka_C.txt");

            char c[20];
            sprintf(c, "%d", a[i]);
            char d[] = "XX";
            char f[] = "Non AC_Day_Dhaka_C.txt";

            Replace(content, c, d, f);
        }
    }

    if(strcmp(bus_type, "[7]") == 0)
    {
        for(int i=1; i<total+1; i++)
        {

            char *content = readFile("Non AC_Night_C_Dhaka.txt");

            char c[20];
            sprintf(c, "%d", a[i]);
            char d[] = "XX";
            char f[] = "Non AC_Night_C_Dhaka.txt";

            Replace(content, c, d, f);
        }
    }

    if(strcmp(bus_type, "[8]") == 0)
    {
        for(int i=1; i<total+1; i++)
        {

            char *content = readFile("Non AC_Night_Dhaka_C.txt");

            char c[20];
            sprintf(c, "%d", a[i]);
            char d[] = "XX";
            char f[] = "Non AC_Night_Dhaka_C.txt";

            Replace(content, c, d, f);
        }
    }




















/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    main_menu();

}

void Replace(const char *text, const char *oldWord, const char *newWord, const char *files)
{
    int i = 0, cnt = 0;
    int len1 = strlen(newWord);
    int len2 = strlen(oldWord);
    for (i = 0; text[i]!='\0'; i++)
    {
        if (strstr(&text[i], oldWord) == &text[i])
        {
            cnt++;
            i += len2 - 1;
        }
    }
    char *newString = (char *)malloc(i + cnt * (len1 - len2) + 1);
    i = 0;
    while (*text)
    {
        if (strstr(text, oldWord) == text)
        {
            strcpy(&newString[i], newWord);
            i += len1;
            text += len2;
        }
        else
            newString[i++] = *text++;
    }
    char array2[120];
    strncpy(array2, newString, 119);

    FILE *fp;

    fp = fopen(files, "w");
    fprintf(fp, array2);
    fclose(fp);
}




void cancel()
{
fake22:

    system("cls");
    char cancel_trx[100];
    system("Color 1B");
    printf("\n\n\n");
    printf("=============== Booking Cancellation Submitting =====================================================================================\n\n\n");
    printf("\n\n\n");
    printf("            (i)==>    Enter Your Ticket TrxID: ");
    scanf("%s",&cancel_trx);
    char part111[300];
    int flager=0;

    FILE *fp111 =fopen("Transaction ID.txt","r");
    if(!fp111)
    {
        printf("error:could not find the file");
        exit(0);
    }

    while(fgets(part111,300,fp111)!=NULL)
    {
        fgets(part111,300,fp111);
        if(strstr(part111,cancel_trx)!=NULL)
            flager=1;
    }
    if(flager==1)
    {
        FILE *file;

        file = fopen("Booking Cancel Req.txt","a");

        fprintf(file,"\n%s",cancel_trx);
        fclose(file);
        goto match111;
    }
    else
    {
        system("Color 1C");
        printf("\n\n\t\t [*_*] It seems to be a forgery transaction ID. Press enter to try with valid TrxID ................");
        getch();
        goto fake22;
    }

match111:



    printf("\n\n\n");
    printf("         ==>    Your Request Has Been Submitted. Soon, You Will Be Contacted.");
    getch();
    main_menu();
}







void calculate()                                          ///                  cost       calculator
{
    int pickera,c_x,c_y;
    int priceey;
    priceey=0;
    do
    {
        system("cls");
        printf("\n\n\n");
        printf("=============== Journey Start's ========================================================================================\n\n\n");
        printf("\n\n\n");
        printf("            (i)==>    From Where You Want To Start Your Journey?");
        printf("\n\n");
        printf("                            1.Dhaka.");
        printf("\n");
        printf("                            2.Chattogram.");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("    Enter your choice (1/2): ");
        do
        {
            pickera =numcheak();

        }
        while(pickera>2 || pickera<1);


    }
    while(pickera>2);


    if(pickera==1)
    {
        do
        {
            system("cls");
            printf("\n\n\n");
            printf("=============== Destination ============================================================================================\n\n\n");
            printf("\n\n\n");
            printf("            (ii)==>    Where You Want To Get Off ?");
            printf("\n\n");
            printf("                        1.Feni.");
            printf("\n");
            printf("                        2.Sitakund.");
            printf("\n");
            printf("                        3.Chattogram.");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("    Enter your choice (1/2/3): ");
            do
            {
                c_x =numcheak();

            }
            while(c_x>3 || c_x<1);
        }
        while (c_x>3);
        if(c_x==1)
            priceey=priceey+300;
        else if(c_x==2)
            priceey=priceey+400;
        else
            priceey=priceey+500;

    }
    else if(pickera==2)
    {
        do
        {
            system("cls");
            printf("\n\n\n");
            printf("=============== Destination ============================================================================================\n\n\n");
            printf("\n\n\n");
            printf("           (ii)==>    Where You Want To Get Off  ?");
            printf("\n\n");
            printf("                        1.Sitakund.");
            printf("\n");
            printf("                        2.Feni.");
            printf("\n");
            printf("                        3.Dhaka.");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("    Enter your choice (1/2/3): ");
            do
            {
                c_y =numcheak();

            }
            while(c_y>3 || c_y<1);
        }
        while (c_y>3);
        if(c_y==1)
            priceey=priceey+300;
        else if(c_y==2)
            priceey=priceey+400;
        else
            priceey=priceey+500;

    }


    int c_z;
    do
    {
        system("cls");
        printf("\n\n\n");
        printf("============== Time For Ride ===========================================================================================\n\n\n");
        printf("\n\n\n");
        printf("        (iii)==>   Which Time You Want To Enjoy Your Ride ?");
        printf("\n\n");
        printf("                        1.Day Time. (Departure at sharp 12 PM)");
        printf("\n");
        printf("                        2.Night Time. (Departure at sharp 12 PM)");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("    Enter your choice (1/2): ");
        do
        {
            c_z =numcheak();

        }
        while(c_z>2 || c_z<1);
    }
    while(c_z>2);


    int c_w;                    ///  AC / Non AC
    do
    {
        system("cls");
        printf("\n\n\n");
        printf("================ AC / Non AC ===========================================================================================\n\n\n");
        printf("\n\n\n");
        printf("        (iv)==>   Which Ride Do You Want To Enjoy ? ?");
        printf("\n\n");
        printf("                        1.AC.");
        printf("\n");
        printf("                        2.Non AC.");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("    Enter your choice (1/2): ");
        do
        {
            c_w =numcheak();

        }
        while(c_w>2 || c_w<1);
    }
    while(c_w>2);

    if(c_w==1)
        priceey=priceey+700;
    else
        priceey=priceey+100;

    int total_x_y;
total1_x:
    system("cls");
    printf("\n\n\n");
    printf("=============== Journey Partner's ======================================================================================\n\n\n");
    printf("\n\n\n        (v)==>      How Many Ticket You Want To Book: ");
    do
    {
        total_x_y = numcheak();
        if(total_x_y<6)
        priceey=priceey*total_x_y;
    else
    {
        printf("\n\n       ('.') Sorry, One person can book total 5 seats at a time.");
        printf("\n\n                                     If you want to book full bus please contact us physically.");
        printf("\n\n                                                           Otherwise, press enter to select again. ..................");
        getch();
        goto total1_x;

    }

    }
    while(total_x_y>5 || total_x_y<1);




    system("cls");
    printf("\n\n\n");
    printf("=============== Total Cost ============================================================================================\n\n\n");

    printf("\n\n\n        Your Total Cost Will Be: %d tk. Thank You.",priceey);



    printf("\n\n\n        To Get Upto 20% Discount Get Our Membership At Any Outlet.",priceey);
    priceey=0;
    printf("\n\n\n\n\n                                    Press enter to go main menu ....................");
    getch();
    main_menu();
}
































