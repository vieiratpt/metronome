#include "metronome.h"

#include <QTimer>
#include <QDebug>

Metronome::Metronome(QObject *parent) : QObject(parent) {
    setObjectName(QStringLiteral("Metronome"));
}

int Metronome::beatsPerBar() {
    qDebug() << "Get BPB" << _beatsPerBar;
    return _beatsPerBar;
}

int Metronome::clicksPerBeat() {
    qDebug() << "Get CPB" << _clicksPerBeat;
    return _clicksPerBeat;
}

int Metronome::beatsPerMinute() {
    qDebug() << "Get BPM" << _beatsPerMinute;
    return _beatsPerMinute;
}

void Metronome::setBeatsPerBar(int value) {
    qDebug() << "BPB Selection" << value;
    _beatsPerBar = value;
}

void Metronome::setClicksPerBeat(int value) {
    qDebug() << "CPB Selection" << value;
    _clicksPerBeat = value;
}

void Metronome::setBeatsPerMinute(int value) {
    qDebug() << "BPM Attribution" << value;
    _beatsPerMinute = value;
}

void Metronome::play() {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Metronome::beep);
    int interval = 60000 / _beatsPerMinute / _clicksPerBeat;
    qDebug() << "Interval" << interval;
    timer->start(interval);
}

void Metronome::beep() {
    qDebug() << "Beep!";
}

QObject* Metronome::provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Metronome *metronome = new Metronome();
    return metronome;
}
