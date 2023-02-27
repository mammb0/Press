#include "Bunker.h"

Bunker::Bunker(int v_Bunker_max)
{
    this->v_Bunker_max = v_Bunker_max;
}

bool Bunker::Mass_Powder_In_Bunker_Check(int* Powder_Param, int m_Boat){

    this->m_Powder_In_Bunker = Powder_Param[1] - m_Boat; //сколько порошка в бункере осталось (масса)
    if ((this->m_Powder_In_Bunker - m_Boat) >= 3*14) //1 таблетка <= 14г (ЧТЗ_Участок прессования таблеток, с.8)
        return true;
    else
        return false;
}

int Bunker::Time(){
    //

    //
    return this->t;
}
