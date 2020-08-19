#include <QApplication>

#include "TDMDetailDataForm.h"

#include "TDMSummaryTableWgt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    TDMTrendChartForm w;
    TDMSummaryTableWgt w;
    w.resize(1000,600);
    w.show();

    return a.exec();
}
