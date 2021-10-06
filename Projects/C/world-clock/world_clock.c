//World Clock UCT (Universal Coordinated Time)
//Muhammad Saud Zahir.

#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    char C[40];
    printf("Enter the Country Name: ");
    scanf("%s", &C);
     time_t t;
     struct tm *ptm;
     time (&t);
     ptm = gmtime (&t);
     system("COLOR B1");

    if (strcmp(C, "Afghanistan") == 0)
    {
       printf ("\t\t\t\t\t Afghanistan:     %2d:%02d:%02d\n",(ptm->tm_hour+4)%24,(ptm->tm_min+30)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Albania") == 0)
    {
       printf ("\t\t\t\t\t Albania:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Algeria") == 0)
    {
       printf ("\t\t\t\t\t Algeria:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Angola") == 0)
    {
       printf ("\t\t\t\t\t Angola:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Andorra") == 0)
    {
       printf ("\t\t\t\t\t Andorra:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Antigua-and-Barbuda") == 0)
    {
       printf ("\t\t\t\t\t Antigua and Barbuda:     %2d:%02d:%02d\n",(ptm->tm_hour-4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Argentina") == 0)
    {
       printf ("\t\t\t\t\t Argentina:     %2d:%02d:%02d\n",(ptm->tm_hour-3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Armenia") == 0)
    {
       printf ("\t\t\t\t\t Armenia:     %2d:%02d:%02d\n",(ptm->tm_hour+4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Australia") == 0)
    {
       printf ("\t\t\t\t\t Australia(Canberra):     %2d:%02d:%02d\n",(ptm->tm_hour+11)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Algeria") == 0)
    {
       printf ("\t\t\t\t\t Algeria:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Austria") == 0)
    {
       printf ("\t\t\t\t\t Austria:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Azerbaijan") == 0)
    {
       printf ("\t\t\t\t\t Azerbaijan:     %2d:%02d:%02d\n",(ptm->tm_hour+4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Bahamas") == 0)
    {
       printf ("\t\t\t\t\t Bahamas:     %2d:%02d:%02d\n",(ptm->tm_hour-5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Bahrain") == 0)
    {
       printf ("\t\t\t\t\t Bahrain:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Bangladesh") == 0)
    {
       printf ("\t\t\t\t\t Bangladesh:     %2d:%02d:%02d\n",(ptm->tm_hour+6)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Barbados") == 0)
    {
       printf ("\t\t\t\t\t Barbados:     %2d:%02d:%02d\n",(ptm->tm_hour-4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Belarus") == 0)
    {
       printf ("\t\t\t\t\t Belarus:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Belgium") == 0)
    {
       printf ("\t\t\t\t\t Belgium:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Belize") == 0)
    {
       printf ("\t\t\t\t\t Belize:     %2d:%02d:%02d\n",(ptm->tm_hour-6)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Benin") == 0)
    {
       printf ("\t\t\t\t\t Benin:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Bhutan") == 0)
    {
       printf ("\t\t\t\t\t Bhutan:     %2d:%02d:%02d\n",(ptm->tm_hour+6)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Bolivia") == 0)
    {
       printf ("\t\t\t\t\t Bolivia:     %2d:%02d:%02d\n",(ptm->tm_hour-4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Bosnia-and-Herzegovina") == 0)
    {
       printf ("\t\t\t\t\t Bosnia and Herzegovina:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Botswana") == 0)
    {
       printf ("\t\t\t\t\t Botswana:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Brazil") == 0)
    {
       printf ("\t\t\t\t\t Brazil (Brasilia):     %2d:%02d:%02d\n",(ptm->tm_hour-3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Brunei") == 0)
    {
       printf ("\t\t\t\t\t Brunei:     %2d:%02d:%02d\n",(ptm->tm_hour+8)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Brunei") == 0)
    {
       printf ("\t\t\t\t\t Brunei:     %2d:%02d:%02d\n",(ptm->tm_hour+8)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Bulgaria") == 0)
    {
       printf ("\t\t\t\t\t Bulgaria:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Burkina-Faso") == 0)
    {
       printf ("\t\t\t\t\t Burkina-Faso:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Burundi") == 0)
    {
       printf ("\t\t\t\t\t Burundi:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Burundi") == 0)
    {
       printf ("\t\t\t\t\t Burundi:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Cabo-verde") == 0)
    {
       printf ("\t\t\t\t\t Cabo Verde:     %2d:%02d:%02d\n",(ptm->tm_hour-1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Cambodia") == 0)
    {
       printf ("\t\t\t\t\t Cambodia:     %2d:%02d:%02d\n",(ptm->tm_hour+7)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Cameroon") == 0)
    {
       printf ("\t\t\t\t\t Cameroon:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Canada") == 0)
    {
       printf ("\t\t\t\t\t Canada (Ottawa):     %2d:%02d:%02d\n",(ptm->tm_hour-5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "CAR") == 0)
    {
       printf ("\t\t\t\t\t CAR:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Chad") == 0)
    {
       printf ("\t\t\t\t\t Chad:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Chile") == 0)
    {
       printf ("\t\t\t\t\t Chile (Santiago):     %2d:%02d:%02d\n",(ptm->tm_hour-3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "China") == 0)
    {
       printf ("\t\t\t\t\t China:     %2d:%02d:%02d\n",(ptm->tm_hour+8)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Colombia") == 0)
    {
       printf ("\t\t\t\t\t Colombia:     %2d:%02d:%02d\n",(ptm->tm_hour-5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Comoros") == 0)
    {
       printf ("\t\t\t\t\t Comoros:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Congo") == 0)
    {
       printf ("\t\t\t\t\t Congo (Kinshasa):     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Costa-Rica") == 0)
    {
       printf ("\t\t\t\t\t Costa Rica:     %2d:%02d:%02d\n",(ptm->tm_hour-6)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Cote-d'Ivoire") == 0)
    {
       printf ("\t\t\t\t\t Cote d'Ivoire:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Croatia") == 0)
    {
       printf ("\t\t\t\t\t Croatia:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Cuba") == 0)
    {
       printf ("\t\t\t\t\t Cuba:     %2d:%02d:%02d\n",(ptm->tm_hour-5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Cyprus") == 0)
    {
       printf ("\t\t\t\t\t Cyprus:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Czech") == 0)
    {
       printf ("\t\t\t\t\t Czech:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Denmark") == 0)
    {
       printf ("\t\t\t\t\t Denmark:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Denmark") == 0)
    {
       printf ("\t\t\t\t\t Denmark:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Djibouti") == 0)
    {
       printf ("\t\t\t\t\t Djibouti:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Dominica") == 0)
    {
       printf ("\t\t\t\t\t Dominica:     %2d:%02d:%02d\n",(ptm->tm_hour-4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Ecuador") == 0)
    {
       printf ("\t\t\t\t\t Ecuador (Quito):     %2d:%02d:%02d\n",(ptm->tm_hour-5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Egypt") == 0)
    {
       printf ("\t\t\t\t\t Egypt:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "El-Salvador") == 0)
    {
       printf ("\t\t\t\t\t El Salvador:     %2d:%02d:%02d\n",(ptm->tm_hour-6)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Guinea") == 0)
    {
       printf ("\t\t\t\t\t Guinea (Equatorial):     %2d:%02d:%02d\n",(ptm->tm_hour)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Eritrea") == 0)
    {
       printf ("\t\t\t\t\t Eritrea:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Estonia") == 0)
    {
       printf ("\t\t\t\t\t Estonia:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Eswatini") == 0 || strcmp(C, "Swaziland") == 0)
    {
       printf ("\t\t\t\t\t Eswatini (Swaziland):     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Ethiopia") == 0)
    {
       printf ("\t\t\t\t\t Ethiopia:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Gabon") == 0)
    {
       printf ("\t\t\t\t\t Gabon:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Gambia") == 0)
    {
       printf ("\t\t\t\t\t Gambia:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Georgia") == 0)
    {
       printf ("\t\t\t\t\t Georgia(U.S.A.):     %2d:%02d:%02d\n",(ptm->tm_hour-5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Germany") == 0)
    {
       printf ("\t\t\t\t\t Germany:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Ghana") == 0)
    {
       printf ("\t\t\t\t\t Ghana:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Greece") == 0)
    {
       printf ("\t\t\t\t\t Greece:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Grenada") == 0)
    {
       printf ("\t\t\t\t\t Grenada:     %2d:%02d:%02d\n",(ptm->tm_hour-4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Guatemala") == 0)
    {
       printf ("\t\t\t\t\t Guatemala:     %2d:%02d:%02d\n",(ptm->tm_hour-6)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Guinea-Bissau") == 0)
    {
       printf ("\t\t\t\t\t Guinea-Bissau:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Guyana") == 0)
    {
       printf ("\t\t\t\t\t Guyana:     %2d:%02d:%02d\n",(ptm->tm_hour-4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Haiti") == 0)
    {
       printf ("\t\t\t\t\t Haiti:     %2d:%02d:%02d\n",(ptm->tm_hour-5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Honduras") == 0)
    {
       printf ("\t\t\t\t\t Honduras:     %2d:%02d:%02d\n",(ptm->tm_hour-6)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Hungary") == 0)
    {
       printf ("\t\t\t\t\t Hungary:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Iceland") == 0)
    {
       printf ("\t\t\t\t\t Iceland:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "India") == 0)
    {
       printf ("\t\t\t\t\t India:     %2d:%02d:%02d\n",(ptm->tm_hour+5)%24,(ptm->tm_min+30)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Indonesia") == 0)
    {
       printf ("\t\t\t\t\t Indonesia (Jakarta):     %2d:%02d:%02d\n",(ptm->tm_hour+7)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Iran") == 0)
    {
       printf ("\t\t\t\t\t Iran:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+30)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Iraq") == 0)
    {
       printf ("\t\t\t\t\t Iraq:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Ireland") == 0)
    {
       printf ("\t\t\t\t\t Ireland:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Israel") == 0)
    {
       printf ("\t\t\t\t\t Israel:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Italy") == 0)
    {
       printf ("\t\t\t\t\t Italy:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Jamaica") == 0)
    {
       printf ("\t\t\t\t\t Jamaica:     %2d:%02d:%02d\n",(ptm->tm_hour-5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Japan") == 0)
    {
       printf ("\t\t\t\t\t Japan (Tokyo):     %2d:%02d:%02d\n",(ptm->tm_hour+9)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Jordan") == 0)
    {
       printf ("\t\t\t\t\t Jordan:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Kazakhstan") == 0)
    {
       printf ("\t\t\t\t\t Kazakhstan (Nor-Sultan):     %2d:%02d:%02d\n",(ptm->tm_hour+6)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Kenya") == 0)
    {
       printf ("\t\t\t\t\t Kenya:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Kiribati") == 0)
    {
       printf ("\t\t\t\t\t South Tarawa:     %2d:%02d:%02d\n",(ptm->tm_hour+12)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
       printf ("\t\t\t\t\t Phoenix:          %2d:%02d:%02d\n",(ptm->tm_hour+13)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
       printf ("\t\t\t\t\t Line Islands:     %2d:%02d:%02d\n",(ptm->tm_hour+14)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Kosovo") == 0)
    {
       printf ("\t\t\t\t\t Kosovo:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Kuwait") == 0)
    {
       printf ("\t\t\t\t\t Kuwait:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Kyrgyzstan") == 0)
    {
       printf ("\t\t\t\t\t Kyrgyzstan:     %2d:%02d:%02d\n",(ptm->tm_hour+6)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Laos") == 0)
    {
       printf ("\t\t\t\t\t Laos:     %2d:%02d:%02d\n",(ptm->tm_hour+7)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Latvia") == 0)
    {
       printf ("\t\t\t\t\t Latvia:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Lebanon") == 0)
    {
       printf ("\t\t\t\t\t Lebanon:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Lesotho") == 0)
    {
       printf ("\t\t\t\t\t Lesotho:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Liberia") == 0)
    {
       printf ("\t\t\t\t\t Liberia:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Libya") == 0)
    {
       printf ("\t\t\t\t\t Libya:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Liechtenstein") == 0)
    {
       printf ("\t\t\t\t\t Liechtenstein:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Lithuania") == 0)
    {
       printf ("\t\t\t\t\t Lithuania:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Luxembourg") == 0)
    {
       printf ("\t\t\t\t\t Luxembourg:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Madagascar") == 0)
    {
       printf ("\t\t\t\t\t Madagascar:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Malawi") == 0)
    {
       printf ("\t\t\t\t\t Malawi:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Malaysia") == 0)
    {
       printf ("\t\t\t\t\t Malaysia:     %2d:%02d:%02d\n",(ptm->tm_hour+8)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Maldives") == 0)
    {
       printf ("\t\t\t\t\t Maldives:     %2d:%02d:%02d\n",(ptm->tm_hour+5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Mali") == 0)
    {
       printf ("\t\t\t\t\t Mali:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Malta") == 0)
    {
       printf ("\t\t\t\t\t Malta:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Marshall-Islands") == 0)
    {
       printf ("\t\t\t\t\t  Marshall Islands:     %2d:%02d:%02d\n",(ptm->tm_hour+12)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Mauritania") == 0)
    {
       printf ("\t\t\t\t\t  Mauritania:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Mauritius") == 0)
    {
       printf ("\t\t\t\t\t  Mauritius:     %2d:%02d:%02d\n",(ptm->tm_hour+4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Mexico") == 0)
    {
       printf ("\t\t\t\t\t  Mexico (Mexico City, CDMX):     %2d:%02d:%02d\n",(ptm->tm_hour-6)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Micronesia") == 0)
    {
       printf ("\t\t\t\t\t  Micronesia (Palikir, Pohnpei, Federated States of Micronesia):     %2d:%02d:%02d\n",(ptm->tm_hour+11)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Moldova") == 0)
    {
       printf ("\t\t\t\t\t  Moldova:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Monaco") == 0)
    {
       printf ("\t\t\t\t\t  Monaco:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Mongolia") == 0)
    {
       printf ("\t\t\t\t\t  Mongolia (Ulaanbaatar):     %2d:%02d:%02d\n",(ptm->tm_hour+8)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Montenegro") == 0)
    {
       printf ("\t\t\t\t\t  Montenegro:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Morocco") == 0)
    {
       printf ("\t\t\t\t\t  Morocco:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Mozambique") == 0)
    {
       printf ("\t\t\t\t\t  Mozambique:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Myanmar") == 0 ||strcmp(C, "Burma") == 0)
    {
       printf ("\t\t\t\t\t  Myanmar (Burma):     %2d:%02d:%02d\n",(ptm->tm_hour+6)%24,(ptm->tm_min+30)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Namibia") == 0)
    {
       printf ("\t\t\t\t\t  Namibia:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Nauru") == 0)
    {
       printf ("\t\t\t\t\t  Nauru:     %2d:%02d:%02d\n",(ptm->tm_hour+12)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Nepal") == 0)
    {
       printf ("\t\t\t\t\t  Nepal:     %2d:%02d:%02d\n",(ptm->tm_hour+5)%24,(ptm->tm_min+45)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Netherlands") == 0)
    {
       printf ("\t\t\t\t\t  Netherlands:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "New-Zealand") == 0)
    {
       printf ("\t\t\t\t\t  New Zealand (Wellington):     %2d:%02d:%02d\n",(ptm->tm_hour+13)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Nicaragua") == 0)
    {
       printf ("\t\t\t\t\t  Nicaragua:     %2d:%02d:%02d\n",(ptm->tm_hour-6)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Niger") == 0)
    {
       printf ("\t\t\t\t\t  Niger:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Nigeria") == 0)
    {
       printf ("\t\t\t\t\t  Nigeria:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "North-Korea") == 0)
    {
       printf ("\t\t\t\t\t  North Korea:     %2d:%02d:%02d\n",(ptm->tm_hour+9)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "North-Macedonia") == 0)
    {
       printf ("\t\t\t\t\t  North Macedonia:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Norway") == 0)
    {
       printf ("\t\t\t\t\t  Norway:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Oman") == 0)
    {
       printf ("\t\t\t\t\t  Oman:     %2d:%02d:%02d\n",(ptm->tm_hour+4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Pakistan") == 0)
    {
       printf ("\t\t\t\t\t  Pakistan:     %2d:%02d:%02d\n",(ptm->tm_hour+5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Palau") == 0)
    {
       printf ("\t\t\t\t\t  Palau:     %2d:%02d:%02d\n",(ptm->tm_hour+9)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Palestine") == 0)
    {
       printf ("\t\t\t\t\t  Palestine:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Panama") == 0)
    {
       printf ("\t\t\t\t\t  Panama:     %2d:%02d:%02d\n",(ptm->tm_hour-5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Papua-New-Guinea") == 0)
    {
       printf ("\t\t\t\t\t  Papua New Guinea:     %2d:%02d:%02d\n",(ptm->tm_hour+10)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Paraguay") == 0)
    {
       printf ("\t\t\t\t\t  Paraguay:     %2d:%02d:%02d\n",(ptm->tm_hour-3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Peru") == 0)
    {
       printf ("\t\t\t\t\t  Peru:     %2d:%02d:%02d\n",(ptm->tm_hour-5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Philippines") == 0)
    {
       printf ("\t\t\t\t\t  Philippines:     %2d:%02d:%02d\n",(ptm->tm_hour+8)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Poland") == 0)
    {
       printf ("\t\t\t\t\t  Poland:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Portugal") == 0)
    {
       printf ("\t\t\t\t\t  Portugal (Lisbon):     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Qatar") == 0)
    {
       printf ("\t\t\t\t\t  Qatar:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Romania") == 0)
    {
       printf ("\t\t\t\t\t  Romania:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Russia") == 0)
    {
       printf ("\t\t\t\t\t  Russia (Moscow):     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Rwanda") == 0)
    {
       printf ("\t\t\t\t\t  Rwanda:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Saint-Kitts-and-Nevis") == 0)
    {
       printf ("\t\t\t\t\t  Saint Kitts and Nevis:     %2d:%02d:%02d\n",(ptm->tm_hour-4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Saint-Lucia") == 0)
    {
       printf ("\t\t\t\t\t  Saint Lucia:     %2d:%02d:%02d\n",(ptm->tm_hour-4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Saint-Vincent-and-the-Grenadines") == 0)
    {
       printf ("\t\t\t\t\t  Saint Vincent and the Grenadines:     %2d:%02d:%02d\n",(ptm->tm_hour-4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Samoa") == 0)
    {
       printf ("\t\t\t\t\t  Samoa:     %2d:%02d:%02d\n",(ptm->tm_hour+14)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "San-Marino") == 0)
    {
       printf ("\t\t\t\t\t  San Marino:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Sao-Tome-and-Principe") == 0)
    {
       printf ("\t\t\t\t\t  Sao Tome and Principe:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Saudi-Arabia") == 0)
    {
       printf ("\t\t\t\t\t  Saudi Arabia:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Scotland") == 0)
    {
       printf ("\t\t\t\t\t  Scotland:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Senegal") == 0)
    {
       printf ("\t\t\t\t\t  Senegal:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Serbia") == 0)
    {
       printf ("\t\t\t\t\t  Serbia:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Seychelles") == 0)
    {
       printf ("\t\t\t\t\t  Seychelles:     %2d:%02d:%02d\n",(ptm->tm_hour+4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Sierra-Leone") == 0)
    {
       printf ("\t\t\t\t\t  Sierra Leone:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Singapore") == 0)
    {
       printf ("\t\t\t\t\t  Singapore:     %2d:%02d:%02d\n",(ptm->tm_hour+8)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Slovakia") == 0)
    {
       printf ("\t\t\t\t\t  Slovakia:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Slovenia") == 0)
    {
       printf ("\t\t\t\t\t  Slovenia:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Solomon-Islands") == 0)
    {
       printf ("\t\t\t\t\t  Solomon Islands:     %2d:%02d:%02d\n",(ptm->tm_hour+11)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Somalia") == 0)
    {
       printf ("\t\t\t\t\t  Somalia:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "South-Africa") == 0)
    {
       printf ("\t\t\t\t\t  South Africa:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "South-Korea") == 0)
    {
       printf ("\t\t\t\t\t  South Korea:     %2d:%02d:%02d\n",(ptm->tm_hour+9)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "South-Sudan") == 0)
    {
       printf ("\t\t\t\t\t  South Sudan:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Spain") == 0)
    {
       printf ("\t\t\t\t\t  Spain:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Sri-Lanka") == 0)
    {
       printf ("\t\t\t\t\t  Sri Lanka:     %2d:%02d:%02d\n",(ptm->tm_hour+5)%24,(ptm->tm_min+30)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Sudan") == 0)
    {
       printf ("\t\t\t\t\t   Sudan:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Suriname") == 0)
    {
       printf ("\t\t\t\t\t   Suriname:     %2d:%02d:%02d\n",(ptm->tm_hour-3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Sweden") == 0)
    {
       printf ("\t\t\t\t\t   Sweden:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Switzerland") == 0)
    {
       printf ("\t\t\t\t\t   Switzerland:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Syria") == 0)
    {
       printf ("\t\t\t\t\t   Syria:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Taiwan") == 0)
    {
       printf ("\t\t\t\t\t   Taiwan:     %2d:%02d:%02d\n",(ptm->tm_hour+8)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
     else if (strcmp(C, "Tajikistan") == 0)
    {
       printf ("\t\t\t\t\t   Tajikistan:     %2d:%02d:%02d\n",(ptm->tm_hour+5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Tanzania") == 0)
    {
       printf ("\t\t\t\t\t   Tanzania:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Thailand") == 0)
    {
       printf ("\t\t\t\t\t   Thailand:     %2d:%02d:%02d\n",(ptm->tm_hour+7)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Timor-Leste") == 0)
    {
       printf ("\t\t\t\t\t   Timor-Leste:     %2d:%02d:%02d\n",(ptm->tm_hour+9)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Togo") == 0)
    {
       printf ("\t\t\t\t\t   Togo:     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Tonga") == 0)
    {
       printf ("\t\t\t\t\t   Tonga:     %2d:%02d:%02d\n",(ptm->tm_hour+13)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Trinidad-and-Tobago") == 0)
    {
       printf ("\t\t\t\t\t   Trinidad and Tobago:     %2d:%02d:%02d\n",(ptm->tm_hour-4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Tunisia") == 0)
    {
       printf ("\t\t\t\t\t   Tunisia:     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Turkey") == 0)
    {
       printf ("\t\t\t\t\t   Turkey:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Turkmenistan") == 0)
    {
       printf ("\t\t\t\t\t   Turkmenistan:     %2d:%02d:%02d\n",(ptm->tm_hour+5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Tuvalu") == 0)
    {
       printf ("\t\t\t\t\t   Tuvalu:     %2d:%02d:%02d\n",(ptm->tm_hour+12)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Uganda") == 0)
    {
       printf ("\t\t\t\t\t   Uganda:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Ukraine") == 0)
    {
       printf ("\t\t\t\t\t   Ukraine:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "U.A.E.") == 0)
    {
       printf ("\t\t\t\t\t   United Arab Emirates (U.A.E.):     %2d:%02d:%02d\n",(ptm->tm_hour+4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "U.K.") == 0)
    {
       printf ("\t\t\t\t\t   United Kingdom (U.K.):     %2d:%02d:%02d\n",(ptm->tm_hour+0)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "U.S.A") == 0 || strcmp(C, "America") == 0)
    {
       printf ("\t\t\t\t\t United State of America (Washington, DC):     %2d:%02d:%02d\n",(ptm->tm_hour-5)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Uruguay") == 0)
    {
       printf ("\t\t\t\t\t   Uruguay:     %2d:%02d:%02d\n",(ptm->tm_hour-3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Vanuatu") == 0)
    {
       printf ("\t\t\t\t\t   Vanuatu:     %2d:%02d:%02d\n",(ptm->tm_hour+11)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Vatican-City") == 0)
    {
       printf ("\t\t\t\t\t   Vatican City (Holy See):     %2d:%02d:%02d\n",(ptm->tm_hour+1)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Venezuela") == 0)
    {
       printf ("\t\t\t\t\t   Venezuela:     %2d:%02d:%02d\n",(ptm->tm_hour-4)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Vietnam") == 0)
    {
       printf ("\t\t\t\t\t   Vietnam:     %2d:%02d:%02d\n",(ptm->tm_hour+7)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Yemen") == 0)
    {
       printf ("\t\t\t\t\t   Yemen:     %2d:%02d:%02d\n",(ptm->tm_hour+3)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Zambia") == 0)
    {
       printf ("\t\t\t\t\t   Zambia:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
    else if (strcmp(C, "Zimbabwe") == 0)
    {
       printf ("\t\t\t\t\t   Zimbabwe:     %2d:%02d:%02d\n",(ptm->tm_hour+2)%24,(ptm->tm_min+0)%60,(ptm->tm_sec));
    }
   else
   {
    printf("\t\t\t\t\t Error\n");
    printf("\t\t\t\t\t Please Enter the correct Country name!");
   }
    return 0;
}
