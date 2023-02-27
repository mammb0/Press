#include "Tablet.h"
#include "Press.h"
#include "Powder.h"

Tablet::Tablet(int id_Tablet, int* Press_Param, int* Powder_Param):Press(Press_Param), Powder(Powder_Param)
{
    this->id_Tablet = id_Tablet;
}

int Tablet::Tablet_Density(){
    //у новоселова (c.34)
    return this->ro_Tablet;
}

int Tablet::Tablet_Mass(int ro_Tablet){
    //m=ro*V=ro*h*2*3,14*R^2
    return this->m_Tablet = ro_Tablet*Tablet_Param_Value(4)*2*3,14*(Tablet_Param_Value(3)/2)^2;
}

int Tablet::Tablet_Param_Value(int i){
    int Tablet_Param[17];
    Tablet_Param[0] = this->id_Tablet;
    Tablet_Param[1] = this->m_Tablet;
    Tablet_Param[2] = this->ro_Tablet;
    //пресс
    int* Press_Param = Press_Param_Value();
    Tablet_Param[3] = Press_Param[0];
    Tablet_Param[4] = Press_Param[1];
    Tablet_Param[5] = Press_Param[2];
    Tablet_Param[6] = Press_Param[3];
    Tablet_Param[7] = Press_Param[4];
    Tablet_Param[8] = Press_Param[5];
    Tablet_Param[9] = Press_Param[6];
    Tablet_Param[10] = Press_Param[7];
    Tablet_Param[11] = Press_Param[8];
    Tablet_Param[12] = Press_Param[9];
    Tablet_Param[13] = Press_Param[10];
    //порошок
    int* Powder_Param = Powder_Param_Value();
    Tablet_Param[14] = Powder_Param[0];
    Tablet_Param[15] = Powder_Param[1];
    Tablet_Param[16] = Powder_Param[2];
    return Tablet_Param[i];
}

