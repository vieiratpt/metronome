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

quint8 Metronome::click() {
    return _click;
}

void Metronome::setBeatsPerBar(quint8 value) {
    _beatsPerBar = value;
}

void Metronome::setClicksPerBeat(quint8 value) {
    _clicksPerBeat = value;
    updateInterval();
}

void Metronome::setBeatsPerMinute(quint8 value) {
    _beatsPerMinute = value;
    updateInterval();
}

void Metronome::setBeat(quint8 value) {
    _beat = value;
    emit beatChanged();
}

void Metronome::setClick(quint8 value) {
    _click = value;
}

void Metronome::incrementBeat() {
    _beat = beat() % beatsPerBar() + 1;
    emit beatChanged();
}

void Metronome::incrementClick() {
    _click = click() % clicksPerBeat() + 1;
}

void Metronome::play() {
    if(!timer) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Metronome::beep);
        quint16 interval = 60000 / beatsPerMinute() / clicksPerBeat();
        setClick(clicksPerBeat());
        beep();
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
        delete timer;
        timer = NULL;
        setBeat(0);
    }
}

void Metronome::beep() {
    if(click() == clicksPerBeat()) {
        incrementBeat();
    }
    incrementClick();

    if(beat() == 1 and click() == 1) {
        QSound::play("qrc:/beep_high.wav");
    }
    else {
        QSound::play("qrc:/beep_low.wav");
    }
}

void Metronome::updateInterval() {
    if(timer) {
        quint16 interval = 60000 / beatsPerMinute() / clicksPerBeat();
        timer->setInterval(interval);
    }
}

QObject* Metronome::provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Metronome *metronome = new Metronome();
    return metronome;
}
