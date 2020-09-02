project(metronome)

cmake_minimum_required(VERSION 2.8)

find_package(Qt5 REQUIRED
    Core
    Qml
    Quick
    QuickControls2
    Widgets
)

add_subdirectory(src)
