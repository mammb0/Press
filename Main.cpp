#include "Boat.h"
#include "Bunker.h"
#include "Powder.h"
#include "Press.h"
#include "Tablet.h"


#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Press_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();*/

    int n_Press = 0; //сколько раз выполнено прессование (промежуточное)
    int n_Tablet = 0; //сколько таблеток проработано из серии(промежуточное, всего 3)
//    int n_catch = 0;//N_попыток захвата таблетки (промежуточное)
//    int n_install = 0;//N_попыток установки таблетки (промежуточное)
    int m_Tablet;
    int ro_Tablet;
    int n_Boat = 0; //колличество заполненных лодочек
    int n_Boat_max; //лодочек в хранилище
    bool i;
    int time1, time2, time3; //Время выхода на усилие прессования (time1) +Время выдержки (time2) +Время разгрузки (time3)

    int Press_Param[11];
    Press press(Press_Param);

    int v_Bunker_max;
    //ввести v_Bunker_max
    Bunker bunker(v_Bunker_max);
    int Powder_Param[3]; //Powder_Param[2] - масса порошка

    int id_Boat = 0;
    int id_Tablet = 0;

    //ввести количество пустых лодочек в хранилище в int n_Boat_max;
    //ввести сигнал начала прессования в press.signal = 1
    //ввести ППР в press.PPR_Update(i)
    press.status = 1;
    while (press.Start()){
        //цикл по времени
        //записать в БД
        if (press.PPR_Status()){ //преверяем ППР
            press.PPR_Time(); //инкрементируем

            //ввести параметры порошка в Powder_Param[3];
            Powder powder(Powder_Param);
            bunker.Powder_List_Bunker.append(powder); //добавляем в список порошок

            Boat boat(id_Boat++); //будет 1, 2 и т.д. как номера

            //ввести параметры пресса в Press_Param[11];
            Press press(Press_Param);

            //Задать Время выхода на усилие прессования (time1) +Время выдержки (time2) +Время разгрузки (time3) в секундах
            while(n_Tablet < 3){ //сделано ли три таблетки

                if(boat.Mass_Boat_Check()){ //если лодочка не заполнена по массе !?!??!?!??!??!?!??!?!?!??!?
                    while(n_Press < press.n_Press){ //делаем нужное количество прессований
                        //pthread_delay_np(time1+time2+time3); //задержка
                        n_Press ++;
                    }

                    Tablet tablet(id_Tablet++, Press_Param, Powder_Param);
                    ro_Tablet = tablet.Tablet_Density();
                    m_Tablet = tablet.Tablet_Mass(ro_Tablet);
                    boat.Tablet_In_Boat(); //инкрементация таблеток в лодочке
                    boat.Mass_Boat(m_Tablet); //увеличение массы лодочки
                    boat.Tablet_List_Boat.append(tablet); //добавляем в список параметры таблетки
                    n_Tablet ++; //3 таблетки
                }
                else { //если заполнена лодочка по массе создаем новую
                    press.status = 0; //пресс не может работать дальше
                    n_Boat++;
                    //записать в JSON

                    if(n_Boat < n_Boat_max){ //проверка наличия пустых лодочек в хранилище
                        Boat boat(id_Boat++);
                    }
                    else{
                        i = boat.Boat_Warning(); //выводим оповещение об отсутствии и предлагаем обновить количество лодочек (записываем в i)
                        if (i){
                            //ввести количество пустых лодочек в хранилище в int n_Boat_max;
                            press.status = 1; //пресс может работать дальше
                        }

                    }
                }

            }

            if(!bunker.Mass_Powder_In_Bunker_Check(Powder_Param, n_Boat*boat.m_Boat)){ //проверка хватит ли пресс порошка на 3 таблетки
                press.status = 0;
                //оповещение об отсутствии пресс порошка и предлагаем засыпать заново (результат в i)
                if(i){
                    //ввести параметры порошка в Powder_Param[3];
                    Powder powder(Powder_Param);
                    bunker.Powder_List_Bunker.append(powder); //добавляем в список порошок
                    press.status = 1;
                    //ввести сигнал начала прессования в press.signal
                }
            }

            //ввести сигнал начала прессования в press.signal = 1
        }
        else{ //если ППР превысило
            press.status = 0;
            i = press.PPR_Warning(); //предложить ввести новое ППР записать в i
            if(i) {
                press.PPR_Update(i);
                press.status = 1;
                //ввести сигнал начала прессования в press.signal = 1
            }
        }

    }

    return 0;
}
