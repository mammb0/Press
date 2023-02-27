#pragma once
#include "Powder.h"
#include "Press.h"


class Tablet : public Press, public Powder
{
private:
    int id_Tablet;
    int m_Tablet;
    int ro_Tablet;

public:
    double delta; //Усадка для печи спекания (!?!??!?!?!??!?!?)

    Tablet(int id_Tablet, int* Press_Param, int* Powder_Param);
    int Tablet_Density();
    int Tablet_Mass(int ro_Tablet);
    int Tablet_Param_Value(int i); //возвращает конкретный параметр

};

