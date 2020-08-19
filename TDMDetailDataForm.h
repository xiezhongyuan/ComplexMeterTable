#ifndef TDMDETAILDATAFORM_H
#define TDMDETAILDATAFORM_H

#include <QWidget>

namespace Ui {
class TDMDetailDataForm;
}

class TDMDetailDataForm : public QWidget
{
    Q_OBJECT

public:
    explicit TDMDetailDataForm(QWidget *parent = 0);
    ~TDMDetailDataForm();

private:
    Ui::TDMDetailDataForm *ui;
};

#endif // TDMDETAILDATAFORM_H
