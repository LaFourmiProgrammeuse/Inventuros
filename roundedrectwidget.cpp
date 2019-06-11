#include "roundedrectwidget.h"

RoundedRectWidget::RoundedRectWidget(QWidget *parent) : QWidget(parent)
{

}

void RoundedRectWidget::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.setPen(Qt::gray);
    p.setBrush(Qt::red);
    p.drawRoundedRect(0, 0, 50, 50, 20, 20);

    this->updateGeometry();
}
