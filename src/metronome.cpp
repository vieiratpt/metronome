#include "metronome.h"

#include <QDebug>

Metronome::Metronome(QObject *parent) : QObject(parent) {
    setObjectName(QStringLiteral("Metronome"));
}

quint8 Metronome::beatsPerBar() {
    qDebug() << "Get BPB" << _beatsPerBar;
    return _beatsPerBar;
}

quint8 Metronome::clicksPerBeat() {
    qDebug() << "Get CPB" << _clicksPerBeat;
    return _clicksPerBeat;
}

quint8 Metronome::beatsPerMinute() {
    qDebug() << "Get BPM" << _beatsPerMinute;
    return _beatsPerMinute;
}

void Metronome::setBeatsPerBar(quint8 value) {
    qDebug() << "BPB Selection" << value;
    _beatsPerBar = value;
}

void Metronome::setClicksPerBeat(quint8 value) {
    qDebug() << "CPB Selection" << value;
    _clicksPerBeat = value;
}

void Metronome::setBeatsPerMinute(quint8 value) {
    qDebug() << "BPM Attribution" << value;
    _beatsPerMinute = value;
}

void Metronome::play() {
    if(!timer) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Metronome::beep);
        int interval = 60000 / _beatsPerMinute / _clicksPerBeat;
        qDebug() << "Interval" << interval;
        timer->start(interval);
    }
    else {
        qDebug() << "Metronome already playing";
    }
}

void Metronome::stop() {
    qDebug() << "Stop playing!";
    delete timer;
    timer = NULL;
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
