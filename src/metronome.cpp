#include "metronome.h"

#include <QDebug>

Metronome::Metronome(QObject *parent) : QObject(parent) {
    setObjectName(QStringLiteral("Metronome"));
}

int Metronome::beatsPerBar() {
    return _beatsPerBar;
}

int Metronome::clicksPerBeat() {
    return _clicksPerBeat;
}

void Metronome::setBeatsPerBar(int value) {
    qDebug() << "BPB Selection" << value;
    _beatsPerBar = value;
}

void Metronome::setClicksPerBeat(int value) {
    qDebug() << "CPB Selection" << value;
    _clicksPerBeat = value;
}

QObject* Metronome::provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Metronome *metronome = new Metronome();
    return metronome;
}
