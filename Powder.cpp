#include "Powder.h"

Powder::Powder(int* Powder_Param)
{
    this->id_Powder = Powder_Param[0];
    this->m_Powder = Powder_Param[1];
    this->ro_Powder = Powder_Param[2];
}

int* Powder::Powder_Param_Value(){
    int Powder_Param[3];
    Powder_Param[0] = this->id_Powder;
    Powder_Param[1] = this->m_Powder;
    Powder_Param[2] = this->ro_Powder;
    return Powder_Param;
}
