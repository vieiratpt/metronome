/*
 * Copyright (C) 2020 by João Pedro Vieira <vieiratpt@pm.me>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
 */

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
