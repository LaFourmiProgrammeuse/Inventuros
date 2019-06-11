#ifndef ROUNDEDRECTWIDGET_H
#define ROUNDEDRECTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QPaintDevice>

class RoundedRectWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RoundedRectWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);

signals:

public slots:
};

#endif // ROUNDEDRECTWIDGET_H
