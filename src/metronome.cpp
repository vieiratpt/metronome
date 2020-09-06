#include "metronome.h"

#include <QDebug>
#include <QSound>

Metronome::Metronome(QObject *parent) : QObject(parent) {
    setObjectName(QStringLiteral("Metronome"));
}

quint8 Metronome::beatsPerBar() {
    return _beatsPerBar;
}

quint8 Metronome::clicksPerBeat() {
    return _clicksPerBeat;
}

quint8 Metronome::beatsPerMinute() {
    return _beatsPerMinute;
}

quint8 Metronome::beat() {
    return _beat;
}

void Metronome::setBeatsPerBar(quint8 value) {
    _beatsPerBar = value;
    qDebug() << "BPB Selection" << value;
}

void Metronome::setClicksPerBeat(quint8 value) {
    _clicksPerBeat = value;
    qDebug() << "CPB Selection" << value;
}

void Metronome::setBeatsPerMinute(quint8 value) {
    _beatsPerMinute = value;
    qDebug() << "BPM Attribution" << value;
}

void Metronome::setBeat(quint8 value) {
    _beat = 0;
    emit beatChanged();
    qDebug() << "Beat Attribution" << beat();
}

void Metronome::incrementBeat() {
    _beat = (beat()) % beatsPerBar() + 1;
    emit beatChanged();
    qDebug() << "Beat Increment" << beat();
}

void Metronome::play() {
    if(!timer) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Metronome::beep);
        quint16 interval = 60000 / beatsPerMinute() / clicksPerBeat();
        qDebug() << "Interval" << interval;
        timer->start(interval);
    }
    else {
        qDebug() << "Metronome already playing";
    }
}

void Metronome::stop() {
    if(!timer) {
        qDebug() << "Metronome is not playing";
    }
    else {
        qDebug() << "Stop playing!";
        delete timer;
        timer = NULL;
        setBeat(0);
    }
}

void Metronome::beep() {
    qDebug() << "Beep!";
    incrementBeat();
    if(beat() == 1) {
        QSound::play("qrc:/beep_high.wav");
    }
    else {
        QSound::play("qrc:/beep_low.wav");
    }
}

QObject* Metronome::provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Metronome *metronome = new Metronome();
    return metronome;
}
