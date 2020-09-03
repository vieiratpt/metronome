set(CMAKE_AUTOMOC ON)
set(SRCS
    main.cpp
    metronome.cpp
)

qt5_add_resources(RESOURCES ../resources.qrc)

add_executable(metronome ${SRCS} ${RESOURCES})

target_link_libraries(metronome
    Qt5::Core
    Qt5::Qml
    Qt5::QuickControls2
    Qt5::Quick
    Qt5::Widgets
)
