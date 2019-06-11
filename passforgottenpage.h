#ifndef PASSFORGOTTENPAGE_H
#define PASSFORGOTTENPAGE_H

#include <QWidget>

namespace Ui {
class PassForgottenPage;
}

class PassForgottenPage : public QWidget
{
    Q_OBJECT

public:
    explicit PassForgottenPage(QWidget *parent = nullptr);
    ~PassForgottenPage();

private:
    Ui::PassForgottenPage *ui;
};

#endif // PASSFORGOTTENPAGE_H
