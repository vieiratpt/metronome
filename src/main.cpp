#include <QApplication>
#include <QQmlApplicationEngine>

#include "metronome.h"

int main(int argc, char *argv[]) {
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterSingletonType<Metronome>("Metronome", 1, 0, "Metronome", Metronome::provider);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine appEngine(QStringLiteral("qrc:/main.qml"));

    return app.exec();
}
