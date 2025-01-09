#include "frontend.h"
#include "backend.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <QTimer>
#include <QRandomGenerator>

Frontend::Frontend(QWidget *parent) : QWidget(parent), time(0) {
    // Set up the main widget
    setWindowTitle("Network Monitor");
    setMinimumSize(800, 600);

    // Create the layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Create labels for download and upload speeds
    downloadLabel = new QLabel("Download: 0.00 Mbps", this);
    uploadLabel = new QLabel("Upload: 0.00 Mbps", this);
    layout->addWidget(downloadLabel);
    layout->addWidget(uploadLabel);

    // Create the chart and series
    chart = new QChart();
    downloadSeries = new QLineSeries();
    uploadSeries = new QLineSeries();
    chart->addSeries(downloadSeries);
    chart->addSeries(uploadSeries);

    // Set up the X and Y axes
    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(0, 100); // Time (0-100 seconds)
    axisX->setLabelFormat("%d");
    axisX->setTitleText("Time (s)");

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 100); // Speed (0-100 Mbps)
    axisY->setLabelFormat("%d");
    axisY->setTitleText("Speed (Mbps)");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    downloadSeries->attachAxis(axisX);
    downloadSeries->attachAxis(axisY);
    uploadSeries->attachAxis(axisX);
    uploadSeries->attachAxis(axisY);

    // Create the chart view
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);

    // Set up a timer to update the speeds and graph
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Frontend::updateNetworkSpeeds);
    timer->start(100); // Update every 100ms
}

void Frontend::updateNetworkSpeeds() {
    double downloadSpeed, uploadSpeed;
    fetch_network_speeds(&downloadSpeed, &uploadSpeed);

    // Update the labels
    downloadLabel->setText(QString("Download: %1 Mbps").arg(downloadSpeed, 0, 'f', 2));
    uploadLabel->setText(QString("Upload: %1 Mbps").arg(uploadSpeed, 0, 'f', 2));

    // Add data points to the graph
    downloadSeries->append(time, downloadSpeed);
    uploadSeries->append(time, uploadSpeed);
    time++;

    // Scroll the X-axis to show the latest data
    if (time > 100) {
        QValueAxis *axisX = qobject_cast<QValueAxis*>(chart->axisX());
        axisX->setRange(time - 100, time);
    }
}