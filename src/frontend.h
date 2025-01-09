#ifndef FRONTEND_H
#define FRONTEND_H

#include <QWidget>
#include <QLabel>
#include <QChartView>
#include <QLineSeries>
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

class Frontend : public QWidget {
    Q_OBJECT

public:
    Frontend(QWidget *parent = nullptr);

private slots:
    void updateNetworkSpeeds();

private:
    QLabel *downloadLabel;
    QLabel *uploadLabel;
    QChartView *chartView;
    QChart *chart;
    QLineSeries *downloadSeries;
    QLineSeries *uploadSeries;
    QTimer *timer;
    int time;
};

#endif // FRONTEND_H