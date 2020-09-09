import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import Metronome 1.0

ApplicationWindow {
    id: window
    title: "Metronome"
    visible: true
    height: 300
    width: 400

    property bool playing: false

    ColumnLayout {
        anchors.centerIn: parent

        Label {
            text: "Beats Per Minute"
        }
        Label {
            text: beatsPerMinuteSlider.value
        }
        Slider {
            id: beatsPerMinuteSlider
            from: 20
            to: 250
            value: Metronome.beatsPerMinute
            onMoved: Metronome.setBeatsPerMinute(value)
        }

        Label {
            text: "Beats Per Bar"
        }
        RowLayout {
            id: beatsPerBarSelection
            RadioButton {
                text: "1"
                onClicked: Metronome.setBeatsPerBar(1)
            }

            RadioButton {
                text: "2"
                onClicked: Metronome.setBeatsPerBar(2)
            }

            RadioButton {
                text: "3"
                onClicked: Metronome.setBeatsPerBar(3)
            }

            RadioButton {
                checked: true
                text: "4"
                onClicked: Metronome.setBeatsPerBar(4)
            }
        }

        Label {
            text: "Clicks Per Beat"
        }
        RowLayout {
            id: clicksPerBeatSelection
            RadioButton {
                checked: true
                text: "1"
                onClicked: Metronome.setClicksPerBeat(1)
            }

            RadioButton {
                text: "2"
                onClicked: Metronome.setClicksPerBeat(2)
            }

            RadioButton {
                text: "3"
                onClicked: Metronome.setClicksPerBeat(3)
            }

            RadioButton {
                text: "4"
                onClicked: Metronome.setClicksPerBeat(4)
            }
        }

        RowLayout {
            Button {
                id: playButton
                text: playing ? "STOP" : "PLAY"
                onClicked: {
                    if(playing) {
                        playing = false
                        Metronome.stop()
                    }
                    else {
                        playing = true
                        Metronome.play()
                    }
                }
            }

            Button {
                id: tapButton
                text: "TAP"
                onClicked: Metronome.tap()
            }
        }

        ProgressBar {
            from: 0
            to: Metronome.beatsPerBar
            value: Metronome.beat
        }
    }
}
