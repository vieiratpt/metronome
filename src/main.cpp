#include <QApplication>
#include <QQmlApplicationEngine>

#include "metronome.h"

int main(int argc, char *argv[]) {
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    Metronome metronome();

    qmlRegisterSingletonType<Metronome>("Metronome", 1, 0, "Metronome", Metronome::provider);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine appEngine("qrc:/main.qml");

    return app.exec();
}
