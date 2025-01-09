#include <QApplication>
#include "frontend.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Apply a modern dark theme
    app.setStyleSheet(
        "QWidget { background-color: #2d2d2d; color: #ffffff; }"
        "QLabel { font-size: 14px; }"
        "QChart { background-color: #2d2d2d; }"
        "QLineSeries { color: #00ff00; }"  // Green for download
        "QLineSeries { color: #ff0000; }"  // Red for upload
    );

    Frontend window;
    window.show();

    return app.exec();
}