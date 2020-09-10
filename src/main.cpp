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
