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

#include "metronome.h"

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
    emit beatsPerBarChanged();
}

void Metronome::setClicksPerBeat(quint8 value) {
    _clicksPerBeat = value;
    updateInterval();
}

void Metronome::setBeatsPerMinute(quint8 value) {
    _beatsPerMinute = value;
    updateInterval();
    emit beatsPerMinuteChanged();
}

void Metronome::setBeat(quint8 value) {
    _beat = value;
    emit beatChanged();
}

void Metronome::setClick(quint8 value) {
    _click = value;
}

void Metronome::incrementBeat() {
    setBeat(beat() % beatsPerBar() + 1);
}

void Metronome::incrementClick() {
    setClick(click() % clicksPerBeat() + 1);
}

void Metronome::play() {
    if(!_timer) {
        deleteElapsedTimer();
        _timer = new QTimer(this);
        connect(_timer, &QTimer::timeout, this, &Metronome::beep);
        quint16 interval = 60000 / beatsPerMinute() / clicksPerBeat();
        setClick(clicksPerBeat());
        beep();
        _timer->start(interval);
    }
}

void Metronome::stop() {
    deleteTimer();
    deleteElapsedTimer();
    setBeat(0);
}

void Metronome::tap() {
    if(!_elapsedTimer) {
        _elapsedTimer = new QElapsedTimer();
        _elapsedTimer->start();
    }
    else {
        if(60000 / _elapsedTimer->elapsed() >= MAX_BPM) {
            setBeatsPerMinute(MAX_BPM);
        }
        else if(60000 / _elapsedTimer->elapsed() <= MIN_BPM) {
            setBeatsPerMinute(MIN_BPM);
        }
        else {
            setBeatsPerMinute(60000 / _elapsedTimer->elapsed());
        }
        _elapsedTimer->restart();
    }
}

void Metronome::beep() {
    if(click() == clicksPerBeat()) {
        incrementBeat();
    }
    incrementClick();

    if(beat() == 1 && click() == 1) {
        QSound::play(QStringLiteral("qrc:/beep_high.wav"));
    }
    else {
        QSound::play(QStringLiteral("qrc:/beep_low.wav"));
    }
}

void Metronome::updateInterval() {
    if(_timer) {
        quint16 interval = 60000 / beatsPerMinute() / clicksPerBeat();
        _timer->setInterval(interval);
    }
}

void Metronome::deleteTimer() {
    if(_timer) {
        delete _timer;
        _timer = NULL;
    }
}

void Metronome::deleteElapsedTimer() {
    if(_elapsedTimer) {
        delete _elapsedTimer;
        _elapsedTimer = NULL;
    }
}

QObject* Metronome::provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Metronome *metronome = new Metronome();
    return metronome;
}
