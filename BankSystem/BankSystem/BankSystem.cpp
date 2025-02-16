
#include "clsLoginScreen.h"


int main()
{


    while (!Locked)
    {
        clsLoginScreen::ShowLoginScreen();
    }



    if (Locked)
    {
        cout << "Locked Secssfully Concet To Admin To UnLocked :-)";
    }

    system("pause>0");
    return 0;
}
