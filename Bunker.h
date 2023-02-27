#pragma once

#include "Powder.h"
#include <QList>

class Bunker
{
private:
    int m_Powder_In_Bunker; //порошка в бункере
    int v_Bunker_max; //чтобы проверить сколько можно засыпать порошка
    int t; // t_ высыпания

public:

    QList<Powder> Powder_List_Bunker;

    Bunker(int v_Bunker_max);
    bool Mass_Powder_In_Bunker_Check(int* Powder_Param, int m_Boat); //рассчитать массу порошка в бункере и проверить можно ли сделать еще 3 таблетки
    int Time(); // t_высыпания (как!?!??!?!?)
};

