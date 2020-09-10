#pragma once

#include <QDebug>
#include <QElapsedTimer>
#include <QJSEngine>
#include <QQmlEngine>
#include <QObject>
#include <QSound>
#include <QTimer>

#define MIN_BPM 20
#define MAX_BPM 250

class Metronome : public QObject {
    Q_OBJECT

    Q_PROPERTY(quint8 beat READ beat NOTIFY beatChanged())
    Q_PROPERTY(quint8 beatsPerBar READ beatsPerBar NOTIFY beatsPerBarChanged())
    Q_PROPERTY(quint8 beatsPerMinute READ beatsPerMinute NOTIFY beatsPerMinuteChanged())

public:
    Metronome(QObject *parent = nullptr);
    ~Metronome() {
        deleteTimer();
        deleteElapsedTimer();
    }

    quint8 beatsPerBar();
    quint8 clicksPerBeat();
    quint8 beatsPerMinute();
    quint8 beat();
    quint8 click();
    Q_INVOKABLE void setBeatsPerBar(quint8 value);
    Q_INVOKABLE void setClicksPerBeat(quint8 value);
    Q_INVOKABLE void setBeatsPerMinute(quint8 value);
    void setBeat(quint8 value);
    void setClick(quint8 value);
    void incrementBeat();
    void incrementClick();
    Q_INVOKABLE void play();
    Q_INVOKABLE void stop();
    Q_INVOKABLE void tap();
    void beep();
    void updateInterval();
    void deleteTimer();
    void deleteElapsedTimer();
    static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    quint8 _beatsPerBar = 4;
    quint8 _clicksPerBeat = 1;
    quint8 _beatsPerMinute = 100;
    quint8 _beat = 0;
    quint8 _click = 0;
    QTimer *_timer = NULL;
    QElapsedTimer *_elapsedTimer = NULL;

signals:
    void beatChanged();
    void beatsPerBarChanged();
    void beatsPerMinuteChanged();
};
