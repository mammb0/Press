#pragma once

/*
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
*/

class Press {
private:
    //Press_Param
    int d_Tablet;
    int h_Tablet;
    int v_in_Press;//Скорость прессования
    int v_out_Press;//Скорость извлечения
    int f_Press0; //Усилие прессования
    int f_Press1; //Усилие удержания
    int t_in;//t_выдержки (для прессования)
    int t_out;//t_разгрузки (для прессования)
    int PPR_max; //ППР_максимальное
    int PPR = 0;

public:
    int n_Press; //повторений прессования
    int n_catch;//N_попыток захвата таблетки
    int n_install;//N_попыток установки таблетки
    double t_start;//t_start прессования
    double t_end;//t_end
    bool signal; //ввести сигнал начала прессования
    bool status; //готовность пресса

    Press(int* Press_Param);
    bool Start();
    int* Press_Param_Value();
    void Risk();//Оценка риска (как?!?!?!??!?)
    void PPR_Time(); //инкрементировать ППР
    bool PPR_Status(); //проверить не превысило ли максимум и если да, то вызвать оповещение
    bool PPR_Warning();//Оповещение о ППР, если bool PPR_Status() - да
    void PPR_Update(int PPR);//Обновление ППР

};
